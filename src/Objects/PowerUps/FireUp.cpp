/*
** EPITECH PROJECT, 2019
** OOP_Indie_Studio
** File description:
** Power up fireup
*/

#include <iostream>
#include "PowerUps.hpp"

FireUp::FireUp(scene::IAnimatedMeshSceneNode *node, std::string name) : AnimatedModel(node, name)
{
}

FireUp::~FireUp()
{
    this->_node->remove();
}

PowerUpsType FireUp::getPowerUpType(void) const
{
    return this->_type;
}

void FireUp::affectPlayer(Player *player)
{
    player->setRange();
}
