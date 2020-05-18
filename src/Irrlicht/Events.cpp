/*
** EPITECH PROJECT, 2019
** IndieStudio
** File description:
** event Irrlicht cpp
*/

#include <iostream>
#include "Irrlicht.hpp"

using namespace irr;

Events moveEvents(sf::Event event)
{
    // switch (event.key.code) {
    //     case sf::Keyboard::Key::Z:
    //         return MOVE_UP;
    //     case sf::Keyboard::Up:
    //         return MOVE_UP;
    //     case sf::Keyboard::Key::Q:
    //         return MOVE_LEFT;
    //     case sf::Keyboard::Left:
    //         return MOVE_LEFT;
    //     case sf::Keyboard::Key::S:
    //         return MOVE_DOWN;
    //     case sf::Keyboard::Down:
    //         return MOVE_DOWN;
    //     case sf::Keyboard::Key::D:
    //         return MOVE_RIGHT;
    //     case sf::Keyboard::Right:
    //         return MOVE_RIGHT;
    //     default:
    //         break;
    // }
    return NONE;
}

Events KeyboardEvent(sf::Event event)
{
    // switch (event.key.code) {
    //     case sf::Keyboard::Key::X:
    //         return CLOSE;
    //     case sf::Keyboard::Key::R:
    //         return RESTART;
    //     case sf::Keyboard::Key::B:
    //         return BACK_MENU;
    //     case sf::Keyboard::Key::A:
    //         return PREVIOUS_GAME;
    //     case sf::Keyboard::Key::E:
    //         return NEXT_GAME;
    //     default:
    //         break;
    // }
    return moveEvents(event);
}

// Events Irrlicht::clickEvents(sf::Event event)
// {
//     return NONE;
// }

Events Irrlicht::checkEvents(void)
{
    // sf::Event event;

    // if (!this->_window)
    //     return NONE;
    // while (this->_window->pollEvent(event)) {
    //     if (event.type == sf::Event::Closed)
    //         return CLOSE;
    //     if (this->playerIsEnteringName)
    //        return this->handleName(event);
    //     if (event.type == sf::Event::KeyPressed && !this->playerIsEnteringName)
    //         return (KeyboardEvent(event));
    //     if (event.type == sf::Event::MouseButtonPressed)
    //         return (this->clickEvents(event));
    // }
    return NONE;
}