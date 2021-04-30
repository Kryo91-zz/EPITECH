/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** _test.c
*/

#include "../include/my_rpg.h"

int background_test(glb_t *global)
{
    sfVector2f scale;
    scale.x = 1;
    scale.y = 1;
    global->test.texture = sfTexture_createFromFile
    ("./Antoine/mapfinale.png", NULL);
    if (!global->test.texture) {
        write(2, "The testound is missing!\n", 27);
        return (84);
    }
    global->test.sprite = sfSprite_create();
    sfSprite_setScale(global->test.sprite, scale);
    sfSprite_setTexture(global->test.sprite, global->test.texture, sfTrue);
    return (0);
}