# CMake entry point
cmake_minimum_required (VERSION 2.6)
project (DL2DCPP)

find_package(OpenGL REQUIRED)


if( CMAKE_BINARY_DIR STREQUAL CMAKE_SOURCE_DIR )
    message( FATAL_ERROR "Please select another Build Directory ! (and give it a clever name, like 'build')" )
endif()
if( CMAKE_SOURCE_DIR MATCHES " " )
	message( "Your Source Directory contains spaces. If you experience problems when compiling, this can be the cause." )
endif()
if( CMAKE_BINARY_DIR MATCHES " " )
	message( "Your Build Directory contains spaces. If you experience problems when compiling, this can be the cause." )
endif()


# Compile external dependencies 
add_subdirectory (external)

# On Visual 2005 and above, this module can set the debug working directory
list(APPEND CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/external/rpavlik-cmake-modules-1c73e35")
include(CreateLaunchers)
include(MSVCMultipleProcessCompile) # /MP

if(INCLUDE_DISTRIB)
	add_subdirectory(distrib)
endif(INCLUDE_DISTRIB)

include_directories(
	external/glfw-3.0.3/include/GLFW/
	external/glm-0.9.7.0/
	external/glew-1.9.0/include/
	/dl2dcpp/
	.
)

set(ALL_LIBS
	${OPENGL_LIBRARY}
	GLFW_303
	dl2dcpp
	GLEW_190
)

add_definitions(
	-DTW_STATIC
	-DTW_NO_LIB_PRAGMA
	-DTW_NO_DIRECT3D
	-DGLEW_STATIC
	-D_CRT_SECURE_NO_WARNINGS
)

# DL2D
add_library(dl2dcpp
	dl2dcpp/shader.cpp
	dl2dcpp/shader.h
	dl2dcpp/camera.cpp
	dl2dcpp/camera.h
	dl2dcpp/texture.cpp
	dl2dcpp/texture.h
	dl2dcpp/renderer.cpp
	dl2dcpp/renderer.h
	dl2dcpp/sprite.cpp
	dl2dcpp/sprite.h
)

file(
	COPY dl2dcpp/shaders
	DESTINATION ${CMAKE_BINARY_DIR}
)


# Demo
add_executable(demo
	demo/demo.cpp
	demo/map.cpp
	demo/map.h	
)

file(
	COPY demo/assets
	DESTINATION ${CMAKE_BINARY_DIR}
)

target_link_libraries(demo
	${ALL_LIBS}
)
# Xcode and Visual working directories
set_target_properties(demo PROPERTIES XCODE_ATTRIBUTE_CONFIGURATION_BUILD_DIR "${CMAKE_CURRENT_SOURCE_DIR}/demo/")
create_target_launcher(demo WORKING_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/demo/")


SOURCE_GROUP(d2ld REGULAR_EXPRESSION ".*/dl2d/.*" )
SOURCE_GROUP(shaders REGULAR_EXPRESSION ".*/.*shader$" )


if (NOT ${CMAKE_GENERATOR} MATCHES "Xcode" )
#add_custom_command(
#   TARGET demo POST_BUILD
#   COMMAND ${CMAKE_COMMAND} -E copy "${CMAKE_CURRENT_BINARY_DIR}/${CMAKE_CFG_INTDIR}/demo${CMAKE_EXECUTABLE_SUFFIX}" "${CMAKE_CURRENT_SOURCE_DIR}/demo/"
#)
elseif (${CMAKE_GENERATOR} MATCHES "Xcode" )

endif (NOT ${CMAKE_GENERATOR} MATCHES "Xcode" )
