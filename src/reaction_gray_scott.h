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

#pragma once

#include "reaction_system.h"

/**
 * @brief      Class for Gray-Scott Reaction
 *
 * See: * DOI: 10.1088/1742-5468/2016/04/043301
        * https://arxiv.org/pdf/1501.01990.pdf
 *      * http://www.theshapeofmath.com/princeton/dynsys/turinginst3
 *      * http://mrob.com/pub/comp/xmorphia/uskate-world.html
 */
class ReactionGrayScott : public ReactionSystem {
private:
    double f = 0.06;
    double k = 0.0609;

public:
    /**
     * @brief      Constructs the object.
     */
    ReactionGrayScott();

    /**
     * @brief      Perform a reaction step
     *
     * @param[in]  a     Concentration matrix A
     * @param[in]  b     Concentration matrix B
     * @param      ra    Pointer to reaction term for A
     * @param      rb    Pointer to reaction term for B
     */
    void reaction(double a, double b, double *ra, double *rb) const override;

    /**
     * @brief      Initialize the system
     *
     * @param      a     Concentration matrix A
     * @param      b     Concentration matrix B
     */
    void init(MatrixXXd& a, MatrixXXd& b) const override;

    /**
     * @brief      Sets the parameters.
     *
     * @param[in]  params  The parameters
     */
    void set_parameters(const std::string& params) override;

    /**
     * @brief      Gets the kinetic parameters.
     *
     * @return     The kinetic parameters.
     */
    std::array<double, 4> get_kinetic_parameters() const override;

private:
};
