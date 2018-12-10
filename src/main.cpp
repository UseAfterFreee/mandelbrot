#include <iostream>
#include <SDL2/SDL.h>

#include "window.hpp"
#include "mandelbrot.hpp"
#include "event_handler.hpp"

#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 600

int main(int argc, char* argv[])
{
    window window(WINDOW_WIDTH, WINDOW_HEIGHT);
    EventHandler eh(WINDOW_WIDTH, WINDOW_HEIGHT);
    Mandelbrot m(WINDOW_WIDTH, WINDOW_HEIGHT);

    window.createWindow();

    m.change_complex_dimensions(-0.8, -0.5, -0.75, -0.25);
    while (!eh.needQuit())
    {
        eh.handleEvents(m);

        m.draw(window.getRenderer());
        SDL_SetRenderDrawColor(window.getRenderer(), 255,0,0,255);
        SDL_RenderDrawRect(window.getRenderer(), &eh.getZoombox());

        SDL_RenderPresent(window.getRenderer());
        SDL_Delay(1000/60.0);
    }
}
