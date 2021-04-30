/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** loop_and_tools2.c
*/

#include "../include/my_rpg.h"

void display_score(glb_t *global)
{
    sfText_setPosition(global->mymana, get_position(1780, 200));
    sfText_setString(global->mymana, \
    my_score(global->mana));
    sfText_setPosition(global->mylife, get_position(1780, 100));
    sfText_setString(global->mylife, \
    my_score(global->health));
    sfText_setFont(global->mymana, global->font);
    sfText_setColor(global->mymana, sfBlue);
    sfText_setCharacterSize(global->mymana, 50);
    sfRenderWindow_drawText(global->wind.window, global->mymana, NULL);
    sfText_setFont(global->mylife, global->font);
    sfText_setColor(global->mylife, sfRed);
    sfText_setCharacterSize(global->mylife, 50);
    sfRenderWindow_drawText(global->wind.window, global->mylife, NULL);
    sfText_setPosition(global->text, get_position(20, 900));
    sfText_setString(global->text, \
    "   Shift          E               A");
    sfText_setFont(global->text, global->font);
    sfText_setColor(global->text, sfRed);
    sfText_setCharacterSize(global->text, 30);
    sfRenderWindow_drawText(global->wind.window, global->text, NULL);
    sfText_setPosition(global->xp, get_position(1780, 10));
    sfText_setString(global->xp, \
    my_score(global->exp));
    sfText_setCharacterSize(global->xp, 50);
    sfText_setFont(global->xp, global->font);
    sfText_setColor(global->xp, sfGreen);
    sfRenderWindow_drawText(global->wind.window, global->xp, NULL);
    sfText_setPosition(global->text2, get_position(1680, 10));
    sfText_setString(global->text2, \
    "XP :\n\nHeal :\n\nMana :");
    sfText_setFont(global->text2, global->font);
    sfText_setColor(global->text2, sfRed);
    sfText_setCharacterSize(global->text2, 40);
    sfRenderWindow_drawText(global->wind.window, global->text2, NULL);
}

void init_sprite(glb_t *global)
{
    button_retour_main_menu(global);
    button_retour_menu_option(global);
    create_title(global);
    button_play_main_menu(global);
    button_charger_main_menu(global);
    button_quit_main_menu(global);
    button_option_main_menu(global);
    button_aide_main_menu(global);
    background_pause(global);
    background_htp(global);
    button_reprendre_in_pause_menu(global);
    button_quitter_in_pause_menu(global);
    button_sauvegarder_in_pause_menu(global);
    button_option_in_pause_menu(global);
    button_menu_prin_in_pause_menu(global);
    button_plus_create(global);
    button_moins_create(global);
    create_title_option(global);
    init_sprite_attack(global);
    create_game_over(global);
    btn_retour_defeat(global);
    create_mob(global);
    global->chara->position = sfSprite_getPosition(global->chara->sprite);
    global->clock_att = sfClock_create();
    global->sec_att = 0;
    global->b_att = -1;
    global->minixp = 0;
    global->drop = 0;
    global->mymana = sfText_create();
    global->mylife = sfText_create();
    global->text = sfText_create();
    global->xp = sfText_create();
    global->text2 = sfText_create();
    global->textDemon2 = sfText_create();
    global->textDemon = sfText_create();
    global->text_pnj = sfText_create();
    global->font = sfFont_createFromFile("texture/BebasNeue.otf");
    global->actual_map = 0;
}

void call_and_help(glb_t *global)
{
    open_window(global);
    draw_cursor(global);
    background_test(global);
    button_pause_in_game(global);
    tableau_background_parallax(global);
    draw_background_parallax(global);
    hud_sort_feu_create(global);
    hud_sort_foudre_create(global);
    hud_sort_epee_create(global);
    demon1_create(global);
    pnj_base(global);
    inventory_base(global);
    inventory_bague(global);
    inventory_collier(global);
    inventory_sceptre(global);
    draw_obj_bague(global);
    draw_obj_collier(global);
    draw_obj_sceptre(global);
    play_music_main_menu(global);
}

void condition_appel_for_all(glb_t *global)
{
    get_mouse_position(global);
    hitbox_button_pause_in_game(global);
    hitbox_button_sort_feu(global);
    hitbox_button_sort_foudre(global);
    hitbox_button_sort_epee(global);
}

void manage_event(glb_t *global)
{
    manage_event_window(global->wind.window, &global->wind.key);
    manage_key_window(&global->wind, &global->wind.key, global);
    parallax(global);
    time_clock_demon1(global);
    time_clock_demon2(global);
    time_clock_demon3(global);
}