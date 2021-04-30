/*
** EPITECH PROJECT, 2019
** PSU_navy_2019
** File description:
** map.c
*/

#include "../inc/my.h"

void print_map(char **map)
{
    for (int i = 0; i < 10; i += 1) {
        for (int y = 0; y < 17; y += 1)
            write(1 , &map[i][y], 1);
        write(1, "\n", 1);
    }
}

char *find_position(char **av)
{
    int i = 0;
    int size = 0;
    char *buff = malloc(sizeof(char) * 4096);

    if (my_getnbr(av[1]) == 0) {
        i = open(av[1], O_RDONLY);
        if (i <= 0)
            return ("kiwi");
        size = read(i, buff, 4096);
    } else {
        i = open(av[2], O_RDONLY);
        if (i <= 0)
            return ("kiwi");
        size = read(i, buff, 4096);
    }
    buff[size] = '\0';
    return (buff);
}

void place_boats(char **map, char boat, int letter, int num)
{
    char *newline = my_strdup(map[num - 1]);

    newline[letter - 1] = boat;
    map[num - 1] = newline;
}

void boats(char **map, char *str)
{
    char **tab = my_str_to_word_array(str, ":\n");
    char boat = tab[0][0];
    int letter = 0;
    int num = 0;

    for (int i = 0; i < 10; i += 3) {
        boat = tab[i][0];
        letter = (tab[i + 1][0] - 65) * 2 + 3;
        num = (tab[i + 1][1] - 48) + 2;
        while (letter < ((tab[i + 2][0] - 65) * 2 + 3)\
|| num < (tab[i + 2][1] - 48) + 2) {
            place_boats(map, boat, letter, num);
            if (letter < (tab[i + 2][0] - 65) * 2 + 3)
                letter += 2;
            if (num < (tab[i + 2][1] - 48) + 2)
                num += 1;
        }
        place_boats(map, boat, ((tab[i + 2][0] - 65) * 2 + 3), \
((tab[i + 2][1] - 48) + 2));
    }
}

char **map_gen(char *str, int boat)
{
    char **map = malloc(sizeof(char *) * 4096);

    map[0] = " |A B C D E F G H\0";
    map[1] = "-+---------------\0";
    map[2] = "1|. . . . . . . .\0";
    map[3] = "2|. . . . . . . .\0";
    map[4] = "3|. . . . . . . .\0";
    map[5] = "4|. . . . . . . .\0";
    map[6] = "5|. . . . . . . .\0";
    map[7] = "6|. . . . . . . .\0";
    map[8] = "7|. . . . . . . .\0";
    map[9] = "8|. . . . . . . .\0";
    map[10] = NULL;
    if (boat == 1)
        boats(map, str);
    return (map);
}