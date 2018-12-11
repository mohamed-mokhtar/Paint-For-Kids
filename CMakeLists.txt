cmake_minimum_required(VERSION 3.0.0 FATAL_ERROR)

################### Variables. ####################
# Change if you want modify path or other values. #
###################################################

set(PROJECT_NAME <PLEASE SET YOUR PROJECT NAME !!>)
# Output Variables
set(OUTPUT_DEBUG ./Debug/)
set(OUTPUT_REL ./Release/)
# Folders files
set(CPP_DIR_1 Actions)
set(CPP_DIR_2 CMUgraphicsLib)
set(CPP_DIR_3 CMUgraphicsLib/jpeg)
set(CPP_DIR_4 Figures)
set(CPP_DIR_5 GUI)
set(CPP_DIR_6 ./)
set(CPP_DIR_7 ./)
set(HEADER_DIR_1 Actions)
set(HEADER_DIR_2 CMUgraphicsLib)
set(HEADER_DIR_3 CMUgraphicsLib/jpeg)
set(HEADER_DIR_4 Figures)
set(HEADER_DIR_5 GUI)
set(HEADER_DIR_6 )

############## CMake Project ################
#        The main options of project        #
#############################################

project(${PROJECT_NAME} CXX)

# Define Release by default.
if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE "Release")
  message(STATUS "Build type not specified: Use Release by default.")
endif(NOT CMAKE_BUILD_TYPE)

# Definition of Macros
add_definitions(
   -DNDEBUG 
   -D_CONSOLE 
)

############## Artefacts Output #################
# Defines outputs , depending Debug or Release. #
#################################################

if(CMAKE_BUILD_TYPE STREQUAL "Debug")
  set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/${OUTPUT_DEBUG}")
  set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/${OUTPUT_DEBUG}")
  set(CMAKE_EXECUTABLE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/${OUTPUT_DEBUG}")
else()
  set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/${OUTPUT_REL}")
  set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/${OUTPUT_REL}")
  set(CMAKE_EXECUTABLE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/${OUTPUT_REL}")
endif()

################# Flags ################
# Defines Flags for Windows and Linux. #
########################################

if(MSVC)
   set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} /W3 /EHsc")
   set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} /W3 /EHsc")
endif(MSVC)
if(NOT MSVC)
   set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
   if ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "Clang")
       set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -stdlib=libc++")
   endif()
endif(NOT MSVC)

################ Files ################
#   --   Add files to project.   --   #
#######################################

file(GLOB SRC_FILES
    ${CPP_DIR_1}/*.cpp
    ${CPP_DIR_1}/*.c
    ${CPP_DIR_2}/*.cpp
    ${CPP_DIR_2}/*.c
    ${CPP_DIR_3}/*.cpp
    ${CPP_DIR_3}/*.c
    ${CPP_DIR_4}/*.cpp
    ${CPP_DIR_4}/*.c
    ${CPP_DIR_5}/*.cpp
    ${CPP_DIR_5}/*.c
    ${CPP_DIR_6}/*.cpp
    ${CPP_DIR_6}/*.c
    ${CPP_DIR_7}/*.cpp
    ${CPP_DIR_7}/*.c
    ${HEADER_DIR_1}/*.h
    ${HEADER_DIR_2}/*.h
    ${HEADER_DIR_3}/*.h
    ${HEADER_DIR_4}/*.h
    ${HEADER_DIR_5}/*.h
    ${HEADER_DIR_6}/*.h
)

# Add executable to build.
add_executable(${PROJECT_NAME} 
   ${SRC_FILES}
)

if(MSVC)
   target_link_libraries(${PROJECT_NAME} odbc32.lib odbccp32.lib winmm.lib )
endif(MSVC)
