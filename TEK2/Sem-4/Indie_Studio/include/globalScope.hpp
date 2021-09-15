/*
** EPITECH PROJECT, 2020
** B-YEP-400-MPL-4-1-indiestudio-alec.ferrari
** File description:
** globalScope.hpp
*/

#pragma once

struct ViewportSettings {
    int width;
    int height;
};

struct PlayerSetup {
    int nb;
};

#define WINDOW_WIDTH 1280
#define WINDOW_HEIGHT 720

void setViewportSettings(int, int);
ViewportSettings &getViewportSettings(void);
