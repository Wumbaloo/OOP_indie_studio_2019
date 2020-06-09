/*
** EPITECH PROJECT, 2019
** OOP_indieStudio
** File description:
** Map game cpp
*/

#include "IndieStudio.hpp"

bool isACorner(vector3_t pos)
{
    if ((pos.x <= 1 && (pos.z == MAP_HEIGHT || pos.z == 1)) ||
        (pos.x == 0 && (pos.z == MAP_HEIGHT - 1 || pos.z == 2)) ||
        (pos.x >= MAP_WIDTH - 2 && (pos.z == MAP_HEIGHT || pos.z == 1)) ||
        (pos.x == MAP_WIDTH - 1 && (pos.z == MAP_HEIGHT - 1 || pos.z == 2)))
        return (true);
    return (false);
}

void Game::makeBorderMap()
{
    for (int z = 0; z < MAP_HEIGHT + 2; z++) {
        float zPos = z * this->_grid - MAP_HEIGHT - this->_grid * 2;
        Model *left = this->createObject("bound", "Square.obj", "Square.jpg", {(float) (-MAP_WIDTH), 0, zPos}, {1, 1, 1}, OBSTACLE);
        Model *right = this->createObject("bound", "Square.obj", "Square.jpg", {(float) (MAP_WIDTH + this->_grid), 0, zPos}, {1, 1, 1}, OBSTACLE);
        this->_map[z].push_back(left);
        this->_map[z].push_back(right);
        if (z == 0 || z == MAP_HEIGHT + 1) {
            for (float x = 0; x < MAP_WIDTH + 1; x++) {
                Model *wall = this->createObject("bound", "Square.obj", "Square.jpg", {x * this->_grid - MAP_WIDTH, 0, zPos}, {1, 1, 1}, OBSTACLE);
                this->_map[z].push_back(wall);
            }
        }
    }
}

void Game::generateMap(unsigned int seed)
{
    this->_grid = 2;
    srand(seed);
    std::cout << "Map with seed: " << seed << std::endl;
    int i = 1;

    this->makeBorderMap();
    for (int z = MAP_HEIGHT; z > 0; z--) {
        for (int x = 0; x < MAP_WIDTH; x++) {
            int random = rand() % 4;
            Model *obj = NULL;
            core::vector3df pos = {(x + 1) * this->_grid - MAP_WIDTH, 0,
                                    z * this->_grid - MAP_HEIGHT - (this->_grid * 2)};
            if (random == 0 || isACorner({x, 0, z}))
                continue;
            else if ((random > 0 && random < 3))
                obj = this->createObject("destructible", "Cube.obj", "Cube.jpg", pos, {1, 1, 1}, BREAKABLE);
            else
                obj = this->createObject("wall", "Cube.obj", "Square.jpg", pos, {1, 1, 1}, OBSTACLE);
            this->_map[i].push_back(obj);
        }
        i++;
    }
    this->createObject("ground", "ground.obj", "Grass.jpg", {0, -1.25, 0}, {0.01, 0.01, 0.01});
}

void Game::placeInMap(AObject *obj, int x, int y)
{
    // float _x = (-(MAP_WIDTH) + this->_grid) + (x * this->_grid);
    // float _z = -((-(MAP_HEIGHT) + 2 * this->_grid) + (y * this->_grid));
    float _x = (x * 2) - 11;
    float _z = ((y * 2) - 7) * (-1);

    obj->setPos({_x, 0, _z});
}

Model *Game::getObjectFromGame(float x, float z)
{
    for (int i = 0; i < MAP_HEIGHT + 2; i++) {
        for (auto it = this->_map[i].begin(); it != this->_map[i].end(); it++) {
            core::vector3df pos = (*it)->getPos();

            if (pos.getDistanceFrom({x, 0, z}) < 1)
                return ((*it));
        }
    }
    return (NULL);
}

AObject *Game::getObjectFromGame(core::vector3df pos)
{
    return (this->getObjectFromGame((float) pos.X, (float) pos.Z));
}

AObject *Game::getObjectFromMap(int x, int y)
{
    float _x = (-(MAP_WIDTH) + this->_grid) + (x * this->_grid);

    for (auto it = this->_map[y + 1].begin(); it != this->_map[y + 1].end(); it++) {
        core::vector3df pos = (*it)->getPos();

        if (pos.X - _x < 1)
            return ((*it));
    }
    return (NULL);
}

core::vector2df Game::getMapPosition(core::vector3df pos)
{
    // int x = (int) ceil(pos.X + MAP_WIDTH) / this->_grid;
    // int y = -((int) ceil(pos.Z - (MAP_HEIGHT - 2 * this->_grid)) / this->_grid) + 1;
    float x = 0;
    std::cout << pos.X << " / " << pos.Z << endl;
    if ((11 - pos.X) / 2 == 0)
        x = (-11 - pos.X);
    else
        x = ((-11 - pos.X) / 2) * (-1);
    float y = (7 - pos.Z) / 2;

    return {round(x), round(y)};
}

core::vector2df Game::getMapPosition(AObject *object)
{
    core::vector3df pos = object->getPos();

    return (this->getMapPosition(pos));
}
