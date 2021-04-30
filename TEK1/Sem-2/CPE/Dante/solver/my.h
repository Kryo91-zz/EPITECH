/*
** EPITECH PROJECT, 2019
** MY
** File description:
** .h
*/

#ifndef __MY_H__
#define __MY_H__

#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
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
#include <signal.h>

struct maze *solv;

struct maze {
    int width;
    int hight;
    int r;
};

char **changemap(char **map, char *pos, char status);
int check_boat_length(char *str);
int error(int ac, char **av);
char *find_position(char **av);
char *tch_pos_play(char **map1, char **map2);
char *wt_infi(struct sigaction *ac, char **map1, char **map2, \
struct sigaction *act);
int letters_to_int(char pos);
int game_loop(int player, char **map1, char **map2);
char *int_to_letters(int x, int y);
int check_input(char *pos);
int hub(char **map1, char **map2);
void check_file(char *str);
void my_putchar(char c);
char **been_shot(char **map, char *pos);
int count_boats(char **map);
void print_map(char **map);
char **map_gen(char *str, int boat);
long my_put_nbr(long nb);
void my_swap(int *a, int *b);
int my_putstr(char *str);
int my_isneg(int nb);
int my_strlen(char *str);
int my_strlen_perc(char const *str);
void my_sort_int_array(int *tab, int size);
int my_compute_power_rec(int nb, int p);
int my_compute_square_root(int nb);
int my_find_prime_sup(int nb);
int my_getnbr(char const *str);
int my_is_prime(int nb);
char *my_revstr(char *str);
int my_showmem(char const *str, int size);
int my_showstr(char const *str);
int my_str_isalpha(char const *str);
int my_str_islower(char const *str);
int my_str_isnum(char *str);
int my_str_isprintable(char const *str);
int my_str_isupper(char const *str);
char *my_strcapitalize(char *str);
char *my_strcat(char *dest, char const *src);
int my_strcmp(char *s1, char *s2);
char *my_strcpy(char *dest, char const *src);
char *my_strlowcase(char *str);
char *my_strncat(char *dest, char *src, int nb);
int my_strncmp(char *s1, char *s2, int n);
char *my_strncpy(char *dest, char *src, int n);
char *my_strstr(char *str, char const *to_find);
char *my_strupcase(char *str);
char **my_str_to_word_array(char *str, char *delimiter);
void my_printf(char *str, ...);
int redirect_one_to_ten(char *str, int i, va_list *my_tab);
int redirect_ten_to_twenty(char *str, int i, va_list *my_tab);
void my_disp_nbr(va_list *my_tab);
int my_putnbr_base(int nbr, char *base);
void my_disp_char(va_list *my_tab);
void my_disp_str(va_list *my_tab);
void my_disp_perc(va_list *my_tab);
void my_disp_hex_maj(va_list *my_tab);
void my_disp_hex_min(va_list *my_tab);
void my_putchar(char c);
void my_disp_binary(va_list *my_tab);
void my_disp_hex_plus_zero_max(va_list *my_tab);
void my_disp_octo(va_list *my_tab);
void my_disp_long_num(va_list *my_tab);
void my_disp_octo_plus_zero(va_list *my_tab);
void my_disp_hex_plus_zero_min(va_list *my_tab);
void my_disp_len(va_list *my_tab, char *str);
void my_disp_unsi_num(va_list *my_tab);
long my_put_unsi_num(long nb);
void redirect(void);
void redirect_all_stdout(void);
int redi_redi(char *str, int i, va_list *my_tab);
int redirec_redi(char *str, int i, va_list *my_tab);
int redirect_ten_to_thirteen(char *str, int i, va_list *my_tab);
char	*my_strdup(char const *src);
void display_shell(char **env);
void my_cd(char *buff, char **env);
int find_execution(char *buff, char **env);
void my_exit(char *str);
char *copy_string(char *buff);
void unset_enviro(char *buff, char **env);
void set_enviro(char *buff, char **env);
void display_enviro(char **env);
void my_cd2(char *path, char *str, char **env);
void reset_enviro2(char *buff, char **env);
char **unset_env2(char *buff, char **env);
void my_cd_minus(char *buf, char *str, char *test, char **env);
char *tcheck_path(char **env, char *buf, char *path);
void print_prompt(void);
void tcheck_error(char **tab, char **env);
void find_status(int stat);
void cat_something(char *buff, char **env);
void cat_something2(char **tab);
void error_dir(char **tab, char *str, char **env);
int my_char_ischar(char c);
int my_char_ispoint(char c);
int tcheck_file_error2(char *str);
int tcheck_file_error3(char *str);
int my_char_isnum(char c);
__sighandler_t ret_func(char **av, char *str);
int tcheck_pid(char **av);
char *find_position(char **av);
int tcheck_file_error(char *str);
struct request *get_request(int ac, char **av);
int tcheck_signal(int i, char **av);
void play(char **map1, char **map2);
void take_pid(int value, siginfo_t *info, void *lol);
char check_sig_back(void);
void send_sig(int x, int y);
void count_sig2(int kiwi);
void count_sig1(int kiwi);
void sig_status(int value, siginfo_t *info, void *lol);
void sig_status2(int value, siginfo_t *info, void *lol);
char *unbackn(char *str);
void place_boats(char **map, char boat, int letter, int num);
int count_crosses(char **map);
char **check_shot(char **map, char *pos);
void description(void);
void destroy_dante(char **map);
void draw_map(char **map);
int solver_maze(char **map, int j, int i, int n);
#endif