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
    float heightBegin = -(MAP_HEIGHT / 2);
    float heightEnd = MAP_HEIGHT / 2;
    float widthBegin = -(MAP_WIDTH / 2);
    float widthEnd = MAP_WIDTH / 2;

    for (float z = heightBegin; z < heightEnd; z+= step) {
        Model *left = this->createModel("wall", "Square.obj", "Square.jpg");
        scene::IMeshSceneNode *node = left->getSceneNode();
        node->setPosition({(float) (widthBegin), 0, (float) z});
        Model *right = this->createModel("wall", "Square.obj", "Square.jpg");
        node = right->getSceneNode();
        node->setPosition({(float) (widthEnd), 0, (float) z});
        if (z == heightBegin || z >= (heightEnd - step)) {
            for (float x = widthBegin; x < widthEnd; x+= step) {
                Model *left = this->createModel("wall", "Square.obj", "Square.jpg");
                scene::IMeshSceneNode *node = left->getSceneNode();
                node->setPosition({(float) (x), 0, (float) z});
            }
        }
    }
}

void Game::generateMap(unsigned int seed)
{
    float step = 2;
    srand(seed);
    std::cout << "Map with seed: " << seed << std::endl;
    float beginHeight = (MAP_HEIGHT / 2) - step * 2;
    float beginWidth = -(MAP_WIDTH / 2) + step;
    float endHeight = -(MAP_HEIGHT / 2);
    float endWidth = MAP_WIDTH / 2;

    this->makeBorderMap();
    for (float z = beginHeight; z > endHeight; z -= step) {
        for (float x = beginWidth; x < endWidth; x += step) {
            int random = rand() % 4;
            Model *obj = NULL;
            if (random == 0 || isBorderNext({x, z}, {beginHeight, endHeight}, {beginWidth, endWidth}, step, 0))
                continue;
            else if ((random > 0 && random < 3) || isBorderNext({x, z}, {beginHeight, endHeight}, {beginWidth, endWidth}, step, 2))
                obj = this->createModel("destructible", "Square.obj", "Destruct.jpg");
            else
                obj = this->createModel("wall", "Square.obj", "Square.jpg");
            scene::IMeshSceneNode *node = obj->getSceneNode();
            node->setPosition({(float) x, 0, (float) z});
        }
    }
}