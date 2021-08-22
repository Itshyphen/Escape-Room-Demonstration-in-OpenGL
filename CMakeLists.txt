cmake_minimum_required(VERSION 3.16)
project(ComputerGraphics)

set(CMAKE_CXX_STANDARD 14)
include_directories(ComputerGraphics includes/Features includes/Living includes/Bedroom VecMat )
add_executable(ComputerGraphics resources/Glad/glad.c src/main.cpp src/Features/shader.cpp src/Features/texture.cpp src/Features/camera.cpp src/Features/shader.cpp src/Features/texture.cpp src/Features/object.cpp VecMat/arithmetic.cpp )
target_link_libraries(ComputerGraphics GL GLU glfw dl X11 Xxf86vm Xrandr pthread Xi dl assimp)

