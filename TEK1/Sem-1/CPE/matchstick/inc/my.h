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
#include "struct_bistro.h"
#include <stdarg.h>
#include "my_ls.h"

void    my_ls_amaj(DIR *dir);
void    my_ls_amin(DIR *dir);
int redirect_flag(char **av);
int check_error_and_redirect(int ac, char **av, my_ls_t *data);
void    my_ls(DIR *dir);
void my_putchar(char c);
long my_put_nbr(long nb);
void my_swap(int *a, int *b);
int my_putstr(char *str);
int my_isneg(int nb);
int my_strlen(char const *str);
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
int my_strcmp(char const *s1, char const *s2);
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
void init_struct(my_ls_t *data);
char    *file_to_inspect(char *ls, char *file);
void    disp_total_block(char *rep);
void my_ls_l(char *path);
void total(char const *path);
void raw_rx(char *nom, struct stat s);
void putid(struct stat *s);
void    my_right(struct stat sb);
void    my_ls_1(DIR *dir);
int check_error_and_redirect2(int ac, char **av, my_ls_t *data);
void    my_ls_r(char *directory);
void    my_ls_R(char *directory);
void    my_ls_for_R(DIR *dir);
void raw_rx2(struct stat s);
void raw_rx3(struct stat s);
char **wordarray(char *str);
int check_error_and_redirect3(int ac, char **av, my_ls_t *data);
int check_error_and_redirect4(int ac, char **av, my_ls_t *data);
void raw_rx4(struct stat s);

#endif

