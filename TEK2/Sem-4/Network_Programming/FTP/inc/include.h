/*
** EPITECH PROJECT, 2021
** B-NWP-400-MPL-4-1-myftp-corentin.petrau
** File description:
** include
*/

#ifndef _INCLUDE__
    #define _INCLUDE__


#include <stdio.h>
#include <sys/stat.h>
#include <dirent.h>
#include <stdlib.h>
#include <pwd.h>
#include <grp.h>
#include <time.h>
#include <unistd.h>
#include <getopt.h>
#include <fcntl.h>
#include <string.h>
#include <getopt.h>
#include <stdarg.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <netdb.h>
#include <errno.h>
#include <arpa/inet.h>
#include <sys/time.h>
#include "Exception.hpp"


typedef struct socket_s
{
    int sock;
    struct sockaddr_in name;
    char *path;
    int opt;
    int log;

}socket_t;

typedef struct client_s
{
    int state;
    int sock;
    char *user;
    char *passwd;
    int login;
    char *path;
    int sdata;
}client_t;

typedef struct server_s
{
    int opt;
    int addrlen;
    int new_socket;
    int max_clients;
    int activity;
    int i;
    int valread;
    int sd;
    int max_sd;
    fd_set readfds;
}server_t;

void create_socket(socket_t *sock, char **tab);
void handle_client(int new, socket_t *sock, char *str);
client_t *create_client(client_t *client, int new);
char **my_str_to_word_array(char *str, char *lim);
void which_cmd(char **tab, client_t *client, socket_t *sock);
void check_accept_sd(socket_t *sock, server_t *serv, int *client_socket);
void check_respond(server_t *serv, socket_t *sock, char *buffer, \
            int *client_socket);

#endif