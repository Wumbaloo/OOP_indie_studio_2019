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

Events Irrlicht::KeyboardEvents(void)
{
    core::vector3df nodePosition = this->getObjectByName("player")->getPos();

    this->_inputManager->isKeyPressed(MOVE_UP) ? nodePosition.Y += PLAYER_SPEED * this->_frameDeltaTime : 0;
    this->_inputManager->isKeyPressed(MOVE_DOWN) ? nodePosition.Y -= PLAYER_SPEED * this->_frameDeltaTime : 0;
    this->_inputManager->isKeyPressed(MOVE_LEFT) ? NULL : NULL;
    this->_inputManager->isKeyPressed(MOVE_RIGHT) ? NULL : NULL;
    if (this->_inputManager->isKeyPressed(CLOSE))
        return (CLOSE);
    if (nodePosition != this->getObjectByName("player")->getPos())
        this->getObjectByName("player")->getSceneNode()->setPosition(nodePosition);
    return NONE;
}

Events Irrlicht::checkEvents(void)
{
    const u32 now = this->_window->getTimer()->getTime();

    this->_frameDeltaTime = this->_frameDeltaTime = (f32)(now - this->_then) / 1000.f;
    this->_then = now;
    return (KeyboardEvents());
}