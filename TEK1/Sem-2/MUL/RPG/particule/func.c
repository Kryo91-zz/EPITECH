/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** btn_menu_prin_in_MP.c
*/

#include "../include/my_rpg.h"

void update_particle(const particle_environment_t *particle_environment, \
particle_t *particule)
{
    if (particule->living == true) {
        if (particule->color.a <= particle_environment->alpha)
            particule->living = false;
        particule->color.a -= particle_environment->alpha;
        particule->vel.x += particle_environment->gravity.x;
        particule->vel.y += particle_environment->gravity.y;
        particule->pos.x += particule->vel.x * particle_environment->speed;
        particule->pos.y += particule->vel.y * particle_environment->speed;
    }
}

void display_particle(sfRenderWindow *window, const particle_t *particule, \
sfCircleShape *circle_shape)
{
    if (particule->living == true) {
        sfCircleShape_setPosition(circle_shape, particule->pos);
        sfCircleShape_setRadius(circle_shape, particule->radius);
        sfCircleShape_setFillColor(circle_shape, particule->color);
        sfRenderWindow_drawCircleShape(window, circle_shape, NULL);
    }
}

sfVector2f get_position(int x, int y)
{
    sfVector2f vector;

    vector.x = x;
    vector.y = y;
    return (vector);
}

int number_digits(int nbr)
{
    int n = 1;
    int po = 10;

    if (nbr < 0)
        nbr = -nbr;
    while (nbr >= po) {
        n++;
        if (po > 214748364)
            break;
        po *= 10;
    }
    return (n);
}

char *my_score(int nbr)
{
    int len = number_digits(nbr);
    char *result;

    result = malloc(sizeof(char) * len + 1);
    if (result == NULL)
        write(1, "Fatal error: malloc failed.\n", 29);
    result[len] = '\0';
    while (len--) {
        result[len] = nbr % 10 + '0';
        nbr /= 10;
    }
    return (result);
}