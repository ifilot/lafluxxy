v

#ifndef _REACTION_FITZHUGH_NAGUMO
#define _REACTION_FITZHUGH_NAGUMO

/**
 * @brief      Calculate gray-scott reaction rate
 *
 * @param[in]  fx    pointer to concentration of compound A
 * @param[in]  fy    pointer to concentration of compound B
 * @param      drx   pointer to reaction rate of compound A
 * @param      dry   pointer to reaction rate of compound B
 */
__global__ void reaction_fitzhugh_nagumo(const float *fx, const float *fy, float *drx, float *dry) {
    int index = blockIdx.x * blockDim.x + threadIdx.x;
    int stride = blockDim.x * gridDim.x;

    for(int i = index; i < d_ncells; i += stride) {
        drx[i] = fx[i] - (fx[i] * fx[i] * fx[i]) - fy[i] + d_c1;
        dry[i] = (fx[i] - fy[i]) * d_c2;
    }
}

#endif // _REACTION_FITZHUGH_NAGUMO
