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

using namespace irr;

typedef struct inputKey_s {
    EKEY_CODE code;
    bool releasedMode;
    bool isDown;
} inputKey_t;

typedef struct input_s {
    std::vector<inputKey_t> codes;
    enum Events event;
} input_t;

class InputManager : public IEventReceiver {
    private:
        std::vector<input_t> _events;

    public:
        InputManager();
        ~InputManager();

        virtual bool OnEvent(const SEvent& event);
        virtual bool IsKeyDown(EKEY_CODE keyCode);

        enum Events getActionByKey(EKEY_CODE keyCode) const;
        input_t getKeyByKeyCode(EKEY_CODE keyCode) const;
        bool isKeyPressed(enum Events event);

        void bindActionToKey(enum Events event, EKEY_CODE keyCode, bool releasedMode = false);
        void bindKeyToAction(EKEY_CODE keyCode, enum Events event);
        void removeKeysAtAction(enum Events event);
        void removeKeyAtAction(EKEY_CODE keyCode, enum Events event);
};

#endif