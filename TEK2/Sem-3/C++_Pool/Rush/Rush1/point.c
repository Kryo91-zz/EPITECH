/*
** EPITECH PROJECT, 2018
** cpp_rush1
** File description:
** Exercice 02
*/

#include <stdio.h>
#include "point.h"
#include "new.h"

typedef struct
{
    Class   base;
    int     x, y;
}   PointClass;

static void Point_ctor(PointClass *this, va_list *args)
{
    this->x = va_arg(*args, int);
    this->y = va_arg(*args, int);
}

static void Point_dtor(PointClass *this)
{
    (void)this;
}

// Create additional functions here

static char *to_str(PointClass *this)
{
    char x[12], y[12], *str;
    int len = 0;

    memset(x, 0, 12);
    memset(y, 0, 12);
    sprintf(x, "%d", this->x);
    sprintf(y, "%d", this->y);
    len = 7 + strlen(this->base.__name__) + strlen(x) + strlen(y);
    if (!(str = malloc(sizeof(*str) * (len + 1))))
        raise("Malloc for str conversion failed");
    str[len] = 0;
    sprintf(str, "<%s (%s, %s)>", this->base.__name__, x, y);
    return (str);
}

static PointClass *Point_add(const PointClass *this, const PointClass *other)
{
    int res_x = 0, res_y = 0;

    res_x = this->x + other->x;
    res_y = this->y + other->y;
    return new(Point, res_x, res_y);
}

static PointClass *Point_sub(const PointClass *this, const PointClass *other)
{
    int res_x, res_y = 0;

    res_x = this->x - other->x;
    res_y = this->y - other->y;

    return (new(Point, res_x, res_y));
}


static bool Point_equ(const PointClass *this, const PointClass *other)
{
    int res_x, res_y = 0;

    res_x = this->x - other->x;
    res_y = this->y - other->y;
    if (!res_x && res_y == 0)
        return (true);
    return (false);
}

static const PointClass _description = {
    {   /* Class struct */
        .__size__ = sizeof(PointClass),
        .__name__ = "Point",
        .__ctor__ = (ctor_t)&Point_ctor,
        .__dtor__ = (dtor_t)&Point_dtor,
        .__str__ = (to_string_t)&to_str,    /* Implement this method for exercice 02 */
        .__add__ = (binary_operator_t)&Point_add,    /* Implement this method for exercice 03 */
        .__sub__ = (binary_operator_t)&Point_sub,    /* Implement this method for exercice 03 */
        .__mul__ = NULL,
        .__div__ = NULL,
        .__eq__ = (binary_comparator_t)&Point_equ,
        .__gt__ = NULL,
        .__lt__ = NULL
    },
    .x = 0,
    .y = 0
};

const Class   *Point = (const Class *)&_description;
