/*
** EPITECH PROJECT, 2021
** B-CCP-400
** File description:
** Mutex
*/

#include "../inc/Mutex.hpp"

Mutex::Mutex()
{
}

void Mutex::lock()
{
    this->_mutex.lock();
}

void Mutex::unlock()
{
    this->_mutex.unlock();
}

void Mutex::trylock()
{
    this->_mutex.try_lock();
}