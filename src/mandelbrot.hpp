#include "complex.hpp"
#include <SDL2/SDL.h>

typedef char byte;

class Mandelbrot
{
    private:
        byte* pixels;
        int width;
        int height;

        double low_x, high_x;
        double low_y, high_y;

        double map(double x, double low, double high, double newlow, double newhigh);
    public:
        Mandelbrot(int window_width);
        Mandelbrot(int window_width, int window_height);
        ~Mandelbrot();

        void calculate();
        void draw(SDL_Renderer* r);
};
