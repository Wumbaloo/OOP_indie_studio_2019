/*
** EPITECH PROJECT, 2019
** OOP_indie_stduio
** File description:
** Player cpp
*/

#include <iostream>
#include "Object.hpp"
#include "AnimatedObjects.hpp"

Player::Player(int nb ,scene::IAnimatedMeshSceneNode *node, std::string name, InputManager *im) : AnimatedModel(node, name, PLAYER)
{
    this->_node = node;
    this->_nb = nb;
    this->_health = 100;
    this->_running = false;
    this->_rotateFix = {0, 25, 0};
    this->_bombUp = 1;
    this->_speedUp = 1;
    this->_fireUp = 1;
    this->_wallPass = false;
    switch (nb) {
        default:
        case 1:
            im->bindActionToKey(MOVE_UP_1, KEY_KEY_Z);
            im->bindActionToKey(MOVE_DOWN_1, KEY_KEY_S);
            im->bindActionToKey(MOVE_LEFT_1, KEY_KEY_Q);
            im->bindActionToKey(MOVE_RIGHT_1, KEY_KEY_D);
            im->bindActionToKey(BOMB_1, KEY_SPACE);
            break;
        case 2:
            im->bindActionToKey(MOVE_UP_2, KEY_UP);
            im->bindActionToKey(MOVE_DOWN_2, KEY_DOWN);
            im->bindActionToKey(MOVE_LEFT_2, KEY_LEFT);
            im->bindActionToKey(MOVE_RIGHT_2, KEY_RIGHT);
            im->bindActionToKey(BOMB_2, KEY_RCONTROL);
            break;
        case 3:
            im->bindActionToKey(MOVE_UP_3, KEY_KEY_Y);
            im->bindActionToKey(MOVE_DOWN_3, KEY_KEY_H);
            im->bindActionToKey(MOVE_LEFT_3, KEY_KEY_G);
            im->bindActionToKey(MOVE_RIGHT_3, KEY_KEY_J);
            im->bindActionToKey(BOMB_3, KEY_KEY_T);
            break;
        case 4:
            im->bindActionToKey(MOVE_UP_4, KEY_KEY_O);
            im->bindActionToKey(MOVE_DOWN_4, KEY_KEY_L);
            im->bindActionToKey(MOVE_LEFT_4, KEY_KEY_K);
            im->bindActionToKey(MOVE_RIGHT_4, KEY_KEY_M);
            im->bindActionToKey(BOMB_4, KEY_KEY_I);
            break;
    }
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

enum Events Player::getUpEvent(void) const
{
    switch (this->_nb) {
        default:
        case 1:
            return (MOVE_UP_1);
        case 2:
            return (MOVE_UP_2);
        case 3:
            return (MOVE_UP_3);
        case 4:
            return (MOVE_UP_4);
    }
}

enum Events Player::getDownEvent(void) const
{
    switch (this->_nb) {
        default:
        case 1:
            return (MOVE_DOWN_1);
        case 2:
            return (MOVE_DOWN_2);
        case 3:
            return (MOVE_DOWN_3);
        case 4:
            return (MOVE_DOWN_4);
    }
}

enum Events Player::getLeftEvent(void) const
{
    switch (this->_nb) {
        default:
        case 1:
            return (MOVE_LEFT_1);
        case 2:
            return (MOVE_LEFT_2);
        case 3:
            return (MOVE_LEFT_3);
        case 4:
            return (MOVE_LEFT_4);
    }
}

enum Events Player::getRightEvent(void) const
{
    switch (this->_nb) {
        default:
        case 1:
            return (MOVE_RIGHT_1);
        case 2:
            return (MOVE_RIGHT_2);
        case 3:
            return (MOVE_RIGHT_3);
        case 4:
            return (MOVE_RIGHT_4);
    }
}

enum Events Player::getBombEvent(void) const
{
    switch (this->_nb) {
        default:
        case 1:
            return (BOMB_1);
        case 2:
            return (BOMB_2);
        case 3:
            return (BOMB_3);
        case 4:
            return (BOMB_4);
    }
}
