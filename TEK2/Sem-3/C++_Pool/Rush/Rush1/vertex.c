/*
** EPITECH PROJECT, 2018
** cpp_rush1
** File description:
** Exercice 02
*/

#include <stdio.h>
#include "vertex.h"
#include "new.h"

typedef struct
{
    Class   base;
    int     x, y, z;
}   VertexClass;

static void Vertex_ctor(VertexClass *this, va_list *args)
{
    this->x = va_arg(*args, int);
    this->y = va_arg(*args, int);
    this->z = va_arg(*args, int);
}

static void Vertex_dtor(VertexClass *this)
{
    (void)this;
}

// Create additional functions here

static char *to_str(VertexClass *this)
{
    char x[12], y[12], z[12], *str;
    int len = 0;

    memset(x, 0, 12);
    memset(y, 0, 12);
    memset(z, 0, 12);
    sprintf(x, "%d", this->x);
    sprintf(y, "%d", this->y);
    sprintf(z, "%d", this->z);
    len = 9 + strlen(this->base.__name__) + strlen(x) + strlen(y) + strlen(z);
    if (!(str = malloc(sizeof(*str) * (len + 1))))
        raise("Malloc for str conversion failed");
    str[len] = 0;
    sprintf(str, "<%s (%s, %s, %s)>", this->base.__name__, x, y, z);
    return (str);
}

static VertexClass *Vertex_add(const VertexClass *this, const VertexClass *other)
{
    int res_x = 0, res_y = 0, res_z = 0;

    res_x = this->x + other->x;
    res_y = this->y + other->y;
    res_z = this->z + other->z;
    return new(Vertex, res_x, res_y, res_z);
}

static VertexClass *Vertex_sub(const VertexClass *this, const VertexClass *other)
{
    int res_x, res_y, res_z = 0;

    res_x = this->x - other->x;
    res_y = this->y - other->y;
    res_z = this->z - other->z;

    return (new(Vertex, res_x, res_y, res_z));
}


static const VertexClass _description = {
    {   /* Class struct */
        .__size__ = sizeof(VertexClass),
        .__name__ = "Vertex",
        .__ctor__ = (ctor_t)&Vertex_ctor,
        .__dtor__ = (dtor_t)&Vertex_dtor,
        .__str__ = (to_string_t)&to_str,    /* Implement this method for exercice 02 */
        .__add__ = (binary_operator_t)&Vertex_add,    /* Implement this method for exercice 03 */
        .__sub__ = (binary_operator_t)&Vertex_sub,    /* Implement this method for exercice 03 */
        .__mul__ = NULL,
        .__div__ = NULL,
        .__eq__ = NULL,
        .__gt__ = NULL,
        .__lt__ = NULL
    },
    .x = 0,
    .y = 0,
    .z = 0
};

const Class   *Vertex = (const Class *)&_description;
