/*
** EPITECH PROJECT, 2019
** IndieStudio
** File description:
** event Irrlicht cpp
*/

#include <iostream>
#include "Irrlicht.hpp"
#include "IndieStudio.hpp"

using namespace irr;

//core::vector3df Irrlicht::PlayerMovements(core::vector3df nodePosition, Object *player)
//{
//    nodePosition = player->getPos();
//    if (this->_inputManager->isKeyPressed(MOVE_UP)) {
//        nodePosition.Z += PLAYER_SPEED * this->_frameDeltaTime;
//        player->getSceneNode()->setRotation((core::vector3df){0.f, 180.f, .0f});
//    }
//    if (this->_inputManager->isKeyPressed(MOVE_DOWN)) {
//        nodePosition.Z -= PLAYER_SPEED * this->_frameDeltaTime;
//        player->getSceneNode()->setRotation((core::vector3df){0.f, 0.f, 0.f});
//    }
//    if (this->_inputManager->isKeyPressed(MOVE_LEFT)) {
//        nodePosition.X -= PLAYER_SPEED * this->_frameDeltaTime;
//        player->getSceneNode()->setRotation((core::vector3df){0.f, 90.f, 0.f});
//    }
//    if (this->_inputManager->isKeyPressed(MOVE_RIGHT)) {
//        nodePosition.X += PLAYER_SPEED * this->_frameDeltaTime;
//        player->getSceneNode()->setRotation((core::vector3df){0.f, -90.f, 0.f});
//    }
//    return nodePosition;
//}

//Events Irrlicht::KeyboardEvents(void)
//{
////    Object *player = this->getObjectByName("player");
////    core::vector3df nodePosition;
////
////    if (!player)
////        return NONE;
////    if (this->_inputManager->isKeyPressed(CLOSE))
////        return CLOSE;
////    nodePosition = PlayerMovements(nodePosition, player);
////    if (nodePosition != player->getPos())
////        player->getSceneNode()->setPosition(nodePosition);
////    return NONE;
//}

//Events Irrlicht::checkEvents(void)
//{
//    const u32 now = this->_window->getTimer()->getTime();
//
//    this->_frameDeltaTime = this->_frameDeltaTime = (f32)(now - this->_then) / 1000.f;
//    this->_then = now;
//    return (KeyboardEvents());
//}