cmake_minimum_required(VERSION 3.2)

# set compiler to clang
set(CMAKE_C_COMPILER)
set(CMAKE_CXX_COMPILER)


project(ComputerGraphics)

#for out of source build
message(${CMAKE_SOURCE_DIR})
set(CMAKE_BINARY_DIR ${CMAKE_SOURCE_DIR}/build)
if ( ${CMAKE_SOURCE_DIR} STREQUAL ${CMAKE_BINARY_DIR} )
    message( FATAL_ERROR "In-source builds not allowed. Please make a new directory (called a build directory) and run CMake from there. You may need to remove CMakeCache.txt." )
endif()

file(GLOB INCLUDES
        includes/*.h
        includes/*.hpp
        ${CMAKE_SOURCE_DIR}/Dependencies/includes/*
        )
file(GLOB SRC src/Features/*.cpp src/Features/*.c VecMat/arithmetic.cpp resources/Glad/glad.c)

include_directories(
        ${CMAKE_SOURCE_DIR}/VecMat
        ${CMAKE_SOURCE_DIR}/includes
        ${CMAKE_SOURCE_DIR}/includes/Features
        ${CMAKE_SOURCE_DIR}/Dependencies/includes
)

set(EXECUTABLE_OUTPUT_PATH ${CMAKE_SOURCE_DIR}/build/)


if(${CMAKE_SYSTEM_NAME} MATCHES "Windows")
    message("You are on windows")
    link_directories(${CMAKE_SOURCE_DIR}/Dependencies/lib)
    link_directories(${CMAKE_SOURCE_DIR}/Dependencies/lib/Release)

    add_executable(ComputerGraphics src/main.cpp ${SRC} ${INCLUDES})
    target_link_libraries(ComputerGraphics glfw3.lib opengl32 assimp-vc142-mt.lib)



elseif(${CMAKE_SYSTEM_NAME} MATCHES "Linux")
    target_link_libraries(ComputerGraphics GL GLU glfw3 dl X11 Xxf86vm Xrandr pthread Xi dl assimp)
endif(${CMAKE_SYSTEM_NAME} MATCHES "Windows")