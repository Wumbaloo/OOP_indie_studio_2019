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

Model *Game::createObject(std::string name, std::string model, std::string texture, core::vector3df pos, core::vector3df scale, ObjectType type)
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
    NewObject = new Model(object, name, type);
    return NewObject;
}

Player *Game::createPlayerObject(int nb, std::string name, data_animations_t data, InputManager *im, bool isHuman)
{
    Player *NewObject = NULL;
    scene::IAnimatedMeshSceneNode *object;

    object = createAnimatedModel(data.model, data.texture, data);
    if (!object) {
        std::cout << "Failed to create a model" << std::endl;
        exit(84);
    }
    NewObject = new Player(nb, object, name, im, isHuman);
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

PowerUp *Game::createPowerUpObject(PowerUpsType type, std::string name, data_animations_t data)
{
    PowerUp *NewObject = NULL;
    scene::IAnimatedMeshSceneNode *object;

    object = createAnimatedModel(data.model, data.texture, data);
    if (!object) {
        std::cout << "Failed to create a model" << std::endl;
        exit(84);
    }
    NewObject = new PowerUp(object, name, type);
    return NewObject;
}

void Game::createGameScene(settings_t *settings, InputManager *im)
{
    for (int i = 0; i < settings->types.size(); i++) {
        if (settings->playing.at(i) == true) {
            std::string name = (settings->types.at(i) == AI ? std::string("AI ") : std::string("Player ")) + std::to_string(i + 1);
            irr::core::vector3df pos;

            switch (i + 1) {
                default:
                case 1:
                    pos = {-(MAP_WIDTH) + 2, -1, (MAP_HEIGHT) - 4};
                    break;
                case 2:
                    pos = {(MAP_WIDTH), -1, -(MAP_HEIGHT) - 2};
                    break;
                case 3:
                    pos = {(MAP_WIDTH), -1, (MAP_HEIGHT) - 4};
                    break;
                case 4:
                    pos = {-(MAP_WIDTH) + 2, -1, -(MAP_HEIGHT) - 2};
                    break;
            }
            this->_playerObjects.push_back(this->createPlayerObject(i + 1, name,
                {"guard.md3", std::string("Guard") + std::to_string(i + 1) + std::string(".png"), pos, {0.035, 0.035, 0.035}, {0, 200}, 32.5}, im, settings->types.at(i) == HUMAN));
            this->_playerObjects.at(i)->setOriginalPos(pos);
        }
    }
    this->generateTree({-22, 0, 11});
    this->generateMap(time(nullptr));
}