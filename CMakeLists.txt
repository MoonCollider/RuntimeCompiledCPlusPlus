project(RunTimeCompiledC++)

cmake_minimum_required(VERSION 2.8)

#
# Options
#
option(BUILD_EXAMPLES "Build example applications" OFF)

set(BUILD_TYPE STATIC)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${KYTHERA_BINARY_DIR})
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${KYTHERA_BINARY_DIR})
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${KYTHERA_BINARY_DIR})

include(cmake/ProjectFiles.cmake)

#
# RuntimeCompiler
#
add_library(RuntimeCompiler ${BUILD_TYPE} ${RuntimeCompiler_SRCS})

#
# RuntimeObjectSystem
#
add_library(RuntimeObjectSystem ${BUILD_TYPE} ${RuntimeObjectSystem_SRCS})
target_link_libraries(RuntimeObjectSystem RuntimeCompiler)
if(UNIX)
	target_link_libraries(RuntimeObjectSystem dl)
endif()

if(BUILD_EXAMPLES)

    #
    # ConsoleExample
    #

    add_executable(ConsoleExample ${ConsoleExample_SRCS})
    target_link_libraries(ConsoleExample RuntimeCompiler RuntimeObjectSystem)
endif()
