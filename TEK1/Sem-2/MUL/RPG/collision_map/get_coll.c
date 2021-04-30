/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** get_coll
*/

#include "../include/my_rpg.h"

void get_coll(map_t *map)
{
    FILE *file = fopen("collision_map/coll.txt", "r");
    char **test;
    int x = 0;
    int y = 0;
    int old_x = 0;
    int test2 = 1;
    int nb_max = 515;
    char *line = NULL;
    size_t len = 0;

    map[0].map = malloc(sizeof(char *) * 145);
    for (int i = 0; i < 145; i++) {
        map[0].map[i] = malloc(sizeof(char) * 257);
        for (int y = 0; y < 256; y++) {
            map[0].map[i][y] = 'X';
            map[0].map[i][y + 1] = '\0';
        }
    }
    for (int i = 0; i < nb_max; i += 5) {
        getline(&line, &len, file);
        test = my_str_to_word_array(line, ',');
        getline(&line, &len, file);
        getline(&line, &len, file);
        getline(&line, &len, file);
        x = my_getnbr(line);
        getline(&line, &len, file);
        y = my_getnbr(line);
        x += 112;
        y += 32;
        old_x = x;
        for (int yt = 0; yt < 256; yt++) {
            if (my_getnbr(test[yt]) != 0)
                map[0].map[y][x] = '1';
            else
                map[0].map[y][x] = '0';
            x += 1;
            if (x == old_x + 16) {
                test2 += 1;
                x = old_x;
                y += 1;
            }
            if (test2 > 16)
                break;
        }
        test2 = 1;
    }

    for (int i = 0; i < 145; i++) {
        for (int y = 0; y < 257; y++) {
            if (map[0].map[i][y] == 'X')
                map[0].map[i][y] = '0';
        }
    }
}

int final_check(map_t map, int x, int y, int dir)
{
    if (dir == 1) {
        if (x <= 0)
            return (1);
        else if (map.map[y][x - 1] == '1')
            return (1);
        else
            return (0);
    }
    if (dir == 2) {
        if (x >= 20000)
            return (1);
        else if (map.map[y][x + 1] == '1')
            return (1);
        else
            return (0);
    }
    return (84);
}

int final_check_2(map_t map, int x, int y, int dir)
{
    if (dir == 3) {
        if (y <= 0)
            return (1);
        else if (map.map[y - 1][x] == '1')
            return (1);
        else if (x > 1)
            return (0);
    }
    if (dir == 4) {
        if (y >= 20000)
            return (1);
        else if (map.map[y + 1][x] == '1')
            return (1);
        else if (x > 1)
            return (0);
    }
    return (84);
}

int check_coll(map_t *map, int nb_map, character_t *chara, int dir)
{
    float x = sfSprite_getPosition(chara->sprite).x;
    float y = sfSprite_getPosition(chara->sprite).y + 290;
    int yt = 2000;
    int xt = 2000;
    int returned = 0;
    for (int i = 0; i < (256); i++) {
        if (8192/(256) * i <= x && 8192/(256) * (i + 1) > x)
            xt = i + 1;
        if (xt == 0)
                xt = -1;
    }
    for (int i = 0; i < 145; i++) {
        if (5120/(145) * i <= y && 5120/(145) * (i + 1) > y) {
            if (i <= 60)
                yt = i - 3;
            else
                yt = i;
        }
    }
    returned = final_check(map[nb_map], xt, yt, dir);
    if (returned == 84)
        returned = final_check_2(map[nb_map], xt, yt, dir);

    return (returned);
}