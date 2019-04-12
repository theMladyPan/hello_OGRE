cmake_minimum_required(VERSION 2.8)

project(hello_OGRE)
# specify which version and components you need
find_package(OGRE 1.11 REQUIRED COMPONENTS Bites RTShaderSystem)
# copy resource.cfg next to our binaries where OGRE looks for it
file(COPY ${OGRE_CONFIG_DIR}/resources.cfg DESTINATION ${CMAKE_BINARY_DIR})

set( project_sources
   main.cpp
   tools.cpp
   mytestapp.cpp
)

include_directories("/usr/local/src")
include_directories("/usr/local/include/OGRE")
include_directories("/usr/local/include/OGRE/RTShaderSystem")
add_executable(${PROJECT_NAME} ${project_sources})
target_link_libraries(${PROJECT_NAME} OgreBites OgreRTShaderSystem)
