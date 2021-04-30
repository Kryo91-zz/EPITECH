/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2019
** File description:
** button_pause.c
*/

#include "../include/my.h"

void back(my_defender_t *df, sfVector2i mouse)
{
    if (mouse.x >= 636 && mouse.x <= 834 && \
        mouse.y >= 321 && mouse.y <= 421) {
            sfRenderWindow_drawSprite(df->window, df->pause_back_s, NULL);
            if (sfMouse_isButtonPressed(sfMouseLeft))
                df->pause = 0;
    }
}

void exit_b(my_defender_t *df, sfVector2i mouse)
{
    if (mouse.x >= 637 && mouse.x <= 837 && \
        mouse.y >= 435 && mouse.y <= 526) {
            sfRenderWindow_drawSprite(df->window, df->pause_retry_s, NULL);
            if (sfMouse_isButtonPressed(sfMouseLeft))
                sfRenderWindow_destroy(df->window);
    }
}

void home_b(my_defender_t *df, sfVector2i mouse)
{
    if (mouse.x >= 641 && mouse.x <= 837 && \
        mouse.y >= 547 && mouse.y <= 638) {
            sfRenderWindow_drawSprite(df->window, df->pause_home_s, NULL);
            if (sfMouse_isButtonPressed(sfMouseLeft)) {
                df->pause = 0;
                for (int i = 0, x = 0; i < df->nb_mob ; i += 1, x -= 80) {
                    df->mob.mob_sprite[i].pos.y = 250;
                    sfSprite_setPosition(df->mob.mob_sprite[i].sprite,
                    (sfVector2f){x, df->mob.mob_sprite[i].pos.y});
                    df->mob.mob_sprite[i].rect.top = 425;
                    df->mob.mob_sprite[i].rect.left = 0;
                    df->mob.mob_sprite[i].rect.width = 534;
                    df->mob.mob_sprite[i].rect.height = 425;
                }
                menu(df);
            }
    }
}

int button_interact(my_defender_t *df)
{
    sfVector2i mouse = sfMouse_getPositionRenderWindow(df->window);

    if (df->pause != 1)
        return (0);

    back(df, mouse);
    exit_b(df, mouse);
    home_b(df, mouse);
}