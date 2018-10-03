cmake_minimum_required(VERSION 2.8)

project(Part3)
add_executable(Part3 main.cpp)
find_package(OpenGL REQUIRED)
find_package(GLUT REQUIRED)
include_directories( ${OPENGL_INCLUDE_DIRS}  ${GLUT_INCLUDE_DIRS} )

target_link_libraries(Part3 ${OPENGL_LIBRARIES} ${GLUT_LIBRARY} )