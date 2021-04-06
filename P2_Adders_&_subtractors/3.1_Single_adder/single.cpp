/*
Project:    Adders and Subtractors
Author:     Joseph Butterworth
License:    This work is licensed under the Creative Commons Attribution-ShareAlike License.
            View this license at https://creativecommons.org/licenses/
*/

#include <iostream>
#include "single.h"
using namespace std;

int main()
{
    bool A;
    bool B;
    bool c_in;
    sum Q;

    cout << "Input your first binary number: ";
    cin >> A;
    cout << "Input your second binary number: ";
    cin >> B;
    cout << "Input your value for C_In: ";
    cin >> c_in;

    Q = full_adder(A, B, c_in);

    cout << endl << "Sum is: " << Q.Q << endl;
    cout << "Carry out is: " << Q.c_out;

    return 0;
}

bool func_and(bool A, bool B)
{
    return A && B;
}
bool func_or(bool A, bool B)
{
    return A || B;
}
bool func_xor(bool A, bool B)
{
    return A ^ B;
}

sum half_adder(bool A, bool B)
{
    sum result;
    result.Q = func_xor(A, B);
    result.c_out = func_and(A, B);

    return result;
}
sum full_adder(bool A, bool B, bool c_in)
{
    sum fa;

    //half add A & B
    sum ha_1 = half_adder(A, B);
    //half add Q & c_in
    sum ha_2 = half_adder(ha_1.Q, c_in);
    //set the output
    fa.Q = ha_2.Q;
    fa.c_out = func_or(ha_1.c_out, ha_2.c_out);

    return fa;
}