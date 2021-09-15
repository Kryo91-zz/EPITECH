/*
** EPITECH PROJECT, 2021
** 1
** File description:
** IPC
*/

#include "../inc/IPC.hpp"
#include "../inc/Reception.hpp"

IPC::IPC()
{
    this->addrlen = 0;
    memset(&this->_addr, 0, sizeof(this->_addr));

    this->_fd = socket(AF_UNIX, SOCK_STREAM, 0);
    if (this->_fd <= 0) {
        if (close(this->_fd) == -1)
            throw Exception("Socket called");
    }
    this->_addr.sun_family = AF_UNIX;
    strcpy(this->_addr.sun_path, "Pizzeria");
    if (bind(this->_fd, (struct sockaddr *) &this->_addr, SUN_LEN(&this->_addr)) < 0) {
        if (close(this->_fd) == -1)
            throw Exception("Binding Socket");
    }
    if (listen(this->_fd, 30) == -1) {
        if (close(this->_fd) == -1)
            throw Exception("Listen");
    }
}

void IPC::prog_socket()
{
    timeval t;
    t.tv_sec = 0;
    t.tv_usec = 0;
    FD_ZERO(&this->readfds);
    FD_SET(this->_fd, &this->readfds);
    FD_SET(0, &this->readfds);
    this->max_sd = this->_fd;
    for (int i = 0 ; i < this->max_clients ; i++) {
        this->sd = client_socket[i];
        if (this->sd > 0)
            FD_SET(this->sd, &this->readfds);
        if (this->sd > this->max_sd)
            this->max_sd = this->sd;
    }
    this->activity = select(this->max_sd + 1, &this->readfds, NULL, NULL, &t);
    if (this->activity < 0)
        throw Exception("select");
}

int IPC::read_on_in()
{
    std::cout << "Please put your order here : ";
    getline(std::cin, this->tmp);
    this->stin = 1;
    return (0);
}

int IPC::read_kitchen()
{
    if (this->_fd > 0) {
        if (this->new_fd == 0) {
            if ((this->new_fd = accept(this->_fd, (struct sockaddr *)&this->_addr, (socklen_t *)&this->addrlen))<0) {
                throw Exception("accept");
            }
        }
        for (int i = 0; i < this->max_clients; i++) {
            if (this->client_socket[i] == 0) {
                this->client_socket[i] = this->new_fd;
                this->stin = 0;
                break;
            }
        }
        return (1);
    }
    return (2);
}

std::string IPC::get_respond()
{
    char buffer[4096] = {0};
    for (int i = 0; i < this->max_clients; i++) {
        this->sd = this->client_socket[i];
        if (this->stin == 1) {
            this->_order = tmp;
            tmp = "";
            this->stin = 0;
            return this->_order;
        }
        if (this->sd > 0) {
            if ((this->valread = read(this->sd, buffer, 4096)) == 0) {
                close(this->sd);
                client_socket[i] = 0;
            } else {
                buffer[this->valread] = '\0';
                this->_order = buffer;
                client_socket[i] = 0;
            }
        }
    }
    return this->_order;
}