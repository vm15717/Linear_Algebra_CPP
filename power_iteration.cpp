#include <iostream>
#include <random>
#include <cmath>

std::vector<double> matmul(std::vector <std::vector <double>> &A, std::vector <double> &b)
{
    if (A.empty())
    {
        throw std::invalid_argument("The matrix is empty!");
    }
    int n = A.size();
    int m1 = A[0].size();
    int m2 = b.size();
    if (m1 != m2)
    {
        throw std::invalid_argument("The number of cols in A dont match with number of rows in b");
    }
    std::vector <double> result(n, 0);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m2; j++)
        {
            result[i] += A[i][j]*b[j];
        }
    }
    return result;
}

void normdivide(std::vector <double> &b)
{
    int n = b.size();
    double sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += b[i]*b[i];
    }  
    double val = std::sqrt(sum);
    for (int i = 0; i < n; i++)
    {
        b[i] /= val;
    }
}
int main()
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::vector <std::vector<double>> A = {{3, 0, 0}, {0, 5, 0}, {0, 0, 1}};
    std::vector <double> b(3, 0);
    for (int i = 0; i < 3; i++)
    {
        std::uniform_real_distribution<double> dist(0, 1);
        b[i] = dist(gen);
    }
    for (int j = 0; j < 100; j++)
    {
        b = matmul(A, b);
        normdivide(b);
    }
    for (int i = 0; i < 3; i++)
    {
        std::cout << b[i] << std::endl;
    }
    auto result = matmul(A, b);
    std::cout << "\n";
    for (int i = 0; i < 3; i++)
    {
        std::cout << result[i] << std::endl;
    }
    //std::cout << "The Eigenvalues is: " << std::endl;
    return 0;
}


