/*
** EPITECH PROJECT, 2021
** B-OOP-400-MPL-4-1-arcade-corentin.petrau
** File description:
** sdl2
*/

#ifndef SDL2_HPP_
#define SDL2_HPP_

#include "IGraphicalLibrary.hpp"

namespace arcade {
    class Sdl2 : public IGraphicalLibrary {
        public:
            Sdl2();
            virtual ~Sdl2() { SDL_Quit();};
            virtual void init();
            virtual void stop();
            virtual const std::string &getName() {return(this->lib);};
            // // Draw uses the information contained in a GameObject to draw it onto the window
            // // Persist those changes with the display method.
            virtual void draw(GameObject &entity);
            // // Returns all the pressed keys at the moment
            virtual std::vector<Input::Key> get_input(void);
            // // Display should be called every frame,
            // // it persists any use of the draw function on the window
            virtual void display(void);
            void clear(void) override;
            SDL_Event event;
        protected:
        private:
            std::string lib = "SDL2";
            SDL_Window *_window;
            int x = 0;
            int y = 0;
            SDL_Renderer *_renderer;
            std::string block;
    };
    extern "C" {
        IGraphicalLibrary *entryPoint(void);
    }
}

#endif /* !SDL2_HPP_ */
