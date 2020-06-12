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
        irrklang::ISoundEngine *_engine = NULL;
        irrklang::ISound *_sound = NULL;
        irrklang::ISoundSource* _hoverSound = NULL;
        irrklang::ISoundSource* _bonusSound = NULL;
        irrklang::ISoundSource* _bombSound = NULL;
        irrklang::ISoundSource* _deadSound = NULL;
        irrklang::ISoundSource* _bombExploSound = NULL;
        irrklang::ISoundSource* _winSound = NULL;
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
        void playWinSound(void);
        void dropSound(void);
        void muteAll(void);
        void demute(void);
        void stopSound(void) const;
        bool isMusicOn(void) const;
};

