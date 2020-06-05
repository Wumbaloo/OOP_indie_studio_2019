/*
** EPITECH PROJECT, 2023
** OOP_indie_studio_2019
** File description:
** game Event cpp,
*/

#include <algorithm>
#include "IndieStudio.hpp"

bool Game::checkColision(AnimatedModel *object, std::vector<Model *> wall[], Direction dir)
{
    for (int y = 0; y < MAP_HEIGHT + 2; y++) {
        for (Model *wall : this->_map[y]) {
            switch (dir) {
                case UP:
                    if ((object->getPos().Z + 2.1 >= wall->getPos().Z && object->getPos().Z < wall->getPos().Z + 1.1)
                        && (object->getPos().X + .5 >= wall->getBoundingPos().MinEdge.X && object->getPos().X + .5 <= wall->getBoundingPos().MaxEdge.X))
                        return false;
                    break;
                case DOWN:
                    if ((object->getPos().Z - 2.1 <= wall->getPos().Z && object->getPos().Z > wall->getPos().Z + 1.1)
                        && (object->getPos().X >= wall->getBoundingPos().MinEdge.X && object->getPos().X <= wall->getBoundingPos().MaxEdge.X))
                        return false;
                    break;
                case LEFT:
                    if ((object->getPos().X - 2.1 <= wall->getPos().X && object->getPos().X > wall->getPos().X + 1.1)
                        && (object->getPos().Z >= wall->getBoundingPos().MinEdge.Z && object->getPos().Z <= wall->getBoundingPos().MaxEdge.Z))
                        return false;
                    break;
                case RIGHT:
                    if ((object->getPos().X + 2.1 >= wall->getPos().X && object->getPos().X < wall->getPos().X + 1.1)
                        && (object->getPos().Z >= wall->getBoundingPos().MinEdge.Z && object->getPos().Z <= wall->getBoundingPos().MaxEdge.Z))
                        return false;
                    break;
                default:
                    break;
            };
        }
    }
    return true;
}

void Game::PlayerMovements(Player *player, InputManager *inputManager)
{
    core::vector3df nodePosition = player->getPos();

    if (inputManager->isKeyPressed(MOVE_UP) && checkColision(player, this->_map, UP)) {
        nodePosition.Z += PLAYER_SPEED * this->_frameDeltaTime * player->getSpeedUp();
        player->setRotation((core::vector3df){0.f, 180.f, .0f} - player->getRotateFix());
        player->changeAnimation(RUNNING);
    } else if (inputManager->isKeyPressed(MOVE_DOWN) && checkColision(player, this->_map, DOWN)) {
        nodePosition.Z -= PLAYER_SPEED * this->_frameDeltaTime * player->getSpeedUp();
        player->setRotation((core::vector3df){0.f, 0.f, 0.f} - player->getRotateFix());
        player->changeAnimation(RUNNING);
    } else if (inputManager->isKeyPressed(MOVE_LEFT) && checkColision(player, this->_map, LEFT)) {
        nodePosition.X -= PLAYER_SPEED * this->_frameDeltaTime * player->getSpeedUp();
        player->setRotation((core::vector3df){0.f, 90.f, 0.f} - player->getRotateFix());
        player->changeAnimation(RUNNING);
    } else if (inputManager->isKeyPressed(MOVE_RIGHT) && checkColision(player, this->_map, RIGHT)) {
        nodePosition.X += PLAYER_SPEED * this->_frameDeltaTime * player->getSpeedUp();
        player->setRotation((core::vector3df){0.f, -90.f, 0.f} - player->getRotateFix());
        player->changeAnimation(RUNNING);
    } else {
        if (player->isRunning()) {
            player->setRotation(player->getRotation() + player->getRotateFix());
            player->changeAnimation(IDLE);
        }
    }
    if (nodePosition != player->getPos())
        player->getSceneNode()->setPosition(nodePosition);
}

void Game::PowerUpContact(PowerUp *bonus, Player *player)
{
    auto it = std::find(this->_powerUpObjects.begin(), this->_powerUpObjects.end(), bonus);
    if (it != this->_powerUpObjects.end()) { this->_powerUpObjects.erase(it); }
    bonus->affectPlayer(player);
    delete(bonus);
}

Events Game::KeyboardEvents(InputManager *inputManager, IrrlichtDevice *window)
{
    Player *player = this->getPlayerByName("player");

    if (!player)
        return NONE;
    if (inputManager->isKeyPressed(CLOSE)) {
        this->destroy();
        return CLOSE;
    }
    if (inputManager->isKeyPressed(PAUSE)) {
        this->_paused = !this->_paused;
    }
    if (this->_paused)
        return NONE;
    if (inputManager->isKeyPressed(BACK_MENU)) {
        this->destroy();
        return BACK_MENU;
    }
    this->bombHandling(window, inputManager, player);
    this->PlayerMovements(player, inputManager);
    return NONE;
}

Events Game::checkEvents(IrrlichtDevice *window, InputManager *inputManager)
{
    const u32 now = window->getTimer()->getTime();

    this->_frameDeltaTime = (f32)(now - this->_then) / 1000.f;
    this->_then = now;
    return (KeyboardEvents(inputManager, window));
}

void Game::destroy()
{
    for (auto object : this->_objects)
        delete (object);
    this->_objects.clear();
    for (auto object : this->_playerObjects)
        delete (object);
    this->_playerObjects.clear();
    for (auto object : this->_bombObjects)
        delete (object);
    this->_bombObjects.clear();
    for (auto object : this->_powerUpObjects)
        delete (object);
    this->_powerUpObjects.clear();
    for (int y = 0; y < MAP_HEIGHT; y++) {
        for (auto object : this->_map[y])
            delete (object);
        this->_map[y].clear();
    }
}