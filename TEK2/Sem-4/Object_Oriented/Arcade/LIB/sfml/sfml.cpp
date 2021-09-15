/*
** EPITECH PROJECT, 2021
** B-OOP-400-MPL-4-1-arcade-corentin.petrau
** File description:
** sfml
*/

#include "sfml.hpp"

arcade::Sfml::Sfml()
{
}

void arcade::Sfml::init()
{
    _window.create(sf::VideoMode(700, 700), this->getName());
}

void arcade::Sfml::stop()
{
    _window.close();
}

void arcade::Sfml::draw(GameObject &entity)
{
    if (entity.type == arcade::GameObject::ObjectType::SPRITE) {
        sf::Texture texture;
        texture.loadFromFile(entity.sprite_src);
        sf::Sprite sprite(texture);
        sprite.setPosition(sf::Vector2f(entity.position.y*10, entity.position.x*10));
        _window.draw(sprite);
    }
}

std::vector<arcade::Input::Key> arcade::Sfml::get_input()
{
    std::vector<arcade::Input::Key> key;
    sf::Event events;
    while (_window.pollEvent(events)) {
        if (events.type == sf::Event::Closed)
            key.push_back(arcade::Input::Closed);
        if(events.type == sf::Event::KeyPressed) {
            switch(events.key.code) {
                case sf::Keyboard::Z:
                    key.push_back(arcade::Input::Z);
                    break;
                case sf::Keyboard::Q:
                    key.push_back(arcade::Input::Q);
                    break;
                case sf::Keyboard::S:
                    key.push_back(arcade::Input::S);
                    break;
                case sf::Keyboard::D:
                    key.push_back(arcade::Input::D);
                    break;
                case sf::Keyboard::Up:
                    key.push_back(arcade::Input::Up);
                    break;
                case sf::Keyboard::Down:
                    key.push_back(arcade::Input::Down);
                    break;
                case sf::Keyboard::Left:
                    key.push_back(arcade::Input::Left);
                    break;
                case sf::Keyboard::Right:
                    key.push_back(arcade::Input::Right);
                    break;
                case sf::Keyboard::R:
                    key.push_back(arcade::Input::R);
                    break;
                case sf::Keyboard::V:
                    key.push_back(arcade::Input::V);
                    break;
                case sf::Keyboard::M:
                    key.push_back(arcade::Input::M);
                    break;
                case sf::Keyboard::Y:
                    key.push_back(arcade::Input::Y);
                    break;
                case sf::Keyboard::U:
                    key.push_back(arcade::Input::U);
                    break;
                case sf::Keyboard::H:
                    _window.clear();
                    key.push_back(arcade::Input::H);
                    break;
                case sf::Keyboard::J:
                    _window.clear();
                    key.push_back(arcade::Input::J);
                    break;
                default : 
                    key.push_back(arcade::Input::Unknown);
                    break; 
            }
        }
    }
    return(key);
}

void arcade::Sfml::clear()
{
}

void arcade::Sfml::display()
{
    //_window.clear();
    _window.display();
}

extern "C" {
    arcade::IGraphicalLibrary *entryPoint(void) {
        return(new arcade::Sfml());
    }
}