/*
** EPITECH PROJECT, 2019
** PSU_navy_2019
** File description:
** shot.c
*/

#include "../inc/my.h"

char **check_shot(char **map, char *pos)
{
    int letter = letters_to_int(pos[0]);
    int num = letters_to_int(pos[1]);
    char *newline = NULL;
    char *status = "missed";

    newline = my_strdup(map[num - 1]);
    if (newline[letter - 1] == '.' || newline[letter - 1] == 'o' || \
    newline[letter - 1] == 'x')
        newline[letter - 1] = 'o';
    else {
        newline[letter - 1] = 'x';
        status = "hit";
        kill(req->enemy, SIGUSR1);
        usleep(500);
    }
    kill(req->enemy, SIGUSR1);
    usleep(500);
    kill(req->enemy, SIGUSR2);
    map[num - 1] = newline;
    my_printf("%s: %s\n", pos, status);
    return (map);
}

char **changemap(char **map, char *pos, char status)
{
    int letter = 0;
    int num = 0;
    char *newline = NULL;
    char *statuss = "missed";

    letter = letters_to_int(pos[0]);
    num = letters_to_int(pos[1]);
    newline = my_strdup(map[num - 1]);
    my_printf("%s: ", pos);
    newline[letter - 1] = status;
    if (status == 'x')
        statuss = "hit";
    map[num - 1] = newline;
    my_printf("%s\n", statuss);
    return (map);
}