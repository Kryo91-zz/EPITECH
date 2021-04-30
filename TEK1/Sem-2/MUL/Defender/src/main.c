/*
** EPITECH PROJECT, 2019
** my_hunter-master
** File description:
** main.c
*/

#include "../include/my.h"

void move_rect(my_defender_t *df, int offset, int max_value)
{
    for (int i = 0; i < df->nb_mob ; i += 1) {
        if (df->mob.mob_sprite[i].rect.left == 1068)
            df->mob.mob_sprite[i].rect.left = 0;
        else
            df->mob.mob_sprite[i].rect.left += 534;
    }
}

int end_this_motherfucker(my_defender_t *df)
{
    sfRenderWindow_destroy(df->window);
    sfMusic_destroy(df->music);
    return (0);
}

int main(int ac, char **av)
{
    my_defender_t *df = malloc(sizeof(my_defender_t));

    create(df);
    sfMusic_play(df->music);
    menu(df);
    if (df->quit)
        return (end_this_motherfucker(df));
    while (sfRenderWindow_isOpen(df->window)) {
        display(df);
        while (sfRenderWindow_pollEvent(df->window, &df->event)) {
            sfVector2i mouse = sfMouse_getPositionRenderWindow(df->window);
            if (df->event.key.code == sfKeyEscape)
                df->pause = 1;
            my_event(df);
        }
    }
    destroy_all(df);
    return (0);
}