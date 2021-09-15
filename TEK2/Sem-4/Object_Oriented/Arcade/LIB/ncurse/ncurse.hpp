/*
** EPITECH PROJECT, 2021
** B-OOP-400-MPL-4-1-arcade-corentin.petrau
** File description:
** ncurse
*/

#ifndef NCURSE_HPP_
#define NCURSE_HPP_

#include "IGraphicalLibrary.hpp"

namespace arcade {
    class Ncurse : public IGraphicalLibrary {
        public:
            Ncurse();
            virtual ~Ncurse() {};
            virtual void init();
            virtual void stop();
            virtual const std::string &getName(){return(this->lib);};
            // // Draw uses the information contained in a GameObject to draw it onto the window
            // // Persist those changes with the display method.
            virtual void draw(GameObject &entity);
            // // Returns all the pressed keys at the moment
            virtual std::vector<Input::Key> get_input(void);
            // // Display should be called every frame,
            // // it persists any use of the draw function on the window
            virtual void display(void);
            void clear(void) override;
        protected:
        private:
            WINDOW *_window;
            std::string lib = "ncurse";
            int x = 0;
            int y = 0;
            std::string block;
    };
    extern "C" {
        IGraphicalLibrary *entryPoint(void);
    }
}

#endif /* !NCURSE_HPP_ */