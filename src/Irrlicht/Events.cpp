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
    return NONE;
}