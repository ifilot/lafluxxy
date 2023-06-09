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

#include "card_manager.h"
#include "check_cuda.h"

/**
 * @brief      Constructs the object.
 */
CardManager::CardManager() {
    int nDevices;
    char buffer[100];

    auto status = checkCuda(cudaGetDeviceCount(&nDevices));
    if(status != cudaSuccess) {
        return;
    }

    for(int i = 0; i < nDevices; i++) {
        cudaDeviceProp prop;
        cudaGetDeviceProperties(&prop, i);
        int length = sprintf(buffer, "%s (device %i)", prop.name, i);
        std::string gpu_name(buffer, length);
        this->gpu_names.emplace_back(gpu_name);
    }
}

/**
 * @brief      Probe the available GPU units
 */
void CardManager::probe_cards() {
    int nDevices;

    std::cout << "GPU DEVICE INFORMATION" << std::endl << std::endl;

    cudaGetDeviceCount(&nDevices);
    for (int i = 0; i < nDevices; i++) {
        cudaDeviceProp prop;
        cudaGetDeviceProperties(&prop, i);
        std::cout << "Device Number: " << i << std::endl;
        std::cout << "    Device name: " << prop.name << std::endl;
        // std::cout << "    Memory Clock Rate (KHz): " << prop.memoryClockRate << std::endl;
        // std::cout << "    Memory Bus Width (bits): " << prop.memoryBusWidth << std::endl;
        std::cout << "    Number of cores: " << this->get_number_cores((void*)&prop) << std::endl;
        std::cout << "    Clock frequency: " << (prop.clockRate / (double)1024) << " MHz" << std::endl;
        std::cout << "    Number of MP units: " << prop.multiProcessorCount << std::endl;
        std::cout << "    Maximum threads per block: " << prop.maxThreadsPerBlock << std::endl;
        std::cout << "    Maximum global memory: " << (prop.totalGlobalMem)/(double)(1024*1024) << " MB" << std::endl;
        // std::cout << "    Peak Memory Bandwidth (GB/s): " << 2.0*prop.memoryClockRate*(prop.memoryBusWidth/8)/1.0e6 << std::endl << std::endl;
    }

    std::cout << "----------------------------------------------------------" << std::endl;
}

/**
 * @brief      Get the total number of cores on the GPU
 *
 * @param      devProp  Card properties
 *
 * @return     The number cores.
 */
int CardManager::get_number_cores(void* prop) {
    // below is a nasty hack to convert a void pointer to a cudaDeviceProp type which
    // is unknown by the C++ compiler when handling the .h file
    cudaDeviceProp devProp = *(cudaDeviceProp*)prop;

    int cores = 0;
    int mp = devProp.multiProcessorCount;

    switch (devProp.major){
        case 2: // Fermi
            if (devProp.minor == 1) {
                cores = mp * 48;
            } else {
                cores = mp * 32;
            }
        break;
        case 3: // Kepler
            cores = mp * 192;
        break;
        case 5: // Maxwell
            cores = mp * 128;
        break;
        case 6: // Pascal
            if (devProp.minor == 1) {
                cores = mp * 128;
            } else if (devProp.minor == 0) {
                cores = mp * 64;
            } else {
                std::cerr << "Unknown device type" << std::endl;
            }
        break;
        case 7: // Volta
            if (devProp.minor == 0) {
                cores = mp * 64;
            } else {
                std::cerr << "Unknown device type" << std::endl;
            }
        break;
        default:
            std::cerr << "Unknown device type" << std::endl;
        break;
    }

    return cores;
}
