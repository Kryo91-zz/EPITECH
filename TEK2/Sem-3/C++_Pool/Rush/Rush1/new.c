/*
** EPITECH PROJECT, 2020
** rush1
** File description:
** new.c
*/

#include "player.h"
#include "new.h"

Object  *new(const Class *class, ...)
{
    Object *new_object = malloc(class->__size__);
    va_list va;

    va_start(va, class);
    memcpy(new_object, class, class->__size__);
    if (class->__ctor__)
        class->__ctor__(new_object, &va);
    va_end(va);
    return (new_object);
}

Object  *va_new(const Class *class, va_list* ap)
{
    Object *new_object = malloc(class->__size__);

    memcpy(new_object, class, class->__size__);
    if (class->__ctor__)
        class->__ctor__(new_object, ap);
    return (new_object);
}

void    delete(Object *ptr)
{
    if (((Class *)ptr)->__dtor__)
        ((Class *)ptr)->__dtor__(ptr);
    free(ptr);
}
