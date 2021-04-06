/*
Project:    Tridiagonal Solver
Author:     Joseph Butterworth
License:    This work is licensed under the Creative Commons Attribution-ShareAlike License.
            View this license at https://creativecommons.org/licenses/
*/

#include <iostream>
#include <iomanip>
#include <random>
#include <chrono>
#include <algorithm>
#include <vector>
#include "tridiagonal.h"
using std::cin;
using std::cout;
using std::endl;

std::default_random_engine dre(std::time(NULL));
std::uniform_real_distribution<double> dr(10, 20);

int main()
{
    //determine size of the matrix and vectoe
    int size;
    cout << "Enter the size of your Matrix." << endl;
    cin >> size;

    //generate tridiagonal matrix and vector
    std::vector<double> vec = VectorGenerate(size);
    std::vector<std::vector<double>> tridiag = TridiagonalGenerate(size);

    cout << endl
         << "Your tridiagonal matrix is:" << endl;
    TridiagonalPrint(size, tridiag);

    cout << "Your vector is:" << endl;
    VectorPrint(size, vec);

    //multiply tridiagonal matrix and vector
    std::vector<double> product = multiplication(size, vec, tridiag);

    cout << endl
         << "The product vector is:" << endl;
    VectorPrint(size, product);

    //solve for original vector from matrix and product
    std::vector<double> diag;
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            if (i == j)
            {
                diag.push_back(tridiag[i][j]);
            }
        }
    }

    std::vector<double> original = TridiagonalSolve(tridiag[0][1], diag, product, size);

    cout << endl
         << "The original vector was:" << endl;
    VectorPrint(size, original);
}

std::vector<double> VectorGenerate(int vec_size)
{
    std::vector<double> vec;

    for (int i = 0; i < vec_size; i++)
    {
        vec.push_back(dr(dre));
    }

    return vec;
}
std::vector<std::vector<double>> TridiagonalGenerate(int mat_size)
{
    std::vector<std::vector<double>> mat(mat_size); //Luchian Grigore at https://stackoverflow.com/questions/12375591/vector-of-vectors-to-create-matrix
    for (int i = 0; i < mat_size; i++)
    {
        mat[i].resize(mat_size);
    }

    double rand = dr(dre);
    for (int i = 0; i < mat_size; i++)
    {
        for (int j = 0; j < mat_size; j++)
        {
            if (i - 1 <= j && j <= i + 1)
            {
                mat[i][j] = rand;
            }
            else
            {
                mat[i][j] = 0;
            }
            if (i == j)
            {
                mat[i][j] = dr(dre);
            }
        }
    }

    return mat;
}

void VectorPrint(int vec_size, std::vector<double> &vec)
{
    for (int i = 0; i < vec_size; i++)
    {
        cout << std::setw(7) << vec[i] << " "; //http://www.cplusplus.com/reference/iomanip/setw/
    }
    cout << endl;
}
void TridiagonalPrint(int mat_size, std::vector<std::vector<double>> &tridiag)
{
    for (int i = 0; i < mat_size; i++)
    {
        for (int j = 0; j < mat_size; j++)
        {
            cout << std::setw(7) << tridiag[i][j] << " "; //http://www.cplusplus.com/reference/iomanip/setw/
        }
        cout << endl;
    }
    cout << endl;
}

std::vector<double> multiplication(int size, std::vector<double> &vec, std::vector<std::vector<double>> &tridiag)
{
    std::vector<double> product;
    for (int i = 0; i < size; i++)
    {
        long double sum = 0;
        for (int j = 0; j < size; j++)
        {
            sum += tridiag[i][j] * vec[j];
        }

        product.push_back(sum);
    }
            return product;
}
    std::vector<double> TridiagonalSolve(double c1, std::vector<double> &diag, std::vector<double> &vect, int n)
    {
        int i;
        std::vector<double> off_diag(n);
        std::vector<double> output(n);
        double id;

        // Set the off diagonal elements
        for (i = 0; i < n; i++)
        {
            off_diag[i] = c1;
        }

        //forward bit
        off_diag[0] /= diag[0]; //if /0 rearrange equations
        vect[0] /= diag[0];

        for (i = 1; i < n; i++)
        {
            id = diag[i] - off_diag[i - 1] * c1;
            off_diag[i] /= id; // Last value calculated is redundant.
            vect[i] = (vect[i] - vect[i - 1] * c1) / id;
        }

        // Now back substitute.
        output[n - 1] = vect[n - 1];

        for (i = n - 2; i >= 0; i--)
        {
            output[i] = vect[i] - off_diag[i] * output[i + 1];
        }

        return output;
    }