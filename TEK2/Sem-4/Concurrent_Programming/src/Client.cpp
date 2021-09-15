/*
** EPITECH PROJECT, 2021
** B-CCP-400-MPL-4-1-theplazza-corentin.petrau
** File description:
** Client
*/

#include "../inc/Client.hpp"

Client::Client()
{
    memset(&this->_addr, 0, sizeof(this->_addr));

    this->_fd = socket(AF_UNIX, SOCK_STREAM, 0);
    if (this->_fd <= 0) {
        if (close(this->_fd) == -1)
            throw Exception("Socket called");
    }
    this->_addr.sun_family = AF_UNIX;
    strcpy(this->_addr.sun_path, "Pizzeria");
    this->len = sizeof(this->_addr);
    if (connect(this->_fd, (struct sockaddr *)&this->_addr, (socklen_t)len) < 0)
        throw Exception("connect");
    write(this->_fd, "YES j'écris", 12);
}

Client::~Client()
{}