/*
** EPITECH PROJECT, 2019
** my_hunter-master
** File description:
** utilities.h
*/

#ifndef UTILITIES_H
#define UTILITIES_H

#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <time.h>
#include <pwd.h>
#include <grp.h>
#include <dirent.h>
#include <sys/sysmacros.h>
#include <signal.h>
#include <sys/wait.h>
#include <math.h>

typedef struct rect_tower4_s
{
    sfIntRect rect;
} rect_tower4_t;

typedef struct rect_tower3_s
{
    sfIntRect rect;
} rect_tower3_t;

typedef struct rect_tower2_s
{
    sfIntRect rect;
} rect_tower2_t;

typedef struct rect_s
{
    sfIntRect rect;
} rect_t;

typedef struct mob_sprite_s
{
    sfTexture *texture;
    sfSprite *sprite;
    sfClock *clock;
    sfVector2f pos;
    sfVector2f size;
    sfTime time;
    sfIntRect rect;
    float seconds;
    int life;
} mob_sprite_t;

typedef struct mob_s
{
    int *mob;
    int size;
    int boole;
    mob_sprite_t *mob_sprite;
} mob_t;

typedef struct my_menu_s {
    sfTexture *texture_logo;
    sfSprite *s_logo;
    sfTexture *texture_menu;
    sfSprite *s_menu;
    sfSprite *s_play_button;
    sfTexture *texture_play_button;
    sfSprite *s_play_button2;
    sfTexture *texture_play_button2;
    sfSprite *s_exit_button;
    sfTexture *texture_exit_button;
    sfSprite *s_exit_button2;
    sfTexture *texture_exit_button2;
} my_menu_t;

typedef struct my_defender_s {
    rect_t rect_tower;
    rect_tower2_t rect_tower2;
    rect_tower3_t rect_tower3;
    rect_tower4_t rect_tower4;
    mob_t mob;
    my_menu_t menu;
    sfRenderWindow *window;
    sfSound *button;
    sfSoundBuffer *button_b;
    sfSound *death;
    sfSoundBuffer *death_b;
    sfTexture *texture_bg;
    sfSprite *s_how;
    sfTexture *t_how;
    sfSprite *s_p;
    sfTexture *t_p;
    sfSprite *background;
    sfSprite *duck;
    sfSprite *s_inventory;
    sfTexture * t_inventory;
    sfSprite *s_pause;
    sfTexture * t_pause;
    sfSprite *s_tower;
    sfSprite *s_tower2;
    sfSprite *s_tower3;
    sfSprite *s_tower4;
    sfTexture *t_tower;
    sfSprite *s_mob;
    sfTexture *t_mob;
    sfVector2f position;
    sfVector2f t1;
    sfMusic *music;
    sfClock *clock;
    sfClock *money_clock;
    sfClock *t1_clock;
    sfVideoMode video_mode;
    sfIntRect rect;
    sfTexture *pause_back_t;
    sfSprite *pause_back_s;
    sfTexture *pause_retry_t;
    sfSprite *pause_retry_s;
    sfTexture *pause_home_t;
    sfSprite *pause_home_s;
    sfTime time;
    sfTime time2;
    sfTime t1_time;
    sfVector2f mouse;
    sfVector2i mouse_pos;
    sfEvent event;
    int my_life;
    float frame;
    int bole;
    int nb_mob;
    int quit;
    int offset;
    int max_value;
    float seconde;
    float seconde2;
    float t1_seconde;
    float x_speed;
    float x_speed2;
    float t1_x_speed;
    int x;
    int y;
    int bo;
    int tower1;
    int tower2;
    int tower3;
    int tower4;
    int pause;
    int money;
    int my_score;
    int actnb_mob;

} my_defender_t;

// Functions of lib:

void my_putchar(char c);
int my_putstr(char const *str);
int my_strcmp(char const *s1, char const *s2);
int my_len(char const *str);
char *my_score(int nbr);
void report_error(char *str);

// Functions of my_create.c:

void my_create_sprite_music(my_defender_t *df);
void my_create_window(my_defender_t *df);
void my_create_rect(my_defender_t *df);
void create(my_defender_t *df);
void my_rand(int min, int max);

//Functions of my_hunter.c:

void rand_axis_y(my_defender_t *df);
void clock1(my_defender_t *df);
void display(my_defender_t *df);
void duck_unpop(my_defender_t *df);
void my_event(my_defender_t *df);

//Functions of main.c :

void my_scope(my_defender_t *df);
void move_rect(my_defender_t *df, int offset, int max_value);
void documentation(void);
int end_this_motherfucker(my_defender_t *df);
int main(int ac, char **av);

//menu.c
void menu(my_defender_t *df);
sfVector2f get_position(int x, int y);
void exit_button_in_game(my_defender_t *df);
int click(my_defender_t *df, int x, int y);
int event(my_defender_t *df);

//button_in_menu.c
void set_button_in_menu(my_defender_t *df);
void set_button_texture_in_menu(my_defender_t *df);
void button_color_change_in_menu(my_defender_t *df);

//button_in_game.c
void set_button_in_game(my_defender_t *df);
void set_button_texture_in_game(my_defender_t *df);
void button_color_change_in_game(my_defender_t *df);
int button_interact(my_defender_t *df);

void path_handling_map(my_defender_t *df);
void inventory_draw(my_defender_t *df);
int create_mob(my_defender_t *df);
void inventory_opener(my_defender_t *df);

void place_tower2(my_defender_t *df);
void place_tower3(my_defender_t *df);
void place_tower4(my_defender_t *df);

void sold(my_defender_t *df);
float get_distance(float x, float y, sfVector2f p2);
void shoot_tower1(my_defender_t *df);
void shoot_tower1_lv2(my_defender_t *df);
void shoot_tower1_lv3(my_defender_t *df);
void shoot_tower1_lv4(my_defender_t *df);

void shoot_tower2(my_defender_t *df);
void shoot_tower2_lv2(my_defender_t *df);
void shoot_tower2_lv3(my_defender_t *df);
void shoot_tower2_lv4(my_defender_t *df);

void shoot_tower3(my_defender_t *df);
void shoot_tower3_lv2(my_defender_t *df);
void shoot_tower3_lv3(my_defender_t *df);
void shoot_tower3_lv4(my_defender_t *df);

void shoot_tower4(my_defender_t *df);
void shoot_tower4_lv2(my_defender_t *df);
void shoot_tower4_lv3(my_defender_t *df);
void shoot_tower4_lv4(my_defender_t *df);

void set_pos_kill(my_defender_t *df, int i);
void create_rect_bis(my_defender_t *df);
void create_bis(my_defender_t *df);

void clock1(my_defender_t *df);
void emplacement_choose_bis2(my_defender_t *df);
void place_tower1(my_defender_t *df);
void destroy_all(my_defender_t *df);
void my_ceate_bis2(my_defender_t *df);
float get_distance(float x, float y, sfVector2f p2);

#endif
