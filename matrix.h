#include <iostream>

using namespace std;

template <class T> class Matrix
{
    private:
        size_t nrows;
        size_t ncols;
    public:
        Matrix();
        Matrix(int nrows, int ncols);
        Matrix(int nrows, int ncols, const T *mat_data);
        void print();
};

template <class T> Matrix<T>::Matrix()
{
    mat_nrows = 1;
    mat_ncols = 1;
    mat_nels = 1;
    mat_data = nullptr;
}

template <class T> Matrix<T>::Matrix(int nrows, int ncols)
{
    mat_nrows = nrows;
    mat_ncols = ncols;
    mat_nels = m_nrows * m_ncols;
    mat_data = new T[mat_nels];
    for (int i = 0; i < mat_nels; i++)
    {
        *(mat_data + i) = 0;
    }
}

template <class T> void Matrix<T>::print()
{
    for (int i = 0; i < nrows; i++)
    {
        for (int j = 0; j < ncols; j++)
        {
            std::cout << Matrix[i][j] << " ";
        }
        std::cout << endl;
    }
}