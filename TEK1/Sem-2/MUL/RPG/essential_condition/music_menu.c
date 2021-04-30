/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** music_menu.c
*/

#include "../include/my_rpg.h"

int play_music_main_menu(glb_t *global)
{
    global->music_menu.music = sfMusic_createFromFile("texture/music/menu.ogg");
    if (!global->music_menu.music) {
        write(2, "The song is missing!\n", 21);
        return (84);
    }
    sfMusic_play(global->music_menu.music);
    return (0);
}