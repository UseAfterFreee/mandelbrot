#include "mandelbrot.hpp"

Mandelbrot::Mandelbrot(int size)
    : dimension(size), low_x(-2), high_x(1), low_y(-1), high_y(1)
{
    pixels = new byte[size*size];
}

Mandelbrot::~Mandelbrot()
{
    delete[] pixels;
}

double Mandelbrot::map(double x, double low, double high, double newlow, double newhigh)
{
    double percentage = (x-low)/(high-low);
    return newlow + percentage * (newhigh - newlow);
}

void Mandelbrot::calculate()
{
    for (int x = 0; x<dimension; ++x)
    {
        for (int y = 0; y<dimension; ++y)
        {
            pixels[x+dimension*y] = 255;
            double real = map(x, 0, dimension, low_x, high_x);
            double imag = map(y, 0, dimension, low_y, high_y);
            Complex c(real, imag);

            Complex current = c;
            int max_iters = 100;
            bool found = false;
            for(int i = 0; i < max_iters; ++i)
            {
                current = current.square()+c;
                if (current.abssqr() > 4)
                    found = true;
            }
            if (!found)
                pixels[x+dimension*y] = 0;
        }
    }
}

void Mandelbrot::draw(SDL_Renderer* r)
{
    for (int x = 0; x<dimension; ++x)
    {
        for (int y = 0; y<dimension; ++y)
        {
            int index = x+dimension*y;
            SDL_SetRenderDrawColor(r, pixels[index], pixels[index], pixels[index], 255);
            SDL_RenderDrawPoint(r, x, y);
        }
    }
}
