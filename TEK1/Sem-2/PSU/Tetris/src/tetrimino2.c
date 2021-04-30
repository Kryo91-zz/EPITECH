/*
** EPITECH PROJECT, 2019
** PSU_tetris_2019
** File description:
** tetrimino2.c
*/

#include "../inc/my.h"

void divide_tetri(int count, int count2, int cmp, char **map)
{
    int cmp2 = 0;

    if (cmp != count || cmp != (count-1))
        exit(84);
    if (map[1] != NULL) {
        cmp2 = my_getnbr(map[1]);
    if (cmp2 != count2 || cmp2 != (count2+1))
        exit(84);
    }
    cmp = 0;
    count = 0;
    cmp2 = 0;
    count2 = 0;
}

void divide_tetri2(int count, int count2, char *str)
{
    int i = 0;

    for (int i = 6; str[i] != '\n' && str[i] != '\0'; ++i)
        ++count;
    for (int i = 6; str[i] != '\0'; ++i)
        if (str[i] == '\n')
            ++count2;
}

char **divide_tetri3(char **map, char *str, struct dirent *directo)
{
    int fd;
    int red;
    char src[1024];
    char *dest = "./tetriminos/";

    my_strcpy(src, dest);
    my_strcat(src, directo->d_name);
    fd = open(src, O_RDONLY);
    red = read(fd, str, 4069);
    str[red] = '\0';
    map = my_str_to_word_array(str, " \n");
}

void error_on_tetrimino(void)
{
    DIR *rep = opendir("./tetriminos");
    struct dirent *directo;
    char **tetris = malloc(sizeof(char *) * 4096);
    char *str = malloc(sizeof(char) * 4096);
    int cmp = 0;
    int count2 = 0;
    int count = 0;
    char **map = malloc(sizeof(char *) * 4096);

    while ((directo = readdir(rep)) != NULL) {
        if ((directo->d_name[0] != '.')) {
            map = divide_tetri3(map, str, directo);
            tetris = my_str_to_word_array(directo->d_name, ".\0\n");
            cmp = my_getnbr(map[0]);
            divide_tetri2(count, count2, str);
            divide_tetri(count, count2, cmp, map);
        }
    }
}
