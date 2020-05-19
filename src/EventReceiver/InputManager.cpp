/*
** EPITECH PROJECT, 2019
** Indie Studio
** File description:
** Input Manager source file
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include "InputManager.hpp"

InputManager::InputManager(irr::EKEY_CODE upKey, irr::EKEY_CODE downKey, irr::EKEY_CODE leftKey, irr::EKEY_CODE rightKey)
{
    this->bindActionToKey(MOVE_UP, upKey);
    this->bindActionToKey(MOVE_UP, downKey);
    this->bindActionToKey(MOVE_LEFT, leftKey);
    this->bindActionToKey(MOVE_RIGHT, rightKey);
    // for (irr::u32 i = 0; i < irr::KEY_KEY_CODES_COUNT; ++i) {
    //     this->_events[i].codes.clear();
    //     this->_keys[i].isDown = false;
    //     if (i == forward)
    //         this->_keys[i].event = MOVE_UP;
    //     else if (i == backward)
    //         this->_keys[i].event = MOVE_DOWN;
    //     else if (i == left)
    //         this->_keys[i].event = MOVE_LEFT;
    //     else if (i == right)
    //         this->_keys[i].event = MOVE_RIGHT;
    //     else
    //         this->_keys[i].event = NONE;
    // }
}

InputManager::~InputManager()
{
    for (auto it = this->_events.begin(); it != this->_events.end(); it++)
        (*it).codes.clear();
    this->_events.clear();
    // for (irr::u32 i = 0; i < irr::KEY_KEY_CODES_COUNT; ++i)
    //     this->_keys[i].codes.clear();
}

bool InputManager::OnEvent(const irr::SEvent &event)
{
    if (event.EventType == irr::EET_KEY_INPUT_EVENT) {
        for (auto itEvent = this->_events.begin(); itEvent != this->_events.end(); itEvent++) {
            for (auto it = (*itEvent).codes.begin(); it != (*itEvent).codes.end(); it++) {
                if ((*it).code == event.KeyInput.Key) {
                    (*it).isDown = event.KeyInput.PressedDown;
                    return (false);
                }
            }
        }
    }
    return (false);
}

bool InputManager::IsKeyDown(irr::EKEY_CODE keyCode)
{
    input_t index = this->getKeyByKeyCode(keyCode);

    for (auto it = index.codes.begin(); it != index.codes.end(); it++) {
        if ((*it).code == keyCode)
            return ((*it).isDown);
    }
    return (false);
}

enum Events InputManager::getActionByKey(irr::EKEY_CODE keyCode) const
{
    for (auto itEvents = this->_events.begin(); itEvents != this->_events.end(); itEvents++) {
        for (auto it = (*itEvents).codes.begin(); it != (*itEvents).codes.end(); it++) {
            if ((*it).code == keyCode)
                return ((*itEvents).event);
        }
    }
    return (NONE);
}

input_t InputManager::getKeyByKeyCode(irr::EKEY_CODE keyCode) const
{
    for (auto itEvents = this->_events.begin(); itEvents != this->_events.end(); itEvents++) {
        for (auto it = (*itEvents).codes.begin(); it != (*itEvents).codes.end(); it++) {
            if ((*it).code == keyCode)
                return (*itEvents);
        }
    }
    return (this->_events.front());
}

bool InputManager::isKeyPressed(enum Events event) const
{
    for (auto itEvents = this->_events.begin(); itEvents != this->_events.end(); itEvents++) {
        if ((*itEvents).event != event)
            continue;
        for (auto it = (*itEvents).codes.begin(); it != (*itEvents).codes.end(); it++) {
            if ((*it).isDown)
                return (true);
        }
    }
    return (false);
}

void InputManager::bindActionToKey(enum Events event, irr::EKEY_CODE keyCode)
{
    inputKey_t inputKey;
    input_t input;

    inputKey.code = keyCode;
    inputKey.isDown = false;
    input.codes.push_back(inputKey);
    input.event = event;
    this->_events.push_back(input);
}

void InputManager::bindKeyToAction(irr::EKEY_CODE keyCode, enum Events event)
{
    inputKey_t inputKey;
    inputKey.code = keyCode;
    inputKey.isDown = false;

    for (auto itEvents = this->_events.begin(); itEvents != this->_events.end(); itEvents++) {
        if ((*itEvents).event != event)
            continue;
        (*itEvents).codes.push_back(inputKey);
        return;
    }
    this->bindActionToKey(event, keyCode);
}

void InputManager::removeKeysAtAction(enum Events event)
{
    for (auto itEvents = this->_events.begin(); itEvents != this->_events.end(); itEvents++) {
        if ((*itEvents).event != event)
            continue;
        (*itEvents).codes.clear();
    }
}

void InputManager::removeKeyAtAction(irr::EKEY_CODE keyCode, enum Events event)
{
    for (auto itEvents = this->_events.begin(); itEvents != this->_events.end(); itEvents++) {
        if ((*itEvents).event != event)
            continue;
        for (auto it = (*itEvents).codes.begin(); it != (*itEvents).codes.end(); it++) {
            if ((*it).code == keyCode) {
                (*itEvents).codes.erase(it);
                return;
            }
        }
    }
}