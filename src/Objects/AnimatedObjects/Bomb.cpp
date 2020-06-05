/*
** EPITECH PROJECT, 2019
** OOP_indie_stduio
** File description:
** Bomb cpp
*/

#include <iostream>
#include "Object.hpp"
#include "AnimatedObjects.hpp"

Bomb::Bomb(std::string name, scene::IAnimatedMeshSceneNode *node, std::string owner, u32 time) : AnimatedModel(node, name)
{
    this->_node = node;
    this->_owner = owner;
    this->_time = time;
    this->_initial_time = time;
}

Bomb::~Bomb(void)
{
    this->_node->remove();
}

u32 Bomb::getTime(void) const
{
    return this->_time - this->_initial_time;
}

void Bomb::setTime(u32 newTime)
{
    this->_time += newTime - this->_time;
}

std::string Bomb::getOwner(void) const
{
    return this->_owner;
}
