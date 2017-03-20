cmake_minimum_required(VERSION 3.6)
project(Fractol)

set(LIB_PATH libft)

set(CMAKE_CXX_STANDARD 11)
set(UBUNTU_FLAGS " -lmlx -lXext -lX11")
set(MACOS_FLAGS "-lmlx -framework OpenGL -framework AppKit")
set(CMAKE_C_FLAGS ${MACOS_FLAGS})
set(SOURCE_FILES src/main.c src/draw.c src/events.c src/fractals.c src/mandelbrot.c src/julia.c src/mandelcube.c)
add_executable(Fractol ${SOURCE_FILES})

file(GLOB SOURCES_LIB ${LIB_PATH}/*.c)
add_library(ft STATIC ${SOURCES_LIB}/)

target_link_libraries(Fractol ft)