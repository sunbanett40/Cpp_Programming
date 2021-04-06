/*
Project:    Adders and Subtractors
Author:     Joseph Butterworth
License:    This work is licensed under the Creative Commons Attribution-ShareAlike License.
            View this license at https://creativecommons.org/licenses/
*/

#define REG_SIZE 8

struct sum
{
    bool Q;
    bool c_out;
};
struct sum_arr
{
    bool Q[REG_SIZE];
    bool c_out;
};

void print_array(bool array[]);

void conv_bin(int num, bool array[]);
void conv_two(bool array[]);
int conv_dec(bool array[]);

bool func_and(bool A, bool B);
bool func_or(bool A, bool B);
bool func_xor(bool A, bool B);

sum half_adder(bool A, bool B);
sum full_adder(bool A, bool B, bool c_in);
sum_arr reg_adder(bool A[], bool B[], bool c_in);