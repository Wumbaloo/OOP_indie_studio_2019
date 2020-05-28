/*
** EPITECH PROJECT, 2019
** arcade
** File description:
** enum
*/

#ifndef ENUM_HPP
#define ENUM_HPP

enum Events
{
    NONE,
    CLOSE,
    PLAY,
    BACK_MENU,
    RESTART,
    MOVE_UP,
    MOVE_DOWN,
    MOVE_LEFT,
    MOVE_RIGHT,
    END_GAME,
};

enum GameStatus {
    MENU,
    GAME,
    UNKNOWN
};

enum ObjectType {
    NOTYPE,
    OBSTACLE,
    CONSUMABLE,
    ENEMY,
    PLAYER,
};

enum Direction {
    LEFT,
    UP,
    DOWN,
    RIGHT,
};

enum EndStatus {
    NOTHING,
    WIN,
    LOSE,
};

#endif