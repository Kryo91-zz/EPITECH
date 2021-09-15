/*
** EPITECH PROJECT, 2021
** B-OOP-400-MPL-4-1-arcade-corentin.petrau
** File description:
** GameObject
*/



#include "GameObject.hpp"

namespace arcade
{
    Color::Color(uint8_t _r, uint8_t _g, uint8_t _b, uint8_t _a):
        r(_r), g(_g), b(_b), a(_a)
    {}
    Color::Color(int hex):
        r((hex & 0xFF0000) >> 16),
        g((hex & 0x00FF00) >> 8),
        b(hex & 0x0000FF),
        a(1)
    {}
    uint64_t Color::get_hex(void)
    {
        return ((r>>3*8) | (g>>2*8) | (b>>8) | a);
    }

    Vector2::Vector2(float _x, float _y):
        x(_x), y(_y)
    {}

    GameObject::GameObject(void):
        color(0xFFFFFF)
    {}

    Circle::Circle(std::size_t r)
    {
        this->circle_radius = r;
        this->type = GameObject::ObjectType::CIRCLE;
    }

    Rectangle::Rectangle(Vector2 dims)
    {
        this->rect_dimensions = dims;
        this->type = GameObject::ObjectType::RECTANGLE;
    }

    Line::Line(Vector2 _end)
    {
        this->line_end = _end;
        this->type = GameObject::ObjectType::LINE;
    }

    Text::Text(std::string text)
    {
        this->text_string = text;
        this->type = GameObject::ObjectType::TEXT;
    }

    Sprite::Sprite(std::string _src)
    {
        this->sprite_src = _src;
        this->type = GameObject::ObjectType::SPRITE;
    }
} // namespace arcade
