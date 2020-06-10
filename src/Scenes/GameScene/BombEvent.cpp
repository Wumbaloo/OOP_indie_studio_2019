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

void pushBackDeadPlayer(vector<Player *> *deadPlayer, Player *player)
{
    if (deadPlayer->size() > 0) {
        for (Player *deadPlayer : (*deadPlayer)) {
            if (deadPlayer->getName() == player->getName())
                return;
        }
    }
    deadPlayer->push_back(player);
}

void Game::CheckIfPlayer(bool exploded[4], Bomb *bomb, vector<Player *> *deadPlayer, int i)
{
    cout << "LOOL" << endl;
    for (Player *player : this->_playerObjects) {
        if (!exploded[0] && bomb->getBoundingPos().MaxEdge.X + (1 + i) > player->getBoundingPos().MinEdge.X
            && (player->getPos().Z > bomb->getBoundingPos().MinEdge.Z && player->getPos().Z < bomb->getBoundingPos().MaxEdge.Z)) {
            exploded[0] = 1;
            pushBackDeadPlayer(deadPlayer, player);
            std::cout << player->getName() << "destroy x+" << endl;
            continue;
        }
        if (!exploded[1] && bomb->getBoundingPos().MinEdge.X + (1 + i) < player->getBoundingPos().MaxEdge.X
            && (player->getPos().Z > bomb->getBoundingPos().MinEdge.Z && player->getPos().Z < bomb->getBoundingPos().MaxEdge.Z)) {
            exploded[1] = 1;
            pushBackDeadPlayer(deadPlayer, player);
            std::cout << player->getName() << "destroy x-" << endl;
            continue;
        }
        if (!exploded[2] && bomb->getBoundingPos().MaxEdge.Z + (1 + i) > player->getBoundingPos().MinEdge.Z
            && (player->getPos().X > bomb->getBoundingPos().MinEdge.X && player->getPos().X < bomb->getBoundingPos().MaxEdge.X)) {
            exploded[2] = 1;
            pushBackDeadPlayer(deadPlayer, player);
            std::cout << player->getName() << "destroy z+" << endl;
            continue;
        }
        if (!exploded[3] && bomb->getBoundingPos().MinEdge.Z - (1 + i) < player->getBoundingPos().MaxEdge.Z
            && (player->getPos().X > bomb->getBoundingPos().MinEdge.X && player->getPos().X < bomb->getBoundingPos().MaxEdge.X)) {
            exploded[3] = 1;
            pushBackDeadPlayer(deadPlayer, player);
            std::cout << player->getName() << "destroy z-" << endl;
            continue;
        }
    }
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

void Game::BombExploded(Bomb *bomb, vector<Player *> *deadPlayer)
{
    int range = this->getPlayerByName(bomb->getOwner())->getRange();
    bool exploded[4] = {0, 0, 0, 0};

    for (int i = 0; i <= range; i++) {
        this->CheckIfNotBreakable(exploded, bomb, i);
        this->CheckIfPlayer(exploded, bomb, deadPlayer, i);
        // std::cout << "HELLO\n";
        if (!exploded[0] && this->getObjectFromGame(bomb->getBoundingPos().MaxEdge.X + (1 + i), bomb->getPos().Z)
                && this->getObjectFromGame(bomb->getBoundingPos().MaxEdge.X + (1 + i), bomb->getPos().Z)->getType() == BREAKABLE) {
            if (rand() % 4 == 1)
                this->SpawnPowerUps(this->getObjectFromGame(bomb->getBoundingPos().MaxEdge.X + (1 + i), bomb->getPos().Z)->getPos());
            this->deleteWall(this->getObjectFromGame(bomb->getBoundingPos().MaxEdge.X + (1 + i), bomb->getPos().Z));
            exploded[0] = 1;
        }
        if (!exploded[1] && this->getObjectFromGame(bomb->getBoundingPos().MinEdge.X - (1 + i), bomb->getPos().Z)
                && this->getObjectFromGame(bomb->getBoundingPos().MinEdge.X - (1 + i), bomb->getPos().Z)->getType() == BREAKABLE) {
            if (rand() % 4 == 1)
                this->SpawnPowerUps(this->getObjectFromGame(bomb->getBoundingPos().MinEdge.X - (1 + i), bomb->getPos().Z)->getPos());
            this->deleteWall(this->getObjectFromGame(bomb->getBoundingPos().MinEdge.X - (1 + i), bomb->getPos().Z));
            exploded[1] = 1;
        }
        if (!exploded[2] && this->getObjectFromGame(bomb->getPos().X, bomb->getBoundingPos().MaxEdge.Z + (1 + i))
                && this->getObjectFromGame(bomb->getPos().X, bomb->getBoundingPos().MaxEdge.Z + (1 + i))->getType() == BREAKABLE) {
            if (rand() % 4 == 1)
                this->SpawnPowerUps(this->getObjectFromGame(bomb->getPos().X, bomb->getBoundingPos().MaxEdge.Z + (1 + i))->getPos());
            this->deleteWall(this->getObjectFromGame(bomb->getPos().X, bomb->getBoundingPos().MaxEdge.Z + (1 + i)));
            exploded[2] = 1;
        }
        if (!exploded[3] && this->getObjectFromGame(bomb->getPos().X, bomb->getBoundingPos().MinEdge.Z - (1 + i))
                && this->getObjectFromGame(bomb->getPos().X, bomb->getBoundingPos().MinEdge.Z - (1 + i))->getType() == BREAKABLE) {
            if (rand() % 4 == 1)
                this->SpawnPowerUps(this->getObjectFromGame(bomb->getPos().X, bomb->getBoundingPos().MinEdge.Z - (1 + i))->getPos());
            this->deleteWall(this->getObjectFromGame(bomb->getPos().X, bomb->getBoundingPos().MinEdge.Z - (1 + i)));
            exploded[3] = 1;
        }
        // std::cout << "HELLO2\n";
    }
}

void Game::BombHandling(IrrlichtDevice *window, InputManager *inputManager, Player *player)
{
    vector<Player *> deadPlayer;

    for (Bomb *obj : this->_bombObjects) {
        obj->setTime(window->getTimer()->getTime());
        if (obj->getTime() >= 2000) {
            this->_bombObjects.erase(std::remove(this->_bombObjects.begin(), this->_bombObjects.end(), obj), this->_bombObjects.end());
            this->BombExploded(obj, &deadPlayer);
            cout << deadPlayer.size() << endl;
            if (deadPlayer.size() > 0) {
                for (Player *_deadPlayer : deadPlayer) {
                    for (auto player = this->_playerObjects.begin(); player != this->_playerObjects.end(); player++) {
                        if (_deadPlayer->getId() == (*player)->getId()) {
                            this->_playerObjects.erase(std::remove(this->_playerObjects.begin(), this->_playerObjects.end(), (*player)), this->_playerObjects.end());
                            delete((*player));
                        }
                    }
                }
                deadPlayer.clear();
            }
            delete(obj);
        }
    }
    if (player && (player->isHuman() && inputManager->isKeyPressed(player->getBombEvent()))) {
        if (getNbBombByOwner(player->getName()) < player->getBombUp())
            this->_bombObjects.push_back(this->createBombObject("bomb", {"bomb_animated.md3", "bomb.png", {player->getPos()}, {.8, .8, .8}, {0, 20}, 20}, player->getName(), window->getTimer()->getTime()));
    }
}