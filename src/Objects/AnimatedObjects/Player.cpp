/*
** EPITECH PROJECT, 2019
** OOP_indie_stduio
** File description:
** Player cpp
*/

#include <iostream>
#include "Object.hpp"
#include "AnimatedObjects.hpp"

Player::Player(int health ,scene::IAnimatedMeshSceneNode *node, std::string name) : AnimatedModel(node, name)
{
    this->_node = node;
    this->_health = health;
    this->_running = false;
    this->_rotateFix = {0, 25, 0};
}

bool Player::isRunning(void) const
{
    return this->_running;
}

core::vector3df Player::getRotateFix(void) const
{
    return this->_rotateFix;
}

void Player::changeAnimation(Animations anim)
{
    if (anim == RUNNING && this->_running == false) {
        this->_running = true;
        this->_node->setFrameLoop(301, 323);
    }
    if (anim == IDLE) {
        if (this->_running)
            this->_running = false;
        this->_node->setFrameLoop(0, 300);
    }
}