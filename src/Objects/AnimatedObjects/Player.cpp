/*
** EPITECH PROJECT, 2019
** OOP_indie_stduio
** File description:
** Player cpp
*/

#include <iostream>
#include "Object.hpp"
#include "AnimatedObjects.hpp"

Player::Player(int health ,scene::IAnimatedMeshSceneNode *node, std::string name) : AnimatedModel(node, name, PLAYER)
{
    this->_node = node;
    this->_health = health;
    this->_running = false;
    this->_rotateFix = {0, 25, 0};
    this->_bombUp = 1;
    this->_speedUp = 1;
    this->_fireUp = 1;
    this->_wallPass = false;
}

Player::~Player()
{
    this->_node->remove();
}

bool Player::isRunning(void) const
{
    return this->_running;
}

void Player::changeAnimation(PlayerAnimations anim)
{
    switch (anim) {
        case RUNNING:
            if (this->_running == false) {
                this->_running = true;
                this->_node->setFrameLoop(301, 323);
            }
            break;
        case IDLE:
            if (this->_running)
                this->_running = false;
            this->_node->setFrameLoop(0, 300);
            break;
        default:
            break;
    }
}

void Player::setSpeedUp(u32 time, float value) // take 1.5 by default (just call the function wihtout value)
{
    this->_speedUp = value;
    this->_speedupTime = time;
}

void Player::setRange(int value) // take 1 by default (just call the function wihtout value)
{
    this->_fireUp += value;
}

void Player::setBombUp(int value) // take 1 by default (just call the function wihtout value)
{
    this->_bombUp += value;
}

void Player::setWallPass(u32 time, bool status)
{
    this->_wallPass = status;
    this->_wallpassTime = time;
}

int Player::getBombUp(void) const
{
    return this->_bombUp;
}

float Player::getSpeedUp(void) const
{
    return this->_speedUp;
}

bool Player::getWallPass(void) const
{
    return this->_wallPass;
}

int Player::getRange(void) const
{
    return this->_fireUp;
}

core::vector3df Player::getRotateFix(void) const
{
    return this->_rotateFix;
}

u32 Player::getSpeedUpTime(void) const
{
    return this->_speedupTime;
}

u32 Player::getWallPassTime(void) const
{
    return this->_wallpassTime;
}
