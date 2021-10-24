cmake_minimum_required(VERSION 3.20)
project(AVS_HW2)

set(CMAKE_CXX_STANDARD 17)

add_executable(AVS_HW2 main.cpp data/cartoon.cpp data/cartoon.h rnd_files/rnd.cpp rnd_files/rnd.h data/movie.cpp data/movie.h data/documentary.cpp data/documentary.h data/game.cpp data/game.h data/container.cpp data/container.h)
