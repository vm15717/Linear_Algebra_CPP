#include <iostream>

using namespace std;

template <class T> class Matrix
{
    private:
        size_t nrows;
        size_t ncols;
        T *mat_data;
    public:
        // Constructors
        Matrix();
        Matrix(int nrows, int ncols, const T val);
        Matrix(int nrows, int ncols, const T *input_data);
        // Destructors
        ~Matrix();
        // Helper methods
        void printMatrix() const;
        T get_elem(int row, int col);
        void set_elem(int row, int col, T num);
        // Mathematical Operations
        T trace();
        T determinant();
        T zero_norm();
        T inf_norm();
};

template <class T> Matrix<T>::Matrix()
{
    mat_nrows = 1;
    mat_ncols = 1;
    mat_nels = 1;
    mat_data = nullptr;
}

template <class T> Matrix<T>::Matrix(int nrows, int ncols, const T val)
{
    mat_nrows = nrows;
    mat_ncols = ncols;
    mat_nels = m_nrows * m_ncols;
    mat_data = new T[mat_nels];
    for (int i = 0; i < mat_nels; i++)
    {
        *(mat_data + i) = val;
    }
}

template <class T> Matrix<T>::Matrix(int nrows, int ncols, const T *input_data)
{
    mat_nrows = nrows;
    mat_ncols = ncols;
    mat_nels = m_nrows * m_ncols;
    mat_data = new T[mat_nels];
    for (int i = 0; i < mat_nels; i++)
    {
        mat_data[i] = input_data[i];
    }
}

template <class T> void Matrix<T>::printMatrix() const
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

template <class T> Matrix<T>::~Matrix()
{

}