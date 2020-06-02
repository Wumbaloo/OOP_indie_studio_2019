/*
** EPITECH PROJECT, 2019
** OOP_Indie_Studio
** File description:
** Power up wallpass
*/

#include <iostream>
#include "PowerUps.hpp"

WallPass::WallPass(scene::IAnimatedMeshSceneNode *node, std::string name) : AnimatedModel(node, name)
{
}

WallPass::~WallPass()
{
    this->_node->remove();
}

PowerUpsType WallPass::getPowerUpType(void) const
{
    return this->_type;
}

void WallPass::affectPlayer(Player *player)
{
    player->setWallPass(true);
}
