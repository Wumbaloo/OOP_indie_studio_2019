/*
** EPITECH PROJECT, 2020
** Indie
** File description:
** Created by nicolas,
*/

#include "Structures.hpp"
#include "Scenes.hpp"


int Menu::Title_music(music_t *_musics) {
    _musics->_title_music.openFromFile("../assets/Music/Title-music.ogg");
    _musics->_title_music.setVolume(50);
    _musics->_title_music.setLoop(true);
    return (1);
}


int Game::Main_music(music_t *_musics) {
    _musics->_main_music.openFromFile("../assets/Music/Battle-music.ogg");
    _musics->_main_music.setVolume(50);
    _musics->_main_music.setLoop(true);
    return (1);
}

void Menu::Hover_sound_effect(music_t *_musics) {
    _musics->_bomb.openFromFile("../assets/Music/sound_effect/sound_effect_5.ogg");
    _musics->_bomb.setVolume(100);
}

