/*
** EPITECH PROJECT, 2020
** B-OOP-400-MPL-4-1-arcade-alec.ferrari
** File description:
** Clock.hpp
*/

#pragma once

#include <chrono>

namespace lib
{
    class Stopwatch
    {
        private:
            bool _is_running = false;
            std::chrono::time_point<std::chrono::system_clock> _start, _end = std::chrono::system_clock::now();
        public:
            Stopwatch(void) = default;
            ~Stopwatch(void) = default;
            void start(void);
            void stop(void);
            void restart(void);
            bool is_running(void) const;
            double getElapsedTime(void) const;
    };
} // namespace arcade
