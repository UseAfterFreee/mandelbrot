/* Class and function definitions of the event handler */

#include "event_handler.hpp"

EventHandler::EventHandler()
{
}

void EventHandler::handleEvents(Mandelbrot& m)
{
    while (SDL_PollEvent(&event))
    {
        if (event.type==SDL_QUIT)
            need_quit = true;
        if (event.type==SDL_KEYDOWN)
        {
            if (event.key.keysym.scancode == SDL_SCANCODE_R)
                m.reset_complex_dimensions();
        }
    }
}

bool EventHandler::needQuit()
{
    return need_quit;
}
