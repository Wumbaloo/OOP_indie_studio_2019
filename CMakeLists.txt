cmake_minimum_required(VERSION 3.11)


project(OOP_indie_studio_2019)


# BINARY

include_directories(include)
set(NAME bomberman)
file(GLOB SRC
    src/Main.cpp
    src/Game.cpp
    src/EventReceiver/InputManager.cpp
    src/EventReceiver/EventReceiver.cpp
    src/Irrlicht/Irrlicht.cpp
    src/Irrlicht/Close.cpp
    src/Irrlicht/Create.cpp
    src/Irrlicht/Display.cpp
    src/Irrlicht/Events.cpp
    src/Irrlicht/Get.cpp
    src/Objects/Object.cpp
    src/Objects/Getters.cpp
    src/Objects/Setters.cpp
)
add_executable(${NAME} ${SRC})



# IRRLITCH LIB
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/irrlicht")
set(Irrlicht_FIND_REQUIRED True)
include(FindIrrlicht)
include_directories(${Irrlicht_INCLUDE_DIRS})
target_link_libraries(${NAME} Irrlicht)


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
