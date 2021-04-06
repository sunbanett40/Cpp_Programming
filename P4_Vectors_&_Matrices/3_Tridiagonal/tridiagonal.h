/*
Project:    Tridiagonal Solver
Author:     Joseph Butterworth
License:    This work is licensed under the Creative Commons Attribution-ShareAlike License.
            View this license at https://creativecommons.org/licenses/
*/
#include <vector>
#include <random>

std::vector<double> VectorGenerate(int vec_size);
std::vector<std::vector<double>> TridiagonalGenerate(int mat_size);

void VectorPrint(int vec_size, std::vector<double> &vec);
void TridiagonalPrint(int mat_size, std::vector<std::vector<double>> &tridiag);

std::vector<double> multiplication(int size, std::vector<double> &vec, std::vector<std::vector<double>> &tridiag);
std::vector<double> TridiagonalSolve(double c1, std::vector<double> &diag, std::vector<double> &vect, int n);