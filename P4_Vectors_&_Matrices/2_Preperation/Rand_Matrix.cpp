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
using std::cin;
using std::cout;
using std::endl;

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