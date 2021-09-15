/*
** EPITECH PROJECT, 2020
** B-CPP-300-MPL-3-1-CPPrush3-lyvia.mallereau
** File description:
** int.cpp
*/

#include "init.hpp"
#include "Line.hpp"
#include "GKrellm.hpp"

void start_sfml()
{
    SysData data;
    sf::RenderWindow window(sf::VideoMode(1240, 900), "MyGKrellm");
    sf::RectangleShape header(sf::Vector2f(1240.f, 900.f));
    header.setFillColor(sf::Color(0x2f3036ff));
    sf::Clock Clock;
    sf::Font font;
    font.loadFromFile("./src/SFML/Roboto-Regular.ttf");
    sf::Text text(data.getData(), font, 30);
    text.setPosition({5, 5});

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        if (Clock.getElapsedTime().asSeconds() > 1)
        {
            data.refreshData();
            text.setString(data.getData());
            Clock.restart();
        }
        window.clear();
        window.draw(header);
        window.draw(text);
        window.display();
    }
}