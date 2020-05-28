/*
** EPITECH PROJECT, 2019
** Arcade
** File description:
** Display Module interface class
*/

#ifndef IDisplayModule_HPP_
#define IDisplayModule_HPP_

#include <iostream>
#include <vector>
#include "Enums.hpp"
#include "Structures.hpp"
#include "Object.hpp"

class IDisplayModule {
    public:
        virtual ~IDisplayModule() = default;

        virtual const std::string &getName(void) const = 0;
        // gameManegement
        virtual bool isWindowOpen(void) const = 0;

        // create
        virtual void createWindow(void) = 0;

        // destroy
        virtual void destroy(void) = 0;
        virtual void close(void) = 0;
};

#endif