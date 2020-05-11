/*
** EPITECH PROJECT, 2019
** indie_studio
** File description:
** main.c
*/

#include <SFML/Audio.h>
#include <boost/lambda/lambda.hpp>
#include <irrlicht.h>
#include "indie_studio.hpp"

// using namespace irr;
// using namespace core;
// using namespace scene;
// using namespace video;
// using namespace io;
// using namespace gui;


int main()
{
    irr::IrrlichtDevice *device =
        irr::createDevice( irr::video::EDT_SOFTWARE,
                            irr::core::dimension2d<irr::u32>(1920, 1080), 16,
                            false, false, false, 0);
    if (!device)
        return 1;
    device->setWindowCaption(L"Hello World! - Irrlicht Engine Demo");
    irr::video::IVideoDriver* driver = device->getVideoDriver();
    irr::scene::ISceneManager* smgr = device->getSceneManager();
    irr::gui::IGUIEnvironment* guienv = device->getGUIEnvironment();
    guienv->addStaticText(L"Hello World! This is the Irrlicht Software renderer!",
                irr::core::rect<irr::s32>(10,10,260,22), true);
     while(device->run()) {
        driver->beginScene(true, true, irr::video::SColor(255,100,101,140));
        smgr->drawAll();
        guienv->drawAll();
        driver->endScene();
    }
    device->drop();
    return 0;
}
