/*
** EPITECH PROJECT, 2019
** PSU_tetris_2019
** File description:
** desc.c
*/

#include "../inc/my.h"

int desc(char **av)
{
    my_printf("Usage: %s [options]\n\
Options:\n\
--help               Display this help\n\
-L --level={num}     Start Tetris at level num (def: 1)\n\
-l --key-left={K}    Move the tetrimino LEFT using the K key (def: left\
arrow)\n-r --key-right={K}   Move the tetrimino RIGHT using the K key \
(def: right arrow)\n-t --key-turn={K}    TURN the tetrimino clockwise \
90d using the K key (def: toparrow)\n-d --key-drop={K}    DROP the \
tetrimino using the K key (def: down arrow)\n\
-q --key-quit={K}    QUIT the game using the K key (def: ‘q’ key)\n\
-p --key-pause={K}   PAUSE/RESTART the game using the K key (def: space bar)\n\
--map-size={row,col} Set the numbers of rows and columns of the map (def: \
20,10)\n\
-w --without-next    Hide next tetrimino (def: false)\n\
-D --debug           Debug mode (def: false)\n", av[0]);
    return (0);
}

void check_args4(int c, option_t *option)
{
    switch (c) {
    case 'p':
        if (optarg[0] == 0)
            option->p = optarg[1];
        else
            option->p = optarg[0];
        break;
    case 'n':
            option->w = 1;
        break;
    case 'D':
            option->debug = 1;
        break;
    }
}

void check_args3(int c, option_t *option)
{
    switch (c) {
    case 't':
        if (optarg[0] == 0)
            option->t = optarg[1];
        else
            option->t = optarg[0];
        break;
    case 'd':
        if (optarg[0] == 0)
            option->d = optarg[1];
        else
            option->d = optarg[0];
        break;
    case 'q':
        if (optarg[0] == 0)
            option->q = optarg[1];
        else
            option->q = optarg[0];
        break;
    }
}

void check_args2(int c, option_t *option)
{
    switch (c) {
    case 'h':
        option->h = 1;
        break;
    case 'L':
        option->L = my_getnbr(optarg);
        break;
    case 'l':
        if (optarg[0] == 0)
            option->l = optarg[1];
        else
            option->l = optarg[0];
        break;
    case 'r':
        if (optarg[0] == 0)
            option->r = optarg[1];
        else
            option->r = optarg[0];
        break;
    }
}

void check_args(int ac, char **av, option_t *option)
{
    int c = 0;
    int option_index = 0;
    static struct option long_options[] =
    {{"help", 0, 0, 'h'}, {"level", 1, 0, 'L'},
    {"key-left", 1, 0, 'l'}, {"key-right", 1, 0, 'r'},
    {"key-turn", 1, 0, 't'}, {"key-drop", 1, 0, 'd'},
    {"key-quit", 1, 0, 'q'}, {"key-pause", 1, 0, 'p'},
    {"map-size", 1, 0, 'm'}, {"without-next", 0, 0, 'n'},
    {"debug", 0, 0, 'D'}, {0, 0, 0, 0}};

    while (1) {
        c = getopt_long(ac, av, "m:h:L:l:r:t:d:q:p:nD", \
        long_options, &option_index);
        if (c == -1)
            break;
        check_args2(c, option);
        check_args3(c, option);
        check_args4(c, option);
    }
}
