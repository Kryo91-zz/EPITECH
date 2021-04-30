/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** loop_and_tools.c
*/

#include "../include/my_rpg.h"

int rpg_loop(glb_t *global)
{
    appel_of_bool(global);
    call_and_help(global);
    init_sprite(global);
    get_coll(global->map);

    sfRenderWindow_setFramerateLimit(global->wind.window, 60);
    for (int i = 0; i < 100; ++i)
        global->wind.particle[i].living = false;
    sfRenderWindow_setMouseCursorVisible(global->wind.window, sfFalse);
    while (sfRenderWindow_isOpen(global->wind.window)) {
        manage_event(global);
        for (int i = 0; i < 7; i += 1)
            sfSprite_setScale(global->obj[i]->sprite, (sfVector2f){4, 4});
        condition_for_menu(global);
        condition_appel_for_all(global);
    }
    destroy_1(global);
    return (0);
}

void event_echap_close(glb_t *global)
{
    if (global->event.type == sfEvtClosed &&
        sfKeyboard_isKeyPressed(sfKeyEscape)) {
        sfRenderWindow_close(global->wind.window);
    }
}