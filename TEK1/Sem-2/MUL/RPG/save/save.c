/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** save.c
*/

#include "../include/my_rpg.h"

void load_game(glb_t * global)
{
    int fd = open("save/saver", O_RDONLY);
    char *str = malloc(sizeof(char) * 4096);
    char **info = NULL;
    read(fd, str, 4096);
    info = my_str_to_word_array(str, '\n');
    global->exp = my_getnbr(info[2]);
    global->health = my_getnbr(info[3]);
    global->mana = my_getnbr(info[4]);
    global->drop = my_getnbr(info[5]);
    free(str);
    free(info);
    close(fd);
}

void save_game(glb_t * global)
{
    int fd = open("save/saver", O_WRONLY | O_TRUNC);
    my_put_nbr((global->chara->position.x * 1000), fd);
    write(fd, "\n", 1);
    my_put_nbr((global->chara->position.y * 1000), fd);
    write(fd, "\n", 1);
    my_put_nbr(global->exp, fd);
    write(fd, "\n", 1);
    my_put_nbr(global->health, fd);
    write(fd, "\n", 1);
    my_put_nbr(global->mana, fd);
    write(fd, "\n", 1);
    my_put_nbr(global->drop, fd);
    write(fd, "\n", 1);
    close(fd);
}