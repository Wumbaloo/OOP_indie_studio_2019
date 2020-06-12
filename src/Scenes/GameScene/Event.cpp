/*
** EPITECH PROJECT, 2023
** OOP_indie_studio_2019
** File description:
** game Event cpp,
*/

#include <algorithm>
#include "IndieStudio.hpp"

bool Game::checkColision(AnimatedModel *object, std::vector<Model *> wall[], Direction dir, bool IsWallPass)
{
    for (int y = 0; y < MAP_HEIGHT + 2; y++) {
        for (Model *wall : this->_map[y]) {
            switch (dir) {
                case UP:
                    if ((object->getPos().Z + 2.1 >= wall->getPos().Z && object->getPos().Z < wall->getPos().Z + 1.1)
                        && (object->getPos().X + .5 >= wall->getBoundingPos().MinEdge.X && object->getPos().X + .5 <= wall->getBoundingPos().MaxEdge.X)) {
                        if ((IsWallPass && wall->getType() == BREAKABLE))
                            return true;
                        else
                            return false;
                    }
                    break;
                case DOWN:
                    if ((object->getPos().Z - 2.1 <= wall->getPos().Z && object->getPos().Z > wall->getPos().Z + 1.1)
                        && (object->getPos().X >= wall->getBoundingPos().MinEdge.X && object->getPos().X <= wall->getBoundingPos().MaxEdge.X)) {
                        if ((IsWallPass && wall->getType() == BREAKABLE))
                            return true;
                        else
                            return false;
                    }
                    break;
                case LEFT:
                    if ((object->getPos().X - 2.1 <= wall->getPos().X && object->getPos().X > wall->getPos().X + 1.1)
                        && (object->getPos().Z >= wall->getBoundingPos().MinEdge.Z && object->getPos().Z <= wall->getBoundingPos().MaxEdge.Z)) {
                        if ((IsWallPass && wall->getType() == BREAKABLE))
                            return true;
                        else
                            return false;
                    }
                    break;
                case RIGHT:
                    if ((object->getPos().X + 2.1 >= wall->getPos().X && object->getPos().X < wall->getPos().X + 1.1)
                        && (object->getPos().Z >= wall->getBoundingPos().MinEdge.Z && object->getPos().Z <= wall->getBoundingPos().MaxEdge.Z)) {
                        if ((IsWallPass && wall->getType() == BREAKABLE))
                            return true;
                        else
                            return false;
                    }
                    break;
                default:
                    break;
            };
        }
    }
    return true;
}

void Game::PlayerEvents(InputManager *inputManager, IrrlichtDevice *window)
{
    for (auto player = this->_playerObjects.begin(); player != this->_playerObjects.end(); player++) {
        this->CheckPowerUpsColision((*player), window);
        this->BombHandling(window, inputManager, (*player));
        if (!(*player))
            continue;
        if ((*player)->isHuman())
            this->PlayerMovements((*player), inputManager);
        else {
            if (this->AIMovements((*player))) {
                if (getNbBombByOwner((*player)->getName()) < (*player)->getBombUp()) {
                    this->_bombObjects.push_back(
                        this->createBombObject("bomb", {"bomb_animated.md3", "bomb.png",
                        {(*player)->getPos()}, {.8, .8, .8}, {0, 20}, 20}, (*player)->getName(), window->getTimer()->getTime()));
                    this->_music->playBombSound();
                }
            }
        }
    }
}

Events Game::KeyboardEvents(InputManager *inputManager, IrrlichtDevice *window)
{
    if (inputManager->isKeyPressed(SAVE_GAME)) {
        this->destroy();
        return SAVE_GAME;
    }
    if (inputManager->isKeyPressed(CLOSE)) {
        this->_music->dropSound();
        delete(this->_music);
        this->destroy();
        return CLOSE;
    }
    if (inputManager->isKeyPressed(RESTART)) {
        this->destroy();
        return RESTART;
    }
    if (inputManager->isKeyPressed(PAUSE)) {
        // this->_paused = !this->_paused;
    }
    if (this->_paused)
        return NONE;
    if (inputManager->isKeyPressed(BACK_MENU)) {
        this->_music->stopSound();
        this->destroy();
        return BACK_MENU;
    }
    this->PlayerEvents(inputManager, window);
    return NONE;
}

Events Game::checkEvents(IrrlichtDevice *window, InputManager *inputManager, settings_t *settings)
{
    const u32 now = window->getTimer()->getTime();

    this->_frameDeltaTime = (f32)(now - this->_then) / 1000.f;
    this->_then = now;
    if (this->_winner != -1) {
        settings->winnerIdx = this->_winner;
        this->destroy();
        return GO_WIN;
    }
    return (KeyboardEvents(inputManager, window));
}