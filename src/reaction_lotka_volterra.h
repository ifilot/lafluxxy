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
 * @brief      Class for Lotka-Volterra Reaction
 */
class ReactionLotkaVolterra : public ReactionSystem {
private:
    double alpha = 4.0/3.0;
    double beta = 8.0/3.0;
    double gamma = 1;
    double delta = 1;

public:
    /**
     * @brief      Constructs the object.
     */
    ReactionLotkaVolterra();

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
