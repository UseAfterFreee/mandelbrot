/* Class and function definitions of the event handler */

#include "event_handler.hpp"
#include "complex.hpp"

EventHandler::EventHandler(int window_width, int window_height)
{
    zoombox.x = 0;
    zoombox.y = 0;
    zoombox.h = 10;

    /* The width to height ratio of the zoombox and the window should be equal */
    ratio = ((double)window_width / window_height);
    zoombox.w = zoombox.h * ratio;
}

void EventHandler::handleEvents(Mandelbrot& m)
{
    while (SDL_PollEvent(&event))
    {
        /* Quit Event handling */
        if (event.type==SDL_QUIT)
            need_quit = true;

        /* Key Event handling */
        if (event.type==SDL_KEYDOWN)
        {
            /* Reset zoom key */
            if (event.key.keysym.scancode == SDL_SCANCODE_R)
                m.reset_complex_dimensions();
        }

        /* Mouse movement handling */
        if (event.type == SDL_MOUSEMOTION)
        {
            zoombox.x = event.motion.x;
            zoombox.y = event.motion.y;
        }

        /* Mouse scroll handling */
        if (event.type == SDL_MOUSEWHEEL)
        {
            zoombox.h += event.wheel.y;
            zoombox.w = zoombox.h * ratio;
        }

        /* Mouse click handling */
        if (event.type == SDL_MOUSEBUTTONUP)
        {
            int lowabsx  = zoombox.x;
            int highabsx = zoombox.x + zoombox.w;
            int lowabsy  = zoombox.y;
            int highabsy = zoombox.y + zoombox.h;
            
            Complex up_left    = m.GetComplexFromPixel(lowabsx , lowabsy );
            Complex down_right = m.GetComplexFromPixel(highabsx, highabsy);

            m.change_complex_dimensions(up_left.real, down_right.real, down_right.imag, up_left.imag);
        }
    }
}

bool EventHandler::needQuit()
{
    return need_quit;
}

const SDL_Rect& EventHandler::getZoombox()
{
    return zoombox;
}
