/*
** EPITECH PROJECT, 2019
** indie stduio
** File description:
** AnimatedObject cpp
*/

#include <iostream>
#include "Object.hpp"

AnimatedModel::AnimatedModel(int health ,scene::IAnimatedMeshSceneNode *object, std::string name) : AObject(name)
{
    this->_node = object;
    this->_health = health;
    this->_rotateFix = {0, 50, 0};
}

scene::IAnimatedMeshSceneNode *AnimatedModel::getSceneNode(void) const
{
    return _node;
}

core::vector3df AnimatedModel::getPos(void) const
{
    return this->_node->getPosition();
}

core::vector3df AnimatedModel::getRotation(void) const
{
    return this->_node->getRotation();
}

void AnimatedModel::setPos(core::vector3df pos)
{
    this->_node->setPosition(pos);
}
void AnimatedModel::setRotation(core::vector3df rotation)
{
    this->_node->setRotation(rotation);
}

void AnimatedModel::changeAnimation(Animations anim)
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

bool AnimatedModel::isRunning(void)
{
    return this->_running;
}