/*
** EPITECH PROJECT, 2019
** OOP_indieStudio
** File description:
** Map game cpp
*/

#include "IndieStudio.hpp"

bool isBorderNext(vector2f_t pos, vector2f_t height, vector2f_t width, float step, float range)
{
    if ((pos.x <= width.x + range && pos.y >= height.x - range * 2) ||
        (pos.x >= (width.y - step) - range && pos.y >= height.x + range) ||
        (pos.x <= width.x + range && pos.y <= height.y + step + range) ||
        (pos.x >= (width.y - step) - range && pos.y <= height.y + step + range))
        return (true);
    return (false);
}

void Game::makeBorderMap()
{
    float step = 2;
    float heightBegin = -MAP_HEIGHT - step * 2;
    float heightEnd = MAP_HEIGHT;
    float widthBegin = -MAP_WIDTH;
    float widthEnd = MAP_WIDTH;
    int i = 0;

    for (float z = heightBegin; z < heightEnd; z+= step) {
        Model *left = this->createObject("bound", "Square.obj", "Square.jpg", {(float) (widthBegin), 0, (float) z}, {1, 1, 1}, OBSTACLE);
        Model *right = this->createObject("bound", "Square.obj", "Square.jpg", {(float) (widthEnd), 0, (float) z}, {1, 1, 1}, OBSTACLE);
        this->_map[i].push_back(left);
        this->_map[i].push_back(right);
        if (z == heightBegin || z >= (heightEnd - step)) {
            for (float x = widthBegin; x < widthEnd; x+= step) {
                Model *wall = this->createObject("bound", "Square.obj", "Square.jpg", {(float) (x), 0, (float) z}, {1, 1, 1}, OBSTACLE);
                this->_map[i].push_back(wall);
            }
        }
        i++;
    }
}

void Game::generateMap(unsigned int seed)
{
    float step = 2;
    srand(seed);
    std::cout << "Map with seed: " << seed << std::endl;
    float beginHeight = MAP_HEIGHT - step * 2;
    float beginWidth = -MAP_WIDTH + step;
    float endHeight = -MAP_HEIGHT;
    float endWidth = MAP_WIDTH;
    int i = 1;

    this->makeBorderMap();
    for (float z = beginHeight; z >= endHeight - step; z -= step) {
        for (float x = beginWidth; x < endWidth; x += step) {
            int random = rand() % 4;
            Model *obj = NULL;
            if (random == 0 || isBorderNext({x, z}, {beginHeight, endHeight}, {beginWidth, endWidth}, step, 0))
                continue;
            else if ((random > 0 && random < 3) || isBorderNext({x, z}, {beginHeight, endHeight}, {beginWidth, endWidth}, step, 2))
                obj = this->createObject("destructible", "Cube.obj", "Cube.jpg", {(float) x, 0, (float) z}, {1, 1, 1}, BREAKABLE);
            else
                obj = this->createObject("wall", "Cube.obj", "Square.jpg", {(float) x, 0, (float) z}, {1, 1, 1}, OBSTACLE);
            this->_map[i].push_back(obj);
        }
        i++;
    }
    this->createObject("ground", "ground.obj", "Grass.jpg", {0, -1.25, 0}, {0.01, 0.01, 0.01});
    for (int j = 0; j < MAP_HEIGHT + 2; j++) {
        std::cout << "-------------" << j << "---------------" << std::endl;
        for (auto tmp = this->_map[j].begin(); tmp != this->_map[j].end(); tmp++) {
            std::cout << "Item " << (*tmp)->getName() << " + type: " << (*tmp)->getType() << std::endl;
        }
    }
}