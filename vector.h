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
        Vector(size_t nels, const T val);
        Vector(size_t nels, const T *inputData);
        // Destructors
        ~Vector();
        // Helper methods
        void printVector() const;
        size_t get_dims();
        T get_elem(int pos);
        void set_elem(int pos, T value);
        // Mathematical methods
        T norm();
        void normalise();
        // Overloading methods
        Vector<T> operator+ (const Vector<T> &rightvector) const;
        Vector<T> operator- (const Vector<T> &rightvector) const;
        Vector<T> operator* (const T &righnum) const;
};

template <class T> Vector<T>::Vector()
{
    vec_nels = 1;
    vec_data = nullptr;
}

template <class T> Vector<T>::Vector(size_t nels, const T val)
{
    vec_nels = nels;
    vec_data = new T[vec_nels];
    for (int i = 0; i < vec_nels; i++)
    {
        vec_data[i] = val;
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

template <class T> void Vector<T>::printVector() const
{
    for (int i = 0; i < vec_nels; i++)
    {
        cout << vec_data[i] << " ";
    }
    cout << endl;
}

template <class T> T Vector<T>::get_elem(int pos)
{
    return vec_data[pos];
}

template <class T> void Vector<T>::set_elem(int pos, T value)
{
    vec_data[pos] = value;
}

template <class T> Vector<T> Vector<T>::operator+ (const Vector<T> &rightvector) const
{
    if (vec_nels != rightvector.vec_nels)
    {
        cout << "cannot add two vectors of different dimensions" << endl;
        return -1;
    }
    else
    {
        Vector result_vector(vec_nels, 0);
        for (int i = 0; i < vec_nels; i++)
        {
            result_vector.set_elem(i, vec_data[i] + rightvector.vec_data[i]);
        }
        return result_vector;
    }
}

template <class T> Vector<T> Vector<T>::operator* (const T &rightnum) const
{
    Vector result_vector(vec_nels, 0);
    for (int i = 0; i < vec_nels; i++)
    {
        result_vector.set_elem(i, vec_data[i] * rightnum);
    }
    return result_vector;
}

template <class T> Vector<T> Vector<T>::operator- (const Vector<T> &rightvector) const
{
    if (vec_nels != rightvector.vec_nels)
    {
        cout << "cannot add two vectors of different dimensions" << endl;
        return -1;
    }
    else
    {
        Vector result_vector(vec_nels, 0);
        for (int i = 0; i < vec_nels; i++)
        {
            result_vector.set_elem(i, vec_data[i] - rightvector.vec_data[i]);
        }
        return result_vector;
    }
}