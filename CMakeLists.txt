cmake_minimum_required(VERSION 3.3.1)
project(superchig_brainfuck_compiler)

enable_testing()

set(SPEC_FILES spec/spec.cpp)

# add_executable(suite ${SPEC_FILES}
# 					 src/compiler.cpp)

add_executable(sbc src/main.cpp
				   src/compiler.cpp)

add_test(NAME suite
			  COMMAND ./suite)

set(CMAKE_CXX_COMPILER clang++)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -pedantic")

set_property(TARGET sbc PROPERTY CXX_STANDARD 14)
set_property(TARGET sbc PROPERTY CXX_STANDARD_REQUIRED ON)
