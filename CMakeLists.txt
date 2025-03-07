cmake_minimum_required(VERSION 3.30.5)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

option(PRODUCTION_BUILD "Make this a production build" OFF)

# export compile commands for clang
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(CMAKE_INTERPROCEDURAL_OPTIMIZATION TRUE)

set(CMAKE_CXX_FLAGS "-Wall -Wextra")
add_compile_options("$<$<COMPILE_LANGUAGE:CXX>:-O3;-ffast-math>")

# Change this to match the name of the current folder
project(DSEmulator CXX)
#option(BUILD_SHARED_LIBS "Build shared libraries" OFF)


# add_subdirectory(ThirdParty/glfw)

file(GLOB_RECURSE MY_SOURCES CONFIGURE_DEPENDS "${CMAKE_CURRENT_SOURCE_DIR}/Src/*.cpp")

#include(FetchContent)
#FetchContent_Declare(
#	SFML
#	GIT_REPOSITORY https://github.com/SFML/SFML.git
#	GIT_TAG 2.6.x
#	GIT_SHALLOW ON
#	EXCLUDE_FROM_ALL
#	SYSTEM
#)
#FetchContent_MakeAvailable(SFML)

add_executable("${CMAKE_PROJECT_NAME}") 

#file(COPY "${CMAKE_CURRENT_SOURCE_DIR}/Resources" DESTINATION "${PROJECT_BINARY_DIR}")

if(PRODUCTION_BUILD)
	# setup the ASSETS_PATH macro to be in the root folder of your exe
	target_compile_definitions("${CMAKE_PROJECT_NAME}" PUBLIC RESOURCES_PATH="./Resources/") 

	target_compile_definitions("${CMAKE_PROJECT_NAME}" PUBLIC PRODUCTION_BUILD=1) 

else()
	# This is useful to get an ASSETS_PATH in your IDE during development
	target_compile_definitions("${CMAKE_PROJECT_NAME}" PUBLIC RESOURCES_PATH="${CMAKE_CURRENT_SOURCE_DIR}/Resources/")
	target_compile_definitions("${CMAKE_PROJECT_NAME}" PUBLIC PRODUCTION_BUILD=0) 

endif()

#target_link_libraries("${CMAKE_PROJECT_NAME}" PRIVATE sfml-graphics)
target_compile_features("${CMAKE_PROJECT_NAME}" PRIVATE cxx_std_20)

target_sources("${CMAKE_PROJECT_NAME}" PRIVATE ${MY_SOURCES} )


target_include_directories("${CMAKE_PROJECT_NAME}" PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/Include/")
target_include_directories("${CMAKE_PROJECT_NAME}" PUBLIC "${PROJECT_BINARY_DIR}")
