/*
** EPITECH PROJECT, 2019
** IndieStudio
** File description:
** Main loop game file
*/

#include "IndieStudio.hpp"

Events checkTransition(Irrlicht *lib)
{
    switch (lib->getScene()->checkEvents(lib->getWindow(), lib->getInputManager(), lib->getSettings())) {
        case PLAY:
            lib->changeGameStatus(GAME);
            break;
        case BACK_MENU:
            lib->changeGameStatus(MENU);
            break;
        case TO_SETTINGS:
            lib->changeGameStatus(SETTINGS);
            break;
        case RESTART:
            break;
        case CLOSE:
            return CLOSE;
        default:
            return NONE;
    }
    lib->getScene()->resetScene(lib->getWindow(), lib->getSettings(), lib->getInputManager());
    return NONE;
}

int GameManager(Irrlicht *lib)
{
    lib->createWindow();
    lib->addScene(new Menu(lib->getWindow()));
    lib->addScene(new Game(lib->getWindow()));
    lib->addScene(new Settings(lib->getWindow()));
    lib->changeGameStatus(MENU);
    lib->getScene()->resetScene(lib->getWindow(), lib->getSettings(), lib->getInputManager());
    while(lib->isWindowOpen()) {
        lib->getScene()->display();
        lib->getScene()->refreshWindow();
        if (checkTransition(lib) == CLOSE)
            break;
    }
    lib->destroy();
    lib->close();
    return 0;
}