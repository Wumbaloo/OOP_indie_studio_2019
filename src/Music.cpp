/*
** EPITECH PROJECT, 2020
** Indie
** File description:
** Created by nicolas,
*/

#include "Structures.hpp"
#include "Scenes.hpp"


void Menu::Title_music(music_t *_musics) {
    _musics->_title_music.openFromFile("../assets/Music/Title-music.ogg");
    _musics->_title_music.setVolume(30);
    _musics->_title_music.setLoop(true);
}


void Menu::Main_music(music_t *_musics) {
    _musics->_main_music.openFromFile("../assets/Music/Battle-music.ogg");
    _musics->_main_music.setVolume(30);
    _musics->_main_music.setLoop(true);
}

void Menu::Hover_sound_effect(music_t *_musics) {
    _musics->_bomb.openFromFile("../assets/Music/sound_effect/menu.ogg");
    _musics->_bomb.setVolume(100);
}

void Menu::Bonus_sound_effect(music_t *_musics) {
    _musics->_bonus.openFromFile("../assets/Music/sound_effect/bonus.ogg");
    _musics->_bonus.setVolume(100);
}

