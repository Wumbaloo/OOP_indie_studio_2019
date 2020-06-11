/*
** EPITECH PROJECT, 2020
** Indie
** File description:
** Created by nicolas,
*/

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
    this->_hoverSound = this->_engine->addSoundSourceFromFile("../assets/Music/sound_effect/menu.ogg");
    if (!_hoverSound)
        error("Failed to open hover sound", 84);
    this->_hoverSound->setDefaultVolume(.1);
    this->_bonusSound = this->_engine->addSoundSourceFromFile("../assets/Music/sound_effect/bonus.ogg");
    if (!_bonusSound)
        error("Failed to open bonus sound", 84);
    this->_bonusSound->setDefaultVolume(.1);
    this->_bombSound = this->_engine->addSoundSourceFromFile("../assets/Music/sound_effect/place_bomb.ogg");
    if (!_bombSound)
        error("Failed to open bomb sound", 84);
    this->_bombSound->setDefaultVolume(.2);
    this->_deadSound = this->_engine->addSoundSourceFromFile("../assets/Music/sound_effect/dead.ogg");
    if (!_deadSound)
        error("Failed to open dead sound", 84);
    this->_deadSound->setDefaultVolume(.05);
    this->_bombExploSound = this->_engine->addSoundSourceFromFile("../assets/Music/sound_effect/explosion.ogg");
    if (!_bombExploSound)
        error("Failed to open explosion sound", 84);
    this->_bombExploSound->setDefaultVolume(.2);
    this->_mute = false;
}

Music::~Music()
{
    this->_engine->drop();
}

void Music::playMenuMusic(void)
{
    if (this->_mute)
        return;
    this->_sound = this->_engine->play2D("../assets/Music/Title-music.ogg", true, false, true);
    if (!_sound)
        error("Failed to open play menu song", 84);
    this->_sound->setVolume(.1);
}

void Music::playGameMusic(void)
{
    if (this->_mute)
        return;
    this->_sound = this->_engine->play2D("../assets/Music/Battle-music.ogg", true, false, true);
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