/*
** EPITECH PROJECT, 2019
** MY
** File description:
** .h
*/

#ifndef __MY_H__
#define __MY_H__

static int turn = 1;
static int lose = 1;

#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <dirent.h>
#include <stdlib.h>
#include <pwd.h>
#include <grp.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include <getopt.h>
#include <fcntl.h>
#include <string.h>
#include <getopt.h>
#include <stdarg.h>
#include <unistd.h>

int chooseline(char **map);
int count_number_of_matches(char **map, int line);
void my_putchar(char c);
void intellignece_artificial(char **play, int ia, char **av);
int    my_getnbr(char *str);
int lines_match(char **play, char **av);
int print_game_return_game(int i, int j, char **play, char **av);
char    **my_str_to_word_array(char *str, char *lim);
char **wordarray(char *str);
char **map(int len, int lines);
int lines_match_one(char **play, char **av);
void print_board_game(int line, int nb_matches, char **map, char **av);
void my_printf(char *str, ...);
int print_game_return_game_one(int i, int j, char **play, char **av);
void print_board_game_one(int line, int nb_matches, char **map);
void IA_game(char **play, char **av);
int scan_matches_ia(char **play);
int scan_matches(char **play);
int tchek_ctrl_d(int i);
int tchek(char **play);
int lose_condition(int count);
int replay(int j, char **play, char **av, char *buff);
int replay_one(int j, char *buff, char **play, char **av);
int matches(int j, char **play, char **av);
int matches_one(int j, char **play, char **av);
int my_str_isnum(char *str);
int error_one(int k, char **play, char **av, int j);
int error(int k, char **av, char **play, int j);
int tchek_2(char **play, int lose);
int lose_condition_2(int count, int lose);
int find_the_line_one(char **play, char **av);
int find_the_line(char **play, char **av);
int my_strlen(char const *str);

#endif