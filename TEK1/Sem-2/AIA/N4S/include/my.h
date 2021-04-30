/*
** EPITECH PROJECT, 2019
** AIA_n4s_2019
** File description:
** my.h
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

int check_str_empty(char *str);
void exec_cmd(char *str);
char **my_sep_array(char *st, char sep);
char **my_word_array(char *st);
char *my_strcat(char *dest, char *src);
char **get_info_lidar(void);
int detect_end(char **tab);
void maintain_left(char **tab);
void maintain_right(char **tab);
void get_dir(char **tab);

#endif