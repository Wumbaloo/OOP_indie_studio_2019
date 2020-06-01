/*
** EPITECH PROJECT, 2023
** OOP_indie_studio_2019
** File description:
** game Event cpp,
*/

#include "IndieStudio.hpp"
#include <algorithm>

core::vector3df Game::PlayerMovements(core::vector3df nodePosition, Player *player, InputManager *inputManager)
{
    nodePosition = player->getPos();
    if (inputManager->isKeyPressed(MOVE_UP)) {
        nodePosition.Z += PLAYER_SPEED * this->_frameDeltaTime;
        player->setRotation((core::vector3df){0.f, 180.f, .0f} - player->getRotateFix());
        player->changeAnimation(RUNNING);
    } else if (inputManager->isKeyPressed(MOVE_DOWN)) {
        nodePosition.Z -= PLAYER_SPEED * this->_frameDeltaTime;
        player->setRotation((core::vector3df){0.f, 0.f, 0.f} - player->getRotateFix());
        player->changeAnimation(RUNNING);
    } else if (inputManager->isKeyPressed(MOVE_LEFT)) {
        nodePosition.X -= PLAYER_SPEED * this->_frameDeltaTime;
        player->setRotation((core::vector3df){0.f, 90.f, 0.f} - player->getRotateFix());
        player->changeAnimation(RUNNING);
    } else if (inputManager->isKeyPressed(MOVE_RIGHT)) {
        nodePosition.X += PLAYER_SPEED * this->_frameDeltaTime;
        player->setRotation((core::vector3df){0.f, -90.f, 0.f} - player->getRotateFix());
        player->changeAnimation(RUNNING);
    } else {
        if (player->isRunning()) {
            player->setRotation(player->getRotation() + player->getRotateFix());
            player->changeAnimation(IDLE);
        }
    }
    return nodePosition;
}

Events Game::KeyboardEvents(InputManager *inputManager, IrrlichtDevice *window)
{
    Player *player = this->getPlayerByName("player");
    core::vector3df nodePosition;
    static u32 bombe_activated;

    if (!player)
        return NONE;
    if (inputManager->isKeyPressed(CLOSE))
        return CLOSE;
    nodePosition = PlayerMovements(nodePosition, player, inputManager);
    if (inputManager->isKeyPressed(BOMB)) {
        if (bombe_activated == 0 || window->getTimer()->getTime() - bombe_activated >= 1500) {
            bombe_activated = window->getTimer()->getTime();
            this->_bombObjects.push_back(this->createBombObject("bomb", {"bomb_animated.md3", "bomb.png", {player->getPos()}, {.8, .8, .8}, {0, 20}, 20}, player->getName(), window->getTimer()->getTime()));
        }
    }
    if (nodePosition != player->getPos())
        player->getSceneNode()->setPosition(nodePosition);
    return NONE;
}

void Game::bombHandling(IrrlichtDevice *window)
{
    for (Bomb *obj : this->_bombObjects) {
        obj->setTime(window->getTimer()->getTime());
        if (obj->getTime() >= 2000) {
            auto it = std::find(this->_bombObjects.begin(), this->_bombObjects.end(), obj);
            if (it != this->_bombObjects.end()) { this->_bombObjects.erase(it); }
            delete(obj);
        }
    }
}

Events Game::checkEvents(IrrlichtDevice *window, InputManager *inputManager)
{
    const u32 now = window->getTimer()->getTime();

    this->_frameDeltaTime = (f32)(now - this->_then) / 1000.f;
    this->_then = now;
    bombHandling(window);
    return (KeyboardEvents(inputManager, window));
}