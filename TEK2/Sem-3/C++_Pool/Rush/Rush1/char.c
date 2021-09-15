/*
** EPITECH PROJECT, 2020
** B-CPP-300-MPL-3-1-CPPrush1-lyvia.mallereau
** File description:
** char.c
*/

#include <stdio.h>
#include "char.h"
#include "new.h"

typedef struct
{
    Class   base;
    char     c;
}   CharClass;

static void Char_ctor(CharClass *this, va_list *args)
{
    this->c = va_arg(*args, int);
}

static void Char_dtor(CharClass *this)
{
    (void)this;
}

// Create additional functions here

static char *to_str(CharClass *this)
{
    char c[13];

    memset(c, 0, 13);
    sprintf(c, "<Char (%c)>", this->c);
    return (strdup(c));
}

static CharClass *Char_add(const CharClass *this, const CharClass *other)
{
    char res;

    res = this->c + other->c;
    return new(Char, res);
}

static CharClass *Char_sub(const CharClass *this, const CharClass *other)
{
    char res;

    res = this->c - other->c;
    return new(Char, res);
}

static CharClass *Char_mul(const CharClass *this, const CharClass *other)
{
    char res;

    res = this->c * other->c;
    return new(Char, res);
}

static CharClass *Char_div(const CharClass *this, const CharClass *other)
{
    char res;

    if (other->c == 0)
        raise("Floating point exception, division by zero\n");
    res = this->c / other->c;
    return new(Char, res);
}

static bool Char_equal(const CharClass *this, const CharClass *other)
{
    return (this->c == other->c);
}

static bool Char_greater_then(const CharClass *this, const CharClass *other)
{
    return (this->c > other->c);
}

static bool Char_lower_then(const CharClass *this, const CharClass *other)
{
    return (this->c < other->c);
}


static const CharClass _description = {
    {   /* Class struct */
        .__size__ = sizeof(CharClass),
        .__name__ = "Char",
        .__ctor__ = (ctor_t)&Char_ctor,
        .__dtor__ = (dtor_t)&Char_dtor,
        .__str__ = (to_string_t)&to_str,    /* Implement this method for exercice 02 */
        .__add__ = (binary_operator_t)&Char_add,    /* Implement this method for exercice 03 */
        .__sub__ = (binary_operator_t)&Char_sub,    /* Implement this method for exercice 03 */
        .__mul__ = (binary_operator_t)&Char_mul,
        .__div__ = (binary_operator_t)&Char_div,
        .__eq__ = (binary_comparator_t)&Char_equal,
        .__gt__ = (binary_comparator_t)&Char_greater_then,
        .__lt__ = (binary_comparator_t)&Char_lower_then
    },
    .c = 0
};

const Class   *Char = (const Class *)&_description;
