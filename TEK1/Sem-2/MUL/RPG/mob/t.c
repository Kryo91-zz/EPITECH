/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** t
*/

#include "../include/my_rpg.h"

void init_sprite_attack(glb_t *global)
{
    sfIntRect rect_o;
    sfVector2f vec;

    rect_o.height = 156;
    rect_o.left = 0;
    rect_o.width = 142;
    rect_o.top = 0;
    vec.x = 0.6f;
    vec.y = 0.6f;
    global->attack = sfSprite_create();
    global->a_text = sfTexture_createFromFile("texture/sprite/slash.png", NULL);
    sfSprite_setTexture(global->attack, global->a_text, sfTrue);
    sfSprite_setTextureRect(global->attack, rect_o);
    sfSprite_setScale(global->attack, vec);
}

void do_key(character_t *chara, int i)
{
    if (i == 1) {
        sfSprite_move(chara->sprite, pos(-5, 0));
        chara->position.x -= 5;
        chara->vision = 1;
    } else if (i == 2) {
        sfSprite_move(chara->sprite, pos(5, 0));
        chara->position.x += 5;
        chara->vision = 2;
        anim_right(chara);
    } else if (i == 3) {
        sfSprite_move(chara->sprite, pos(0, 5));
        chara->position.y += 5;
        chara->vision = 3;
        anim_down(chara);
    } else if (i == 4) {
        sfSprite_move(chara->sprite, pos(0, -5));
        chara->position.y -= 5;
        chara->vision = 4;
        anim_up(chara);
    }
}

void moov_chara(character_t *chara, glb_t *global)
{
    chara->old_vision = chara->vision;
    if ((sfKeyboard_isKeyPressed(sfKeyLeft) ||
    sfKeyboard_isKeyPressed(sfKeyQ))) {
            anim_left(chara);
            if (check_coll(global->map,
            global->actual_map, global->chara, 1) == 0)
                do_key(chara, 1);
    }
    if ((sfKeyboard_isKeyPressed(sfKeyRight) ||
    sfKeyboard_isKeyPressed(sfKeyD))) {
            anim_right(chara);
            if (check_coll(global->map,
            global->actual_map, global->chara, 2) == 0)
                do_key(chara, 2);
    }
    if ((sfKeyboard_isKeyPressed(sfKeyDown) ||
    sfKeyboard_isKeyPressed(sfKeyS))) {
            anim_down(chara);
            if (check_coll(global->map,
            global->actual_map, global->chara, 4) == 0)
                do_key(chara, 3);
    }
    if ((sfKeyboard_isKeyPressed(sfKeyUp) ||
    sfKeyboard_isKeyPressed(sfKeyZ))) {
            anim_up(chara);
            if (check_coll(global->map, global->actual_map,
            global->chara, 3) == 0)
                do_key(chara, 4);
    }
}

character_t *init_chara(void)
{
    character_t *chara = malloc(sizeof(character_t));
    sfVector2f scale;
    chara->clock = sfClock_create();
    scale.x = 1.5;
    scale.y = 1.5;
    chara->texture = sfTexture_createFromFile
    ("texture/sprite/main_chara.png", NULL);
    chara->sprite = sfSprite_create();
    chara->rect = rect(0, 323, 27, 32);
    chara->position.x = (3850.0f);
    chara->health = 100;
    chara->dmg = 5;
    chara->dmga = 6;
    chara->dmge = 3;
    chara->dmgs = 1;
    chara->position.y = (1310.0f);
    sfSprite_setTexture(chara->sprite, chara->texture, sfTrue);
    sfSprite_setPosition(chara->sprite, chara->position);
    sfSprite_setTextureRect(chara->sprite, chara->rect);
    sfSprite_setScale(chara->sprite, scale);
    chara->vision = 1;
    chara->anim = 1;
    return (chara);
}

void attack(glb_t *global)
{
    sfTime time;
    sfVector2f pos1 = sfSprite_getPosition(global->chara->sprite);
    sfVector2f pos2;
    sfIntRect rect2;
    float distance = 0;
    if (sfMouse_isButtonPressed(sfMouseLeft) == sfTrue && global->b_att == -1) {
        global->b_att = 0;
        sfClock_restart(global->clock_att);
        sfSprite_setPosition(global->attack,
        get_pos(global->chara, global->attack));
        sfRenderWindow_drawSprite(global->wind.window, global->attack, NULL);
    }
    time = sfClock_getElapsedTime(global->clock_att);
    global->sec_att = time.microseconds/10000.0;
    if (global->b_att >= 0 && global->sec_att >= 7) {
        if (global->b_att == 5) {
            sfSprite_setTextureRect(global->attack, rect(0, 568, 142, 156));
            global->b_att = -2;
        }
        if (global->b_att == 4) {
            sfSprite_setTextureRect(global->attack, rect(0, 426, 142, 156));
            global->b_att = 5;
        }
        if (global->b_att == 3) {
            sfSprite_setTextureRect(global->attack, rect(0, 284, 142, 156));
            global->b_att = 4;
        }
        if (global->b_att == 0) {
            sfSprite_setTextureRect(global->attack, rect(0, 142, 142, 156));
            global->b_att = 3;
        }
        sfClock_restart(global->clock_att);
    } else if (global->b_att == -2 || global->b_att == -1){
        moov_chara(global->chara, global);
    }
    if (global->b_att == -2 && (time.microseconds/10000.0) >= 50)
        global->b_att = -1;
    for (int i = 0; i < 3; i++) {
        rect2 = sfSprite_getTextureRect(global->mob[i].sprite);
        pos2 = sfSprite_getPosition(global->mob[i].sprite);
        if (global->mob[i].vision == 1) {
            pos2.x = pos2.x + rect2.width;
        }
        if (global->chara->vision == 1)
            pos1.x -= 25;
        if (global->chara->vision == 2)
            pos1.x += 35;
        if (global->chara->vision == 4)
            pos1.y -= 20;
        if (global->chara->vision == 3)
            pos1.y += 40;
        if (global->b_att >= 0) {
            distance = v2f_dist(&pos1, &pos2);
        }
        if (distance <= 20 && global->b_att >= 0 &&
        global->mob[i].atta_wolf >= 7) {
            global->mob[i].health -= global->chara->dmg;
            global->mob[i].atta_wolf = 0;
        }
        if (sfKeyboard_isKeyPressed(sfKeyLShift)) {
            global->mob[i].health -= global->chara->dmgs;
            global->mob[i].atta_wolf = 0;
        }
        if (sfKeyboard_isKeyPressed(sfKeyE)) {
            global->mob[i].health -= global->chara->dmge;
            global->mob[i].atta_wolf = 0;
        }
        if (sfKeyboard_isKeyPressed(sfKeyA)) {
            global->mob[i].health -= global->chara->dmga;
            global->mob[i].atta_wolf = 0;
        }
        if (global->mob[i].health <= 0)
            global->minixp += 50;
    }
}