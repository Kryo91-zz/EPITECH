/*
** EPITECH PROJECT, 2020
** B-NWP-400-MPL-4-1-myftp-corentin.petrau
** File description:
** client_respond.c
*/

#include "../inc/include.h"

client_t *create_client(client_t *client, int new)
{
    client = malloc(sizeof(client_t));
    client->sock = new;
    client->login = 1;
    client->user = NULL;
    client->passwd = NULL;
    client->state = 0;
    return (client);
}

void handle_client(int new, socket_t *sock, char *str)
{
    client_t *client;
    char **tab;

    client = create_client(client, new);
    while (client->login == 1) {
        tab = my_str_to_word_array(str, " \r\n");
        if (!tab[0])
            break;
        if (sock->log == 0) {
            write(client->sock, "530\r\n", 5);
            break;
        }
        which_cmd(tab, client, sock);
        bzero(str, 1024);
        read(client->sock, str, 1024);
    }
}