/*
** EPITECH PROJECT, 2021
** B-OOP-400-MPL-4-1-arcade-corentin.petrau
** File description:
** sfml
*/

#ifndef SFML_HPP_
#define SFML_HPP_

#include "IGraphicalLibrary.hpp"

namespace arcade {
    class Sfml : public IGraphicalLibrary {
        public:
            Sfml();
            virtual ~Sfml() { SDL_Quit();};
            void init() override;
            void stop() override;
            const std::string &getName() {return(this->lib);};
            // // Draw uses the information contained in a GameObject to draw it onto the window
            // // Persist those changes with the display method.
            void draw(GameObject &entity) override;
            // // Returns all the pressed keys at the moment
            std::vector<Input::Key> get_input(void) override;
            // // Display should be called every frame,
            // // it persists any use of the draw function on the window
            void display(void) override;
            void clear(void) override;
        protected:
        private:
            std::string lib = "Sfml";
            sf::RenderWindow _window;
            int x = 0;
            int y = 0;
    };
    extern "C" {
        IGraphicalLibrary *entryPoint(void);
    }
}

#endif /* !SFML_HPP_ */
