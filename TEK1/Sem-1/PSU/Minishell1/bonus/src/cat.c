/*
** EPITECH PROJECT, 2019
** minishell1
** File description:
** minishell1
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include "../inc/my.h"

void cat_something(char *buff, char **env)
{
    char *buf = copy_string(buff);
    char **tab = my_str_to_word_array(buf, " ");
    int fd = 0;

    if (my_strcmp(tab[1], "-e") == 0){
        fd = open(tab[2], O_RDONLY);
        char *str = malloc(sizeof(char) * 4096);
        int i = read(fd, str, 4096);
        for (int j = 0; str[j] != '\0'; ++j) {
            if (str[j] == '\n')
                my_putchar(36);
            my_putchar(str[j]);
        }
        close(fd);
    } else
        cat_something2(tab);
    close(fd);
    display_shell(env);
}

void cat_something2(char **tab)
{
    int fd = open(tab[1], O_RDONLY);
    char *str = malloc(sizeof(char) * 4096);
    int i = read(fd, str, 4096);
    my_putstr(str);
}