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

#ifndef CONFIG_H
#define CONFIG_H

#define PROGRAM_NAME "LaFluxxy"
#define PROGRAM_VERSION "0.8.2.2"

enum class KINETICS {
    NONE,
    LOTKA_VOLTERRA,
    GRAY_SCOTT,
    FITZHUGH_NAGUMO,
    BRUSSELATOR,
    BARKLEY
};

static const std::vector<KINETICS> kinetic_types = {
    KINETICS::NONE,
    KINETICS::LOTKA_VOLTERRA,
    KINETICS::GRAY_SCOTT,
    KINETICS::FITZHUGH_NAGUMO,
    KINETICS::BRUSSELATOR,
    KINETICS::BARKLEY
};

#endif // CONFIG_H
