/*
** EPITECH PROJECT, 2019
** OOP_indie_studio
** File description:
** power ups event cpp
*/

#include <iostream>
#include "Scenes.hpp"

void Game::SpawnPowerUps(core::vector3df pos)
{
    PowerUpsType powerTab[4] = {BOMBUP, SPEEDUP, FIREUP, WALLPASS};
    int idx = rand() % 4;

    switch (powerTab[idx]) {
        case BOMBUP:
            this->_powerUpObjects.push_back(this->createPowerUpObject(BOMBUP, "BombUp", {"bombUp.md3", "Rough.png",
                {pos.X, 0, pos.Z}, {.8, .8, .8}, {0, 50}, 25}));
            break;
        case SPEEDUP:
            this->_powerUpObjects.push_back(this->createPowerUpObject(SPEEDUP, "speedUp", {"SpeedUp.md3", "wing_textureColor.png",
                {pos.X, 0, pos.Z}, {.8, .8, .8}, {0, 31}, 20}));
            break;
        case FIREUP:
            this->_powerUpObjects.push_back(this->createPowerUpObject(FIREUP, "fireUp", {"FireUp.md3", "FireUp.png",
                {pos.X, 0, pos.Z}, {.8, .8, .8}, {0, 62}, 20}));
            break;
        case WALLPASS:
            this->_powerUpObjects.push_back(this->createPowerUpObject(WALLPASS, "WallPass", {"WallPass.md3", "WallPass.bmp",
                {pos.X, 0, pos.Z}, {.8, .8, .8}, {0, 50}, 25}));
            break;
        default:
            return;
    }
}

void Game::PowerUpContact(PowerUp *bonus, Player *player, IrrlichtDevice *window)
{
    this->_powerUpObjects.erase(std::remove(this->_powerUpObjects.begin(), this->_powerUpObjects.end(), bonus), this->_powerUpObjects.end());
    bonus->affectPlayer(player, window);
    delete(bonus);
}

void Game::PowerUpsTimerHandling(Player *player, IrrlichtDevice *window)
{
    core::aabbox3df playerPos;
    core::vector2df pos;
    int count = 1;

    if (player->getWallPass() && window->getTimer()->getTime() - player->getWallPassTime() >= 3500) {
        player->setWallPass(0, false);
        playerPos = player->getBoundingPos();
        pos = getMapPosition({playerPos.MaxEdge.X, 0, player->getPos().Z});
        if (!getObjectFromGame(playerPos.MaxEdge.X + count, player->getPos().Z)) {
            cout << player->getPos().X << endl;
            cout << player->getPos().Z << endl;
            cout << pos.X << endl;
            cout << pos.Y << endl;
            placeInMap(player, pos.X + count, pos.Y);
        //     // break;
        }
        // while (1) {
        //     if (!getObjectFromMap(playerPos.X + count, playerPos.Y)->getType()) {
        //         placeInMap(player, playerPos.X, playerPos.Y);
        //         break;
        //     }
        //     if (!getObjectFromMap(playerPos.X - count, playerPos.Y)->getType()) {
        //         placeInMap(player, playerPos.X, playerPos.Y);
        //         break;
        //     }
        //     if (!getObjectFromMap(playerPos.X, playerPos.Y + count)->getType()) {
        //         placeInMap(player, playerPos.X, playerPos.Y);
        //         break;
        //     }
        //     if (!getObjectFromMap(playerPos.X, playerPos.Y - count)->getType()) {
        //         placeInMap(player, playerPos.X, playerPos.Y);
        //         break;
        //     }
        //     count++;
        // }
    }
    if (player->getSpeedUp() == 1.5 && window->getTimer()->getTime() - player->getSpeedUpTime() >= 5000)
        player->setSpeedUp(0, 1);
}

void Game::CheckPowerUpsColision(Player *player, IrrlichtDevice *window)
{
    if (player->getWallPass() || player->getSpeedUp() == 1.5)
        this->PowerUpsTimerHandling(player, window);
    for (PowerUp *obj : this->_powerUpObjects) {
        if (obj->getBoundingPos().intersectsWithBox(player->getBoundingPos()))
            this->PowerUpContact(obj, player, window);
    }
}