/*
** EPITECH PROJECT, 2019
** ls
** File description:
** ls
*/

#include "../inc/my_ls.h"
#include "../inc/my.h"

void total(char const *path)
{
    int count = 0;
    struct stat s;
    DIR *rep = opendir(path);
    struct dirent *fichier;

    while ((fichier = readdir(rep)) != NULL) {
        if (fichier->d_name[0] != '.' ) {
            lstat(fichier->d_name, &s);
            count += s.st_blocks;
        }
    }
    write(1, "total ", 7);
    my_put_nbr(count / 2);
    write(1, "\n", 1);
    closedir(rep);
}

void putid(struct stat *s)
{
    struct group *gid = getgrgid(s->st_gid);
    struct passwd *pwd = getpwuid(s->st_uid);

    my_put_nbr((int)s->st_nlink);
    write(1, " ", 1);
    write(1, gid->gr_name, my_strlen(gid->gr_name));
    write(1, " ", 1);
    write(1, pwd->pw_name, my_strlen(pwd->pw_name));
    write(1, " ", 1);
    my_put_nbr((int)s->st_size);
    write(1, " ", 1);
    ctime(&s->st_mtime);
    write(1, (ctime(&s->st_mtime) + 4), (my_strlen(ctime(&s->st_mtime)) - 13));
    write(1, " ", 1);
}

void raw_rx2(struct stat s)
{
    if (s.st_mode & S_IXUSR)
        my_putchar('x');
    else
        my_putchar('-');
    if (s.st_mode & S_IRGRP)
        my_putchar('r');
    else
        my_putchar('-');
    if (s.st_mode & S_IWGRP)
        my_putchar('w');
    else
        my_putchar('-');
}

void raw_rx3(struct stat s)
{
    if (s.st_mode & S_IXGRP)
        my_putchar('x');
    else
        my_putchar('-');
    if (s.st_mode & S_IROTH)
        my_putchar('r');
    else
        my_putchar('-');
    if (s.st_mode & S_IWOTH)
        my_putchar('w');
    else
        my_putchar('-');
}

void raw_rx4(struct stat s)
{
    if (s.st_mode & S_IXOTH)
        my_putchar('x');
    else
        my_putchar('-');
    my_putchar(' ');
}