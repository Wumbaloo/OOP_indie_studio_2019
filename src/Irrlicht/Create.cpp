/*
** EPITECH PROJECT, 2019
** InideStudio
** File description:
** create Irrlicht object cpp
*/

#include <iostream>
#include <string>
#include "Irrlicht.hpp"

using namespace irr;

void Irrlicht::createWindow(void)
{
    this->_window = createDevice(video::EDT_SOFTWARE,
            core::dimension2d<u32>(1920, 1080), 16,
            false, false, false, 0);
    if (!this->_window) {
        std::cout << "Failed to create window" << std::endl;
        exit(84);
    } else if (this->_inputManager)
        this->_window->setEventReceiver(this->_inputManager);
    this->_window->setWindowCaption(L"Bomberman - Indie Studio");
}