/*
** EPITECH PROJECT, 2020
** Indie
** File description:
** Created by nicolas,
*/

#include "Scenes.hpp"

void Menu::Music_play() {
    this->_title_music.openFromFile("../assets/Music/Title-music.ogg");
    this->_title_music.setLoop(true);
}

void Game::Music_play() {
    this->_main_music.openFromFile("../assets/Music/Title-music.ogg");
    this->_main_music.setLoop(true);
}

