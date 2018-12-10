#include <iostream>
#include <SDL2/SDL.h>

#include "window.hpp"
#include "mandelbrot.hpp"
#include "event_handler.hpp"

int main(int argc, char* argv[])
{
    window window(1000, 1000);
    EventHandler eh;
    Mandelbrot m(1000);

    window.createWindow();

    m.calculate();
    while (!eh.needQuit())
    {
        eh.handleEvents();
        window.drawBackground(255,0,0);

        m.draw(window.getRenderer());

        SDL_RenderPresent(window.getRenderer());
        SDL_Delay(1000/60.0);
    }
}
