/*
** EPITECH PROJECT, 2021
** B-CCP-400
** File description:
** Thread
*/

#include "../inc/Thread.hpp"

Thread::Thread(std::thread t)
{
    this->_thread.swap(t);
}

void Thread::join()
{
    this->_thread.join();
}

void Thread::detach()
{
    this->_thread.detach();
}