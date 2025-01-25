#include <iostream>
#include <stdexcept>
#include <cmath>

class Complex
{
    private:
    double real;
    double imag;
    public:
    Complex(double a = 0, double b = 0): real(a), imag(b) {}
    double getreal() const
    {
        return real;
    }
    double getimag() const
    {
        return imag;
    }
    void setreal(double a)
    {
        real = a;
    }
    void setimag(double b)
    {
        imag = b;
    }

    Complex operator+(const Complex &other) const
    {
        return Complex(real + other.real, imag + other.imag);
    }

    Complex operator-(const Complex &other) const
    {
        return *this + Complex(-other.real, -other.imag);
    }
    Complex operator*(const Complex &other) const 
    {
        return Complex(real*other.real - imag*other.imag, real*other.imag + imag*other.real);
    }
    Complex conjugate() const
    {
        return Complex(real, -imag);
    }
    double abs() const
    {
        return real*real + imag*imag;
    }
    Complex operator/(const Complex &other) const
    {
        if (other.real == 0 && other.imag == 0)
        {
            throw std::invalid_argument("Cannot divide by 0");
        }
        return Complex((real * other.real + imag * other.imag) / other.abs(), -other.imag*real + other.real*imag);
    }
    double argument() const 
    {
        return std::atan(imag/real);
    }
    friend std::ostream &operator<<(std::ostream &out, const Complex &complex)
    {
        if (complex.getimag() == 0)
        {
            out << complex.getreal();
        }
        else if (complex.getimag() < 0)
        {
            out << complex.getreal() << " - " << -complex.getimag() << "i";
        }
        else
        {
            out << complex.getreal() << " + " << complex.getimag() << "i";
        }
        return out;
    }
};