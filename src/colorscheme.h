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

#include <string>
#include <stdexcept>
#include <array>

#include "colorschemes/magma.h"
#include "colorschemes/viridis.h"
#include "colorschemes/plasma.h"
#include "colorschemes/inferno.h"
#include "colorschemes/piyg.h"
#include "colorschemes/spectral.h"

class ColorScheme {
private:
    std::vector<float> colors;

public:
    ColorScheme(const std::string& name);

    /**
     * @brief      Obtain color from data point using color scheme
     *
     * @param[in]  val     The value
     * @param[in]  minval  Minimum value
     * @param[in]  maxval  Maximum value
     *
     * @return     The color.
     */
    std::array<uint8_t, 3> get_color(double val, double minval, double maxval) const;

private:

};
