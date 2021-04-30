/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** open_window.c
*/

#include "../include/my_rpg.h"

int open_window(glb_t *global)
{
    global->wind.mode.width = 1920;
    global->wind.mode.height = 1080;
    global->wind.mode.bitsPerPixel = 32;
    global->wind.window = malloc(sizeof(sfRenderWindow *));
    global->wind.window = sfRenderWindow_create
    (global->wind.mode, "La Legende d'Isidore", sfResize | sfClose, NULL);
    if (!global->wind.window) {
        write(2, "Screen doesn't work!\n", 23);
        return (84);
    }
    return (0);
}