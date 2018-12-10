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
    while (!eh.needQuit())
    {
        eh.handleEvents();
        window.drawBackground(255,0,0);

        m.draw(window.getRenderer());

        SDL_RenderPresent(window.getRenderer());
        SDL_Delay(1000/60.0);
    }
}
