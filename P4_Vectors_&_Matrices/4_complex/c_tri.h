/*
Project:    Complex Tridiagonal Solver
Author:     Joseph Butterworth
License:    This work is licensed under the Creative Commons Attribution-ShareAlike License.
            View this license at https://creativecommons.org/licenses/
*/
#include <vector>
#include <random>
#include "complex.h"

std::vector<complex> VectorGenerate(int vec_size);
std::vector<std::vector<complex>> TridiagonalGenerate(int mat_size);

void VectorPrint(int vec_size, std::vector<complex> &vec);
void TridiagonalPrint(int mat_size, std::vector<std::vector<complex>> &tridiag);

std::vector<complex> multiplication(int size, std::vector<complex> &vec, std::vector<std::vector<complex>> &tridiag);
std::vector<complex> TridiagonalSolve(complex c1, std::vector<complex> &diag, std::vector<complex> &vect, int n);

class complex;
void print_cartesian(complex a);
complex ComplexRandom(void);