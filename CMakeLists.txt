cmake_minimum_required(VERSION 3.6)
project(Fractol)

set(CMAKE_CXX_STANDARD 11)
set(UBUNTU_FLAGS " -lmlx -lXext -lX11")
set(MACOS_FLAGS "-lmlx -framework OpenGL -framework AppKit")
set(CMAKE_C_FLAGS ${MACOS_FLAGS})
set(SOURCE_FILES main.c)
add_executable(Fractol ${SOURCE_FILES})