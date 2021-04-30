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
#include <sys/wait.h>
#include <errno.h>

struct envi *envv;

struct envi {
    char **enviro;
    char *path;
    int statuss;
    int status2;
    int i;
    int countp;
    int vercrocd;
    int vercrocdd;
    int nbco;
}envi;

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
int my_strcmp(char *s1, char *s2);
char *my_strcpy(char *dest, char const *src);
char *my_strlowcase(char *str);
char *my_strncat(char *dest, char *src, int nb);
int my_strncmp(char *s1, char *s2, int n);
char *my_strncpy(char *dest, char *src, int n);
char *my_strstr(char *str, char const *to_find);
char *my_strupcase(char *str);
char **my_str_to_word_array(char *str, char *delimiter);
char **my_str_to_word_array_piper(char *str, char *delimiter);
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
char **reset_enviro2(char *buff, char **env);
char **unset_env2(char *buff, char **env);
void my_cd_minus(char *buf, char *str, char *test, char **env);
char *tcheck_path(char **env, char *buf, char *path);
void print_prompt(void);
void tcheck_error(char **tab, char **env);
void find_status(int stat);
void cat_something(char *buff, char **env);
void cat_something2(char **tab);
void error_dir(char **tab, char *str, char **env);
int check_operands(char **cmds_list);
void find_operand(char **cmds_list, char **env);
char **list_commands(char *buff, char **cmds_list, char **env);
char *clean_str(char *buff);
char *without_space(char *buff);
int  execution(char *buff, char **env);
void separator_loop(char **env, char *str);
void disp_shell(char **tab, char **env, char *buff, char **cmds_list);
char *copy_string2(char *buff);
void one_pipe(char **cmd1, char **cmd2, char **env);
void one_pipe_exec(char *str, char *src, char **env);
char *copy_string3(char *buff);
int check_ambiguous_redirect(char **cmds_list);
int find_execution2(char *buff, char **env);
int find_execution3(char *buff, int fd);
void my_echo(char *buff, char **env);
void operand_sep(char **cmds_list, int i, char **env);
int operand_redirr(char **cmds_list, int i, char **env);
int operand_nd(char **cmds_list, int i, char **env);
int operand_re(char **cmds_list, int i, char **env);
int operand_pipe(char **cmds_list, int i, char **env);
int last_operand(char ** cmds_list, int i, char **env);
int operand_redirrr(char **cmds_list, int i, char **env);
int operand_redirl(char **cmds_list, int i, char **env);
int operand_redirll(char **cmds_list, int i, char **env);
void one_pipe_exec2(char *str, char *src, char **env);
void one_pipe2(char **cmd1, char *src, char **env);
void one_pipe_exec3(char *str, char *src, char **env);
void one_pipe3(char **cmd1, char *src, char **env);
void one_pipe4(char **cmd1, char *src, char **env);
int count_tab(char **tab, char *sep, int i);
char ***get_tab(char **cmds_list, char ***tab, int i);
void pipe_everything(int ac, char ***args, char **env, int pipes[]);
char **prepare_string(char **cmd);
int check_for_dots(char **cmds_list, int i);
void one_pipe_exec5(char *str, char *src, char **env);
void one_pipe_exec4(char *str, char *src, char **env);
void check_smth(char *test, char **env);
char **put_backslash_zero(char **cmds_list, int ind, int j);
void operands_loop(char **cmds_list, char **env);
int operands_loop2(char **cmds_list, char **env, int i);
int fork_pipe(int pid, int pipefd[], char **cmd2, char **env);
void my_which(char *buff);
void my_history(char *buff);
void pipe_everything_exec(int ac, char ***args, char **env, int pipes[]);

#endif