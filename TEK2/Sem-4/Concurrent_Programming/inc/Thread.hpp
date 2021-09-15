/*
** EPITECH PROJECT, 2021
** B-CCP-400
** File description:
** Thread
*/

#pragma once

#include "inc.hpp"

class Thread {
    public:
        Thread(std::thread);
        ~Thread(){};
        void join();
        void detach();

    protected:
    private:
        std::thread _thread;
};