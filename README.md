# LaFluxxy

## Purpose
LaFluxxy is a simple GUI for performing reaction-diffusion integration on a rectangular grid, with and without mazes.

## Dependencies

```bash
sudo apt install build-essential qt6-base-dev qmake6 libeigen3-dev \
libboost-all-dev libfftw3-dev qt6-tools-dev
```

## Compilation

```bash
mkdir build
cd build
qmake6 ../lafluxxy.pro
make -j9
```
