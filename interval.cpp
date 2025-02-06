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
    Interval(double a, double b) {
        if (b < a)
        {
            throw std::invalid_argument("The end point of the interval must be greater than or equal to the starting point");
        }
        this->start = a;
        this->end = b;
    }
    Interval(double a) {Interval(a, a);}
    bool in(const double x)
    {
        return this->start <= x && this->end >= x;
    }
    double getstart() const
    {
        return this->start;
    }
    double getend() const
    {
        return this->end;
    }
    void setstart(const double a)
    {
        this->start = a;
    }
    void setend(const double b)
    {
        this->end = b;
    }
    Interval operator+(const Interval &other) const
    {
        int old_round = std::fegetround();
        std::fesetround(FE_DOWNWARD);
        double a = other.getstart()  + this->start;
        std::fesetround(FE_UPWARD);
        double b = other.getend() + this->end;
        std::fesetround(old_round);
        return Interval(a, b);
    }
    Interval operator/(const int n) const
    {
        if (n == 0)
        {
            throw std::invalid_argument("Cannot divide by 0.");
        }
        int old_round = std::fegetround();
        double a, b;
        std::fesetround(FE_DOWNWARD);
        if (n > 0)
        {
            a = this->start/n;       
        }
        else
        {
            a = this->end/n;
        }
        std::fesetround(FE_UPWARD);
        if (n > 0)
        {
            b = this->end/n;       
        }
        else
        {
            b = this->start/n;
        }
        std::fesetround(old_round);
        return Interval(a, b);
    }
    Interval operator+(double number)
    {
        int old_round = std::fegetround();
        std::fesetround(FE_DOWNWARD);
        double a = number + this->start;
        std::fesetround(FE_UPWARD);
        double b = number + this->end;
        std::fesetround(old_round);
        return Interval(a, b);    
    }
    Interval operator*(const Interval &other) const
    {
        if (!((other.getstart() >= 0) && (this->start >=0)))
        {
            throw std::invalid_argument("the intervals fail to satisfy positivity arguments");
        }
        int old_round = std::fegetround();
        std::fesetround(FE_DOWNWARD);
        double a = other.getstart()  * this->start;
        std::fesetround(FE_UPWARD);
        double b = other.getend() * this->end;
        std::fesetround(old_round);
        return Interval(a, b);    
    }
    Interval operator-(const Interval &other) const
    {
        int old_round = std::fegetround();
        std::fesetround(FE_DOWNWARD);
        double a = this->start - other.getend();
        std::fesetround(FE_UPWARD);
        double b = this->end - other.getstart();
        std::fesetround(old_round);
        return Interval(a, b);        
    }
    Interval operator-()
    {
        return Interval(-this->end, -this->start);
    }
    Interval pow(const int n) const
    {
        Interval result = Interval(1.0);
        if (n < 0)
        {
           throw std::invalid_argument("need positive power to satisfy positivity arguments"); 
        }
        else
        {
            for (int j = 0; j < n; j++)
            {
                result = (*this) * result;
            }
        }
        return result;
    }
    friend std::ostream &operator<<(std::ostream &out, const Interval &interval)
    {
        out << "[" << interval.getstart() << ", " << interval.getend() << "]";
        return out;
    }
};