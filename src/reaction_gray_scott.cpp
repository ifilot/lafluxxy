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

#include "reaction_gray_scott.h"

ReactionGrayScott::ReactionGrayScott() {
    this->reacttype = KINETICS::GRAY_SCOTT;
}


/**
 * @brief      reaction kinetics for Gray-Scott
 *
 * @param[in]  a     concentration of A
 * @param[in]  b     concentration of B
 * @param      ra    reaction rate of A
 * @param      rb    reaction rate of B
 *
 * LATEX:
 * \frac{\partial X}{\partial t} = -XY^{2} + f (1 - X) \\
 * \frac{\partial Y}{\partial t} = XY^{2} - (f + k)Y
 *
 */
void ReactionGrayScott::reaction(double a, double b, double *ra, double *rb) const {
    double r = a * b * b;
    *ra = -r + this->f * (1.0 - a);
    *rb =  r - (this->f + this->k) * b;
}


void ReactionGrayScott::init(MatrixXXd& a, MatrixXXd& b) const {
    this->init_central_square_gaussian_noise(a, b, 1.0, 0.0, 0.5, 0.25, 0.05);
}

/**
 * @brief      Sets the parameters.
 *
 * @param[in]  params  The parameters
 */
void ReactionGrayScott::set_parameters(const std::string& params) {
    auto map = this->parse_parameters(params);

    auto got = map.find("k");
    if(got != map.end()) {
        this->k = got->second;
    } else {
        throw std::runtime_error("Cannot find parameter k");
    }

    got = map.find("f");
    if(got != map.end()) {
        this->f = got->second;
    } else {
        throw std::runtime_error("Cannot find parameter f");
    }

    // std::vector<std::string> paramlist = {"k", "f"};
    // std::cout << "Succesfully loaded the following parameters" << std::endl;
    // for(const std::string& variable : paramlist) {
    //     auto got = map.find(variable);
    //     std::cout << "    " << variable << " = " << got->second << std::endl;
    // }
}

/**
 * @brief      Gets the kinetic parameters.
 *
 * @return     The kinetic parameters.
 */
std::array<double, 4> ReactionGrayScott::get_kinetic_parameters() const {
    return {this->f, this->k, 0.0, 0.0};
}
