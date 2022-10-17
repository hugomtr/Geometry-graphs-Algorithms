cmake_minimum_required(VERSION 3.20)
project(Geometry_Graph_Project)

set(CMAKE_CXX_STANDARD 20)

find_package(OpenGL REQUIRED)
add_subdirectory(lib/glad)
add_subdirectory(lib/glfw)
add_subdirectory(lib/glm)

add_compile_options(-Wall -Wextra)

file(GLOB_RECURSE SOURCES_FILES CONFIGURE_DEPENDS src/*)
add_executable(Geometry_Graph_Project src/main.cpp ${SOURCES_FILES})

target_include_directories(Geometry_Graph_Project PRIVATE lib/)

target_link_libraries(Geometry_Graph_Project
	PRIVATE
	glad
	glfw
	glm
	OpenGL::GL)
