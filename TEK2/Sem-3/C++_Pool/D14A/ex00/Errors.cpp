/*
** EPITECH PROJECT, 2020
** B-CPP-300-MPL-3-1-CPPD14A-corentin.petrau
** File description:
** Errors.cpp
*/

#include "Errors.hpp"

NasaError::NasaError(const std::string &message, const std::string &component) :
    _message(message), _component(component) { }

NasaError::~NasaError() throw() { }

const std::string &NasaError::getComponent() const
{
    return this->_component;
}

const std::string &NasaError::getMessage() const
{
    return this->_message;
}


MissionCriticalError::MissionCriticalError(std::string const &message, std::string const &component) :
        NasaError(message, component) { }

LifeCriticalError::LifeCriticalError(std::string const &message, std::string const &component) :
        NasaError(message, component) { }

UserError::UserError(std::string const &message, std::string const &component) :
        NasaError(message, component) { }

CommunicationError::CommunicationError(std::string const &message) :
        NasaError(message, "CommunicationDevice") { }