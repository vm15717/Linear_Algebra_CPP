#include <iostream>
#include <exception>
template <typename T>

class Matrix
{
    private:
    std::vector<std::vector <T>> matrix;
    size_t rows, cols;
    public:
    Matrix(size_t r, size_t c, T default = T()) : rows(r), cols(c), matrix(r, std::vector <T>(c, default)) {}
    Matrix(size_t r , size_t c, const std::vector <std::vector <T>> &mat) : rows(r), cols(c), matrix(mat) 
    {
        if (r != mat.size() || (r > 0 && c != mat[0].size()))
        {
            throw std::invalid_argument("The matrix doesnt match its size");
        }
    }
    Matrix(const std::vector <std::vector <T>> &mat) : matrix(mat), rows(mat.size())
    {
        if (rows > 0)
        {
            cols = mat[0].size();
            for (const &row: rows)
            {
                if (row.size() != cols)
                {
                    throw std::invalid_argument("The matrix is jagged");
                }
            }
        }
    }
    Matrix multiply(const Matrix &other)
    {

    }
    Matrix dot(const Matrix &other)
    {

    }
    Matrix operator+(const Matrix &other) const
    {
        if (other.rows != rows && other.cols != cols)
        {
            throw std::invalid_argument("Cannot add matrices, the number of rows and columns do not match!")
        }
        Matrix result(rows, cols, 0);
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                result.matrix[i][j] = other.matrix[i][j] + matrix[i][j]
            }
        }
        return result;
    }
};