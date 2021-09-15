/*
** EPITECH PROJECT, 2020
** B-NWP-400-MPL-4-1-myftp-corentin.petrau
** File description:
** server.c
*/

#include "../inc/include.h"

void check_respond(server_t *serv, socket_t *sock, char *buffer, \
            int *client_socket)
{
    for (serv->i = 0; serv->i < serv->max_clients; serv->i++) {
        serv->sd = client_socket[serv->i];
        if (FD_ISSET(serv->sd , &serv->readfds)) {
            if ((serv->valread = read(serv->sd , buffer, 1024)) == 0) {
                close(serv->sd);
                client_socket[serv->i] = 0;
            } else {
                buffer[serv->valread] = '\0';
                handle_client(serv->sd, sock, buffer);
            }
        }
    }
}

void check_accept_sd(socket_t *sock, server_t *serv, int *client_socket)
{
    if (FD_ISSET(sock->sock, &serv->readfds)) {
        if ((serv->new_socket = accept(sock->sock, \
        (struct sockaddr *)&sock->name, (socklen_t *)&serv->addrlen))<0)
            exit(84);
        for (serv->i = 0; serv->i < serv->max_clients; serv->i++) {
            if (client_socket[serv->i] == 0) {
                client_socket[serv->i] = serv->new_socket;
                write(serv->new_socket, "220\r\n", 5);
                sock->log = 1;
                break;
            }
        }
    }
}