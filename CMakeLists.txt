cmake_minimum_required(VERSION 3.16)
project(ComputerGraphics)

set(CMAKE_CXX_STANDARD 14)
include_directories(ComputerGraphics include/Features include/Living include/Bedroom include/Kitchen )
add_executable(ComputerGraphics resources/Glad/glad.c source/main.cpp source/Features/shader.cpp source/Features/texture.cpp source/Features/camera.cpp source/Features/shader.cpp source/Features/texture.cpp source/Features/object.cpp )
target_link_libraries(ComputerGraphics GL GLU glfw3 dl X11 Xxf86vm Xrandr pthread Xi dl assimp)

