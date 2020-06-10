/*
** EPITECH PROJECT, 2019
** Indie Studio
** File description:
** Movements handling
*/

#include "IndieStudio.hpp"

void Game::movePlayer(Player *player, core::vector2di dir)
{
    core::vector3df nodePosition = player->getPos();
    float speedUp = player->getSpeedUp();
    core::vector3df rotateFix = player->getRotateFix();
    bool wallPass = player->getWallPass();

    if (dir != (core::vector2di) {0, 0})
        player->changeAnimation(RUNNING);
    if (dir.X == 0 && dir.Y == 1 &&
        (checkColision(player, this->_map, UP, wallPass))) {
        nodePosition.Z += PLAYER_SPEED * this->_frameDeltaTime * speedUp;
        player->setRotation((core::vector3df) {0.f, 180.f, .0f} - rotateFix);
    } else if (dir.X == 0 && dir.Y == - 1 && 
        (checkColision(player, this->_map, DOWN, wallPass))) {
        nodePosition.Z -= PLAYER_SPEED * this->_frameDeltaTime * speedUp;
        player->setRotation((core::vector3df) {0.f, 0.f, 0.f} - rotateFix);
    } else if (dir.X == -1 && dir.Y == 0 && 
        (checkColision(player, this->_map, LEFT, wallPass))) {
        nodePosition.X -= PLAYER_SPEED * this->_frameDeltaTime * speedUp;
        player->setRotation((core::vector3df) {0.f, 90.f, 0.f} - rotateFix);
    } else if (dir.X == 1 && dir.Y == 0 && 
        (checkColision(player, this->_map, RIGHT, wallPass))) {
        nodePosition.X += PLAYER_SPEED * this->_frameDeltaTime * speedUp;
        player->setRotation((core::vector3df) {0.f, -90.f, 0.f} - rotateFix);
    } else {
        if (player->isRunning())
            player->changeAnimation(IDLE);
    }
    if (nodePosition != player->getPos())
        player->getSceneNode()->setPosition(nodePosition);
}

Player *getNearestPlayer(std::vector<Player *> players, Player *player)
{
    Player *nearest = NULL;
    f32 nearRange = 0;
    core::vector3df playerPos = player->getPos();

    for (Player *pl : players) {
        if (pl == player)
            continue;
        else if (!nearest ||
            (nearest && pl->getPos().getDistanceFrom(playerPos) < nearRange)) {
            nearest = pl;
            nearRange = pl->getPos().getDistanceFrom(playerPos);
        }
    }
    return (nearest);
}

bool Game::AIGoToNearest(Player *player, core::vector3df nodePosition, core::vector2di mapPos)
{
    Player *nearest = getNearestPlayer(this->_playerObjects, player);

    if (!nearest)
        return (false);
    core::vector2di nearestPos = this->getMapPosition(nearest->getPos());
    core::vector2di nodePos = this->getMapPosition(nodePosition);
    if (nearestPos.getDistanceFrom(nodePos) < 1)
        return (true);
    // std::cout << "Nearest found for " << player->getName() << " at X: " << nodePos.X << "- Y: " << nodePos.Y << std::endl;
    // std::cout << "\tnearest is " << nearest->getName() << " at X: " << nearestPos.X << "- Y: " << nearestPos.Y << std::endl;
    if (nearestPos.Y < nodePos.Y) {
        if (!this->getObjectFromMap(mapPos.X, mapPos.Y - 1))
            movePlayer(player, {0, -1});
        else if (!this->getObjectFromMap(mapPos.X - 1, mapPos.Y))
            movePlayer(player, {-1, 0});
        else if (!this->getObjectFromMap(mapPos.X + 1, mapPos.Y))
            movePlayer(player, {1, 0});
        else
            movePlayer(player, {0, 1});
    } else if (nearestPos.Y > nodePos.Y) {
        if (!this->getObjectFromMap(mapPos.X, mapPos.Y + 1))
            movePlayer(player, {0, 1});
        else if (!this->getObjectFromMap(mapPos.X - 1, mapPos.Y))
            movePlayer(player, {-1, 0});
        else if (!this->getObjectFromMap(mapPos.X + 1, mapPos.Y))
            movePlayer(player, {1, 0});
        else
            movePlayer(player, {0, -1});
    } else if (nearestPos.X < nodePos.X) {
        if (!this->getObjectFromMap(mapPos.X - 1, 0))
            movePlayer(player, {-1, 0});
        else if (!this->getObjectFromMap(mapPos.X, mapPos.Y - 1))
            movePlayer(player, {0, -1});
        else if (!this->getObjectFromMap(mapPos.X, mapPos.Y + 1))
            movePlayer(player, {0, 1});
        else
            movePlayer(player, {-1, 0});
    } else if (nearestPos.X > nodePos.X) {
        if (!this->getObjectFromMap(mapPos.X + 1, 0))
            movePlayer(player, {1, 0});
        else if (!this->getObjectFromMap(mapPos.X, mapPos.Y - 1))
            movePlayer(player, {0, -1});
        else if (!this->getObjectFromMap(mapPos.X, mapPos.Y + 1))
            movePlayer(player, {0, 1});
        else
            movePlayer(player, {1, 0});
    }
    return (false);
}

bool Game::AIMovements(Player *player)
{
    core::vector3df nodePosition = player->getPos();
    core::vector2di mapPos = this->getMapPosition(nodePosition);
    AObject *obj = this->getObjectFromMap(mapPos.X - 1, mapPos.Y);

    if (obj && obj->getType() == BREAKABLE) {
        movePlayer(player, {1, 0});
        return (true);
    }
    obj = this->getObjectFromMap(mapPos.X + 1, mapPos.Y);
    if (obj && obj->getType() == BREAKABLE) {
        movePlayer(player, {1, 0});
        return (true);
    }
    obj = this->getObjectFromMap(mapPos.X, mapPos.Y - 1);
    if (obj && obj->getType() == BREAKABLE) {
        movePlayer(player, {0, 1});
        return (true);
    }
    obj = this->getObjectFromMap(mapPos.X, mapPos.Y + 1);
    if (obj && obj->getType() == BREAKABLE) {
        movePlayer(player, {0, -1});
        return (true);
    }
    if (this->AIGoToNearest(player, nodePosition, mapPos))
        return (true);
    return (false);
}

void Game::PlayerMovements(Player *player, InputManager *inputManager)
{
    if (inputManager->isKeyPressed(player->getUpEvent()))
        movePlayer(player, {0, 1});
    else if (inputManager->isKeyPressed(player->getDownEvent()))
        movePlayer(player, {0, -1});
    else if (inputManager->isKeyPressed(player->getLeftEvent()))
        movePlayer(player, {-1, 0});
    else if (inputManager->isKeyPressed(player->getRightEvent()))
        movePlayer(player, {1, 0});
    else
        movePlayer(player, {0, 0});
}
