/* Class and function definitions of the event handler */

#include "event_handler.hpp"

EventHandler::EventHandler()
{
}

void EventHandler::handleEvents()
{
    while (SDL_PollEvent(&event))
    {
        if (event.type==SDL_QUIT)
            need_quit = true;
    }
}

bool EventHandler::needQuit()
{
    return need_quit;
}
