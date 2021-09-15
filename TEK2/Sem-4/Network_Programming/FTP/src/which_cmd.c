/*
** EPITECH PROJECT, 2020
** B-NWP-400-MPL-4-1-myftp-corentin.petrau
** File description:
** which_cmd.c
*/

#include "../inc/include.h"

void which_cmd4(char **tab, client_t *client, socket_t *sock)
{
    if (strncmp(tab[0], "CWD", 4) == 0) {
        if (tab[1] == NULL)
            write(client->sock, "550\r\n", 5);
        else if (chdir(tab[1]) < 0)
            write(client->sock, "550\r\n", 5);
        else {
            getcwd(sock->path, 4096);
            chdir(tab[1]);
            write(client->sock, "250\r\n", 5);
            sock->path = strdup(tab[1]);
        }
    } else if (strncmp(tab[0], "PWD", 4) == 0) {
        write(client->sock, "257\r\n", 5);
    } else
        write(client->sock, "500\r\n", 5);
}

void which_cmd3(char **tab, client_t *client, socket_t *sock)
{
    if (strncmp(tab[0], "HELP", 4) == 0) {
        printf("List of command :\n*USER <username>\n*PASS <password>\n\
*CWD <pathname>\n*CDUP\n*QUIT\n*DELE\n*PWD\n*PASV\n*PORT <host-port>\n\
*HELP [<string>]\nNOOP\n");
        write(client->sock, "214\r\n", 5);
    } else if (strncmp(tab[0], "CDUP", 4) == 0) {
        getcwd(sock->path, 4096);
        chdir("/home");
        sock->path = strdup("home");
        write(client->sock, "200\r\n", 5);
    } else
        which_cmd4(tab, client, sock);
}

void which_cmd2(char **tab, client_t *client, socket_t *sock)
{
    if (strncmp(tab[0], "QUIT", 4) == 0) {
        write(client->sock, "221\r\n", 5);
        client->login = 0;
    } else if (strncmp(tab[0], "NOOP", 4) == 0) {
        write(client->sock, "200\r\n", 5);
    } else
        which_cmd3(tab, client, sock);
}

void which_cmd(char **tab, client_t *client, socket_t *sock)
{
    if (strncmp(tab[0], "USER", 4) == 0) {
        if (tab[1] == NULL)
            write(client->sock, "530\r\n", 5);
        else {
            write(client->sock, "331\r\n", 5);
            client->user = strdup(tab[1]);
        }
    } else if (strncmp(tab[0], "PASS", 4) == 0) {
        if (client->user == NULL)
            write(client->sock, "530\r\n", 5);
        else if (strncmp(client->user, "Anonymous", 9) == 0)
            write(client->sock, "230\r\n", 5);
        if (strncmp(client->user, "Anonymous", 9) != 0 && \
                strcmp(client->user, tab[1]) != 0)
            write(client->sock, "530\r\n", 5);
        if (strncmp(client->user, "Anonymous", 9) != 0 && \
                strcmp(client->user, tab[1]) == 0)
                write(client->sock, "230\r\n", 5);
    } else
        which_cmd2(tab, client, sock);
}