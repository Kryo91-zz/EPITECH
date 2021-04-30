/*
** EPITECH PROJECT, 2020
** CPE_dante_2019
** File description:
** generator
*/

#ifndef GENERATOR_H_
#define GENERATOR_H_

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stddef.h>

typedef struct gen
{
    int wall_to_open;
    int north;
    int south;
    int west;
    int est;
}gen;

struct gen *gene;

void perfect_maze(int i, int j);
void imperfect_maze(int i, int j);
void print_map(char **map);
char **fill_maze(int x, int y, char **maze);
char **create_perfect(char **maze, int x, int y);
void destroy_dante(char **map);

#endif /* !GENERATOR_H_ */
