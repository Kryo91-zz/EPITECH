/*
** EPITECH PROJECT, 2019
** HUNTER
** File description:
** .h
*/

#ifndef hunter_
#define hunter_

#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <SFML/Graphics/Color.h>
#include <SFML/Graphics/Rect.h>
#include <SFML/System.h>
#include <SFML/System/Clock.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

struct game {
    int score;
    int miss;
    int step;
    int best_score;
    struct bird *bird;
    struct bird *bird2;
    struct bird *bird3;
    struct bird *bird4;
    sfVector2f mouse;
    sfSprite *play;
    sfSprite *aim;
    sfSprite *sprite;
    sfSprite *lvl;
    sfSprite *hard;
    sfSprite *hard2;
    sfSprite *sprite2;
    sfSprite *sprite3;
    sfSprite *sprite4;
    sfSprite *dog;
    sfSprite *game_over;
    sfSprite *try_again;
    sfSprite *leave;
    sfSprite *leave2;
    sfSprite *info;
    sfSprite *info2;
    sfSprite *play2;
    sfSprite *luc;
    sfSprite *luc2;
    sfSprite *sim;
    sfSprite *sim2;
    sfSprite *bap;
    sfSprite *bap2;
    sfText *best_score_text;
    sfText *best_score_field;
    sfText *score_field;
    sfText *title;
    sfText *score_text;
    sfText *miss_text;
    sfText *speed_text;
    sfFont *font_julietta;
    sfFont *font_debas;
};

struct bird {
    sfSprite *sprite;
    sfSprite *sprite2;
    sfSprite *sprite3;
    sfSprite *sprite4;
    sfVector2f pos;
    int move_length;
    int order;
    int skin_index;
    double speed;
};


void exit_game(sfEvent event, sfRenderWindow *window);

void elim(sfTexture *texture_pack, sfRenderWindow* window, sfMusic *music);
int description_and_error(int ac, char **av);


sfSprite *get_sprite(sfTexture* texture);
sfIntRect get_rect(int top, int left, int width, int height);
sfVector2f get_position(int x, int y);
struct game *get_game_instance(void);
struct bird *get_bird_instance(void);


int rand_line_height(void);
sfIntRect get_rect_bird_skin(struct game *game_instance);
void make_bird_move(struct game *game_instance);
void spawn_new_bird(struct game *game_instance);
void bird_miss(struct game *game_instance);


int my_put_nbr(int nb);
void my_putchar(char c);
void my_putstr(char const *str);


void report_error(char *str);
void manage_speed(struct game *game_instance);
void manage_score(struct game *game_instance);
char *my_score(int nbr);
int number_digits(int nbr);


void window_draw(sfRenderWindow *window, struct game *game_instance,
                sfEvent event);
void window_draw_start(sfRenderWindow *window, struct game *game_instance,
                        sfEvent event);
void window_draw_game(sfRenderWindow *window, struct game *game_instance);
void window_draw_end(sfRenderWindow *window, struct game *game_instance,
                        sfEvent event);
void window_draw_info(sfRenderWindow *window, struct game *game_instance,
                        sfEvent event);
void window_draw_lvl(sfRenderWindow *window, struct game *game_instance,
                        sfEvent event);


void manage_window_events(sfEvent event, struct game *game_instance,
                            sfRenderWindow *window);
int start_event(sfEvent event, struct game *game_instance);
void game_event(sfEvent event, struct game *game_instance);
void end_event(sfEvent event, struct game *game_instance,
                sfRenderWindow *window);
void game_event_info(sfEvent event, struct game *game_instance);
void game_event_game(sfEvent event, struct game *game_instance);

void load_other(struct game *game_instance);
void load_main_text(struct game *game_instance);
void load_game_text(struct game *game_instance);
void load_end_text(struct game *game_instance);
void load_sprites(struct game *game_instance);
void load_sprites2(struct game *game_instance);


void run_window_with_sprite(sfRenderWindow *window, sfEvent event,
    sfSprite *sprite, sfMusic *music);
void run_window_mouse_event(sfEvent event, struct game *game_instance,
                            sfRenderWindow *window);
void run_window_anim(sfClock *anim_clock, struct game *game_instance);
void run_window_draw(sfRenderWindow *window, struct game *game_instance,
                        sfEvent event);

void window_draw_gamelvl3(sfRenderWindow *window, struct game *game_instance);
void window_draw_gamelvl2(sfRenderWindow *window, struct game *game_instance);
void window_draw_gamelvl1(sfRenderWindow *window, struct game *game_instance);
void window_draw_lvl2(sfRenderWindow *window, struct game *game_instance,
                        sfEvent event);
void make_bird_move_lvl1(struct game *game_instance);
void manage_speed_lvl1(struct game *game_instance);
void game_event_lvl1(sfEvent event, struct game *game_instance);
void bird_miss_lvl1(struct game *game_instance);
void spawn_new_bird_lvl1(struct game *game_instance);
void manage_score_lvl1(struct game *game_instance);
void game_event_lvl2(sfEvent event, struct game *game_instance);
void game_event_lvl3(sfEvent event, struct game *game_instance);
void make_bird_move_lvl3(struct game *game_instance);
void spawn_new_bird_lvl3(struct game *game_instance);
void bird_miss_lvl3(struct game *game_instance);
void manage_speed_lvl3(struct game *game_instance);
void manage_score_lvl3(struct game *game_instance);
void make_bird_move_lvl2(struct game *game_instance);
void spawn_new_bird_lvl2(struct game *game_instance);
void bird_miss_lvl2(struct game *game_instance);
void manage_speed_lvl2(struct game *game_instance);
void manage_score_lvl2(struct game *game_instance);
void manage_window_events2(sfEvent event, struct game *game_instance);
void window_draw_end2(sfRenderWindow *window, struct game *game_instance,
                        sfEvent event);
void load_sprites3(struct game *game_instance);
void game_event_game2(sfEvent event, struct game *game_instance);

#endif