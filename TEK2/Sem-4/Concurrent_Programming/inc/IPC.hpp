/*
** EPITECH PROJECT, 2021
** B-CCP-400-MPL-4-1-theplazza-corentin.petrau
** File description:
** IPC
*/

#pragma once

#include "inc.hpp"
#include "Client.hpp"

class IPC {
    public:
        IPC();
        ~IPC(){};
        void prog_socket();
        std::string get_respond();
        int read_on_in();
        int read_kitchen();

    private:
        int _fd;
        struct sockaddr_un _addr;
        int max_sd;
        fd_set readfds;
        int client_socket[30] = {0};
        int max_clients = 30;
        int sd;
        int activity;
        int new_fd = 0;
        int addrlen;
        std::string _order;
        int valread;
        std::string tmp;
        int stin;
};
