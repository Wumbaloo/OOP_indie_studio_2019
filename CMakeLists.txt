cmake_minimum_required(VERSION 3.11)


project(OOP_indie_studio_2019)


# BINARY

include_directories(include)
set(NAME bomberman)
file(GLOB SRC
    src/Main.cpp
    src/Game.cpp
    src/InputManager/InputManager.cpp
    src/Irrlicht/Irrlicht.cpp
    src/Irrlicht/Close.cpp
    src/Irrlicht/Create.cpp
    src/Irrlicht/Events.cpp
    src/Irrlicht/Get.cpp
    src/Objects/Object.cpp
    src/Objects/AnimatedModel.cpp
    src/Objects/Model.cpp
    src/Scenes/GameScene/Game.cpp
    src/Scenes/GameScene/Create.cpp
    src/Scenes/GameScene/Event.cpp
    src/Scenes/GameScene/Get.cpp
    src/Scenes/GameScene/Map.cpp
    src/Scenes/MenuScene/Menu.cpp
)
add_executable(${NAME} ${SRC})



# IRRLITCH LIB
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/irrlicht")
set(Irrlicht_FIND_REQUIRED True)
include(FindIrrlicht)
include_directories(${Irrlicht_INCLUDE_DIRS})
target_link_libraries(${NAME} Irrlicht)


# SFML LIB
set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake_modules" ${CMAKE_MODULE_PATH})
find_package(SFML 2.5 REQUIRED audio)
if(SFML_FOUND)
  include_directories(${SFML_INCLUDE_DIR})
#   target_link_libraries(${NAME} ${SFML_LIBRARIES} ${SFML_DEPENDENCIES})
endif()
