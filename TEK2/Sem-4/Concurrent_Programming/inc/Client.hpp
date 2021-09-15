/*
** EPITECH PROJECT, 2021
** B-CCP-400-MPL-4-1-theplazza-corentin.petrau
** File description:
** Client
*/

#pragma once

#include "inc.hpp"

class Client {
    public:
        Client();
        ~Client();

    private:
        int _fd;
        struct sockaddr_un _addr;
        int len;
};
