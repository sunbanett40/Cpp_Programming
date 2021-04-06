/*
Project:    random vector
Author:     Joseph Butterworth
License:    This work is licensed under the Creative Commons Attribution-ShareAlike License.
            View this license at https://creativecommons.org/licenses/
*/

#include <iostream>
#include <random>
#include <ctime>
#include <algorithm>
#include <vector>
#include "linear_solver.h"
using std::cin; using std::cout; using std::endl;

int main()
{
    std::default_random_engine dre(std::time(NULL));
    std::uniform_real_distribution<double> dr(10, 20);

    int mat_size;
    cout << "Enter the size of your Matrix." << endl;
    cin >> mat_size;

    std::vector<std::vector<double>> M(mat_size); //Luchian Grigore at https://stackoverflow.com/questions/12375591/vector-of-vectors-to-create-matrix
    for (int i = 0; i < mat_size; i++)
    {
        M[i].resize(mat_size);
    }

    for (int i = 0; i < mat_size; i++)
    {
        for (int j = 0; j < mat_size; j++)
        {
            M[i][j] = dr(dre);
        }
    }

    for (int i = 0; i < mat_size; i++)
    {
        for (int j = 0; j < mat_size; j++)
        {
            cout << M[i][j] << " ";
        }
        cout << endl;
    }
}

/*
void TridiagonalSolve(double E, double *D, double *R, double *L, int n)
{
    int i, ;
    double *c = malloc(n, sizeof(double));
    Complex id;
    // Set the off diagonal elements
    for (i = 0; i < n; i++)
    {
        c[i] = E;
    }
    //forward bit
    c[0] /= D[0]; //if /0 rearrange equations
    R[0] /= D[0];
    for (i = 1; i < n; i++)
    {
        id = D[i] - c[i - 1] * E;
        c[i] /= id; // Last value calculated is redundant.
        R[i] = (R[i] - R[i - 1] * E) / id;
    }
    // Now back substitute.
    L[n - 1] = R[n - 1];
    for (i = n - 2; i >= 0; i--)
    {
        L[i] = R[i] - c[i] * L[i + 1];
    }
}
*/
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