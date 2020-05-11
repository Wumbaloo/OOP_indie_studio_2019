cmake_minimum_required(VERSION 3.11)


project(OOP_indie_studio_2019)


# BINARY
include_directories(./include)
set(NAME bomberman)
file(GLOB SRC   src/main.cpp)
add_executable(${NAME} ${SRC})



# IRRLITCH LIB
# include(${CMAKE_CURRENT_SOURCE_DIR}/Irrlicht/FindIrrlicht.cmake)
# set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/irrlicht")
# find_package(Irrlicht REQUIRED)
# target_link_libraries(${NAME} ${IRRLICHT_LIBRARY})
# target_include_directories(${NAME} PUBLIC ${IRRLICHT_INCLUDE_DIR})


# BOOST LIB
set(Boost_USE_STATIC_LIBS OFF)
set(Boost_USE_MULTITHREADED ON)
set(Boost_USE_STATIC_RUNTIME OFF)
find_package(Boost 1.69 REQUIRED COMPONENTS filesystem)
message(STATUS "Boost version: ${Boost_VERSION}")
if(NOT TARGET Boost::filesystem)
    add_library(Boost::filesystem IMPORTED INTERFACE)
    set_property(TARGET Boost::filesystem PROPERTY
        INTERFACE_INCLUDE_DIRECTORIES ${Boost_INCLUDE_DIR})
    set_property(TARGET Boost::filesystem PROPERTY
        INTERFACE_LINK_LIBRARIES ${Boost_LIBRARIES})
endif()
# target_link_libraries(${NAME} PUBLIC Boost::filesystem)


# SFML LIB
set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake_modules" ${CMAKE_MODULE_PATH})
find_package(SFML 2.5 REQUIRED audio)
if(SFML_FOUND)
  include_directories(${SFML_INCLUDE_DIR})
#   target_link_libraries(${NAME} ${SFML_LIBRARIES} ${SFML_DEPENDENCIES})
endif()
