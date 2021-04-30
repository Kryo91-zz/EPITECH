/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** draw_all.c
*/

#include "../include/my_rpg.h"

void draw_textdemon(glb_t *global)
{
    static int n = 0;

    if (global->chara->position.x < global->demon1.position.x + 300 && \
    global->chara->position.x > global->demon1.position.x && \
    global->chara->position.y < global->demon1.position.y + 300 && \
    global->chara->position.y > global->demon1.position.y && n == 0) {
        sfText_setPosition(global->textDemon, get_position(1030, 1700));
        sfText_setString(global->textDemon, \
        "TU AS TROUVE MON BIEN ! (press space)");
        sfText_setFont(global->textDemon, global->font);
        sfText_setColor(global->textDemon, sfWhite);
        sfText_setCharacterSize(global->textDemon, 30);
        sfRenderWindow_drawText(global->wind.window, global->textDemon, NULL);
        if (sfKeyboard_isKeyPressed(sfKeySpace))
            n += 1;
    } else if (n == 1) {
        sfText_setPosition(global->textDemon2, get_position(1030, 1700));
        sfText_setString(global->textDemon2, \
        "Retrouve les 2 autres reliques d'isidores\net rapportes les moi pour devenir Immortels\net maitre du monde avec mon pouvoir !\n(press B)");
        sfText_setFont(global->textDemon2, global->font);
        sfText_setColor(global->textDemon2, sfWhite);
        sfText_setCharacterSize(global->textDemon2, 30);
        sfRenderWindow_drawText(global->wind.window, global->textDemon2, NULL);
        if (sfKeyboard_isKeyPressed(sfKeyB))
            n = 2;
    } else if (n == 2) {
        sfText_setPosition(global->textDemon, get_position(1030, 1700));
        sfText_setString(global->textDemon, \
        "J'eu ouie dire que mon collier se trouvais dans le labyrinthe des fees !");
        sfText_setFont(global->textDemon, global->font);
        sfText_setColor(global->textDemon, sfWhite);
        sfText_setCharacterSize(global->textDemon, 30);
        sfRenderWindow_drawText(global->wind.window, global->textDemon, NULL);
    }
}

void particule(glb_t *global)
{
    for (size_t index = 0; index != 100; index++)
            update_particle(global->wind.particle_environment, \
            &global->wind.particle[index]);
    for (size_t index = 0; index != 100; index++)
        display_particle(global->wind.window, &global->wind.particle[index], \
        global->wind.particle_environment->circle_shape);
}

void draw_inventory(glb_t *global)
{
    if (global->drop == 0) {
        sfRenderWindow_drawSprite(global->wind.window,
        global->inventory_base.sprite, NULL);
    }
    if (global->drop == 1) {
        sfRenderWindow_drawSprite(global->wind.window,
        global->inventory_1.sprite, NULL);
    }
    if (global->drop == 2) {
        sfRenderWindow_drawSprite(global->wind.window,
        global->inventory_2.sprite, NULL);
    }
    if (global->drop == 3) {
        sfRenderWindow_drawSprite(global->wind.window,
        global->inventory_3.sprite, NULL);
    }
}

void draw_2(glb_t *global)
{
    sfRenderWindow_drawSprite(global->wind.window,
    global->hud_sort_feu.sprite, NULL);
    sfRenderWindow_drawSprite(global->wind.window,
    global->hud_sort_foudre.sprite, NULL);
    sfRenderWindow_drawSprite(global->wind.window,
    global->hud_sort_epee.sprite, NULL);
    sfRenderWindow_drawSprite(global->wind.window, global->pause.sprite, NULL);
    sfRenderWindow_drawSprite(global->wind.window, global->cursor.sprite, NULL);
    draw_inventory(global);
    attack(global);
    if (global->b_att >= 0)
        sfRenderWindow_drawSprite(global->wind.window, global->attack, NULL);
    display_score(global);
    particule(global);
    if (sfKeyboard_isKeyPressed(sfKeyEscape) == 1)
        global->bool_menu_pause = 1;
    sfRenderWindow_display(global->wind.window);
}

void draw_1(glb_t *global)
{
    sfRenderWindow_clear(global->wind.window, sfBlack);
    sfRenderWindow_drawSprite(global->wind.window, global->test.sprite, NULL);
    if (global->drop == 0) {
        sfRenderWindow_drawSprite(global->wind.window,
        global->pnj.sprite, NULL);
        draw_text_pnj(global);
    } else if (global->drop == 1) {
        sfRenderWindow_drawSprite(global->wind.window,
        global->demon1.sprite, NULL);
        draw_textdemon(global);
    } else if (global->drop == 2) {
        sfRenderWindow_drawSprite(global->wind.window,
        global->demon2.sprite, NULL);
        draw_textdemon2(global);
    } else if (global->drop == 3) {
        sfRenderWindow_drawSprite(global->wind.window,
        global->demon3.sprite, NULL);
        draw_textdemon3(global);
    }
    global->chara->health = global->health;
    if (global->drop == 2)
        get_player(global->chara, global->mob, global);
    for (int i = 0; i < 3; i++) {
        if (global->mob[i].health > 0 && global->drop == 2 &&
        sfSprite_getPosition(global->chara->sprite).x > 3600) {
            sfRenderWindow_drawSprite(global->wind.window,
            global->mob[i].sprite, NULL);
            global->vec = sfSprite_getPosition(global->mob[i].sprite);
        }
        else if (sfSprite_getPosition(global->chara->sprite).x < 3600) {
            for (int i = 0; i < 3; i++) {
                global->mob[0].position.x = 4430;
                global->mob[0].position.y = 2800.0;
                global->mob[1].position.x = 4800;
                global->mob[1].position.y = 2650.0;
                global->mob[2].position.x = 5150;
                global->mob[2].position.y = 2700.0;
                sfSprite_setPosition(global->mob[i].sprite,
                global->mob[i].position);
            }
        }
    }
    sfRenderWindow_drawSprite(global->wind.window, global->chara->sprite, NULL);
    make_functionnal_inventory(global);
    if (global->mob[0].health <= 0 && global->mob[1].health <= 0
    && global->mob[2].health <= 0 && global->drop == 2) {
        sfSprite_setPosition(global->sceptre.sprite, pos(4500, 2800));
        sfRenderWindow_drawSprite(global->wind.window,
        global->sceptre.sprite, NULL);
    } else
        sfSprite_setPosition(global->sceptre.sprite, pos(0, 0));
}