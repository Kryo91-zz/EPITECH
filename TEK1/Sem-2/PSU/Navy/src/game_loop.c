/*
** EPITECH PROJECT, 2019
** PSU_navy_2019
** File description:
** game_loop.c
*/

#include "../inc/my.h"

int player1(char **map1, char **map2)
{
    char *pos = malloc(sizeof(char) * 4096);
    char status = 'o';
    int letter = 0;
    int num = 0;

    my_printf("attack: ");
    int i = read(0, pos, 4096);
    if (i <= 0)
        return (12);
    pos = unbackn(pos);
    if (check_input(pos) == 0) {
        my_printf("wrong position\n");
        player1(map1, map2);
        return (0);
    }
    letter = letters_to_int(pos[0]);
    num = letters_to_int(pos[1]);
    send_sig(letter, num);
    status = check_sig_back();
    map2 = changemap(map2, pos, status);
}

void player2(char **map1, char **map2)
{
    struct sigaction *ac = malloc(sizeof(struct sigaction));
    struct sigaction *act = malloc(sizeof(struct sigaction));
    act->sa_flags = 0;
    ac->sa_flags = 0;
    ac->sa_handler = &count_sig1;
    act->sa_handler = &count_sig2;
    sigemptyset(&act->sa_mask);
    sigemptyset(&ac->sa_mask);
    char *pos = malloc(sizeof(char) * 4096);
    char status = 'o';
    int letter = 0;
    int num = 0;

    my_printf("\nwaiting for enemy's attack...\n");
    pos = wt_infi(ac, map1, map2, act);
    check_shot(map1, pos);
}

int whowins(int player)
{
    char *whowins = "I won";

    if (player == 1)
        whowins = "Enemy won";
    my_printf("%s\n", whowins);
    return (player);
}

int game_loop(int player, char **map1, char **map2)
{
    my_printf("\nmy positions:\n");
    print_map(map1);
    my_printf("\nenemy's positions:\n");
    print_map(map2);
    my_putchar('\n');
    for (int i = 0; i < 2; i++) {
        if (player == 1) {
            if (count_boats(map1) == 0 || count_crosses(map2) == 14)
                return (whowins(player));
            int a = player1(map1, map2);
            if (a == 12)
                return (0);
            player = 0;
        } else {
            if (count_boats(map1) == 0 || count_crosses(map2) == 14)
                return (whowins(player));
            player2(map1, map2);
            player = 1;
        }
    }
    game_loop(player, map1, map2);
}