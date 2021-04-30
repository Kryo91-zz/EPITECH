/*
** EPITECH PROJECT, 2019
** ls
** File description:
** ls
*/

#include "../inc/my_ls.h"
#include "../inc/my.h"

int main(int ac, char **av)
{
    DIR *dir;
    my_ls_t data;
    struct stat st;

    if (ac == 1) {
        my_ls(opendir("./"));
        return (0);
    }
    check_error_and_redirect(ac, av, &data);
    check_error_and_redirect2(ac, av, &data);
    if (check_error_and_redirect(ac, av, &data) == 1 &&
        check_error_and_redirect2(ac, av, &data) == 1 &&
        check_error_and_redirect3(ac, av, &data) == 1 &&
        check_error_and_redirect4(ac, av, &data) == 1)
        exit(84);
}

int check_error_and_redirect(int ac, char **av, my_ls_t *data)
{
    data->directory = wordarray(".");

    if (av[1][0] == '-' && av[1][1] == 'a')
        my_ls_amin(opendir("./"));
    else if (av[1][0] == '-' && av[1][1] == 'R') {
        my_printf(".:\n");
        my_ls_R(data->directory[0]);
        exit(0);
    } else
        return  (1);
}

int check_error_and_redirect2(int ac, char **av, my_ls_t *data)
{
    if (av[1][0] == '-' && av[1][1] == '1')
            my_ls_1(opendir("./"));
    else if (av[1][0] == '-' && av[1][1] == 'A')
        my_ls_amaj(opendir("./"));
    else
        return (1);
}

int check_error_and_redirect3(int ac, char **av, my_ls_t *data)
{
    if (av[1][0] == '-' && av[1][1] == 't')
        exit(0);
    else if (av[1][0] == '-' && av[1][1] == 'l') {
        my_ls_l(data->directory[0]);
        exit(0);
    } else
        return (1);
}

int check_error_and_redirect4(int ac, char **av, my_ls_t *data)
{
    if (av[1][0] == '-' && av[1][1] == 'r')
        my_ls_r(data->directory[0]);
    else if (av[1][0] == '-' && av[1][1] == 'd') {
        my_printf(".\n");
        exit(0);
    } else
        return (1);
}