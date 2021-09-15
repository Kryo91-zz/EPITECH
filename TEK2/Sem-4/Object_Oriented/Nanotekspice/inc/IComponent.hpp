/*
** EPITECH PROJECT, 2020
** B-OOP-400-MPL-4-1-tekspice-lyvia.mallereau
** File description:
** IComponent.hpp
*/

#pragma once

#include "lib_included.hpp"

namespace nts
{
    enum statement {
        UNDEFINED = (-true),
        TRUE = true,
        FALSE = false
    };

    class IComponent
    {
        public:
            virtual ~IComponent () = default;
            virtual  void            simulate(std::size_t tick) = 0;
            virtual  nts::statement  compute(std::size_t pin) = 0;
            virtual  void            setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin) = 0;
            virtual  void            dump() const = 0;
    };

    class Pin {
        public:
            Pin() = default;
            ~Pin() = default;
            bool is_linked = false;
            IComponent *linked_to = nullptr;
            size_t otherPin;
    };

}