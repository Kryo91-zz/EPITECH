/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** my_rpg
*/

#ifndef MY_RPG_H_
#define MY_RPG_H_

#include "titouan.h"
#include "lyvia.h"
#include "../Antoine/antoine.h"
#include "corentin.h"
#include <stdlib.h>
#include <stdio.h>
#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <SFML/System.h>
#include <SFML/Audio.h>
#include <SFML/Audio/SoundBuffer.h>
#include <SFML/Audio/Sound.h>
#include <unistd.h>
#include <sys/stat.h>
#include <stdbool.h>
#include <fcntl.h>
#include <string.h>
#include <math.h>

#define PARICULE_ANGLE_MIN (M_PI)
#define PARICULE_ANGLE_MAX (-M_PI)

typedef struct cam_s
{
    sfView *view;
    sfFloatRect rect;
    sfVector2f pos;
    float zoom;
} cam_t;

typedef struct music_s
{
    sfMusic *music;
} music_t;

typedef struct particle_s
{
    sfVector2f pos;
    sfVector2f vel;
    sfColor color;
    size_t radius;
    bool living;
} particle_t;

typedef struct particle_environment_s
{
    float angle_min;
    float angle_max;
    float speed;
    sfVector2f gravity;
    sfUint8 alpha;
    sfClock *clock;
    sfCircleShape *circle_shape;
} particle_environment_t;

typedef struct window_s
{
    sfVideoMode mode;
    sfRenderWindow *window;
    sfEvent event;
    sfKeyCode key;
    particle_t *particle;
    particle_environment_t *particle_environment;
} window_t;

typedef enum parallax_s
{
    SKY1,
    WOOD_RED1_1,
    WOOD_RED1_2,
    WOOD_TRANS1_1,
    WOOD_TRANS1_2,
    WOOD1_1,
    WOOD1_2
} parallax_t;

typedef struct cursor_s
{
    sfTexture *texture;
    sfSprite *sprite;
    sfVector2i mouseposition;
} cursor_t;

typedef struct button_s
{
    sfIntRect rect;
    sfTexture *texture;
    sfSprite *sprite;
    sfVector2f pos;
    sfVector2f size;
} button_t;

typedef struct background_s
{
    sfTexture *texture;
    sfSprite *sprite;
    sfVector2f pos;
} background_t ;

typedef struct charachter_s
{
    sfTexture *texture;
    sfSprite *sprite;
    sfIntRect rect;
    int old_vision;
    int vision;
    int anim;
    int left;
    int right;
    int up;
    int down;
    int dmgs;
    int dmge;
    int dmga;
    sfVector2f position;
    sfClock *clock;
    sfTime time;
    int health;
    int atta_wolf;
    sfClock *a_wolf;
    sfTime at_wolf;
    int dmg;
}character_t;

typedef struct HUD_s
{
    sfSprite *sprite;
    sfTexture *texture;
    sfClock *clock;
    sfTime time;
    float seconds;
    sfIntRect rect;
    sfVector2f size;
    sfVector2f position;
} HUD_t;

typedef struct mob_s
{
    sfSprite *sprite;
    sfTexture *texture;
    sfClock *clock;
    sfTime time;
    float seconds;
    sfIntRect rect;
    sfVector2f size;
    sfVector2f position;
} mob_t;

typedef struct game_object_s
{
    sfTexture *texture;
    sfSprite *sprite;
    sfClock *clock;
    sfVector2f position;
    sfTime time;
    float seconds;
    parallax_t paral;
} game_object_t;

typedef struct map_s
{
    char **map;
    int nb_map;
    int x;
    int y;
}map_t;

typedef struct glb_s
{
    int bool_main_menu;
    int bool_menu_htp;
    int bool_menu_option;
    int bool_menu_pause;
    int bool_menu_inventaire;
    int defeat;
    int health;
    int mana;
    int exp;
    int expmax;
    int minixp;
    int minimana;
    int minhealth;
    int manamax;
    int healthmax;
    int actual_map;
    int sec_att;
    int drop;
    int b_att;
    sfText *xp;
    sfText *mymana;
    sfText *mylife;
    sfText *text;
    sfFont *font;
    sfText *text2;
    sfText *textDemon;
    sfText *textDemon2;
    sfText *text_pnj;
    sfSprite *attack;
    sfTexture *a_text;
    sfClock *clock_att;
    map_t *map;
    window_t wind;
    music_t music_menu;
    sfEvent event;
    game_object_t **obj;
    cursor_t cursor;
    character_t *chara;
    int anim_wolf;
    sfClock *wolf;
    sfVector2f vec;
    character_t *mob;
    background_t title;
    background_t test;
    background_t back_htp;
    background_t back_option;
    background_t back_pause;
    background_t title_option;
    background_t game_over;
    button_t play_MM;
    button_t quit_MM;
    button_t option_MM;
    button_t aide_MM;
    button_t charger_MM;
    button_t retour_htp;
    button_t pause;
    button_t reprendre;
    button_t quitter_MP;
    button_t sauvegarder;
    button_t option_MP;
    button_t menu_principal;
    button_t retour_MO;
    button_t plus;
    button_t moins;
    button_t retour_defeat;
    particle_t *particule;
    HUD_t hud_sort_feu;
    HUD_t hud_sort_foudre;
    HUD_t hud_sort_epee;
    mob_t demon1;
    mob_t demon2;
    mob_t demon3;
    mob_t pnj;
    HUD_t inventory_base;
    HUD_t inventory_1;
    HUD_t inventory_2;
    HUD_t inventory_3;
    HUD_t bague;
    HUD_t collier;
    HUD_t sceptre;
    cam_t *cam;
}glb_t;


//function for the -h
void doc(void);

//FUNCTIONvoid destroy_for_the_menu_pause(glb_t *global) TEST, NEED TO BY SUPRIM
int background_test(glb_t *global);
//function basiq for the rpg
int open_window(glb_t *global);
void event_echap_close(glb_t *global);
int play_music_main_menu(glb_t *global);
int play_music_in_game(glb_t *global);

//function for draw and destroy
void draw_1(glb_t *global);
void destroy_1(glb_t *global);

//function for the cursor
int draw_cursor(glb_t *global);
void get_mouse_position(glb_t *global);

//function menu defeat
int btn_retour_defeat(glb_t *global);
void texture_retour_defeat(glb_t *global);
void anim_retour_defeat(glb_t *global);
void hitbox_btn_retour_menu_defeat(glb_t *global);
int create_game_over(glb_t *global);
int the_menu_defeat(glb_t *global);
void draw_for_the_menu_defeat(glb_t *global);
void destroy_for_the_menu_defeat(glb_t *global);

//function loop and call for helping the main and optimisation of the code
int rpg_loop(glb_t *global);
void call_and_help(glb_t *global);
void condition_appel_for_all(glb_t *global);
void init_sprite(glb_t *global);
void manage_event(glb_t *global);
void appel_of_bool(glb_t *global);

//function for the main menu
int main_menu(glb_t *global);
int create_title(glb_t *global);
void draw_for_the_main_menu(glb_t *global);
void destroy_for_the_main_menu(glb_t *global);
void condition_for_menu(glb_t *global);

//function jouer main menu
int button_play_main_menu(glb_t *global);
void texture_button_play_main_menu(glb_t *global);
void anim_button_play_main_menu(glb_t *global);
void hitbox_button_play_main_menu(glb_t *global);

//function btn quitter main menu
int button_quit_main_menu(glb_t *global);
void texture_button_quit_main_menu(glb_t *global);
void anim_button_quit_main_menu(glb_t *global);
void hitbox_button_quit_main_menu(glb_t *global);

//function btn option main menu
int button_option_main_menu(glb_t *global);
void texture_option_main_menu(glb_t *global);
void anim_button_option_main_menu(glb_t *global);
void hitbox_button_option_main_menu(glb_t *global);

//funtion for btn aide in main menu
int button_aide_main_menu(glb_t *global);
void texture_aide_main_menu(glb_t *global);
void anim_button_aide_main_menu(glb_t *global);
void hitbox_button_aide_main_menu(glb_t *global);
int background_htp(glb_t *global);

//function for btn charger main menu
int button_charger_main_menu(glb_t *global);
void texture_charger_main_menu(glb_t *global);
void anim_button_charger_main_menu(glb_t *global);
void hitbox_button_charger_main_menu(glb_t *global);

//function for the menu comment jouer
int background_htp(glb_t *global);
int the_menu_htp(glb_t *global);
void draw_for_the_menu_htp(glb_t *global);
void destroy_for_the_menu_htp(glb_t *global);

//funtion for the button retour main menu in htp
int button_retour_main_menu(glb_t *global);
void texture_retour_main_menu(glb_t *global);
void anim_button_retour_main_menu(glb_t *global);
void hitbox_button_retour_main_menu(glb_t *global);

//function for the menu option
int background_option(glb_t *global);
int the_menu_option(glb_t *global);
void draw_for_the_menu_option(glb_t *global);
void destroy_for_the_menu_option(glb_t *global);
int create_title_option(glb_t *global);

//function draw the pause button
int button_pause_in_game(glb_t *global);
void texture_pause_in_game(glb_t *global);
void anim_button_pause_in_game(glb_t *global);
void hitbox_button_pause_in_game(glb_t *global);

//function for the menu option
int background_pause(glb_t *global);
int the_menu_pause(glb_t *global);
void draw_for_the_menu_pause(glb_t *global);
void destroy_for_the_menu_pause(glb_t *global);

//function for the btn reprendre
int button_reprendre_in_pause_menu(glb_t *global);
void texture_reprendre_in_pause_menu(glb_t *global);
void anim_button_reprendre_in_pause_menu(glb_t *global);
void hitbox_button_reprendre_in_menu_pause(glb_t *global);

//function for the btn quiter in the menu pause
int button_quitter_in_pause_menu(glb_t *global);
void texture_quitter_in_pause_menu(glb_t *global);
void anim_button_quitter_in_pause_menu(glb_t *global);
void hitbox_button_quiter_in_menu_pause(glb_t *global);

//function for the btn sauvegarder in the menu pause
int button_sauvegarder_in_pause_menu(glb_t *global);
void texture_sauvegarder_in_pause_menu(glb_t *global);
void anim_button_sauvegarder_in_pause_menu(glb_t *global);
void hitbox_button_sauvegarder_in_menu_pause(glb_t *global);

//function for the btn option in the menu pause
int button_option_in_pause_menu(glb_t *global);
void texture_option_in_pause_menu(glb_t *global);
void anim_button_option_in_pause_menu(glb_t *global);
void hitbox_button_option_in_menu_pause(glb_t *global);

//function for the btn menu principal in menu pause
int button_menu_prin_in_pause_menu(glb_t *global);
void texture_menu_prin_in_pause_menu(glb_t *global);
void anim_button_menu_prin_in_pause_menu(glb_t *global);
void hitbox_button_menu_prin_in_menu_pause(glb_t *global);

//function for the btn retour in the menu option
int button_retour_menu_option(glb_t *global);
void texture_retour_menu_option(glb_t *global);
void anim_button_retour_menu_option(glb_t *global);
void hitbox_button_retour_menu_option(glb_t *global);
void hitbox_btn_moins(glb_t *global);
void hitbox_btn_plus(glb_t *global);

//draw the background of parallax for start menu
int draw_red_sky(game_object_t *obj);
int draw_wood_red_1_1(game_object_t *obj);
int draw_wood_red_1_2(game_object_t *obj);
int draw_wood_trans_1_1(game_object_t *obj);
int draw_wood_trans_1_2(game_object_t *obj);
int draw_wood_1_1(game_object_t *obj);
int draw_wood_1_2(game_object_t *obj);

//set the move of the parallax
void set_wood_red_1_1(game_object_t *obj);
void set_wood_red_1_2(game_object_t *obj);
void set_wood_trans_1_1(game_object_t *obj);
void set_wood_trans_1_2(game_object_t *obj);
void set_wood_1_1(game_object_t *obj);
void set_wood_1_2(game_object_t *obj);

//move the background for the parralax
void move_wood_red_1_1(game_object_t *obj);
void move_wood_red_1_2(game_object_t *obj);
void move_wood_trans_1_1(game_object_t *obj);
void move_wood_trans_1_2(game_object_t *obj);
void move_wood_1_1(game_object_t *obj);
void move_wood_1_2(game_object_t *obj);

//function of the parallax
void tableau_background_parallax(glb_t *global);
void draw_background_parallax(glb_t *global);
void parallax(glb_t *global);

//Function mooving main-character
character_t *init_chara(void);
void moov_chara(character_t *chara, glb_t *global);
sfIntRect rect(int top, int left, int width, int height);
sfVector2f pos(float x, float y);

//Function animating character
void anim_left(character_t *chara);
void anim_right(character_t *chara);
void anim_down(character_t *chara);
void anim_up(character_t *chara);
int inventory_sceptre(glb_t *global);
void init_sprite_attack(glb_t *global);
sfVector2f get_pos(character_t *chara, sfSprite *sprite);
void attack(glb_t *global);

//Get_collision
void get_coll(map_t *map);
int check_coll(map_t *map, int nb_map, character_t *chara, int dir);

//function HUD heart bar
int health_bar_create(glb_t *global);
void texture_health_bar(glb_t *global);
void anim_health_bar(glb_t *global);

//function for the mana bar
int mana_bar_create(glb_t *global);
void texture_mana_bar(glb_t *global);
void anim_mana_bar(glb_t *global);

//function for the HUD sort
int hud_sort_feu_create(glb_t *global);
void texture_hud_sort_feu(glb_t *global);
void anim_hud_sort_feu(glb_t *global);
void hitbox_button_sort_feu(glb_t *global);
int hud_sort_foudre_create(glb_t *global);
void texture_hud_sort_foudre(glb_t *global);
void anim_hud_sort_foudre(glb_t *global);
void hitbox_button_sort_foudre(glb_t *global);
int hud_sort_epee_create(glb_t *global);
void texture_hud_sort_epee(glb_t *global);
void anim_hud_sort_epee(glb_t *global);
void hitbox_button_sort_epee(glb_t *global);

//function for the inventory
int inventory_base(glb_t *global);
int inventory_bague(glb_t *global);
int inventory_collier(glb_t *global);
int inventory_sceptre(glb_t *global);
void make_functionnal_inventory(glb_t *global);

//function to drawx and see the obj for the quete
int draw_obj_bague(glb_t *global);
int draw_obj_collier(glb_t *global);
int draw_obj_sceptre(glb_t *global);

//function draw the first mob demon
int demon1_create(glb_t *global);
void anim_demon1(glb_t *global);
void texture_demon1(glb_t *global);
void time_clock_demon1(glb_t *global);

//function score
void display_score(glb_t *global);

//function control volume
int button_plus_create(glb_t *global);
void texture_btn_plus(glb_t *global);
void anim_btn_plus(glb_t *global);
int button_moins_create(glb_t *global);
void texture_btn_moins(glb_t *global);
void anim_btn_moins(glb_t *global);

//function pnj base
int pnj_base(glb_t *global);
void draw_text_pnj(glb_t *global);

//func.c
sfVector2f get_position(int x, int y);
int number_digits(int nbr);
char *my_score(int nbr);
void init_particule(const particle_environment_t *particle_environment, \
particle_t *particule, const sfVector2f pos);
void init_particule(const particle_environment_t *particle_environment, \
particle_t *particule, const sfVector2f pos);
void add_particle(const particle_environment_t *particle_environment, \
particle_t *particule, const size_t particle_num, const sfVector2f pos);
void display_particle(sfRenderWindow *window, const particle_t *particule, \
sfCircleShape *circle_shape);
void update_particle(const particle_environment_t *particle_environment, \
particle_t *particule);
void manage_key_window(window_t *screen, const sfKeyCode *key, glb_t *global);
void manage_event_window(sfRenderWindow *window, sfKeyCode *key);
void init_particle_environment(particle_environment_t *particle_environment, \
const sfVector2f angle, const sfVector2f gravity, const sfUint8 alpha);
void add_particle2(const particle_environment_t *particle_environment, \
particle_t *particule, const size_t particle_num, const sfVector2f pos);
void add_particle3(const particle_environment_t *particle_environment, \
particle_t *particule, const size_t particle_num, const sfVector2f pos);
void draw_2(glb_t *global);
void reset_to_default_view(sfRenderWindow *window);
void power_xp(glb_t *global);
void power_mana(glb_t *global);
void power_life(glb_t *global);
void tree_competence(glb_t *global);
float v2f_dist(const sfVector2f *p1, const sfVector2f *p2);
void save_game(glb_t * global);
long my_put_nbr(long nb, int fd);
void load_game(glb_t * global);
void anim_demon2(glb_t *global);
void texture_demon2(glb_t *global);
void time_clock_demon2(glb_t *global);
void draw_textdemon2(glb_t *global);
void texture_demon3(glb_t *global);
void anim_demon3(glb_t *global);
void time_clock_demon3(glb_t *global);
void draw_textdemon3(glb_t *global);

//ennemy
void create_mob(glb_t *global);
void get_player(character_t *chara, character_t *mob, glb_t *global);

#endif /* !MY_RPG_H_ */
