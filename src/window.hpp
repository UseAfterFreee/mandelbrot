#include <SDL2/SDL.h>

class window
{
    private:
        const int width, height;
        SDL_Window *window_object;
        SDL_Surface *surf = nullptr;
        SDL_Renderer *renderer;

    public:
        window(); // Default window will have size 800*600
        window(const int& width, const int& height); // Window with with specified sizes
        SDL_Renderer* getRenderer();

        void createWindow();
        void drawBackground(char r, char g, char b); // Chars because we only need 1 byte, we're not actually using chars.
};
