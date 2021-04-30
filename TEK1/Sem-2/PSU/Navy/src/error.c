/*
** EPITECH PROJECT, 2019
** PSU_navy_2019
** File description:
** main.c
*/

#include "../inc/my.h"
#include <signal.h>

int check_boat_length(char *str)
{
    char **tab = my_str_to_word_array(str, ":\n");
    int boat = 0;
    int len = 0;
    int cmp = 0;
    int i = 0;
    int j = 1;
    int k = 2;

    for (int ind = 0; ind < 4; ind += 1) {
        boat = tab[i][0] - 48;
        len = (tab[j][0] - 65) + (tab[j][1] - 48);
        cmp = (tab[k][0] - 65) + (tab[k][1] - 48);
        if ((cmp - len) + 1 != boat) {
            return (84);
        }
        i += 3;
        j += 3;
        k += 3;
    }
    return (0);
}

struct request *get_request(int ac, char **av)
{
    req = malloc(sizeof(struct request));
    req->map1 = malloc(sizeof(char *) * 4096);
    req->map2 = malloc(sizeof(char *) * 4096);
    req->enemy = 0;
    req->sig1 = 0;
    req->sig2 = 0;
    req->sigx = 0;
    req->sigy = 0;
    if (ac == 3)
        req->enemy = my_getnbr(av[1]);
    return (req);
}

int tcheck_file_error3(char *str)
{
    if (str[0] == str[8] || str[0] == str[16] || str[0] == str[24] || \
    str[8] == str[16] || str[8] == str[24] || str[16] == str[24])
        return (1);
    return (0);
}