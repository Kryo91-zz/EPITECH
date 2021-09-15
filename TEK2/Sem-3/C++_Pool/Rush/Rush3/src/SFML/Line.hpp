/*
** EPITECH PROJECT, 2020
** B-CPP-300-MPL-3-1-CPPrush3-lyvia.mallereau
** File description:
** Line.hpp
*/

#ifndef LINE_HPP_
    #define LINE_HPP_

    #include <SFML/Graphics.hpp>
    #include <SFML/Window.hpp>
    #include <SFML/System.hpp>

    class Line
    {
        private:
            sf::Font _font;
            sf::Text _left;
            sf::Text _right;
            sf::Vector2f _pos;
            sf::Vector2f _dimensions;
            int _padding = 0;
        public:
            Line(const std::string left, const std::string right, const sf::Vector2f pos, const sf::Vector2f dimensions);
            ~Line(void);

            void setPos(const sf::Vector2f pos);
            void setText(const std::string left, const std::string right);
            void draw(sf::RenderWindow &window);
    };

#endif