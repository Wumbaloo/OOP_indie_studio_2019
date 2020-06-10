cmake_minimum_required(VERSION 3.11)

set(CMAKE_BUILD_TYPE Debug)


project(OOP_indie_studio_2019)


# BINARY
include_directories(include)
set(NAME bomberman)
file(GLOB SRC
        src/Main.cpp
        src/Music.cpp
        src/Game.cpp
        src/InputManager/InputManager.cpp
        src/Irrlicht/Irrlicht.cpp
        src/Irrlicht/Close.cpp
        src/Irrlicht/Create.cpp
        src/Irrlicht/Events.cpp
        src/Irrlicht/Get.cpp
        src/Objects/Object.cpp
        src/Objects/Model.cpp
        src/Objects/AnimatedObjects/AnimatedModel.cpp
        src/Objects/AnimatedObjects/Bomb.cpp
        src/Objects/AnimatedObjects/Player.cpp
        src/Objects/AnimatedObjects/PowerUp.cpp
        src/Scenes/GameScene/Game.cpp
        src/Scenes/GameScene/Create.cpp
        src/Scenes/GameScene/BombEvent.cpp
        src/Scenes/GameScene/Movements.cpp
        src/Scenes/GameScene/PowerUpsEvent.cpp
        src/Scenes/GameScene/Event.cpp
        src/Scenes/GameScene/Get.cpp
        src/Scenes/GameScene/Map.cpp
        src/Scenes/MenuScene/Menu.cpp
        src/Scenes/SettingsScene/Settings.cpp
        src/Scenes/SettingsScene/GenerateSettings.cpp
        src/Scenes/SettingsScene/CreateSettingsTools.cpp
        src/Scenes/AScene.cpp
        src/Scenes/HowToPlay/HowToPlay.cpp
        )

set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/libs" ${CMAKE_MODULE_PATH})
set(CMAKE_PREFIX_PATH "${CMAKE_SOURCE_DIR}/libs")

# IRRLITCH LIB
set(Irrlicht_DIR "${CMAKE_SOURCE_DIR}/libs/irrlicht")
set(Irrlicht_FIND_REQUIRED True)
include(FindIrrlicht)
include_directories(${Irrlicht_INCLUDE_DIRS})


# SFML LIB
set(SFML_DIR "${CMAKE_SOURCE_DIR}/libs/SFML/cmake/SFML")
set(SFML_DOC_DIR "${SFML_DIR}/doc")
set(SFML_FIND_REQUIRED True)
find_package(SFML 2.5 COMPONENTS audio REQUIRED)
include(FindSFML)
include_directories(${SFML_INCLUDE_DIRS})
add_executable(${NAME} ${SRC})
# target_link_libraries(${NAME} sfml-audio)
target_link_libraries(${NAME} ${Irrlicht_LIBRARIES})
target_link_libraries(${NAME} ${SFML_LIBRARIES} ${SFML_DEPENDENCIES})
