/*
** EPITECH PROJECT, 2019
** BISTROMATIC
** File description:
** main
*/
#include <stdlib.h>
#include <unistd.h>

void description(int argc, char **argv);

char **str_to_array(char *str, char *delimiter);

int err_nbr(int ac, char **av)
{
    int BUFF_SIZE = 32000;
    char buff[BUFF_SIZE + 1];

    if (ac == 4)
    {
        if (error_arg_syn(av) == 84) {
            return (0);
        } else {
            read(0, buff, BUFF_SIZE);
            const int err = errors_syn(buff);
            const int conv = eval_expr(buff);

            if (err == 84) {
                write(2, "syntax error", 13);
                return (84);
            }
            if (conv != NULL || conv == 0)
                my_put_nbr(conv);
            return (0);
        }
    } else if (ac == 3 || ac == 1) {
        write(2, "error", 6);
        return (84);
    }
}
int    main(int ac, char **av)
{
    description(ac, av);
    err_nbr(ac, av);
    return (0);
}
