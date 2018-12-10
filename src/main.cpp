#include <iostream>
#include <SDL2/SDL.h>

#include "window.hpp"
#include "event_handler.hpp"

int main(int argc, char* argv[])
{
    window window(1000, 1000);
    EventHandler eh;

    window.createWindow();

    while (!eh.needQuit())
    {
        eh.handleEvents();
        window.drawBackground(255,0,0);

        SDL_RenderPresent(window.getRenderer());
        SDL_Delay(1000/60.0);
    }
}
