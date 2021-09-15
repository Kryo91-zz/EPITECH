/*
** EPITECH PROJECT, 2020
** B-YEP-400-MPL-4-1-indiestudio-alec.ferrari
** File description:
** Input.hpp
*/

#pragma once

#include <raylib.h>
#include <vector>
#include <memory>
#include <array>

namespace engine {

    struct GlobalMouseInput {
        bool leftClick;
        bool rightClick;
        Vector2 mousePosition;
    };

    struct MouseInput {
        std::shared_ptr<const GlobalMouseInput> gInput;
    };
} // namespace engine