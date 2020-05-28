/*
** EPITECH PROJECT, 2019
** Indie Studio
** File description:
** Generate the map
*/

#include "IndieStudio.hpp"
#include "Irrlicht.hpp"

//void Irrlicht::makeBorderMap(void)
//{
//    float step = 2;
//    float heightBegin = -(MAP_HEIGHT / 2);
//    float heightEnd = MAP_HEIGHT / 2;
//    float widthBegin = -(MAP_WIDTH / 2);
//    float widthEnd = MAP_WIDTH / 2;
//
//    for (float z = heightBegin; z < heightEnd; z+= step) {
//        Object *left = this->createObject("wall", "Square.obj", "Square.jpg");
//        scene::IAnimatedMeshSceneNode *node = left->getSceneNode();
//        node->setPosition({(float) (widthBegin), 0, (float) z});
//        Object *right = this->createObject("wall", "Square.obj", "Square.jpg");
//        node = right->getSceneNode();
//        node->setPosition({(float) (widthEnd), 0, (float) z});
//        if (z == heightBegin || z >= (heightEnd - step)) {
//            for (float x = widthBegin; x < widthEnd; x+= step) {
//                Object *left = this->createObject("wall", "Square.obj", "Square.jpg");
//                scene::IAnimatedMeshSceneNode *node = left->getSceneNode();
//                node->setPosition({(float) (x), 0, (float) z});
//            }
//        }
//    }
//}

bool isBorderNext(vector2f_t pos, vector2f_t height, vector2f_t width, float step, float range)
{
    if ((pos.x <= width.x + range && pos.y >= height.x - range * 2) ||
        (pos.x >= (width.y - step) - range && pos.y >= height.x + range) ||
        (pos.x <= width.x + range && pos.y <= height.y + step + range) ||
        (pos.x >= (width.y - step) - range && pos.y <= height.y + step + range))
        return (true);
    return (false);
}

//void Irrlicht::generateMap(unsigned int seed)
//{
//    float step = 2;
//    srand(seed);
//    std::cout << "Map with seed: " << seed << std::endl;
//    float beginHeight = (MAP_HEIGHT / 2) - step * 2;
//    float beginWidth = -(MAP_WIDTH / 2) + step;
//    float endHeight = -(MAP_HEIGHT / 2);
//    float endWidth = MAP_WIDTH / 2;
//
//    this->makeBorderMap();
//    for (float z = beginHeight; z > endHeight; z -= step) {
//        for (float x = beginWidth; x < endWidth; x += step) {
//            int random = rand() % 4;
//            Object *obj = NULL;
//            if (random == 0 || isBorderNext({x, z}, {beginHeight, endHeight}, {beginWidth, endWidth}, step, 0))
//                continue;
//            else if ((random > 0 && random < 3) || isBorderNext({x, z}, {beginHeight, endHeight}, {beginWidth, endWidth}, step, 2))
//                obj = this->createObject("destructible", "Square.obj", "Destruct.jpg");
//            else
//                obj = this->createObject("wall", "Square.obj", "Square.jpg");
//            scene::IAnimatedMeshSceneNode *node = obj->getSceneNode();
//            node->setPosition({(float) x, 0, (float) z});
//        }
//    }
//}