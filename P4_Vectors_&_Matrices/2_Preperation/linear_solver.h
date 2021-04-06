/*
Project:    linear solver
Author:     Joseph Butterworth
License:    This work is licensed under the Creative Commons Attribution-ShareAlike License.
            View this license at https://creativecommons.org/licenses/
*/
#include <vector>

void TridiagonalSolve(double off_diag, std::vector<double> diag, std::vector<double> row, std::vector<double> output, int n);