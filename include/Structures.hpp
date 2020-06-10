/*
** EPITECH PROJECT, 2019
** arcade
** File description:
** structure hpp
*/

#ifndef STRUCTURE_HPP
#define STRUCTURE_HPP

#include <iostream>
#include <vector>
#include <irrlicht/irrlicht.h>
#include <SFML/Audio/Music.hpp>
#include "Enums.hpp"

using namespace std;

typedef struct vector3_s
{
    int x;
    int y;
    int z;
} vector3_t;

typedef struct vector2f_s
{
    float x;
    float y;
} vector2f_t;

typedef struct data_animations_s
{
    std::string model;
    std::string texture;
    irr::core::vector3df pos;
    irr::core::vector3df scale;
    vector2f_t frameLoop;
    float animationSpeed;
} data_animations_t;

typedef struct music_s
{
    sf::Music _title_music;
    sf::Music _main_music;
    sf::Music _bomb;
} music_t;

typedef struct settings_s
{
    int nbrPlayers = 4;
    std::vector<PlayerType> types = {HUMAN, AI, AI, AI};
    std::vector<std::wstring> names = {L"Human", L"BotOne", L"BotTwo", L"BotThree"};
    std::vector<bool> playing = {true, true, true, true};
    bool isMuted = false;
    bool loadFile = false;
    int winnerIdx;
} settings_t;

#endif