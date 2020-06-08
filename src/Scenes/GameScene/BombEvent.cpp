/*
** EPITECH PROJECT, 2019
** OOP_indie_studio
** File description:
** BombEvent.cpp
*/

#include "Scenes.hpp"

void Game::deleteWall(Model *wall, int y)
{
    this->_map[y].erase(std::remove(this->_map[y].begin(), this->_map[y].end(), wall), this->_map[y].end());
    delete(wall);
}

void Game::BombExploded(Bomb *bomb)
{
    int range = this->getPlayerByName(bomb->getOwner())->getRange() + 1;

    for (int y = 0; y < MAP_HEIGHT + 2; y++) {
        for ( vector<Model *>::iterator iter = this->_map[y].begin(); iter != this->_map[y].end(); iter++ ) {
            if ((*iter)->getType() == BREAKABLE) {
                if ((bomb->getBoundingPos().MinEdge.Z > (*iter)->getBoundingPos().MaxEdge.Z && (bomb->getBoundingPos().MinEdge.Z - (1.5 * range)) < (*iter)->getBoundingPos().MaxEdge.Z)
                    && (bomb->getPos().X >= (*iter)->getBoundingPos().MinEdge.X && bomb->getPos().X <= (*iter)->getBoundingPos().MaxEdge.X))
                    this->deleteWall((*iter), y);
                else if ((bomb->getBoundingPos().MaxEdge.Z < (*iter)->getBoundingPos().MinEdge.Z && (bomb->getBoundingPos().MaxEdge.Z + (1.5 * range)) > (*iter)->getBoundingPos().MinEdge.Z)
                    && (bomb->getPos().X >= (*iter)->getBoundingPos().MinEdge.X && bomb->getPos().X <= (*iter)->getBoundingPos().MaxEdge.X))
                    this->deleteWall((*iter), y);
                else if ((bomb->getBoundingPos().MaxEdge.X < (*iter)->getBoundingPos().MinEdge.X && (bomb->getBoundingPos().MaxEdge.X + (1.5 * range)) > (*iter)->getBoundingPos().MinEdge.X)
                    && (bomb->getPos().Z >= (*iter)->getBoundingPos().MinEdge.Z && bomb->getPos().Z <= (*iter)->getBoundingPos().MaxEdge.Z)) {
                    this->deleteWall((*iter), y);
                    iter--;
                }
                else if ((bomb->getBoundingPos().MinEdge.X > (*iter)->getBoundingPos().MaxEdge.X && (bomb->getBoundingPos().MinEdge.X - (1.5 * range)) < (*iter)->getBoundingPos().MaxEdge.X)
                    && (bomb->getPos().Z >= (*iter)->getBoundingPos().MinEdge.Z && bomb->getPos().Z <= (*iter)->getBoundingPos().MaxEdge.Z)) {
                    this->deleteWall((*iter), y);
                    iter--;
                }
            }
        }
    }
}

void Game::bombHandling(IrrlichtDevice *window, InputManager *inputManager, Player *player)
{
    static u32 bombe_activated;

    for (Bomb *obj : this->_bombObjects) {
        obj->setTime(window->getTimer()->getTime());
        if (obj->getTime() >= 2000) {
            this->_bombObjects.erase(std::remove(this->_bombObjects.begin(), this->_bombObjects.end(), obj), this->_bombObjects.end());
            std::cout << "EXPLOSION\n";
            this->BombExploded(obj);
            delete(obj);
        }
    }
    if (inputManager->isKeyPressed(BOMB)) {
        if (bombe_activated == 0 || window->getTimer()->getTime() - bombe_activated >= 1500) {
            bombe_activated = window->getTimer()->getTime();
            this->_bombObjects.push_back(this->createBombObject("bomb", {"bomb_animated.md3", "bomb.png", {player->getPos()}, {.8, .8, .8}, {0, 20}, 20}, player->getName(), window->getTimer()->getTime()));
        }
    }
}