/*
** EPITECH PROJECT, 2020
** B-CPP-300-MPL-3-1-CPPD14A-corentin.petrau
** File description:
** Errors.hpp
*/


#ifndef ERRORS_HPP_
#define ERRORS_HPP_

#include <string>

class NasaError : public std::exception
{
    public:
        NasaError(std::string const &message, std::string const &component = "Unknown");
        virtual ~NasaError() throw();

        const std::string &getComponent() const;
        const std::string &getMessage() const;
        const char *what() const noexcept override {return this->_message.c_str();};
    protected :
        std::string _component;
    private:
        std::string _message;
};

class MissionCriticalError : public NasaError
{
    public:
        MissionCriticalError(std::string const &message, std::string const &component = "Unknown");
        virtual ~MissionCriticalError() throw() { };
};

class LifeCriticalError : public NasaError
{
    public:
        LifeCriticalError(std::string const &message, std::string const &component = "Unknown");
        virtual ~LifeCriticalError() throw() { };
};

class UserError : public NasaError
{
    public:
        UserError(std::string const &message, std::string const &component = "Unknown");
        virtual ~UserError() throw() { };
};

class CommunicationError : public NasaError
{
    public:
        CommunicationError(std::string const &message);
        virtual ~CommunicationError() throw() { };
};

#endif
