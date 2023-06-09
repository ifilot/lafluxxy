/**************************************************************************
 *                                                                        *
 *   Author: Ivo Filot <i.a.w.filot@tue.nl>                               *
 *                                                                        *
 *   LaFluxxy is free software:                                           *
 *   you can redistribute it and/or modify it under the terms of the      *
 *   GNU General Public License as published by the Free Software         *
 *   Foundation, either version 3 of the License, or (at your option)     *
 *   any later version.                                                   *
 *                                                                        *
 *   LaFluxxy is distributed in the hope that it will be useful,          *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty          *
 *   of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.              *
 *   See the GNU General Public License for more details.                 *
 *                                                                        *
 *   You should have received a copy of the GNU General Public License    *
 *   along with this program.  If not, see http://www.gnu.org/licenses/.  *
 *                                                                        *
 **************************************************************************/

#include "reaction_barkley.h"

ReactionBarkley::ReactionBarkley() {
    this->reacttype = KINETICS::BARKLEY;
}

void ReactionBarkley::init(MatrixXXd& a, MatrixXXd& b) const {
    this->init_half_screen(a, b, 1.0, this->alpha / 2.0);
}

/**
 * @brief      reaction kinetics Barkley
 *
 * @param[in]  a     concentration of A
 * @param[in]  b     concentration of B
 * @param      ra    reaction rate of A
 * @param      rb    reaction rate of B
 *
 * LATEX:
 * \frac{\partial X}{\partial t} = \epsilon X \left(1 - X\right) \cdot \left(X - \frac{Y + \beta}{\alpha} \right ) \\
 * \frac{\partial Y}{\partial t} = X^{3} - Y
 */
void ReactionBarkley::reaction(double a, double b, double *ra, double *rb) const {
    *ra = epsilon * a * (1.0 - a) * (a - (b + this->beta)/this->alpha);
    *rb = a*a*a - b;
}

/**
 * @brief      Sets the parameters.
 *
 * @param[in]  params  The parameters
 */
void ReactionBarkley::set_parameters(const std::string& params) {
    auto map = this->parse_parameters(params);

    auto got = map.find("alpha");
    if(got != map.end()) {
        this->alpha = got->second;
    } else {
        throw std::runtime_error("Cannot find parameter alpha");
    }

    got = map.find("beta");
    if(got != map.end()) {
        this->beta = got->second;
    } else {
        throw std::runtime_error("Cannot find parameter beta");
    }

    got = map.find("epsilon");
    if(got != map.end()) {
        this->epsilon = got->second;
    } else {
        throw std::runtime_error("Cannot find parameter epsilon");
    }

    // std::vector<std::string> paramlist = {"alpha", "beta", "epsilon"};
    // std::cout << "Succesfully loaded the following parameters" << std::endl;
    // for(const std::string& variable : paramlist) {
    //     try {
    //         auto got = map.find(variable);
    //         std::cout << "    " << variable << " = " << got->second << std::endl;
    //     } catch (const std::exception& e) {
    //         std::cerr << "Found error: " << e.what() << std::endl;
    //     }

    // }
}

/**
 * @brief      Gets the kinetic parameters.
 *
 * @return     The kinetic parameters.
 */
std::array<double, 4> ReactionBarkley::get_kinetic_parameters() const {
    return {this->alpha, this->beta, this->epsilon, 0.0};
}
