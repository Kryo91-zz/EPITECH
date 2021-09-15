/*
** EPITECH PROJECT, 2020
** B-CPP-300-MPL-3-1-CPPD07M-corentin.petrau
** File description:
** Borg.hpp
*/

#ifndef BORG_HPP_
#define BORG_HPP_

#include <iostream>
#include <fstream>
#include <stdio.h>
#include "WarpSystem.hpp"

namespace Borg
{
    class Ship
    {
        public:
            Ship();
            ~Ship();
            void setupCore(WarpSystem::Core *core);
            void checkCore(void);
            WarpSystem::Core *_core = nullptr;

        private:
            int _side = 300;
            short _maxWarp = 9; 
    };
};

#endif /* !BORG_HPP_ */