/*
** EPITECH PROJECT, 2019
** IndieStudio
** File description:
** EventReceiver class from irrlicht doc itself
*/

#ifndef EVENT_RECEIVER_HPP
#define EVENT_RECEIVER_HPP

#include <irrlicht/irrlicht.h>
#include "irrlicht/driverChoice.h"

using namespace irr;


#include <iostream>
class MyEventReceiver : public IEventReceiver {
    private:
        bool KeyIsDown[KEY_KEY_CODES_COUNT];

    public:
        virtual bool OnEvent(const SEvent& event) {
            if (event.EventType == irr::EET_KEY_INPUT_EVENT)
                this->KeyIsDown[event.KeyInput.Key] = event.KeyInput.PressedDown;
            return false;
        }

        virtual bool IsKeyDown(EKEY_CODE keyCode) const {
            return this->KeyIsDown[keyCode];
        }

        MyEventReceiver() {
            for (u32 i = 0; i < KEY_KEY_CODES_COUNT; ++i)
                KeyIsDown[i] = false;
        }
};

#endif