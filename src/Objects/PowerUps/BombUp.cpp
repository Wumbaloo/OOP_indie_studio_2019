/*
** EPITECH PROJECT, 2019
** OOP_Indie_Studio
** File description:
** Power up bombup
*/

#include <iostream>
#include "PowerUps.hpp"

BombUp::BombUp(scene::IAnimatedMeshSceneNode *node, std::string name) : AnimatedModel(node, name)
{
}

BombUp::~BombUp()
{
    this->_node->remove();
}

PowerUpsType BombUp::getPowerUpType(void) const
{
    return this->_type;
}

void BombUp::affectPlayer(Player *player)
{
    player->setBombUp();
}
