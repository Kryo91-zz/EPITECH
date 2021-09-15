/*
** EPITECH PROJECT, 2021
** B-OOP-400-MPL-4-1-arcade-corentin.petrau
** File description:
** GameObject
*/



#pragma once

#include <iostream>
#include <memory>
#include <vector>
#include <algorithm>

namespace arcade
{
    // Colors should be assigned using hexadecimal reprentation
    // i.e. 0xFF0000 for red, 0x00FF00 for green, 0x0000FF for blue
    // You can also use rgba through the associated constructor
    struct Color
    {
        Color(uint8_t r = 0, uint8_t g = 0, uint8_t b = 0, uint8_t a = 0);
        Color(int hex);
        ~Color(void) = default;
        uint64_t get_hex(void);
        uint8_t r, g, b, a;
    };

    // Used for any positioning in game space
    struct Vector2
    {
        Vector2(float _x = 0, float _y = 0);
        ~Vector2(void) = default;
        float x, y;
    };

    namespace Input {
        enum Key {
            Unknown = -1, A = 0, B, C,
            D, E, F, G,
            H, I, J, K,
            L, M, N, O,
            P, Q, R, S,
            T, U, V, W,
            X, Y, Z, Num0,
            Num1, Num2, Num3, Num4,
            Num5, Num6, Num7, Num8,
            Num9, Escape, Space, Enter,
            Backspace, Tab, Closed, Up,
            Down, Left, Right
        };
    }

    struct GameObject {
        GameObject(void);
        enum ObjectType {
            CIRCLE,
            RECTANGLE,
            LINE,
            SPRITE,
            TEXT
        };
        // Determines the type of object. Possible options are:
        // "Circle", "Rectangle", "Sprite", "Line", "Text"
        // Use subclasses to define it implicitly.
        GameObject::ObjectType type;
        arcade::Vector2 position;
        // Ignored by sprites.
        arcade::Color color;
        // If the game object is a circle, this should be filled.
        // It is ignored otherwise.
        float circle_radius;
        arcade::Vector2 rect_dimensions;
        // Sprite sources expects the name of the asset without the extension of the file
        // The function will append the right extension to find the file, corresponding to the file
        // If the file is not found, the game will stop and return to the menu until the right file is found
        // File extensions are: .txt for ncurses, .png for all the others
        std::string sprite_src;
        std::string text_string;
        arcade::Vector2 line_end;
    };

    // Circle centered at pos of r radius.
    struct Circle : public GameObject
    {
        Circle(std::size_t r);
        ~Circle(void) = default;
    };

    // Rect constructed from the top-left corner, going right and down
    // x is horizontal length, y is vertical.
    struct Rectangle : public GameObject
    {
        Rectangle(Vector2 dims);
        ~Rectangle(void) = default;
    };

    // line from pos to end;
    struct Line : public GameObject
    {
        Line(Vector2 _end);
        ~Line(void) = default;
    };

    // Sprite wrapper to be used differently in each library
    // contains a void * to the "real" object specific to each library
    struct Sprite : public GameObject {
        Sprite(std::string source);
        ~Sprite(void) = default;
    };

    struct Text : public GameObject {
        Text(std::string text);
        ~Text(void) = default;
    };
}
