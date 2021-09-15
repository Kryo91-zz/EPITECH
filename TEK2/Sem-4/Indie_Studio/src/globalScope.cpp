/*
** EPITECH PROJECT, 2020
** B-YEP-400-MPL-4-1-indiestudio-alec.ferrari
** File description:
** globalScope.cpp
*/

#include "globalScope.hpp"

static ViewportSettings vs = { 0 };

void setViewportSettings(int width, int height)
{
    vs.width = width;
    vs.height = height;
}

ViewportSettings &getViewportSettings(void)
{
    return vs;
}