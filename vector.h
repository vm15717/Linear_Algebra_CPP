#include <iostream>
#include "mysqrt.cpp"
using namespace std;

template <class T> class Vector
{
    private:
        size_t vec_nels;
        T *vec_data;
    public:
        // Constructors
        Vector();
        Vector(size_t nels);
        Vector(size_t nels, const T *inputData);
        // Destructors
        ~Vector();
        // Helper methods
        void printVector();
        size_t get_dims();
        T get_elem(int pos);
        // Mathematical methods
        T norm();
        void normalise();
};

template <class T> Vector<T>::Vector()
{
    vec_nels = 1;
    vec_data = nullptr;
}

template <class T> Vector<T>::Vector(size_t nels)
{
    vec_nels = nels;
    vec_data = new T[vec_nels];
    for (int i = 0; i < vec_nels; i++)
    {
        vec_data[i] = 0;
    }
}

template <class T> Vector<T>::Vector(size_t nels, const T *inputData)
{
    vec_nels = nels;
    vec_data = new T[vec_nels];
    for (int i = 0; i < vec_nels; i++)
    {
        vec_data[i] = inputData[i];
    }
}

template <class T> Vector<T>::~Vector()
{

}

template <class T> T Vector<T>::norm()
{
    T norm_sum = 0;
    for (int i = 0; i < vec_nels; i++)
    {
        norm_sum += vec_data[i]*vec_data[i];
    }
    return mysqrt(norm_sum);
}

template <class T> size_t Vector<T>::get_dims()
{
    return vec_nels;
}

template <class T> void Vector<T>::normalise()
{
    T vec_norm = this->norm();
    for (int i = 0; i < vec_nels; i++)
    {
        vec_data[i] = vec_data[i]/vec_norm;
    }
}

template <class T> void Vector<T>::printVector()
{
    for (int i = 0; i < vec_nels; i++)
    {
        cout << vec_data[i] << " ";
    }
}

template <class T> T Vector<T>::get_elem(int pos)
{
    return vec_data[pos]
}