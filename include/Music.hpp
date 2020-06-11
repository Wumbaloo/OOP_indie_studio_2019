/*
** EPITECH PROJECT, 2019
** OOP_indie_studio_2019
** File description:
** Music.cpp
*/

#include <irrKlang.h>

class Music
{
    private:
        irrklang::ISoundEngine *_engine;
        irrklang::ISound *_sound;
        irrklang::ISoundSource* _hoverSound;
        irrklang::ISoundSource* _bonusSound;
        irrklang::ISoundSource* _bombSound;
        irrklang::ISoundSource* _deadSound;
        irrklang::ISoundSource* _bombExploSound;
        bool _mute;

    public:
        Music();
        ~Music();

        void playMenuMusic(void);
        void playGameMusic(void);
        void playHoverSound(void);
        void playBonusSound(void);
        void playBombSound(void);
        void playBombExploSound(void);
        void playDeadSound(void);
        void dropSound(void);
        void muteAll(void);
        void demute(void);
        void stopSound(void) const;
        bool isMusicOn(void) const;
};

