/*
** EPITECH PROJECT, 2019
** ls
** File description:
** ls
*/

#include "../inc/my_ls.h"
#include "../inc/my.h"

void    my_ls(DIR *dir)
{
    struct dirent  *directo;

    while ((directo = readdir(dir)) != NULL) {
        if ((directo->d_name[0] != '.'))
            my_printf("%s\n", directo->d_name);
    }
    exit(0);
}

void    my_ls_amin(DIR *dir)
{
    struct dirent *directo;

    while ((directo = readdir(dir)) != NULL)
        my_printf("%s\n", directo->d_name);
    exit(0);
}

void    my_ls_amaj(DIR *dir)
{
    struct dirent  *directo;

    while ((directo = readdir(dir)) != 0) {
        if ((directo->d_name[0] != '.' || directo->d_name[1] != '.')
            && (directo->d_name[0] != '.' || directo->d_name[1] != '\0'))
            my_printf("%s\n", directo->d_name);
    }
    exit(0);
}

void    my_ls_1(DIR *dir)
{
    struct dirent  *directo;

    while ((directo = readdir(dir)) != NULL) {
        if ((directo->d_name[0] != '.'))
            my_printf("%s ", directo->d_name);
    }
    exit(0);
}

void    my_ls_r(char *directory)
{
    char    **tab = wordarray(" ");
    struct dirent *dirent;
    DIR *dir;
    int y = 0;

    dir = opendir(directory);
    while ((dirent = readdir(dir)) != 0) {
        if ((dirent->d_name[0] != '.')) {
            tab[y] = my_strdup(dirent->d_name);
            y += 1;
        }
    }
    y -= 1;
    while (y >= 0) {
        my_printf("%s\n", tab[y]);
        y--;
    }
    exit (0);
}