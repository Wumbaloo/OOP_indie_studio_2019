cmake_minimum_required(VERSION 3.11)

SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pthread")
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
        src/Scenes/GameScene/Save_Load.cpp
        src/Scenes/MenuScene/Menu.cpp
        src/Scenes/SettingsScene/Settings.cpp
        src/Scenes/SettingsScene/GenerateSettings.cpp
        src/Scenes/SettingsScene/CreateSettingsTools.cpp
        src/Scenes/AScene.cpp
        src/Scenes/HowToPlayScene/HowToPlay.cpp
        src/Scenes/WinScene/Win.cpp
        src/Scenes/LoadScene/Load.cpp
)

set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/libs" ${CMAKE_MODULE_PATH})
set(CMAKE_PREFIX_PATH "${CMAKE_SOURCE_DIR}/libs")
set(LIBS_DIRECTORY "${CMAKE_SOURCE_DIR}/libs")
configure_file("${LIBS_DIRECTORY}/irrKlang/ikpFlac.dll" "${CMAKE_SOURCE_DIR}" COPYONLY)
configure_file("${LIBS_DIRECTORY}/irrKlang/ikpFlac.so" "${CMAKE_SOURCE_DIR}" COPYONLY)
configure_file("${LIBS_DIRECTORY}/irrKlang/ikpMP3.dll" "${CMAKE_SOURCE_DIR}" COPYONLY)
configure_file("${LIBS_DIRECTORY}/irrKlang/ikpMP3.so" "${CMAKE_SOURCE_DIR}" COPYONLY)
configure_file("${LIBS_DIRECTORY}/irrKlang/irrKlang.dll" "${CMAKE_SOURCE_DIR}" COPYONLY)
configure_file("${LIBS_DIRECTORY}/irrKlang/irrKlang.exp" "${CMAKE_SOURCE_DIR}" COPYONLY)
configure_file("${LIBS_DIRECTORY}/irrKlang/irrKlang.lib" "${CMAKE_SOURCE_DIR}" COPYONLY)
configure_file("${LIBS_DIRECTORY}/irrKlang/libIrrKlang.so" "${CMAKE_SOURCE_DIR}" COPYONLY)
configure_file("${LIBS_DIRECTORY}/irrlicht/Irrlicht.dll" "${CMAKE_SOURCE_DIR}" COPYONLY)
configure_file("${LIBS_DIRECTORY}/irrlicht/Irrlicht.exp" "${CMAKE_SOURCE_DIR}" COPYONLY)
configure_file("${LIBS_DIRECTORY}/irrlicht/Irrlicht.lib" "${CMAKE_SOURCE_DIR}" COPYONLY)

configure_file("${LIBS_DIRECTORY}/irrKlang/ikpFlac.dll" "${CMAKE_RUNTIME_OUTPUT_DIRECTORY}" COPYONLY)
configure_file("${LIBS_DIRECTORY}/irrKlang/ikpFlac.so" "${CMAKE_RUNTIME_OUTPUT_DIRECTORY}" COPYONLY)
configure_file("${LIBS_DIRECTORY}/irrKlang/ikpMP3.dll" "${CMAKE_RUNTIME_OUTPUT_DIRECTORY}" COPYONLY)
configure_file("${LIBS_DIRECTORY}/irrKlang/ikpMP3.so" "${CMAKE_RUNTIME_OUTPUT_DIRECTORY}" COPYONLY)
configure_file("${LIBS_DIRECTORY}/irrKlang/irrKlang.dll" "${CMAKE_RUNTIME_OUTPUT_DIRECTORY}" COPYONLY)
configure_file("${LIBS_DIRECTORY}/irrKlang/irrKlang.exp" "${CMAKE_RUNTIME_OUTPUT_DIRECTORY}" COPYONLY)
configure_file("${LIBS_DIRECTORY}/irrKlang/irrKlang.lib" "${CMAKE_RUNTIME_OUTPUT_DIRECTORY}" COPYONLY)
configure_file("${LIBS_DIRECTORY}/irrKlang/libIrrKlang.so" "${CMAKE_RUNTIME_OUTPUT_DIRECTORY}" COPYONLY)
configure_file("${LIBS_DIRECTORY}/irrlicht/Irrlicht.dll" "${CMAKE_RUNTIME_OUTPUT_DIRECTORY}" COPYONLY)
configure_file("${LIBS_DIRECTORY}/irrlicht/Irrlicht.exp" "${CMAKE_RUNTIME_OUTPUT_DIRECTORY}" COPYONLY)
configure_file("${LIBS_DIRECTORY}/irrlicht/Irrlicht.lib" "${CMAKE_RUNTIME_OUTPUT_DIRECTORY}" COPYONLY)

# IRRLITCH LIB
set(Irrlicht_DIR "${CMAKE_SOURCE_DIR}/libs/irrlicht")
set(Irrlicht_FIND_REQUIRED True)
include(FindIrrlicht)
include_directories(${Irrlicht_INCLUDE_DIRS})


# IRRKLANG LIB
set(IrrKlang_DIR "${CMAKE_SOURCE_DIR}/libs/irrKlang")
set(IrrKlang_FIND_REQUIRED True)
include(FindIrrKlang)
include_directories(${IrrKlang_INCLUDE_DIRS})

add_executable(${NAME} ${SRC})
target_link_libraries(${NAME} ${Irrlicht_LIBRARIES} ${IrrKlang_LIBRARIES})
