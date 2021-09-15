/*
** EPITECH PROJECT, 2020
** B-CPP-300-MPL-3-1-CPPrush1-lyvia.mallereau
** File description:
** int.c
*/

#include <stdio.h>
#include "int.h"
#include "new.h"

typedef struct
{
    Class   base;
    int     nb;
}   IntClass;

static void Int_ctor(IntClass *this, va_list *args)
{
    this->nb = va_arg(*args, int);
}

static void Int_dtor(IntClass *this)
{
    (void)this;
}

// Create additional functions here

static char *to_str(IntClass *this)
{
    char nb[12];
    char str[12 + 9];

    memset(nb, 0, 12);
    memset(str, 0, 21);
    sprintf(nb, "%d", this->nb);
    sprintf(str, "<Int (%s)>", nb);
    return (strdup(str));
}

static IntClass *Int_add(const IntClass *this, const IntClass *other)
{
    int res;

    res = this->nb + other->nb;
    return new(Int, res);
}

static IntClass *Int_sub(const IntClass *this, const IntClass *other)
{
    int res;

    res = this->nb - other->nb;
    return new(Int, res);
}

static IntClass *Int_mul(const IntClass *this, const IntClass *other)
{
    int res;

    res = this->nb * other->nb;
    return new(Int, res);
}

static IntClass *Int_div(const IntClass *this, const IntClass *other)
{
    int res;

    if (other->nb == 0)
        raise("Floating point exception, division by zero\n");
    res = this->nb / other->nb;
    return new(Int, res);
}

static bool Int_equal(const IntClass *this, const IntClass *other)
{
    return (this->nb == other->nb);
}

static bool Int_greater_then(const IntClass *this, const IntClass *other)
{
    return (this->nb > other->nb);
}

static bool Int_lower_then(const IntClass *this, const IntClass *other)
{
    return (this->nb < other->nb);
}

static const IntClass _description = {
    {   /* Class struct */
        .__size__ = sizeof(IntClass),
        .__name__ = "Int",
        .__ctor__ = (ctor_t)&Int_ctor,
        .__dtor__ = (dtor_t)&Int_dtor,
        .__str__ = (to_string_t)&to_str,    /* Implement this method for exercice 02 */
        .__add__ = (binary_operator_t)&Int_add,    /* Implement this method for exercice 03 */
        .__sub__ = (binary_operator_t)&Int_sub,    /* Implement this method for exercice 03 */
        .__mul__ = (binary_operator_t)&Int_mul,
        .__div__ = (binary_operator_t)&Int_div,
        .__eq__ = (binary_comparator_t)&Int_equal,
        .__gt__ = (binary_comparator_t)&Int_greater_then,
        .__lt__ = (binary_comparator_t)&Int_lower_then
    },
    .nb = 0
};

const Class   *Int = (const Class *)&_description;
