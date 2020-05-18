/*
** EPITECH PROJECT, 2019
** IndieStudio
** File description:
** Irrlicht display cpp
*/

#include <iostream>
#include "Irrlicht.hpp"

using namespace std;

void Irrlicht::display()
{
    this->_driver->beginScene(true, true, video::SColor(255,100,101,140));
    this->_smgr->drawAll();
    this->_guienv->drawAll();
}