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

#ifndef _REACTION_GRAY_SCOTT
#define _REACTION_GRAY_SCOTT

/**
 * @brief      Calculate gray-scott reaction rate
 *
 * @param[in]  fx    pointer to concentration of compound A
 * @param[in]  fy    pointer to concentration of compound B
 * @param      drx   pointer to reaction rate of compound A
 * @param      dry   pointer to reaction rate of compound B
 */
__global__ void reaction_gray_scott(const float *fx, const float *fy, float *drx, float *dry) {
    int index = blockIdx.x * blockDim.x + threadIdx.x;
    int stride = blockDim.x * gridDim.x;

    for(int i = index; i < d_ncells; i += stride) {
        float r = fx[i] * fy[i] * fy[i];
        drx[i] = -r + d_c1 * (1.0 - fx[i]);
        dry[i] = r - (d_c1 + d_c2) * fy[i];
    }
}

#endif // _REACTION_GRAY_SCOTT
