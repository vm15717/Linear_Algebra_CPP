#include <iostream>
#include <cmath>
class Dual
{
    private:
    double reala;
    double realb;
    public:
    // Constructor
    Dual(double a = 0, double b = 0) : reala(a), realb(b) {}
    // Copy Constructor 
    Dual(const Dual &dual): reala(dual.geta()), realb(dual.getb()){}
    // Getters
    double geta() const
    {
        return reala;
    }
    double getb() const
    {
        return realb;
    }
    // Setters
    void seta(double a)
    {
        reala = a;
    }
    void setb(double b)
    {
        realb = b;
    }
    // Operators
    Dual operator+(const Dual &other) const
    {
        return Dual(reala + other.reala, realb + other.realb);
    }
    Dual operator-(const Dual &other) const
    {
        return *this + Dual(-other.reala, -other.realb);
    }
    Dual operator*(const Dual &other) const
    {
        return Dual(reala*other.reala, realb*other.reala + reala*other.realb);
    }
    Dual operator/(const Dual &other) const
    {
        if (other.reala == 0)
        {
            if (reala == 0)
            {
                return Dual(realb/other.realb, 0);
            }
            else
            {
                throw std::invalid_argument("Cannot perform division");
            }
        }
        return Dual(reala/other.reala, (realb * other.reala - reala * other.realb)/(other.reala * other.reala));
    }
    bool operator==(const Dual &other) const
    {
        return reala == other.reala && realb == other.realb;
    }
    friend std::ostream &operator<<(std::ostream &out, const Dual &dual)
    {
        if (dual.realb == 0)
        {
            out << dual.reala;
        }
        else if (dual.reala == 0)
        {
            out << dual.realb << "e";
        }
        else if (dual.realb < 0)
        {
            out << dual.reala << " - " << -dual.realb << "e";
        }
        else
        {
            out << dual.reala << " + " << dual.realb << "e";
        }
        return out;
    }
    Dual apply(double (*f)(double), double (*df)(double)) const
    {
        return Dual(f(reala), realb * df(reala));
    }
};
// functions
inline Dual sin(const Dual &dual)
{
        return Dual(std::sin(dual.geta()), std::cos(dual.geta())*dual.getb());
}

inline Dual cos(const Dual &dual)
{
        return Dual(std::cos(dual.geta()), -std::sin(dual.geta())*dual.getb());
}

inline Dual pow(const Dual &dual, const int n)
{
    return Dual(std::pow(dual.geta(), n), n*std::pow(dual.geta(), n-1)*dual.getb());
}