/*
** EPITECH PROJECT, 2019
** PSU_tetris_2019
** File description:
** main.c
*/


#include "../inc/my.h"

void divide_read(char **map, char *str, char **tetris)
{
    int i = 6;

    map = my_str_to_word_array(str, "\n");
    if (map[1] == NULL)
        my_printf("Tetriminos : Name : %s : Error\n", tetris[0]);
    else {
        my_printf("Tetriminos : Name : %s : Size %c*%c : Color %c\n", \
        tetris[0], str[0], str[2], str[4]);
        for (; str[i] != '\0'; ++i)
            my_printf("%c", str[i]);
        if (str[i-1] != '\n')
            my_printf("\n");
    }
    i = 6;
}

char **divide_read_two(void)
{
    DIR *rep = opendir("./tetriminos");
    DIR *oth = opendir("./tetriminos");
    int count = 0;
    struct dirent  *directo;
    char **kiwi = sort_tetrimino(oth);

    while ((directo = readdir(rep)) != NULL) {
        if ((directo->d_name[0] != '.'))
            ++count;
    }
    my_printf("Tetriminos : %d\n", count);
    return (kiwi);
}

void read_tetri(void)
{
    char **tetris = malloc(sizeof(char *) * 4096);
    char **kiwi = divide_read_two();
    int fd;
    int red;
    char *dest = "./tetriminos/";
    char src[1024];
    char *str = malloc(sizeof(char) * 4096);
    char **map;

    for (int j = 0; kiwi[j] != NULL; ++j) {
        tetris = my_str_to_word_array(kiwi[j], ".\0\n");
        my_strcpy(src, dest);
        my_strcat(src, kiwi[j]);
        fd = open(src, O_RDONLY);
        red = read(fd, str, 4069);
        str[red] = '\0';
        divide_read(map, str, tetris);
        src[0] = '\0';
    }
}