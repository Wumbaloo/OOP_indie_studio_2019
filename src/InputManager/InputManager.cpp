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

using namespace irr;

InputManager::InputManager()
{
    this->bindActionToKey(CLOSE, KEY_DELETE, true);
    this->bindActionToKey(PAUSE, KEY_ESCAPE, true);
    this->bindActionToKey(BACK_MENU, KEY_KEY_B, true);
    this->bindActionToKey(RESTART, KEY_KEY_R, true);
    this->bindActionToKey(SAVE_GAME, KEY_KEY_P, true);
}

InputManager::~InputManager()
{
    for (auto it = this->_events.begin(); it != this->_events.end(); it++)
        (*it).codes.clear();
    this->_events.clear();
}

bool InputManager::OnEvent(const SEvent &event)
{
    if (event.EventType == EET_KEY_INPUT_EVENT) {
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

bool InputManager::IsKeyDown(EKEY_CODE keyCode)
{
    input_t index = this->getKeyByKeyCode(keyCode);

    for (auto it = index.codes.begin(); it != index.codes.end(); it++) {
        if ((*it).code == keyCode)
            return ((*it).isDown);
    }
    return (false);
}

enum Events InputManager::getActionByKey(EKEY_CODE keyCode) const
{
    for (auto itEvents = this->_events.begin(); itEvents != this->_events.end(); itEvents++) {
        for (auto it = (*itEvents).codes.begin(); it != (*itEvents).codes.end(); it++) {
            if ((*it).code == keyCode)
                return ((*itEvents).event);
        }
    }
    return (NONE);
}

input_t InputManager::getKeyByKeyCode(EKEY_CODE keyCode) const
{
    for (auto itEvents = this->_events.begin(); itEvents != this->_events.end(); itEvents++) {
        for (auto it = (*itEvents).codes.begin(); it != (*itEvents).codes.end(); it++) {
            if ((*it).code == keyCode)
                return (*itEvents);
        }
    }
    return (this->_events.front());
}

bool InputManager::isKeyPressed(enum Events event)
{
    for (auto itEvents = this->_events.begin(); itEvents != this->_events.end(); itEvents++) {
        if ((*itEvents).event != event)
            continue;
        for (auto it = (*itEvents).codes.begin(); it != (*itEvents).codes.end(); it++) {
            if ((*it).isDown) {
                (*it).isDown = ((*it).releasedMode ? false : (*it).isDown);
                return (true);
            }
        }
    }
    return (false);
}

void InputManager::bindActionToKey(enum Events event, EKEY_CODE keyCode, bool releasedMode)
{
    inputKey_t inputKey;
    input_t input;

    inputKey.code = keyCode;
    inputKey.releasedMode = releasedMode;
    inputKey.isDown = false;
    input.codes.push_back(inputKey);
    input.event = event;
    this->_events.push_back(input);
}

void InputManager::bindKeyToAction(EKEY_CODE keyCode, enum Events event)
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

void InputManager::removeKeyAtAction(EKEY_CODE keyCode, enum Events event)
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