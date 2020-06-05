/*
** EPITECH PROJECT, 2019
** OOP_indie_studio
** File description:
** BombEvent.cpp
*/

#include "Scenes.hpp"

void Game::deleteWall(Model *wall, int y)
{
    auto it = std::find(this->_map[y].begin(), this->_map[y].end(), wall);
    if (it != this->_map[y].end()) { this->_map[y].erase(it); }
    delete(wall);
}

void Game::BombExploded(Bomb *bomb)
{
    int range = this->getPlayerByName(bomb->getOwner())->getRange();

    for (int y = 0; y < MAP_HEIGHT + 2; y++) {
        for (Model *wall : this->_map[y]) {
            if (wall->getType() == BREAKABLE) {
                if ((bomb->getBoundingPos().MinEdge.Z > wall->getBoundingPos().MaxEdge.Z && (bomb->getBoundingPos().MinEdge.Z - (1.5 * range)) < wall->getBoundingPos().MaxEdge.Z)
                    && (bomb->getPos().X >= wall->getBoundingPos().MinEdge.X && bomb->getPos().X <= wall->getBoundingPos().MaxEdge.X)) {
                    std::cout << "lol\n";
                    this->deleteWall(wall, y);
                }
                if ((bomb->getBoundingPos().MaxEdge.Z < wall->getBoundingPos().MinEdge.Z && (bomb->getBoundingPos().MaxEdge.Z + (1.5 * range)) > wall->getBoundingPos().MinEdge.Z)
                    && (bomb->getPos().X >= wall->getBoundingPos().MinEdge.X && bomb->getPos().X <= wall->getBoundingPos().MaxEdge.X)) {
                    std::cout << "lol\n";
                    this->deleteWall(wall, y);
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
            auto it = std::find(this->_bombObjects.begin(), this->_bombObjects.end(), obj);
            if (it != this->_bombObjects.end()) { this->_bombObjects.erase(it); }
            std::cout << "EXPLOSION\n";
            // this->BombExploded(obj);
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