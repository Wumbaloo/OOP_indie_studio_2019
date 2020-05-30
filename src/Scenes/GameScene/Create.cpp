/*
** EPITECH PROJECT, 2019
** indie studio
** File description:
** create game component cpp
*/

#include "IndieStudio.hpp"

Model *Game::createObject(std::string name, std::string model, std::string texture, core::vector3df pos, core::vector3df scale)
{
    Model *NewObject = NULL;
    scene::IMeshSceneNode *object;

    object = createModel(model, texture);
    object->setPosition(pos);
    object->setScale(scale);
    if (!object) {
        std::cout << "Failed to create a model" << std::endl;
        exit(84);
    }
    NewObject = new Model(object, name);
    return NewObject;
}

scene::IMeshSceneNode *Game::createModel(std::string modelPath, std::string texturePath)
{
    scene::IMesh *mesh;
    scene::IMeshSceneNode *node = NULL;

    mesh = this->_smgr->getMesh(std::string(MODELS_PATH + modelPath).c_str());
    if (!mesh)
        return (NULL);
    node = this->_smgr->addMeshSceneNode(mesh);
    if (node) {
        node->setMaterialFlag(video::EMF_LIGHTING, false);
        node->setMaterialTexture(0, this->_driver->getTexture(std::string(TEXTURES_PATH + texturePath).c_str()));
    }
    return (node);
}

AnimatedModel *Game::createAnimatedObject(std::string name, std::string model, std::string texture, core::vector3df pos, core::vector3df scale)
{
    AnimatedModel *NewObject = NULL;
    scene::IAnimatedMeshSceneNode *object;

    object = createAnimatedModel(model, texture);
    object->setScale(scale);
    object->setPosition(pos);
    if (!object) {
        std::cout << "Failed to create a model" << std::endl;
        exit(84);
    }
    NewObject = new AnimatedModel(100, object, name);
    return NewObject;
}

scene::IAnimatedMeshSceneNode *Game::createAnimatedModel(std::string modelPath, std::string texturePath)
{
    scene::IAnimatedMesh *mesh;
    scene::IAnimatedMeshSceneNode *node = NULL;

    mesh = this->_smgr->getMesh(std::string(MODELS_PATH + modelPath).c_str());
    if (!mesh)
        return (NULL);
    node = this->_smgr->addAnimatedMeshSceneNode(mesh);
    if (node) {
        node->setMaterialFlag(video::EMF_LIGHTING, false);
        node->setMaterialTexture(0, this->_driver->getTexture(std::string(TEXTURES_PATH + texturePath).c_str()));
        node->setFrameLoop(0, 300);
        node->setAnimationSpeed(32.5);
    }
    return (node);
}

void Game::createGameScene(void)
{
    this->_animObjects.push_back(this->createAnimatedObject("player", "guard.md3", "Guard.png",
        (core::vector3df){-(MAP_WIDTH / 2) + 2, 0, (MAP_HEIGHT / 2) - 4}, (core::vector3df){0.05, 0.05, 0.05}));
    this->generateMap(time(nullptr));
}