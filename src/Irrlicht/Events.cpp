/*
** EPITECH PROJECT, 2019
** IndieStudio
** File description:
** event Irrlicht cpp
*/

#include <iostream>
#include "Irrlicht.hpp"
#include "EventReceiver.hpp"

using namespace irr;

Events Irrlicht::checkEvents(void)
{
    MyEventReceiver receiver;

    if (receiver.IsKeyDown(irr::KEY_KEY_Z))
        exit(84);
    if (this->_inputManager->isKeyPressed(MOVE_UP)) {
        std::cout << "HERE MOVE UP" << std::endl;
    } else if (this->_inputManager->isKeyPressed(MOVE_RIGHT)) {
        std::cout << "HERE MOVE RIGHT" << std::endl;
    } else if (this->_inputManager->isKeyPressed(MOVE_LEFT)) {
        std::cout << "HERE MOVE LEFT" << std::endl;
    }
    return NONE;
}