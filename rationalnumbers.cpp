#include <iostream>
#include <stdexcept>
#include <numeric>
class Rational
{
    private:
    int numerator;
    int denominator;
    void simplify()
    {
        int gcd = std::gcd(numerator, denominator);
        numerator = numerator/gcd;
        denominator = denominator/gcd;
        if (denominator < 0)
        {
            denominator = -denominator;
            numerator = -numerator;
        }
    }
    public:
    Rational (int num = 0, int denom = 1) : numerator(num), denominator(denom)
    {
        if (denom == 0)
        {
            throw std::invalid_argument("Denominator cannot be zero.");
        }
        simplify();
    }
    // Getters
    int getnumerator()
    {
        return numerator;
    }
    int getdenominator()
    {
        return denominator;
    }
    // Setters
    void setnumerator(int num)
    {
        numerator = num;
        simplify();
    }
    void setdenominator(int denom)
    {
         if (denom == 0)
        {
            throw std::invalid_argument("Denominator cannot be zero.");
        }
        denominator = denom;
        simplify();
    }
    // Operator overloading
    Rational operator+(const Rational &other)
    {
        int newnum = numerator * other.denominator + denominator * other.numerator;
        int newdenom = denominator * other.denominator;
        return Rational(newnum, newdenom);
    }
    Rational operator-(const Rational &other)
    {
        return Rational(numerator, denominator) + Rational(-other.numerator, -other.denominator);
    }
    Rational operator*(const Rational &other)
    {
        int newnum = numerator * other.numerator;
        int newdenom = denominator * other.denominator;
        return Rational(newnum, newdenom);
    }
    Rational operator/(const Rational &other)
    {
        if (other.numerator == 0)
        {
            throw std::invalid_argument("Cannot do division by 0");
        }
        return Rational(numerator, denominator) * Rational(other.denominator, other.numerator);
    }
    bool operator==(const Rational &other)
    {
        return numerator == other.numerator && denominator == other.denominator;
    }
    bool operator<(const Rational &other)
    {
        return numerator*other.denominator < other.numerator*denominator;
    }
    friend std::ostream &operator<<(std::ostream &out, const Rational &r)
    {
        if (r.denominator == 1)
        {
            out << r.numerator;
        }
        else
        {
            out << r.numerator << "/" << r.denominator;
        }
        return out;
    }

};