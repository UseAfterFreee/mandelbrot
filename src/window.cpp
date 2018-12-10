/* Class and function definition for window.hpp */

#include "window.hpp"

window::window()
    : width(800), height(600)
{
}

window::window(const int& width, const int& height)
    : width(width), height(height)
{
}

void window::createWindow()
{
    SDL_CreateWindowAndRenderer(width, height, 0, &window_object, &renderer);
}

SDL_Renderer* window::getRenderer()
{
    return renderer;
}

void window::drawBackground(char r, char g, char b)
{
    if (!surf) SDL_GetWindowSurface(window_object);
    SDL_SetRenderDrawColor(renderer, r, g, b, 255);
    SDL_RenderClear(renderer);

}
