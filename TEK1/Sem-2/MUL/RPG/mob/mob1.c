/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** mob1
*/

#include "../include/my_rpg.h"

int e_attack(character_t *chara, character_t mob)
{
    sfVector2f pos1 = sfSprite_getPosition(chara->sprite);
    sfVector2f pos2;
    sfIntRect rect2;
    float distance = 0;
    rect2 = sfSprite_getTextureRect(mob.sprite);
    pos2 = sfSprite_getPosition(mob.sprite);
    if (mob.vision == 1) {
        pos2.x = pos2.x + rect2.width;
    }
    distance = v2f_dist(&pos1, &pos2);
    if (distance <= 30) {
        chara->health -= 10;
        return (1);
    }
    else
        return (0);
}

void anim_mob_r(character_t *mob, float sec, int nb)
{
    if (sec >= 3) {
        mob[nb].vision = 1;
        if (mob[nb].anim == 5) {
            sfSprite_setTextureRect(mob[nb].sprite, rect(96, 577, 63, 32));
            mob[nb].anim = 0;
            sfClock_restart(mob[nb].clock);
        }
        if (mob[nb].anim == 4) {
            sfSprite_setTextureRect(mob[nb].sprite, rect(97, 512, 63, 31));
            mob[nb].anim = 5;
            sfClock_restart(mob[nb].clock);
        }
        if (mob[nb].anim == 3) {
            sfSprite_setTextureRect(mob[nb].sprite, rect(96, 448, 64, 32));
            mob[nb].anim = 4;
            sfClock_restart(mob[nb].clock);
        }
        if (mob[nb].anim == 2) {
            sfSprite_setTextureRect(mob[nb].sprite, rect(97, 384, 64, 31));
            mob[nb].anim = 3;
            sfClock_restart(mob[nb].clock);
        }
        if (mob[nb].anim == 0)
            mob[nb].anim = 2;
    }
}

void anim_mob_l(character_t *mob, float sec, int nb)
{
    if (sec >= 3) {
        mob[nb].vision = 2;
        if (mob[nb].anim == 5) {
            sfSprite_setTextureRect(mob[nb].sprite, rect(288, 577, 63, 32));
            mob[nb].anim = 0;
            sfClock_restart(mob[nb].clock);
        }
        if (mob[nb].anim == 4) {
            sfSprite_setTextureRect(mob[nb].sprite, rect(289, 512, 63, 31));
            mob[nb].anim = 5;
            sfClock_restart(mob[nb].clock);
        }
        if (mob[nb].anim == 3) {
            sfSprite_setTextureRect(mob[nb].sprite, rect(288, 448, 64, 32));
            mob[nb].anim = 4;
            sfClock_restart(mob[nb].clock);
        }
        if (mob[nb].anim == 2) {
            sfSprite_setTextureRect(mob[nb].sprite, rect(289, 384, 64, 31));
            mob[nb].anim = 3;
            sfClock_restart(mob[nb].clock);
        }
        if (mob[nb].anim == 0)
            mob[nb].anim = 2;
    }
}

void create_mob(glb_t *global)
{
    sfVector2f scale;
    global->mob = malloc(sizeof(character_t) * 3);
    for (int i = 0; i < 3; i++) {
        global->mob[i].clock = sfClock_create();
        scale.x = 1.5;
        scale.y = 1.5;
        global->mob[i].texture = sfTexture_createFromFile
        ("texture/mob/wolf.png", NULL);
        global->mob[i].sprite = sfSprite_create();
        global->mob[i].rect = rect(289, 320, 63, 31);
        global->mob[i].health = 100;
        global->mob[0].position.x = (4200.0f) - 100;
        global->mob[0].position.y = (2800.0f);
        global->mob[1].position.x = (4200.0f) + 400;
        global->mob[1].position.y = (2650.0f);
        global->mob[2].position.x = (4200.0f) + 200;
        global->mob[2].position.y = (2700.0f);
        global->mob[i].anim = 0;
        global->mob[i].vision = 0;
        global->mob[i].atta_wolf = 12;
        global->wolf = sfClock_create();
        global->mob[i].a_wolf = sfClock_create();
        sfSprite_setTexture(global->mob[i].sprite,
        global->mob[i].texture, sfTrue);
        sfSprite_setPosition(global->mob[i].sprite, global->mob[i].position);
        sfSprite_setTextureRect(global->mob[i].sprite, global->mob[i].rect);
        sfSprite_setScale(global->mob[i].sprite, scale);
    }

}

void get_player(character_t *chara, character_t *mob, glb_t *global)
{
    sfVector2f pos1 = sfSprite_getPosition(chara->sprite);
    sfVector2f pos2;
    float sec = 0;

    for (int i = 0; i < 3; i++) {
        if (mob[i].atta_wolf >= 7) {
            mob[i].atta_wolf = 0;
            if (e_attack(chara, mob[i]) == 0) {
                mob[i].atta_wolf = 12;
                global->health = chara->health;
                pos2 = sfSprite_getPosition(mob[i].sprite);
                if (pos1.x > pos2.x)
                    pos2.x += 1;
                else
                    pos2.x -= 1;
                if (pos1.y > pos2.y)
                    pos2.y += 1;
                else
                    pos2.y -= 1;
                if (pos1.x != pos2.x && pos1.y != pos2.y) {
                    mob[i].time = sfClock_getElapsedTime(mob[i].clock);
                    sec = mob[i].time.microseconds/100000;
                    if (pos1.x > pos2.x)
                        anim_mob_r(mob, sec, i);
                    else
                        anim_mob_l(mob, sec, i);
                }
                sfSprite_setPosition(mob[i].sprite, pos2);
                sfClock_restart(mob[i].a_wolf);
            } else {
                mob[i].at_wolf = sfClock_getElapsedTime(mob[i].a_wolf);
                mob[i].atta_wolf = mob[i].at_wolf.microseconds/100000;
                if (mob[i].atta_wolf == 0)
                    mob[i].atta_wolf = 1;
                if (mob[i].atta_wolf >= 7) {
                    mob[i].atta_wolf = 0;
                    sfClock_restart(mob[i].a_wolf);
                }
            }
        } else {
            mob[i].at_wolf = sfClock_getElapsedTime(mob[i].a_wolf);
            mob[i].atta_wolf = mob[i].at_wolf.microseconds/100000;
            if (mob[i].atta_wolf == 0)
                mob[i].atta_wolf = 1;
            if (mob[i].atta_wolf >= 7) {
                sfClock_restart(mob[i].a_wolf);
            }
        }
    }
}