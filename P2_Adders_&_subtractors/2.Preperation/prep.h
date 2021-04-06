/*
Project:    Adders and Subtractors
Author:     Joseph Butterworth
License:    This work is licensed under the Creative Commons Attribution-ShareAlike License.
            View this license at https://creativecommons.org/licenses/
*/

struct sum
{
    bool Q;
    bool c_out;
};

bool func_and(bool A, bool B);
bool func_or(bool A, bool B);
bool func_nand(bool A, bool B);
bool func_nor(bool A, bool B);
bool func_xor(bool A, bool B);
bool func_xnor(bool A, bool B);
bool func_not(bool A);

sum half_adder(bool A, bool B);
sum full_adder(bool A, bool B, bool c_in);