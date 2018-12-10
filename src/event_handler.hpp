/* Event handler */

#include <SDL2/SDL.h>
#include "mandelbrot.hpp"

class EventHandler
{
    private:
        SDL_Event event;

        SDL_Rect zoombox;

        double ratio;

        // This one is private because only the handler should change it
        bool need_quit = false; 
    public:
        EventHandler(int width, int height); // Constructor

        const SDL_Rect& getZoombox();
        void handleEvents(Mandelbrot& m); // Handle all events in the event queue
        bool needQuit(); // Checks if the window should quit
};
