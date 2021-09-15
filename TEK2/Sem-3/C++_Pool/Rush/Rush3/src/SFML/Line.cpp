/*
** EPITECH PROJECT, 2020
** B-CPP-300-MPL-3-1-CPPrush3-lyvia.mallereau
** File description:
** Line.cpp
*/

#include "Line.hpp"

Line::Line(const std::string left, const std::string right, const sf::Vector2f pos, const sf::Vector2f dimensions):
    _pos(pos), _dimensions(dimensions)
{
    if (!_font.loadFromFile("./src/SFML/Roboto-Regular.ttf")) {
        throw std::runtime_error("Font was not loaded");
    }
    this->_left = sf::Text(left, _font, 50);
    this->_right = sf::Text(right, _font, 50);

    this->_left.setFillColor(sf::Color::White);
    this->_right.setFillColor(sf::Color::White);

    this->setPos(pos);
}

Line::~Line(void)
{
}

void Line::setPos(const sf::Vector2f pos)
{
    this->_pos = pos;
    sf::Vector2f left_pos = {pos.x + _padding, pos.y + _dimensions.y/2};
    sf::Vector2f right_pos = {pos.x + _padding + _dimensions.x/2, pos.y + _dimensions.y/2};

    this->_left.setPosition(left_pos);
    this->_right.setPosition(right_pos);
}

void Line::setText(const std::string left, const std::string right)
{
    this->_left.setString(left);
    this->_right.setString(right);
}

void Line::draw(sf::RenderWindow &window)
{
    window.draw(this->_left);
    window.draw(this->_right);
}