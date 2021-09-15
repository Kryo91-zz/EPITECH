/*
** EPITECH PROJECT, 2020
** B-CPP-300-MPL-3-1-CPPrush1-lyvia.mallereau
** File description:
** float.c
*/

#include <stdio.h>
#include "float.h"
#include "new.h"

typedef struct
{
    Class   base;
    float     nb;
}   FloatClass;

static void Float_ctor(FloatClass *this, va_list *args)
{
    float nb = (float)va_arg(*args, double);
    this->nb = nb;
}

static void Float_dtor(FloatClass *this)
{
    (void)this;
}

// Create additional functions here

static char *to_str(FloatClass *this)
{
    char nb[24];
    char src[24 + 11];

    memset(nb, 0, 24);
    memset(src, 0, 35);
    sprintf(src, "<Float (%.6f)>", this->nb);
    return (strdup(src));
}

static FloatClass *Float_add(const FloatClass *this, const FloatClass *other)
{
    float res;

    res = this->nb + other->nb;
    return new(Float, res);
}

static FloatClass *Float_sub(const FloatClass *this, const FloatClass *other)
{
    float res;

    res = this->nb - other->nb;
    return new(Float, res);
}

static FloatClass *Float_mul(const FloatClass *this, const FloatClass *other)
{
    float res;

    res = this->nb * other->nb;
    return new(Float, res);
}

static FloatClass *Float_div(const FloatClass *this, const FloatClass *other)
{
    float res;

    if (other->nb == 0)
        raise("Floating point exception, division by zero\n");
    res = this->nb / other->nb;
    return new(Float, res);
}


static bool Float_equal(const FloatClass *this, const FloatClass *other)
{
    return (this->nb == other->nb);
}

static bool Float_greater_then(const FloatClass *this, const FloatClass *other)
{
    return (this->nb > other->nb);
}

static bool Float_lower_then(const FloatClass *this, const FloatClass *other)
{
    return (this->nb < other->nb);
}

static const FloatClass _description = {
    {   /* Class struct */
        .__size__ = sizeof(FloatClass),
        .__name__ = "Float",
        .__ctor__ = (ctor_t)&Float_ctor,
        .__dtor__ = (dtor_t)&Float_dtor,
        .__str__ = (to_string_t)&to_str,    /* Implement this method for exercice 02 */
        .__add__ = (binary_operator_t)&Float_add,    /* Implement this method for exercice 03 */
        .__sub__ = (binary_operator_t)&Float_sub,    /* Implement this method for exercice 03 */
        .__mul__ = (binary_operator_t)&Float_mul,
        .__div__ = (binary_operator_t)&Float_div,
        .__eq__ = (binary_comparator_t)&Float_equal,
        .__gt__ = (binary_comparator_t)&Float_greater_then,
        .__lt__ = (binary_comparator_t)&Float_lower_then
    },
    .nb = 0
};

const Class   *Float = (const Class *)&_description;
