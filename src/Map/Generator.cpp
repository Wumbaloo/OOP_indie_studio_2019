/*
** EPITECH PROJECT, 2019
** Indie Studio
** File description:
** Generate the map
*/

#include "IndieStudio.hpp"
#include "Irrlicht.hpp"

void Irrlicht::makeBorderMap(void)
{
    float step = 2;
    float heightBegin = -(MAP_HEIGHT / 2);
    float heightEnd = MAP_HEIGHT / 2;
    float widthBegin = -(MAP_WIDTH / 2);
    float widthEnd = MAP_WIDTH / 2;

    for (float z = heightBegin; z < heightEnd; z+= step) {
        Object *left = this->createObject("wall", "Square.obj", "Square.jpg");
        scene::IAnimatedMeshSceneNode *node = left->getSceneNode();
        node->setPosition({(float) (widthBegin), 0, (float) z});
        Object *right = this->createObject("wall", "Square.obj", "Square.jpg");
        node = right->getSceneNode();
        node->setPosition({(float) (widthEnd), 0, (float) z});
        if (z == heightBegin || z >= (heightEnd - step)) {
            for (float x = widthBegin; x < widthEnd; x+= step) {
                Object *left = this->createObject("wall", "Square.obj", "Square.jpg");
                scene::IAnimatedMeshSceneNode *node = left->getSceneNode();
                node->setPosition({(float) (x), 0, (float) z});
            }
        }
    }
}

void Irrlicht::generateMap(unsigned int seed)
{
    float step = 2;
    srand(seed);

    this->makeBorderMap();
    // for (float z = -(MAP_HEIGHT / 2); z < MAP_HEIGHT / 2; z += 2) {
    //     for (float x = -(MAP_WIDTH / 2); x < MAP_WIDTH / 2; x += 2) {
    //         Object *wall = this->createObject("wall", "Square.obj", "Square.jpg");
    //         scene::IAnimatedMeshSceneNode *node = wall->getSceneNode();
    //         node->setPosition({(float) x, 0, (float) z});
    //     }
    // }
}