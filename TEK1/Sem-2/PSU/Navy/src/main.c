/*
** EPITECH PROJECT, 2019
** PSU_navy_2019
** File description:
** main.c
*/

#include "../inc/my.h"
#include <time.h>

char *red(int argc, char **argv)
{
    int fd = 0;
    int red = 0;
    char *str = malloc(sizeof(char) * 4096);

    if (argc == 2)
        fd = open(argv[1], O_RDONLY);
    else
        fd = open(argv[2], O_RDONLY);
    if (fd < 1)
        return ("kiwi");
    red = read(fd, str, 4069);
    str[red] = '\0';
    if (tcheck_file_error(str) == 1)
        return ("kiwi");
    if (check_boat_length(str) == 84)
        return ("kiwi");
    return (str);
}

int errmain(int ac, char **av)
{
    if (error(ac, av) == 1)
        return (84);
    req = get_request(ac, av);
    if (ac == 3) {
        if (tcheck_pid(av) == 1)
            return (84);
    }
    return (1);
}

void declmain(int ac)
{
    struct sigaction *act = malloc(sizeof(struct sigaction));
    sigemptyset(&act->sa_mask);
    pid_t pid = getpid();

    act->sa_flags = 0;
    act->sa_flags = SA_SIGINFO;
    act->sa_sigaction = &take_pid;

    if (ac == 2) {
        my_printf("my_pid: %d\nwaiting for enemy connection...\n", pid);
        sigaction(SIGUSR1, act, NULL);
        pause();
        my_printf("\nenemy connected\n");
    }
}

int main(int ac, char **av)
{
    char **map1 = NULL;
    char **map2 = map_gen("", 0);
    int player = 1;

    if (ac != 2 && ac != 3)
        return (84);
    if (ac == 3)
        player = 0;
    if (my_strncmp(av[1], "-h", 2) == 0) {
        description();
        return (0);
    }
    if (errmain(ac, av) == 84 || my_strcmp(red(ac, av), "kiwi") == 0)
        return (84);
    char *str = find_position(av);
    if (my_strcmp(str, "kiwi") == 0)
        return (84);
    map1 = map_gen(str, 1);
    declmain(ac);
    return (game_loop(player, map1, map2));
}