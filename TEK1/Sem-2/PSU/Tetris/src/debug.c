/*
** EPITECH PROJECT, 2019
** PSU_tetris_2019
** File description:
** debug.c
*/

#include "../inc/my.h"

char *check_chars2(char **opts, option_t *option, int i, char *options)
{
    if (options[i] == 27)
        opts[i] = "^EOD";
    if (options[i] == 25)
        opts[i] = "^EOA";
    if (options[i] == 26)
        opts[i] = "^EOC";
    return (opts[i]);
}

char **check_chars(char **opts, option_t *option)
{
    char options[6] = {option->l, option->r, option->t, option->d\
, option->q, option->p};
    for (int i = 0; i < 6; i += 1) {
        if (options[i] < 90 && options[i] > 65)
            options[i] += 32;
        opts[i] = malloc(sizeof(char) * 4096);
        opts[i][0] = options[i];
        if (options[i] == ' ')
            opts[i] = "(space)";
        if (options[i] == '\t')
            opts[i] = "(tab)";
        if (options[i] == 24)
            opts[i] = "^EOB";
        opts[i] = check_chars2(opts, option, i, options);
    }
    return (opts);
}

void debug_mode(option_t *option)
{
    int key = 0;
    char *next = "Yes";
    char **opts = malloc(sizeof(char *) * 7);
    char *buf = malloc(sizeof(char) * 4096);
    int size = 1;
    opts = check_chars(opts, option);
    if (option->w == 1)
        next = "No";
    my_printf("*** DEBUG MODE ***\n");
    my_printf("Key Left :  %s\n", opts[0]);
    my_printf("Key Right :  %s\n", opts[1]);
    my_printf("Key Turn :  %s\n", opts[2]);
    my_printf("Key Drop :  %s\n", opts[3]);
    my_printf("Key Quit :  %s\n", opts[4]);
    my_printf("Key Pause :  %s\n", opts[5]);
    my_printf("Next :  %s\n", next);
    my_printf("Level :  %d\n", option->L);
    my_printf("Size :  %d*%d\n", option->map_size[0], option->map_size[1]);
    //error_on_tetrimino();
    read_tetri();
    my_printf("Press any key to start Tetris\n");
    while (key <= 0)
        key = read(0, buf, 4096);
}