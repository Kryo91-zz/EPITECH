/*
** EPITECH PROJECT, 2020
** B-NWP-400-MPL-4-1-myftp-corentin.petrau
** File description:
** main.c
*/

#include "../inc/include.h"

void check_sd(server_t *serv, int *client_socket)
{
    for (serv->i = 0 ; serv->i < serv->max_clients ; serv->i++) {
        serv->sd = client_socket[serv->i];
        if (serv->sd > 0)
            FD_SET(serv->sd , &serv->readfds);
        if (serv->sd > serv->max_sd)
            serv->max_sd = serv->sd;
    }
    serv->activity = select(serv->max_sd + 1, &serv->readfds, NULL, NULL, NULL);
    if (serv->activity < 0)
        perror("select");
}

void serv_loop(socket_t *sock, server_t *serv)
{
    serv->addrlen = sizeof(sock->name);
    int client_socket[30] = {0};
    char buffer[1025];

    while (1) {
        FD_ZERO(&serv->readfds);
        FD_SET(sock->sock, &serv->readfds);
        serv->max_sd = sock->sock;

        check_sd(serv, client_socket);
        check_accept_sd(sock, serv, client_socket);
        check_respond(serv, sock, buffer, client_socket);
    }
}

void error_handling(int ac, char **tab)
{
    if (ac == 1)
        exit(84);
    if (ac == 2 && !strncmp(tab[1], "-help", 5)) {
        printf("USAGE: ./myftp port path\n\tport is the \
        number on which the server socket listens\n\tpath is \
        the path to the home directory for the Anonymous user\n");
        exit(0);
    }
    if (atoi(tab[1]) == 0)
        exit(84);
    return ;
}

server_t *create_server(server_t *serv)
{
    serv = malloc(sizeof(server_t));
    serv->opt = 1;
    serv->max_clients = 30;
    return (serv);
}

int main(int ac, char **av)
{
    socket_t *sock;
    server_t *serv;

    error_handling(ac, av);
    sock = malloc(sizeof(socket_t));
    serv = create_server(serv);
    sock->opt = 1;
    sock->path = malloc(sizeof(char) * (strlen(av[2]) + 1));
    create_socket(sock, av);
    if (sock->sock == -1)
        exit(84);
    serv_loop(sock, serv);
}