#include "complex.hpp"
#include <SDL2/SDL.h>

typedef char byte;

class Mandelbrot
{
    private:
        byte* pixels;
        int dimension;

        double low_x, high_x;
        double low_y, high_y;

        double map(double x, double low, double high, double newlow, double newhigh);
    public:
        Mandelbrot(int window_width);
        ~Mandelbrot();

        void calculate();
        void draw(SDL_Renderer* r);
};
