/*
** EPITECH PROJECT, 2019
** InideStudio
** File description:
** getters Irrlicht cpp
*/

#include <iostream>
#include "Irrlicht.hpp"

using namespace irr;

const string &Irrlicht::getName(void) const
{
    return (this->_name);
}

//Object *Irrlicht::getObjectByName(std::string name) const
//{
//    for (Object *obj : this->_objects) {
//        if (obj->getName() == name)
//            return obj;
//    }
//    return NULL;
//}

IScene *Irrlicht::getScene()
{
    return this->_scenes[this->_status];
}

std::vector<IScene *> Irrlicht::getScenes()
{
    return this->_scenes;
}

InputManager *Irrlicht::getInputManager()
{
    return this->_inputManager;
}
