#ifndef COMPLEX_H
#define COMPLEX_H

#include <iostream>

class Complex
{
    private:
    public:
        double real, imag;
        Complex(double real, double imag);

        Complex operator+(const Complex& rhs) const;
        Complex operator-(const Complex& rhs) const;

        Complex square();
        double abssqr();

        friend std::ostream& operator<<(std::ostream& os, const Complex& c);
};

#endif
