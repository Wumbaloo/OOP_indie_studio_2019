/*
** EPITECH PROJECT, 2020
** Indie
** File description:
** Created by nicolas,
*/

#include <iostream>
#include <string>
#include "Structures.hpp"
#include "Scenes.hpp"

void error(std::string msg, int value)
{
    std::cout << msg << std::endl;
    exit(value);
}


Music::Music()
{
    this->_engine = irrklang::createIrrKlangDevice();
    if (!this->_engine)
        error("Failed to create engine", 84);
    this->_hoverSound = this->createSourceSound("./assets/Music/sound_effect/menu.ogg", .1);
    this->_bonusSound = this->createSourceSound("./assets/Music/sound_effect/bonus.ogg", .1);
    this->_bombSound = this->createSourceSound("./assets/Music/sound_effect/place_bomb.ogg", .2);
    this->_deadSound = this->createSourceSound("./assets/Music/sound_effect/dead.ogg", .05);
    this->_bombExploSound = this->createSourceSound("./assets/Music/sound_effect/explosion.ogg", .2);
    this->_winSound = this->createSourceSound("./assets/Music/sound_effect/win.ogg", .3);
    this->_mute = false;
}

Music::~Music()
{
    this->_engine->drop();
}

irrklang::ISoundSource *Music::createSourceSound(std::string path, float volume)
{
    irrklang::ISoundSource *snd = NULL;

    snd = this->_engine->addSoundSourceFromFile(path.c_str());
    if (!snd)
        error("Failed to open a source sound", 84);
    snd->setDefaultVolume(volume);
    return (snd);
}

void Music::playMenuMusic(void)
{
    if (this->_mute)
        return;
    this->_sound = this->_engine->play2D("./assets/Music/Title-music.ogg", true, false, true);
    if (!_sound)
        error("Failed to open play menu song", 84);
    this->_sound->setVolume(.1);
}

void Music::playGameMusic(void)
{
    if (this->_mute)
        return;
    this->_sound = this->_engine->play2D("./assets/Music/Battle-music.ogg", true, false, true);
    if (!_sound)
        error("Failed to open play game song", 84);
    this->_sound->setVolume(.05);
}

void Music::playHoverSound(void)
{
    if (this->_mute)
        return;
    this->_engine->play2D(this->_hoverSound);
}

void Music::playDeadSound(void)
{
    if (this->_mute)
        return;
    this->_engine->play2D(this->_deadSound);
}

void Music::playBombExploSound(void)
{
    if (this->_mute)
        return;
    this->_engine->play2D(this->_bombExploSound);
}

void Music::playBonusSound(void)
{
    if (this->_mute)
        return;
    this->_engine->play2D(this->_bonusSound);
}

void Music::playBombSound(void)
{
    if (this->_mute)
        return;
    this->_engine->play2D(this->_bombSound);
}

void Music::playWinSound(void)
{
    if (this->_mute)
        return;
    this->_engine->play2D(this->_winSound);
}

void Music::muteAll()
{
    this->_mute = true;
    if (this->_sound)
        this->_sound->setIsPaused(true);
    this->_hoverSound->setDefaultVolume(0);
    this->_bonusSound->setDefaultVolume(0);
    this->_bombSound->setDefaultVolume(0);
    this->_deadSound->setDefaultVolume(0);
    this->_bombExploSound->setDefaultVolume(0);
}

void Music::demute()
{
    this->_mute = false;
    if (this->_sound)
        this->_sound->setIsPaused(false);
     this->_hoverSound->setDefaultVolume(.1);
    this->_bonusSound->setDefaultVolume(.1);
    this->_bombSound->setDefaultVolume(.2);
    this->_deadSound->setDefaultVolume(.05);
    this->_bombExploSound->setDefaultVolume(.2);
}

void Music::stopSound(void) const
{
    if (this->_sound && !this->_sound->getIsPaused())
        this->_sound->stop();
}

void Music::dropSound(void)
{
    if (this->_mute)
        return;
    this->stopSound();
    this->_sound->drop();
    this->_sound = 0;
}

bool Music::isMusicOn(void) const
{
    if (this->_sound && !this->_sound->isFinished())
        return true;
    return false;
}

void Music::manageVolume(float volume)
{
    this->_engine->setSoundVolume(0 + (volume / 100));
}
