/*
** EPITECH PROJECT, 2020
** B-OOP-400-MPL-4-1-arcade-corentin.petrau
** File description:
** sdl2.cpp
*/

#include "sdl2.hpp"

arcade::Sdl2::Sdl2()
{
}

void arcade::Sdl2::init()
{
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "[DEBUG] > %s", SDL_GetError());
        exit(84);
    }

    if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
        exit(84);
    SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "linear");
    if (SDL_CreateWindowAndRenderer(700, 700, SDL_WINDOW_SHOWN, &this->_window, &this->_renderer) < 0) {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "[DEBUG] > %s", SDL_GetError());
        SDL_Quit(); 
        exit(84);
    }
    SDL_SetRenderDrawBlendMode(_renderer, SDL_BLENDMODE_BLEND);
}

void arcade::Sdl2::stop()
{
    SDL_Quit();
}

void arcade::Sdl2::draw(GameObject &entity)
{
    if (entity.type == arcade::GameObject::ObjectType::SPRITE) {
        SDL_Texture *img = NULL;
        int w = 0;
        int h = 0;
        img = IMG_LoadTexture(_renderer, entity.sprite_src.c_str());
        SDL_QueryTexture(img, NULL, NULL, &w, &h);
        SDL_Rect texr;
        texr.x = entity.position.y*10;
        texr.y = entity.position.x*10;
        texr.w = w;
        texr.h = h;
        SDL_RenderCopy(this->_renderer, img, NULL, &texr);
        SDL_DestroyTexture(img);
    }
}

std::vector<arcade::Input::Key> arcade::Sdl2::get_input()
{
    std::vector<arcade::Input::Key> key;
    SDL_Event events;
    SDL_PollEvent(&events);
    switch (events.type) {
        case SDL_QUIT:
            key.push_back(arcade::Input::Closed);
            break;
    }
    if (events.type == SDL_KEYDOWN) {
        switch (events.key.keysym.sym) {
            case SDLK_z:
                key.push_back(arcade::Input::Z);
                break;
            case SDLK_q:
                key.push_back(arcade::Input::Q);
                break;
            case SDLK_s:
                key.push_back(arcade::Input::S);
                break;
            case SDLK_d:
                key.push_back(arcade::Input::D);
                break;
            case SDLK_UP:
                key.push_back(arcade::Input::Up);
                break;
            case SDLK_DOWN:
                key.push_back(arcade::Input::Down);
                break;
            case SDLK_LEFT:
                key.push_back(arcade::Input::Left);
                break;
            case SDLK_RIGHT:
                key.push_back(arcade::Input::Right);
                break;
            case SDLK_r:
                key.push_back(arcade::Input::R);
                break;
            case SDLK_v:
                key.push_back(arcade::Input::V);
                break;
            case SDLK_m:
                key.push_back(arcade::Input::M);
                break;
            case SDLK_y:
                key.push_back(arcade::Input::Y);
                break;
            case SDLK_u:
                key.push_back(arcade::Input::U);
                break;
            default:
                key.push_back(arcade::Input::Unknown);
                break;
        }
    }
    return(key);
}

void arcade::Sdl2::clear(void)
{
    SDL_SetRenderDrawColor(_renderer, 0, 0, 0, 255);
    SDL_RenderClear(_renderer);
}

void arcade::Sdl2::display(void)
{
    SDL_RenderPresent(this->_renderer);
}

extern "C" {
    arcade::IGraphicalLibrary *entryPoint(void) {
        return(new arcade::Sdl2());
    }
}