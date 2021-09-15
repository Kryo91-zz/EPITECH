/*
** EPITECH PROJECT, 2021
** B-CCP-400
** File description:
** Process
*/

#pragma once
#include "inc.hpp"

class Process {
    public:
        Process();
        ~Process(){};
        const pid_t &getPid() const;
        void wait();
    protected:
    private:
        pid_t _pid;
};
