/*
** EPITECH PROJECT, 2019
** ls
** File description:
** ls
*/

#include "../inc/my_ls.h"
#include "../inc/my.h"

void my_ls_l(char *path)
{
    struct stat s;
    DIR *rep = opendir(path);
    struct dirent *file = NULL;

    if (rep == NULL)
        exit(84);
    total(path);
    while ((file = readdir(rep)) != NULL) {
        if (file->d_name[0] != '.') {
            lstat(file->d_name, &s);
            raw_rx(file->d_name, s);
            putid(&s);
            write(1 , file->d_name, my_strlen(file->d_name));
        write(1, "\n", 1);
        }
    }
    if (closedir(rep) == -1)
        exit(84);
}

void    my_ls_R(char *directory)
{
    struct dirent *dirent;
    struct stat   s;
    DIR     *dir;
    char *str;

    my_ls_for_R(opendir(directory));
    dir = opendir(directory);
    while ((dirent = readdir(dir)) != 0) {
        str = my_strcat(my_strcat(directory, "/"), dirent->d_name);
        stat(str, &s);
        if (S_ISDIR(s.st_mode) && dirent->d_name[0] != '.') {
            my_printf("\n");
            my_printf("%s:\n", str);
            my_ls_R(str);
        }
    }
}

void    my_ls_for_R(DIR *dir)
{
    struct dirent  *directo;

    while ((directo = readdir(dir)) != NULL) {
        if ((directo->d_name[0] != '.'))
            my_printf("%s\n", directo->d_name);
    }
    return ;
}

void raw_rx(char *nom, struct stat s)
{
    lstat(nom, &s);
    if (S_ISREG(s.st_mode))
        my_putchar('-');
    else if (S_ISDIR(s.st_mode))
        my_putchar('d');
    if (S_ISLNK(s.st_mode))
        my_putchar('l');
    if (s.st_mode & S_IRUSR)
        my_putchar('r');
    else
        my_putchar('-');
    if (s.st_mode & S_IWUSR)
        my_putchar('w');
    else
        my_putchar('-');
    raw_rx2(s);
    raw_rx3(s);
    raw_rx4(s);
}