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
    float _x = (-(MAP_WIDTH) + this->_grid) + (x * this->_grid);
    float _z = ((MAP_HEIGHT) - 2 * this->_grid) + (-y * this->_grid);

    obj->setPos({_x, 0, _z});
}