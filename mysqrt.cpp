#include <iostream>
using namespace std;

template <typename T> T mysqrt(T num);
template <typename T> T init_guess(T num);
template <typename T> T myabs(T num);

template <typename T> T mysqrt(T num)
{
    if (num < 0)
    {
        cout << "Cannot calculate the square root of a negative number" << endl;
        return -1;
    }
    else
    {
        T num_abs = myabs(num);
        T init_val = init_guess(num_abs);
        T abs_err = myabs(num_abs - init_val * init_val);
        T iter_val = init_val;
        while (abs_err >= 1E-10)
        {
            iter_val = (iter_val + (num_abs / iter_val)) * (0.5);  
            abs_err = myabs(num_abs - iter_val * iter_val);
        }
        return iter_val;
    }
}

template <typename T> T init_guess(T num)
{
    T num_abs = myabs(num);
    for (int i = 0; i < num_abs; i++)
    {
        if (i * i > num_abs)
        {
            return i-1;
        }
    }
    return num_abs/2;
}

template <typename T> T myabs(T num)
{
    if (num > 0)
    {
        return num;
    }
    else
    {
        return -1*num;
    }
}