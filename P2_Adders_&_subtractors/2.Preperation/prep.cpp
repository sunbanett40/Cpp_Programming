/*
Project:    Adders and Subtractors
Author:     Joseph Butterworth
License:    This work is licensed under the Creative Commons Attribution-ShareAlike License.
            View this license at https://creativecommons.org/licenses/
*/

#include <iostream>
#include "prep.h"
using namespace std;

int main()
{
    bool A = 0;
    bool B = 1;
    bool Q;
    sum result;

    bool c_in = 0;
    bool c_out;

    Q = half_adder(A, B).Q;
    cout << "Q: " << Q << endl;
    c_out = half_adder(A, B).c_out;
    cout << "c_out: " << c_out << endl;
    
}

bool func_and(bool A, bool B)
{
    return A && B;
}
bool func_or(bool A, bool B)
{
    return A || B;
}
bool func_nand(bool A, bool B)
{
    return !(A && B);
}
bool func_nor(bool A, bool B)
{
    return !(A || B);
}
bool func_xor(bool A, bool B)
{
    return A ^ B;
}
bool func_xnor(bool A, bool B)
{
    return !(A ^ B);
}
bool func_not(bool A)
{
    return !A;
}

sum half_adder(bool A, bool B)
{
    sum result;
    result.Q = func_xor(A, B);
    result.c_out = func_and(A, B);

    return result;
}