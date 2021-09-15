/*
** EPITECH PROJECT, 2021
** B-CCP-400
** File description:
** Mutex
*/

#pragma once
#include "inc.hpp"

class Mutex {
    public :
        Mutex();
        ~Mutex(){};
        void lock();
        void unlock();
        void trylock();
    private :
        std::mutex _mutex;
};
