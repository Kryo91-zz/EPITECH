/*
** EPITECH PROJECT, 2020
** error
** File description:
** fonc 2
*/

#include "../include/main.h"
#include "../include/garbage.h"

char *my_strdup(char *src)
{
    char *dest;
    int length;

    length = my_strlen(src);
    dest = malloc(length + 1);
    length = 0;
    while (src[length] != '\0') {
        dest[length] = src[length];
        length = length + 1;
    }
    dest[length] = '\0';
    return (dest);
}

int my_strcmp(char const *s1, char const *s2)
{
    int i;

    for (i = 0; (s1[i] == s2[i]) && (s1[i] != '\0') && (s2[i] != '\0'); i++);
    return (s1[i] - s2[i]);
}

int check_tunnel(main_t *struct_main, int i)
{
    ARRAY tab = malloc(sizeof(char *) * (i - 2));
    tab[i - 3] = NULL;
    char **tmp = NULL;
    for (int ind = 1, pos = 0; ind < i; ind++) {
        if (struct_main->map[ind][0] != '#') {
            tmp = my_str_to_word_array(struct_main->map[ind], ' ');
            tab[pos] = my_strdup(tmp[0]);
            tmp[0] = "\0";
            pos++;
        }
    }
    tmp[0] = 0;
    tmp[1] = 0;
    tmp[2] = 0;
    return (final_ver(i, struct_main, tab , tmp));
}

int check_2(main_t *struct_main)
{
    int done = 0;

    for (int i = 1; i < struct_main->tunels; i += 1) {
        if (struct_main->map[i][1] == '-' && done == 0) {
            done = 1;
            if (check_tunnel(struct_main, i) == 1)
                return (1);
        }
    }
    if (done == 0)
        return (1);
    return (0);
}

int error2(main_t *my_struct)
{
    int bol = check_2(my_struct);
    return (bol);
}