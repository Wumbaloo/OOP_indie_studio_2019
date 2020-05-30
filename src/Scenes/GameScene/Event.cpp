/*
** EPITECH PROJECT, 2023
** OOP_indie_studio_2019
** File description:
** game Event cpp,
*/

#include "IndieStudio.hpp"

core::vector3df Game::PlayerMovements(core::vector3df nodePosition, AnimatedModel *player, InputManager *inputManager)
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
    AnimatedModel *player = this->getAnimObjByName("player");
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
            this->_objects.push_back(this->createObject("bomb", "Bomb.3ds", "bomb.png", (core::vector3df){player->getPos()}, (core::vector3df){4, 4, 4}));
        }
    }
    if (nodePosition != player->getPos())
        player->getSceneNode()->setPosition(nodePosition);
    return NONE;
}

Events Game::checkEvents(IrrlichtDevice *window, InputManager *inputManager)
{
    const u32 now = window->getTimer()->getTime();

    this->_frameDeltaTime = (f32)(now - this->_then) / 1000.f;
    this->_then = now;
    return (KeyboardEvents(inputManager, window));
}