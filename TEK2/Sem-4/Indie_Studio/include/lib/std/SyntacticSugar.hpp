/*
** EPITECH PROJECT, 2020
** B-YEP-400-MPL-4-1-indiestudio-alec.ferrari
** File description:
** castComp.cpp
*/

#pragma once

#include <memory>

namespace lib
{
    template <typename T>
    using shPtr = std::shared_ptr<T>;

    template <typename T>
    using uPtr = std::unique_ptr<T>;

    template <class T, class U>
    shPtr<T> cast(const shPtr<U>& sp) noexcept
    {
        return std::dynamic_pointer_cast<T>(sp);
    }
} // namespace lib