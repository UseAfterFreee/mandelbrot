#include "mandelbrot.hpp"

#define DEFAULT_LX -2
#define DEFAULT_HX  1
#define DEFAULT_LY -1
#define DEFAULT_HY  1

Mandelbrot::Mandelbrot(int size)
    : width(size), height(size), low_x(DEFAULT_LX), high_x(DEFAULT_HX), low_y(DEFAULT_LY), high_y(DEFAULT_HY)
{
    pixels = new byte[size*size];
}

Mandelbrot::Mandelbrot(int width, int height)
    : width(width), height(height), low_x(DEFAULT_LX), high_x(DEFAULT_HX), low_y(DEFAULT_LY), high_y(DEFAULT_HY)
{
    pixels = new byte[width*height];
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

Complex Mandelbrot::GetComplexFromPixel(int x, int y)
{
    double real = map(x, 0, width, low_x, high_x);
    double imag = map(y, 0, height, high_y, low_y); // Flipped x and y because pixels start at the top
    return Complex(real, imag);
}

void Mandelbrot::calculate()
{
    for (int x = 0; x<width; ++x)
    {
        for (int y = 0; y<height; ++y)
        {
            int index = x + width * y;

            Complex c = GetComplexFromPixel(x, y);

            Complex current = c;
            int max_iters = 100;
            bool unbounded = false;
            for(int i = 0; i < max_iters; ++i)
            {
                current = current.square()+c;
                if (current.abssqr() > 4)
                {
                    pixels[index] = i*(255/max_iters);
                    unbounded = true;
                }
            }
            if (!unbounded)
                pixels[index] = 0;
        }
    }
}

void Mandelbrot::draw(SDL_Renderer* r)
{
    for (int x = 0; x<width; ++x)
    {
        for (int y = 0; y<height; ++y)
        {
            int index = x+width*y;
            SDL_SetRenderDrawColor(r, 0, pixels[index], 0, 255);
            SDL_RenderDrawPoint(r, x, y);
        }
    }
}

void Mandelbrot::change_complex_dimensions(double lx, double hx, double ly, double hy)
{
    low_x = lx;
    high_x = hx;
    low_y = ly;
    high_y = hy;
    calculate();
}

void Mandelbrot::reset_complex_dimensions()
{
    low_x = DEFAULT_LX;
    high_x = DEFAULT_HX;
    low_y = DEFAULT_LY;
    high_y = DEFAULT_HY;
    calculate();
}
