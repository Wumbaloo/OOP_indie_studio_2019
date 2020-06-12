/*
** EPITECH PROJECT, 2019
** Indie Studio
** File description:
** Our custom input manager
*/

#ifndef INPUT_MANAGER_HPP
#define INPUT_MANAGER_HPP

#include <irrlicht.h>
#include <vector>
#include "Enums.hpp"

typedef struct inputKey_s {
    irr::EKEY_CODE code;
    bool releasedMode;
    bool isDown;
} inputKey_t;

typedef struct input_s {
    std::vector<inputKey_t> codes;
    enum Events event;
} input_t;

class InputManager : public irr::IEventReceiver {
    private:
        std::vector<input_t> _events;

    public:
        InputManager();
        ~InputManager();

        virtual bool OnEvent(const irr::SEvent& event);
        virtual bool IsKeyDown(irr::EKEY_CODE keyCode);

        enum Events getActionByKey(irr::EKEY_CODE keyCode) const;
        input_t getKeyByKeyCode(irr::EKEY_CODE keyCode) const;
        bool isKeyPressed(enum Events event);

        void bindActionToKey(enum Events event, irr::EKEY_CODE keyCode, bool releasedMode = false);
        void bindKeyToAction(irr::EKEY_CODE keyCode, enum Events event);
        void removeKeysAtAction(enum Events event);
        void removeKeyAtAction(irr::EKEY_CODE keyCode, enum Events event);
};

#endif