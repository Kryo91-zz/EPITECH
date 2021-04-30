/*
** EPITECH PROJECT, 2019
** SOKOBAN
** File description:
** .h
*/

#ifndef SOKOBAN
# define SOKOBAN_H

# include <stdlib.h>
# include <unistd.h>
# include <string.h>
#include <ncurses.h>
#include <curses.h>

typedef struct    player_s
{
    int    x;
    int    y;
    int    xo;
    int    yo;
    int    xx;
    int    yx;
    int    nbo;
    char *dest;
}player_t;

int my_popup(char **tab, player_t *posi, char **av);
size_t my_strlen(char const *str);
int description(int ac, char **av);
int reader(char **av);
int col(char *str);
char **sec_tab(char *str, player_t *posi);
void cpy_map(char *str, char ***tab, player_t *posi);
void error_management(size_t countx, size_t counto, size_t countp, char *str);
void moove_start_close(int key, char **tab, player_t *posi);
void coor_rec(char ***tab, player_t *posi, int count2, int count);
void mouv_up(char **tab, player_t *posi);
void mouv_down(char **tab, player_t *posi);
void mouv_left(char **tab, player_t *posi);
void mouv_right(char **tab, player_t *posi);
int tchek_map(player_t *posi);

#endif