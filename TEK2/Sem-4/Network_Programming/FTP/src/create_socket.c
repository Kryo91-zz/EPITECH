/*
** EPITECH PROJECT, 2020
** B-NWP-400-MPL-4-1-myftp-corentin.petrau
** File description:
** create_socket.c
*/

#include "../inc/include.h"

void create_socket(socket_t *sock, char **tab)
{
    sock->sock = socket(AF_INET, SOCK_STREAM, 0);
    sock->log = 0;
    if (sock->sock == -1)
        exit(84);
    if (setsockopt(sock->sock, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, \
        (char *)&sock->opt, sizeof(sock->opt)) < 0 )
        exit(84);
    sock->path = tab[2];
    sock->name.sin_port = htons(atoi(tab[1]));
    sock->name.sin_family = AF_INET;
    sock->name.sin_addr.s_addr = INADDR_ANY;

    if (bind(sock->sock, (struct sockaddr *) &sock->name, \
        sizeof(sock->name)) < 0)
        exit(84);
    if (listen(sock->sock, 30) < 0) {
        if (close(sock->sock) == -1)
        exit(84);
    }
}