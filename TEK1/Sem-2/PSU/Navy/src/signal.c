/*
** EPITECH PROJECT, 2019
** PSU_navy_2019
** File description:
** signal.c
*/

#include "../inc/my.h"

int tcheck_pid(char **av)
{
    pid_t pid = my_getnbr(av[1]);
    char *str = malloc(sizeof(char) * 4096);

    if (kill(pid, SIGUSR1) == -1) {
        my_printf("this PID is not found\n");
        return (1);
    }
    pid = getpid();
    my_printf("my_pid: %d\nsuccessfully connected\n", pid);
    str = find_position(av);
    if (tcheck_file_error(str) == 1)
        return (84);
}

void take_pid(int value, siginfo_t *info, void *lol)
{
    if (value == 10)
        req->enemy = info->si_pid;
}

char *wt_infi(struct sigaction *ac, char **map1, char **map2, struct \
sigaction *act)
{
    while (req->sig2 != 2) {
        sigaction(SIGUSR1, ac, NULL);
        sigaction(SIGUSR2, act, NULL);
    }
    return (tch_pos_play(map1, map2));
}

char *tch_pos_play(char **map1, char **map2)
{
    char *pos = malloc(sizeof(char) * 4096);

    req->sig1 = 0;
    req->sig2 = 0;
    pos = int_to_letters(req->sigx, req->sigy);
    req->sigy = 0;
    req->sigx = 0;
    return (pos);
}

void count_sig1(int kiwi)
{
    req->sig1 += 1;
}
