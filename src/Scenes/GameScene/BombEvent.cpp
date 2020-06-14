/*
** EPITECH PROJECT, 2019
** OOP_indie_studio
** File description:
** BombEvent.cpp
*/

#include <algorithm>
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
    for (Player *player : this->_playerObjects) {
        if (player->isHuman() && this->getMapPosition(bomb->getPos()) == this->getMapPosition(player->getPos()))
            pushBackDeadPlayer(deadPlayer, player);
        if (!exploded[0] && bomb->getBoundingPos().MaxEdge.X + (1 + i) > player->getBoundingPos().MinEdge.X
            && bomb->getBoundingPos().MaxEdge.X + (1 + i) < player->getBoundingPos().MaxEdge.X
            && (player->getPos().Z > bomb->getBoundingPos().MinEdge.Z && player->getPos().Z < bomb->getBoundingPos().MaxEdge.Z)) {
            exploded[0] = 1;
            pushBackDeadPlayer(deadPlayer, player);
            continue;
        }
        if (!exploded[1] && bomb->getBoundingPos().MinEdge.X - (1 + i) < player->getBoundingPos().MaxEdge.X
            && bomb->getBoundingPos().MinEdge.X - (1 + i) > player->getBoundingPos().MinEdge.X
            && (player->getPos().Z > bomb->getBoundingPos().MinEdge.Z && player->getPos().Z < bomb->getBoundingPos().MaxEdge.Z)) {
            exploded[1] = 1;
            pushBackDeadPlayer(deadPlayer, player);
            continue;
        }
        if (!exploded[2] && bomb->getBoundingPos().MaxEdge.Z + (1 + i) > player->getBoundingPos().MinEdge.Z
            && bomb->getBoundingPos().MaxEdge.Z + (1 + i) < player->getBoundingPos().MaxEdge.Z
            && (player->getPos().X > bomb->getBoundingPos().MinEdge.X && player->getPos().X < bomb->getBoundingPos().MaxEdge.X)) {
            exploded[2] = 1;
            pushBackDeadPlayer(deadPlayer, player);
            continue;
        }
        if (!exploded[3] && bomb->getBoundingPos().MinEdge.Z - (1 + i) < player->getBoundingPos().MaxEdge.Z
            && bomb->getBoundingPos().MinEdge.Z - (1 + i) > player->getBoundingPos().MinEdge.Z
            && (player->getPos().X > bomb->getBoundingPos().MinEdge.X && player->getPos().X < bomb->getBoundingPos().MaxEdge.X)) {
            exploded[3] = 1;
            pushBackDeadPlayer(deadPlayer, player);
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
    int range = bomb->getRange();
    bool exploded[4] = {0, 0, 0, 0};
    Model *obj = NULL;

    for (int i = 0; i <= range; i++) {
        this->CheckIfNotBreakable(exploded, bomb, i);
        this->CheckIfPlayer(exploded, bomb, deadPlayer, i);
        obj = this->getObjectFromGame(bomb->getBoundingPos().MaxEdge.X + (1 + i), bomb->getPos().Z);
        if (!exploded[0] && obj && obj->getType() == BREAKABLE) {
            if (rand() % 4 == 1)
                this->SpawnPowerUps(obj->getPos());
            this->deleteWall(obj);
            exploded[0] = 1;
        }
        obj = this->getObjectFromGame(bomb->getBoundingPos().MinEdge.X - (1 + i), bomb->getPos().Z);
        if (!exploded[1] && obj && obj->getType() == BREAKABLE) {
            if (rand() % 4 == 1)
                this->SpawnPowerUps(obj->getPos());
            this->deleteWall(obj);
            exploded[1] = 1;
        }
        obj = this->getObjectFromGame(bomb->getPos().X, bomb->getBoundingPos().MaxEdge.Z + (1 + i));
        if (!exploded[2] && obj && obj->getType() == BREAKABLE) {
            if (rand() % 4 == 1)
                this->SpawnPowerUps(obj->getPos());
            this->deleteWall(obj);
            exploded[2] = 1;
        }
        obj = this->getObjectFromGame(bomb->getPos().X, bomb->getBoundingPos().MinEdge.Z - (1 + i));
        if (!exploded[3] && obj && obj->getType() == BREAKABLE) {
            if (rand() % 4 == 1)
                this->SpawnPowerUps(obj->getPos());
            this->deleteWall(obj);
            exploded[3] = 1;
        }
    }
}

void DeletePlayers(vector<Player *> *deadPlayer, vector<Player *> *_playerObjects, Music *music)
{
    int endPlayers = _playerObjects->size();

    if (deadPlayer->size() > 0) {
        for (Player *_deadPlayer : (*deadPlayer)) {
            for (int i = 0; i < endPlayers; i++) {
                if (_deadPlayer->getId() == _playerObjects->at(i)->getId()) {
                    Player *save = _playerObjects->at(i);

                    music->playDeadSound();
                    _playerObjects->erase(std::remove(_playerObjects->begin(),
                        _playerObjects->end(), _playerObjects->at(i)), _playerObjects->end());
                    delete(save);
                    endPlayers--;
                }
            }
        }
    }
    deadPlayer->clear();
}

void Game::addExplosionsObjects(Bomb *bomb)
{
    int range = bomb->getRange();
    Model *obj = NULL;

    obj = this->createObject("explosion", "Explosion.obj", "explosion.png", {(float) bomb->getPos().X, 0, (float) bomb->getPos().Z}, {1, 1, 1}, EXPLOSION);
    bomb->addBombExplosion(obj);
    for (int x = 0; x < range; x++) {
        if (!this->getObjectFromGame(bomb->getBoundingPos().MaxEdge.X + (1 + x), bomb->getPos().Z)) {
            obj = this->createObject("explosion", "Explosion.obj", "explosion.png", {(float) bomb->getPos().X + (1 + x), 0, (float) bomb->getPos().Z}, {1, 1, 1}, EXPLOSION);
            bomb->addBombExplosion(obj);
        }
        if (!this->getObjectFromGame(bomb->getBoundingPos().MinEdge.X - (1 + x), bomb->getPos().Z)) {
            obj = this->createObject("explosion", "Explosion.obj", "explosion.png", {(float) bomb->getPos().X - (1 + x), 0, (float) bomb->getPos().Z}, {1, 1, 1}, EXPLOSION);
            bomb->addBombExplosion(obj);
        }
    }
    for (int y = 0; y < range; y++) {
         if (!this->getObjectFromGame(bomb->getPos().X, bomb->getPos().Z + (1 + y))) {
            obj = this->createObject("explosion", "Explosion.obj", "explosion.png", {(float) bomb->getPos().X, 0 , (float) bomb->getPos().Z + (1 + y)}, {1, 1, 1}, EXPLOSION);
            bomb->addBombExplosion(obj);
         }
         if (!this->getObjectFromGame(bomb->getPos().X, bomb->getPos().Z - (1 + y))) {
            obj = this->createObject("explosion", "Explosion.obj", "explosion.png", {(float) bomb->getPos().X, 0 , (float) bomb->getPos().Z - (1 + y)}, {1, 1, 1}, EXPLOSION);
            bomb->addBombExplosion(obj);
         }
    }
}

void Game::BombHandling(IrrlichtDevice *window, InputManager *inputManager, Player *player)
{
    vector<Player *> deadPlayer;
    int bombEnd = this->_bombObjects.size();

    for (int i = 0; i < bombEnd; i++) {
        Bomb *obj = this->_bombObjects.at(i);
        if (!obj)
            continue;
        obj->setTime(window->getTimer()->getTime());
        if (obj->getTime() >= 2500) {
            std::vector<Model *> explosions = obj->getBombExplosions();
            int endBomb = explosions.size();
            for (int j = 0; j < endBomb; j++)
                delete(explosions.at(j));
            obj->clearExplosionsObjects();
            this->_bombObjects.erase(std::remove(this->_bombObjects.begin(), this->_bombObjects.end(), obj), this->_bombObjects.end());
            delete(obj);
            bombEnd--;
            i = 0;
        } else if (obj->getTime() >= 2000 && obj->getSceneNode()->isVisible()) {
            this->_music->playBombExploSound();
            this->BombExploded(obj, &deadPlayer);
            this->addExplosionsObjects(obj);
            DeletePlayers(&deadPlayer, &this->_playerObjects, this->_music);
            if (this->_playerObjects.size() == 1)
                this->_winner = this->_playerObjects.at(0)->getNb();
            obj->getSceneNode()->setVisible(false);
        }
    }
    if (player && (player->isHuman() && inputManager->isKeyPressed(player->getBombEvent()))) {
        if (getNbBombByOwner(player->getName()) < player->getBombUp()) {
            this->_bombObjects.push_back(this->createBombObject("bomb", {"bomb_animated.md3", "bomb.png",
                {player->getPos()}, {.8, .8, .8}, {0, 20}, 20}, player->getName(), window->getTimer()->getTime(), player->getRange()));
            this->_music->playBombSound();
        }
    }
}