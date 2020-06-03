/*
** EPITECH PROJECT, 2019
** indie studio
** File description:
** create game component cpp
*/

#include "IndieStudio.hpp"
#include "AnimatedObjects.hpp"

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

scene::IAnimatedMeshSceneNode *Game::createAnimatedModel(std::string modelPath, std::string texturePath, data_animations_t data)
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
        node->setScale(data.scale);
        node->setPosition(data.pos);
        node->setFrameLoop(data.frameLoop.x, data.frameLoop.y);
        node->setAnimationSpeed(data.animationSpeed);
    }
    return (node);
}


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

Player *Game::createPlayerObject(std::string name, data_animations_t data)
{
    Player *NewObject = NULL;
    scene::IAnimatedMeshSceneNode *object;

    object = createAnimatedModel(data.model, data.texture, data);
    if (!object) {
        std::cout << "Failed to create a model" << std::endl;
        exit(84);
    }
    NewObject = new Player(100, object, name);
    return NewObject;
}

Bomb *Game::createBombObject(std::string name, data_animations_t data, std::string launcherName, u32 time)
{
    Bomb *NewObject = NULL;
    scene::IAnimatedMeshSceneNode *object;

    object = createAnimatedModel(data.model, data.texture, data);
    if (!object) {
        std::cout << "Failed to create a model" << std::endl;
        exit(84);
    }
    NewObject = new Bomb(name, object, launcherName, time);
    return NewObject;
}

void Game::createGameScene(void)
{
    this->_playerObjects.push_back(this->createPlayerObject("player", {"guard.md3", "Guard.png",
        {-(MAP_WIDTH / 2) + 2, 0, (MAP_HEIGHT / 2) - 4}, {0.05, 0.05, 0.05}, {0, 200}, 32.5}));
    this->generateMap(time(nullptr));
}