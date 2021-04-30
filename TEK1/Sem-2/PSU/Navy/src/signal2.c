/*
** EPITECH PROJECT, 2019
** PSU_navy_2019
** File description:
** game_loop.c
*/

#include "../inc/my.h"

char check_sig_back(void)
{
    struct sigaction *ac = malloc(sizeof(struct sigaction));
    struct sigaction *act = malloc(sizeof(struct sigaction));
    sigemptyset(&act->sa_mask);
    sigemptyset(&ac->sa_mask);
    ac->sa_flags = SA_SIGINFO;
    act->sa_flags = SA_SIGINFO;
    ac->sa_sigaction = &sig_status;
    act->sa_sigaction = &sig_status2;
    req->sig2 = 0;
    req->sig1 = 0;
    while (req->sig2 != 1) {
        sigaction(SIGUSR2, act, NULL);
        sigaction(SIGUSR1, ac, NULL);
        if (req->sig1 == 2)
            req->status = 'x';
        else
            req->status = 'o';
    }
    req->sig1 = 0;
    req->sig2 = 0;
    return (req->status);
}

void send_sig(int x, int y)
{
    int i = 0;

    while (i < x) {
        kill(req->enemy, SIGUSR1);
        usleep(500);
        ++i;
    }
    kill(req->enemy, SIGUSR2);
    usleep(500);
    i = 0;
    while (i < y) {
        kill(req->enemy, SIGUSR1);
        usleep(500);
        ++i;
    }
    kill(req->enemy, SIGUSR2);
}

void sig_status(int value, siginfo_t *info, void *lol)
{
    req->sig1 += 1;
}

void sig_status2(int value, siginfo_t *info, void *lol)
{
    req->sig2 += 1;
}