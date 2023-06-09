#-------------------------------------------------
#
# Project created by QtCreator 2018-03-18T15:17:16
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = lafluxxy
TEMPLATE = app
CONFIG += c++14

gcc {
  QMAKE_CXXFLAGS += -fopenmp -march=native -Wall -Wextra
  QMAKE_LFLAGS += -fopenmp -march=native
  QMAKE_CXXFLAGS_RELEASE -= -O2
  QMAKE_CXXFLAGS_RELEASE *= -O3
}

msvc {
  QMAKE_CXXFLAGS += -openmp
  QMAKE_CXXFLAGS_RELEASE *= -O2
  RC_FILE = lafluxxy.rc
}

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += src/main.cpp\
           src/mainwindow.cpp \
           src/inputtab.cpp \
           src/resultstab.cpp \
           src/mazetab.cpp \
           src/input_reaction.cpp \
           src/input_lotka_volterra.cpp \
           src/input_brusselator.cpp \
           src/input_barkley.cpp \
           src/input_fitzhugh_nagumo.cpp \
           src/input_gray_scott.cpp \
           src/renderarea.cpp \
           src/two_dim_rd.cpp \
           src/reaction_lotka_volterra.cpp \
           src/reaction_gray_scott.cpp \
           src/reaction_brusselator.cpp \
           src/reaction_barkley.cpp \
           src/reaction_fitzhugh_nagumo.cpp \
           src/reaction_system.cpp \
           src/worker_thread.cpp \
           src/mazerenderer.cpp \
           src/mazeholder.cpp \
           src/movietab.cpp \
           src/colorscheme.cpp \
           src/mazebuilder/cell.cpp \
           src/mazebuilder/maze.cpp \
           src/mazebuilder/maze_algorithm.cpp \
           src/mazebuilder/maze_algorithm_aldous_broder.cpp \
           src/mazebuilder/maze_algorithm_binary_tree.cpp \
           src/mazebuilder/maze_algorithm_prims_simplified.cpp \
           src/mazebuilder/maze_algorithm_sidewinder.cpp \
           src/mazebuilder/maze_builder.cpp \
           src/mazebuilder/maze_statistics.cpp

HEADERS  += src/mainwindow.h \
            src/config.h \
            src/inputtab.h \
            src/resultstab.h \
            src/mazetab.h \
            src/input_reaction.h \
            src/input_lotka_volterra.h \
            src/input_barkley.h \
            src/input_brusselator.h \
            src/input_fitzhugh_nagumo.h \
            src/input_gray_scott.h \
            src/renderarea.h \
            src/two_dim_rd.h \
            src/reaction_gray_scott.h \
            src/reaction_lotka_volterra.h \
            src/reaction_brusselator.h \
            src/reaction_barkley.h \
            src/reaction_fitzhugh_nagumo.h \
            src/reaction_system.h \
            src/worker_thread.h \
            src/mazerenderer.h \
            src/mazeholder.h \
            src/matrices.h \
            src/movietab.h \
            src/colorscheme.h \
            src/mazebuilder/cell.h \
            src/mazebuilder/maze.h \
            src/mazebuilder/maze_algorithm.h \
            src/mazebuilder/maze_algorithm_aldous_broder.h \
            src/mazebuilder/maze_algorithm_binary_tree.h \
            src/mazebuilder/maze_algorithm_prims_simplified.h \
            src/mazebuilder/maze_algorithm_sidewinder.h \
            src/mazebuilder/maze_builder.h \
            src/mazebuilder/maze_statistics.h

# cuda sources
CUDA_SOURCES += src/card_manager.cu \
                src/rd2d_cuda.cu

# cuda headers
HEADERS += src/card_manager.h \
           src/rd2d_cuda.h \
           src/check_cuda.h \
           src/cuda_events.h


RESOURCES += assets.qrc

unix {
    exists(/usr/local/cuda-12.0/bin/nvcc) {
        CUDA_DIR = /usr/local/cuda-12.0
        CUDA_LIBRT = /usr/local/cuda-12.0/lib64/libcudart_static.a
    }

    exists(/usr/local/cuda-12.1/bin/nvcc) {
        CUDA_DIR = /usr/local/cuda-12.1
        CUDA_LIBRT = /usr/local/cuda-12.1/lib64/libcudart_static.a
    }

    # CUDA_ARCH = compute_52
    NVCCFLAGS = -use_fast_math --compile -cudart static -O3

    cuda.commands = $$CUDA_DIR/bin/nvcc -m64 -c $$NVCCFLAGS $$LIBS ${QMAKE_FILE_NAME} -o ${QMAKE_FILE_OUT}
    cuda.dependency_type = TYPE_C
    cuda.depend_command = $$CUDA_DIR/bin/nvcc -M $$CUDA_INC $$NVCCFLAGS ${QMAKE_FILE_OUT}

    # other libraries
    INCLUDEPATH += $$CUDA_DIR/include /usr/include/eigen3
    LIBS += $$CUDA_LIBS $$CUDA_LIBRT -lboost_filesystem -lboost_system -ldl -lrt -lfftw3
    QMAKE_LIBDIR += $$CUDA_DIR/lib64

    cuda.input = CUDA_SOURCES
    cuda.output = ${OBJECTS_DIR}/${QMAKE_FILE_BASE}_cuda.o
}

win32 {
    QMAKE_CXXFLAGS += /MD

    CUDA_DIR = "C:/Program Files/NVIDIA GPU Computing Toolkit/CUDA/v11.6"
    SYSTEM_NAME = x64
    SYSTEM_TYPE = 64
    NVCC_OPTIONS = --use_fast_math -Xcompiler /MD -arch=sm_50 \
                   -gencode=arch=compute_50,code=sm_50 \
                   -gencode=arch=compute_52,code=sm_52 \
                   -gencode=arch=compute_60,code=sm_60 \
                   -gencode=arch=compute_61,code=sm_61 \
                   -gencode=arch=compute_70,code=sm_70 \
                   -gencode=arch=compute_75,code=sm_75 \
                   -gencode=arch=compute_75,code=compute_75 \
                   -gencode=arch=compute_80,code=compute_80 \
                   -gencode=arch=compute_86,code=compute_86

    QMAKE_LIBDIR += $$CUDA_DIR/lib/$$SYSTEM_NAME \
                    $$CUDA_SDK/common/lib/$$SYSTEM_NAME \
                    $$CUDA_SDK/../shared/lib/$$SYSTEM_NAME

    INCLUDEPATH += ../../LIBS/boost-1.74.0-win-x64/include
    INCLUDEPATH += ../../LIBS/eigen-3.3.9
    INCLUDEPATH += ../../LIBS/fftw-3.3.8-win-x64/include
    CUDA_OBJECTS_DIR = release/cuda
    CUDA_INC = $$join(INCLUDEPATH,'" -I"','-I"','"')

    cuda.input = CUDA_SOURCES
    cuda.output = $$CUDA_OBJECTS_DIR/${QMAKE_FILE_BASE}_cuda.o
    cuda.commands = $$CUDA_DIR/bin/nvcc.exe $$NVCC_OPTIONS $$CUDA_INC $$LIBS --machine $$SYSTEM_TYPE -c -o ${QMAKE_FILE_OUT} ${QMAKE_FILE_NAME}
    cuda.dependency_type = TYPE_C

    LIBS += -LD:/PROGRAMMING/LIBS/boost-1.74.0-win-x64/lib \
            -LD:/PROGRAMMING/LIBS/fftw-3.3.8-win-x64/lib \
            -lboost_filesystem-vc142-mt-x64-1_74 \
            -lboost_system-vc142-mt-x64-1_74 \
            -lfftw3 \
            -lcuda \
            -lcudart_static
}

QMAKE_EXTRA_COMPILERS += cuda
