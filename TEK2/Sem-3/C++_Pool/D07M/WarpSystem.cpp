/*
** EPITECH PROJECT, 2020
** ex00
** File description:
** WarpSystem.cpp
*/

#include "WarpSystem.hpp"

WarpSystem::QuantumReactor::QuantumReactor()
{
    this->_stability = true;
}

WarpSystem::QuantumReactor::~QuantumReactor() {}

WarpSystem::QuantumReactor *WarpSystem::Core::checkReactor(void)
{
    return (this->_coreReactor);
}

WarpSystem::Core::Core(WarpSystem::QuantumReactor *coreReactor):
    _coreReactor(coreReactor)
{ }

WarpSystem::Core::~Core() {}

bool WarpSystem::QuantumReactor::isStable(void)
{
    return(this->_stability);
}

void WarpSystem::QuantumReactor::setStability(bool stability)
{
    this->_stability = stability;
}