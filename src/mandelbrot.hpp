#ifndef MANDELBROT_H
#define MANDELBROT_H

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
        Complex GetComplexFromPixel(int x, int y);
        double GetYFromImag(double imag);
        void change_complex_dimensions(double lx, double hx, double ly, double hy);
        void reset_complex_dimensions();
        void draw(SDL_Renderer* r);
};

#endif
