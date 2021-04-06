/*
Project:    Adders and Subtractors
Author:     Joseph Butterworth
License:    This work is licensed under the Creative Commons Attribution-ShareAlike License.
            View this license at https://creativecommons.org/licenses/
*/

#include <iostream>
#include <math.h>
#include "subtraction.h"
using namespace std;

bool bin[REG_SIZE] = {0};

int main()
{
    int num_1;
    int num_2;
    int sum;

    bool A[REG_SIZE];
    bool B[REG_SIZE];
    bool c_in;
    char op;
    sum_arr Q;

    cout << "Input your first number (A): ";
    cin >> num_1;
    cout << "Your corresponding value A in binary is: ";
    conv_bin(num_1, A);
    print_array(A);

    cout << endl
         << "Input your second number (B): ";
    cin >> num_2;
    cout << "Your corresponding value B in binary is: ";
    conv_bin(num_2, B);
    print_array(B);

    cout << endl
         << "Input your value for C_In: ";
    cin >> c_in;

    cout << "Select operation ( + or - ):";
    cin >> op;
    cout << num_1 << op << num_2 << endl;
    if ((int)op == 45)
    {
        num_2 *= -1;
        conv_bin(num_2, B);
    }

    Q = reg_adder(A, B, c_in);
    sum = conv_dec(Q.Q);

    cout << endl
         << "Sum is: " << sum;
    cout << endl
         << "Overflow bit is: " << Q.c_out;

    return 0;
}

void print_array(bool array[])
{
    for (int i = 0; i < REG_SIZE; i++)
    {
        cout << array[i];
    }
}

void conv_bin(int num, bool array[])
{
    int temp = abs(num);

    for (int i = REG_SIZE - 1, j = 0; i >= 0; i--, j++)
    {
        if (temp >= pow(2, i))
        {
            temp -= pow(2, i);
            array[j] = 1;
        }
        else
        {
            array[j] = 0;
        }
    }

    if (num < 0)
    {
        conv_two(array);
    }
}
void conv_two(bool array[])
{
    bool empty[REG_SIZE] = {0};

    for (int i = 0; i < REG_SIZE; i++)
    {
        if (array[i] == 1)
        {
            array[i] = 0;
        }
        else
        {
            array[i] = 1;
        }
    }

    sum_arr temp = reg_adder(array, empty, 1);
    for (int i = 0; i < REG_SIZE; i++)
    {
        array[i] = temp.Q[i];
    }
}
int conv_dec(bool array[])
{
    int sum = 0;
    int dir = 1;

    //converts from twos complement
    if(array[0] == 1)
    {
        conv_two(array);
        dir = -1;
    }

    for (int i = REG_SIZE - 1, j = 0; i >= 0; i--, j++)
    {
        if (array[j] == 1)
        {
            sum += pow(2, i);
        }
    }

    return sum*dir;
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

sum_arr reg_adder(bool A[], bool B[], bool c_in)
{
    sum_arr output;
    sum temp;

    //full adder each bit of the registers.
    for (int i = REG_SIZE - 1; i >= 0; i--)
    {
        temp = full_adder(A[i], B[i], c_in);
        output.Q[i] = temp.Q;
        c_in = temp.c_out;
    }

    //set c_out to notify of an overflow
    output.c_out = c_in;
    return output;
}