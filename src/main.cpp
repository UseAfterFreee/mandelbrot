#include <iostream>
#include <SDL2/SDL.h>

#include "window.hpp"
#include "mandelbrot.hpp"
#include "event_handler.hpp"

#define WINDOW_WIDTH 1000
#define WINDOW_HEIGHT 1000

int main(int argc, char* argv[])
{
    window window(WINDOW_WIDTH, WINDOW_HEIGHT);
    EventHandler eh;
    Mandelbrot m(WINDOW_WIDTH);

    window.createWindow();

    m.calculate();
    m.change_complex_dimensions(-1,0,-1,0);
    while (!eh.needQuit())
    {
        eh.handleEvents();

        m.draw(window.getRenderer());

        SDL_RenderPresent(window.getRenderer());
        SDL_Delay(1000/60.0);
    }
}
