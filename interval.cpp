#include <iostream>
#include <stdexcept>
#include <cfenv>

#pragma STDC FENV_ACCESS ON

class Interval
{
    private:
    double start;
    double end;
    public:
    Interval(double a):start(a), end(a) {}
    Interval(double a = 0, double b = 0) {
        if (b < a)
        {
            throw std::invalid_argument("The end point of the interval must be greater than or equal to the starting point");
        }
        this->start = a;
        this->end = b;
    }
    bool in(double x)
    {
        return this->start <= x && this->end >= x;
    }
    double getstart()
    {
        return this->start;
    }
    double getend()
    {
        return this->end;
    }
    Interval operator+(Interval &other)
    {
        std::fesetround(FE_DOWNWARD);
        double a = other.getstart()  + start;
        std::fesetround(FE_UPWARD);
        double b = other.getend() + end;
        return Interval(a, b);
    }
    Interval operator/(Interval &other)
    {
        
    }
    Interval operator-(Interval &other)
    {
        return Interval(start - other.getend(), end - other.getstart());    
    }
};