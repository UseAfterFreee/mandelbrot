#include "complex.hpp"

Complex::Complex(double real, double imag)
    : real(real), imag(imag)
{
}

double Complex::abssqr()
{
    return (real*real+imag*imag);
}

Complex Complex::operator+(const Complex& rhs) const
{
    return Complex(real+rhs.real, imag+rhs.imag);
}

Complex Complex::operator-(const Complex& rhs) const
{
    return Complex(real-rhs.real, imag-rhs.imag);
}

Complex Complex::square()
{
    return Complex(real*real-imag*imag, 2*real*imag);
}

std::ostream& operator<<(std::ostream& os, const Complex& c)
{
    os << c.real << "+ i" << c.imag;
    return os;
}
