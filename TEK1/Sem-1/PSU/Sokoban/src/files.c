/*
** EPITECH PROJECT, 2019
** MY_SOKOBAN
** File description:
** .c
*/

#include <unistd.h>
#include <ncurses.h>
#include <curses.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>

#include "../inc/my_sokoban.h"

int reader(char **av)
{
    struct stat    st;
    char *buff = NULL;
    char **tab = NULL;
    int fd = open(av[1], O_RDONLY);
    int size = 0;
    player_t *posi = malloc(sizeof(player_t));

    if (stat(av[1], &st) == -1)
        return (84);
    buff = malloc(sizeof(char *) * st.st_size);
    size = read(fd, buff, st.st_size + 1);
    if (fd == -1 || size == -1)
        return (84);
    buff[size] = '\0';
    tab = sec_tab(buff, posi);
    my_popup(tab, posi, av);
    return (0);
}

int col(char *str)
{
    int nb = 0;
    int countx = 0;
    int counto = 0;
    int countp = 0;

    for (int i = 0, j = 0; str[i] != '\0'; ++i) {
        if (str[i] == '\n')
            ++j;
        if (str[i] == 'X')
            ++countx;
        if (str[i] == 'O')
            ++counto;
        if (str[i] == 'P') {
            ++countp;
        }
        nb = j + 1;
    }
    error_management(countx, counto, countp, str);
    return (nb);
}

char **sec_tab(char *str, player_t *posi)
{
    int colum = col(str);
    int line = my_strlen(str);
    char **arr;
    int i = 0;

    arr = malloc(sizeof(char *) * (colum+1));
    while (i < colum) {
        arr[i] = malloc(sizeof(char) * (line + 1));
        ++i;
    }
    arr[i] = NULL;
    cpy_map(str, &arr, posi);
    return (arr);
}

void error_management(size_t countx, size_t counto, size_t countp, char *str)
{

    if (counto != countx)
        exit (84);
    if (counto == 0 || countx == 0)
        exit (84);
    if (countp != 1)
        exit (84);
    for (int i = 0; str[i] != '\0'; ++i)
        if (str[i] != 35 && str[i] != ' ' && str[i] != 'X'
            && str[i] != 'O' && str[i] != 'P' && str[i] != '\n')
            exit (84);
}

int my_popup(char **tab, player_t *posi, char **av)
{
    int key;
    int i = 0;

    initscr();
    keypad(stdscr, TRUE);
    curs_set(0);
    while (1) {
        while (COLS < 220 && LINES < 220) {
            clear();
            while (tab[i] != NULL) {
                mvprintw(i, 0, tab[i]);
                i += 1;
            }
            keypad(stdscr, TRUE);
            key = getch();
            if (key == 27) {
                endwin();
                exit (0);
            }
            if (key == ' ')
                reader(av);
            moove_start_close(key, tab, posi);
            my_popup(tab, posi, av);
            refresh();
        }
    }
    endwin();
    return (0);
}