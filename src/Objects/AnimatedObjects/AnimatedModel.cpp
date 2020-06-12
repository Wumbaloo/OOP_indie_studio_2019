/*
** EPITECH PROJECT, 2019
** indie stduio
** File description:
** AnimatedObject cpp
*/

#include <iostream>
#include "Object.hpp"
#include "AnimatedObjects.hpp"

AnimatedModel::AnimatedModel(scene::IAnimatedMeshSceneNode *object, std::string name, ObjectType type) : AObject(name, type)
{
    this->_node = object;
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

void AnimatedModel::changeAnimation(PlayerAnimations anim)
{}

core::aabbox3df AnimatedModel::getBoundingPos(void) const
{
    return this->_node->getTransformedBoundingBox();
}