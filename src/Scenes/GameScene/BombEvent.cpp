/*
** EPITECH PROJECT, 2019
** OOP_indie_studio
** File description:
** BombEvent.cpp
*/

#include "Scenes.hpp"

void Game::deleteWall(Model *wall)
{
    for (int y = 0; y < MAP_HEIGHT + 2; y++)
        this->_map[y].erase(std::remove(this->_map[y].begin(), this->_map[y].end(), wall), this->_map[y].end());
    delete(wall);
}

void Game::CheckIfNotBreakable(bool exploded[4], Bomb *bomb, int i)
{
    if (!exploded[0] && this->getObjectFromGame(bomb->getBoundingPos().MaxEdge.X + (1 + i), bomb->getPos().Z)
            && this->getObjectFromGame(bomb->getBoundingPos().MaxEdge.X + (1 + i), bomb->getPos().Z)->getType() == OBSTACLE)
        exploded[0] = 1;
    if (!exploded[1] && this->getObjectFromGame(bomb->getBoundingPos().MinEdge.X - (1 + i), bomb->getPos().Z)
            && this->getObjectFromGame(bomb->getBoundingPos().MinEdge.X - (1 + i), bomb->getPos().Z)->getType() == OBSTACLE)
        exploded[1] = 1;
    if (!exploded[2] && this->getObjectFromGame(bomb->getPos().X, bomb->getBoundingPos().MaxEdge.Z + (1 + i))
            && this->getObjectFromGame(bomb->getPos().X, bomb->getBoundingPos().MaxEdge.Z + (1 + i))->getType() == OBSTACLE)
        exploded[2] = 1;
    if (!exploded[3] && this->getObjectFromGame(bomb->getPos().X, bomb->getBoundingPos().MinEdge.Z - (1 + i))
            && this->getObjectFromGame(bomb->getPos().X, bomb->getBoundingPos().MinEdge.Z - (1 + i))->getType() == OBSTACLE)
        exploded[3] = 1;
}

void Game::BombExploded(Bomb *bomb)
{
    int range = this->getPlayerByName(bomb->getOwner())->getRange();
    bool exploded[4] = {0, 0, 0, 0};

    for (int i = 0; i <= range; i++) {
        this->CheckIfNotBreakable(exploded, bomb, i);
        if (!exploded[0] && this->getObjectFromGame(bomb->getBoundingPos().MaxEdge.X + (1 + i), bomb->getPos().Z)
                && this->getObjectFromGame(bomb->getBoundingPos().MaxEdge.X + (1 + i), bomb->getPos().Z)->getType() == BREAKABLE) {
            this->deleteWall(this->getObjectFromGame(bomb->getBoundingPos().MaxEdge.X + (1 + i), bomb->getPos().Z));
            exploded[0] = 1;
        }
        if (!exploded[1] && this->getObjectFromGame(bomb->getBoundingPos().MinEdge.X - (1 + i), bomb->getPos().Z)
                && this->getObjectFromGame(bomb->getBoundingPos().MinEdge.X - (1 + i), bomb->getPos().Z)->getType() == BREAKABLE) {
            this->deleteWall(this->getObjectFromGame(bomb->getBoundingPos().MinEdge.X - (1 + i), bomb->getPos().Z));
            exploded[1] = 1;
        }
        if (!exploded[2] && this->getObjectFromGame(bomb->getPos().X, bomb->getBoundingPos().MaxEdge.Z + (1 + i))
                && this->getObjectFromGame(bomb->getPos().X, bomb->getBoundingPos().MaxEdge.Z + (1 + i))->getType() == BREAKABLE) {
            this->deleteWall(this->getObjectFromGame(bomb->getPos().X, bomb->getBoundingPos().MaxEdge.Z + (1 + i)));
            exploded[2] = 1;
        }
        if (!exploded[3] && this->getObjectFromGame(bomb->getPos().X, bomb->getBoundingPos().MinEdge.Z - (1 + i))
                && this->getObjectFromGame(bomb->getPos().X, bomb->getBoundingPos().MinEdge.Z - (1 + i))->getType() == BREAKABLE) {
            this->deleteWall(this->getObjectFromGame(bomb->getPos().X, bomb->getBoundingPos().MinEdge.Z - (1 + i)));
            exploded[3] = 1;
        }
    }
}

void Game::BombHandling(IrrlichtDevice *window, InputManager *inputManager, Player *player)
{
    for (Bomb *obj : this->_bombObjects) {
        obj->setTime(window->getTimer()->getTime());
        if (obj->getTime() >= 2000) {
            this->_bombObjects.erase(std::remove(this->_bombObjects.begin(), this->_bombObjects.end(), obj), this->_bombObjects.end());
            this->BombExploded(obj);
            if (rand() % 3 == 1)
                this->SpawnPowerUps(obj->getPos());
            delete(obj);
        }
    }
    if (inputManager->isKeyPressed(player->getBombEvent())) {
        if (getNbBombByOwner(player->getName()) < player->getBombUp())
            this->_bombObjects.push_back(this->createBombObject("bomb", {"bomb_animated.md3", "bomb.png", {player->getPos()}, {.8, .8, .8}, {0, 20}, 20}, player->getName(), window->getTimer()->getTime()));
    }
}