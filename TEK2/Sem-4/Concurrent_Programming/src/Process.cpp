/*
** EPITECH PROJECT, 2021
** B-CCP-400
** File description:
** Process
*/

#include "../inc/Process.hpp"

Process::Process()
{
    _pid = fork();
    if (_pid < 0) {
        throw Exception("fork failed.");
    }
}

const pid_t &Process::getPid() const {
    return _pid;
}

void Process::wait()
{
    int status;
    waitpid(-1, &status, 0);
}