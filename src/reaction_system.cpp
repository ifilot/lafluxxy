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

#include "reaction_system.h"

/**
 * @brief      Constructs the object.
 */
ReactionSystem::ReactionSystem() {

}

/**
 * @brief      random initialization
 *
 * @param      a     Concentration matrix A
 * @param      b     Concentration matrix B
 */
void ReactionSystem::init_random(MatrixXXd& a, MatrixXXd& b, double ca, double cb, double delta) const {
    unsigned int width = a.cols();
    unsigned int height = a.rows();

    a = MatrixXXd::Zero(height, width);
    b = MatrixXXd::Zero(height, width);

    for(unsigned int i=0; i<height; i++) {
        for(unsigned int j=0; j<width; j++) {
            a(i,j) = ca + this->uniform_dist() * delta;
            b(i,j) = cb + this->uniform_dist() * delta;
        }
    }
}

/**
 * @brief      Make a single sphere in the center of the system
 *
 * @param      a     Concentration matrix A
 * @param      b     Concentration matrix B
 * @param[in]  ca    concentration of A in center
 * @param[in]  cb    concentration of B in center
 */
void ReactionSystem::init_central_circle(MatrixXXd& a, MatrixXXd& b, double ca, double cb) const {
    unsigned int width = a.cols();
    unsigned int height = a.rows();

    a = MatrixXXd::Zero(height, width);
    b = MatrixXXd::Zero(height, width);

    for(unsigned int i=0; i<height; i++) {
        for(unsigned int j=0; j<width; j++) {
            double r = (double)width / 16.0;
            double r2 = r * r;
            double dx = (double)(width) / 2.0 - (double)j;
            double dy = (double)(height) / 2.0 - (double)i;
            if( (dx * dx + dy * dy) < r2) {
                a(i,j) = ca;
                b(i,j) = cb;
            }
        }
    }
}

/**
 * @brief      Make a two spheres in the center of the system
 *
 * @param      a     Concentration matrix A
 * @param      b     Concentration matrix B
 * @param[in]  ca    concentration of A in center
 * @param[in]  cb    concentration of B in center
 */
void ReactionSystem::init_dual_central_circle(MatrixXXd& a, MatrixXXd& b, double ca, double cb) const {
    unsigned int width = a.cols();
    unsigned int height = a.rows();

    a = MatrixXXd::Zero(height, width);
    b = MatrixXXd::Zero(height, width);

    // make upper circle
    for(unsigned int i=0; i<height; i++) {
        for(unsigned int j=0; j<width; j++) {
            double r = (double)width / 32.0;
            double r2 = r * r;
            double dx = (double)(width) / 2.0 - (double)(j - height / 4);
            double dy = (double)(height) / 2.0 - (double)i;
            if( (dx * dx + dy * dy) < r2) {
                a(i,j) = ca;
                b(i,j) = cb;
            }
        }
    }

    // make lower circle
    for(unsigned int i=0; i<height; i++) {
        for(unsigned int j=0; j<width; j++) {
            double r = (double)width / 32.0;
            double r2 = r * r;
            double dx = (double)(width) / 2.0 - (double)(j + height / 4);
            double dy = (double)(height) / 2.0 - (double)i;
            if( (dx * dx + dy * dy) < r2) {
                a(i,j) = ca;
                b(i,j) = cb;
            }
        }
    }
}

/**
 * @brief      Set random rectangles as initial value
 *
 * @param      a     Concentration matrix A
 * @param      b     Concentration matrix B
 */
void ReactionSystem::init_random_rectangles(MatrixXXd& a, MatrixXXd& b) const {
    unsigned int width = a.cols();
    unsigned int height = a.rows();

    a = MatrixXXd::Ones(height, width) * 0.4201;
    b = MatrixXXd::Ones(height, width) * 0.2878;

    for(unsigned int k=0; k<100; k++) {
        int f = height / 2 + (int)((this->uniform_dist()-0.5) * height * 0.90);
        int g = width / 2 + (int)((this->uniform_dist()-0.5) * width * 0.90);
        double val1 = this->uniform_dist();
        double val2 = this->uniform_dist();
        const int imax = (unsigned int)((this->uniform_dist() * 0.1 * height));
        const int jmax = (unsigned int)((this->uniform_dist() * 0.1 * height));
        for(int i=-imax/2; i<imax/2; i++) {
            for(int j=-jmax/2; j<jmax/2; j++) {
                a(f+i, g+j) = val1;
                b(f+i, g+j) = val2;
            }
        }
    }
}

/**
 * @brief      Make a half screen filling
 *
 * @param      a     Concentration matrix A
 * @param      b     Concentration matrix B
 * @param[in]  ca    concentration of A in center
 * @param[in]  cb    concentration of B in center
 */
void ReactionSystem::init_half_screen(MatrixXXd& a, MatrixXXd& b, double ca, double cb) const {
    unsigned int width = a.cols();
    unsigned int height = a.rows();

    a = MatrixXXd::Zero(height, width);
    b = MatrixXXd::Zero(height, width);

    for(unsigned int i=height/2; i<height; i++) {
        for(unsigned int j=0; j<width; j++) {
            a(i,j) = ca;
        }
    }

    for(unsigned int i=0; i<height; i++) {
        for(unsigned int j=0; j<width/2; j++) {
            b(i,j) = cb;
        }
    }
}

/**
 * @brief      Initialize central rectangle with random noise everywhere
 *
 * @param      a      Concentration matrix A
 * @param      b      Concentration matrix B
 * @param[in]  a0     Initial concentration A
 * @param[in]  b0     Initial concentration B
 * @param[in]  ca     Concentration of A in central square
 * @param[in]  cb     Concentration of B in central square
 * @param[in]  noise  Gaussian noise
 */
void ReactionSystem::init_central_square_gaussian_noise(MatrixXXd& a, MatrixXXd& b, double a0, double b0, double ca, double cb, double noise) const {
    unsigned int width = a.cols();
    unsigned int height = a.rows();

    a = MatrixXXd::Ones(height, width) * a0;
    b = MatrixXXd::Ones(height, width) * b0;

    for(unsigned int i=height/2-10; i<height/2+10; i++) {
        for(unsigned int j=width/2-10; j<width/2+10; j++) {
            a(i,j) = ca;
            b(i,j) = cb;
        }
    }

    for(unsigned int i=0; i<height; i++) {
        for(unsigned int j=0; j<width; j++) {
            a(i,j) += this->normal_dist() * noise;
            b(i,j) += this->normal_dist() * noise;
        }
    }
}

/**
 * @brief      Parse parameters
 *
 * @param[in]  params  string containing list of parameters
 *
 * @return     unordered map with the parameters
 */
std::unordered_map<std::string, double> ReactionSystem::parse_parameters(const std::string& params) const {
    std::vector<std::string> pieces;
    boost::split(pieces, params, boost::is_any_of(";"), boost::token_compress_on);

    std::unordered_map<std::string, double> map;

    for(const std::string& piece : pieces) {
        std::vector<std::string> vars;
        boost::split(vars, piece, boost::is_any_of("="), boost::token_compress_on);
        if(vars.size() != 2) {
            std::cerr << "Piece: " << piece << std::endl;
            std::cerr << "Var size: " << vars.size() << std::endl;
            throw std::runtime_error("Invalid params list encountered: " + params);
        }

        map.emplace(vars[0], boost::lexical_cast<double>(vars[1]));
    }

    return map;
}
