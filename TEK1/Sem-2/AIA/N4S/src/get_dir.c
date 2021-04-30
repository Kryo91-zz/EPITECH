/*
** EPITECH PROJECT, 2019
** AIA_n4s_2019
** File description:
** get_dir.c
*/

#include "my.h"

size_t array_len(void *array)
{
    void **it = array;
    int len = -1;

    if (!array)
        return (0);
    while (it[++len]);
    return ((size_t)len);
}

void get_big_ray(float *offset, float *biggest, char **tab, int i)
{
    if (atof(tab[i]) > atof(tab[(int)(*biggest)])) {
        *offset = 0;
        (*biggest) = (float)i;
        while (tab[i + 2 +(int)*offset] && \
        atof(tab[i + 1 + (int)*offset]) == atof(tab[(int)(*biggest)]))
            *offset += 1;
        *offset = *offset / 2 + i;
    }
}

void exec_dir(char **tab, float offset)
{
    char dir[14];
    char *cmd = NULL;

    memset(dir, 0, 14);
    if ((atof(tab[0]) > 225  && offset >= 0) || \
    (atof(tab[array_len(tab) - 2]) > 225 && offset <= 0)) {
        gcvt(offset, 3, dir);
        cmd = my_strcat("WHEELS_DIR:", dir);
        exec_cmd(cmd);
    } else {
        fprintf(stderr, "\nBLOCKED\n\n");
        exec_cmd("WHEELS_DIR:0");
    }
    if (cmd)
        free(cmd);
}

void get_dir(char **tab)
{
    float biggest = 0;
    float offset = 0.0;

    if ((atof(tab[0]) > 300 && atof(tab[31]) > 300)) {
        exec_cmd("WHEELS_DIR:0");
    } else {
        for (int i = 0; tab[i + 1]; i++)
            get_big_ray(&offset, &biggest, tab, i);
        offset = (offset / 16 - 1.0) * (-1);
        offset = offset > 0.4 ? 0.4 : offset;
        offset = offset < -0.4 ? -0.4 : offset;
        exec_dir(tab, offset);
    }
}