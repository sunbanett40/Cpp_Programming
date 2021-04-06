/*
Project:    Adders and Subtractors
Author:     Joseph Butterworth
License:    This work is licensed under the Creative Commons Attribution-ShareAlike License.
            View this license at https://creativecommons.org/licenses/
*/

#define REG_SIZE 8

class gate
{
    public:
    gate() = default;
    gate(bool in_A, bool in_B);

    bool op();  //returns Q

    private:
    bool A;
    bool B;
    bool Q;
};

class AND : public gate
{
    public:
    AND() = default;
    AND(bool in_A, bool in_B);
    bool op();

    private:
    bool A;
    bool B;
    bool Q;
};
class OR : public gate
{
    public:
    OR() = default;
    OR(bool in_A, bool in_B);
    bool op();

    private:
    bool A;
    bool B;
    bool Q;
};
class XOR : public gate
{
    public:
    XOR() = default;
    XOR(bool in_A, bool in_B);
    bool op();
    
    private:
    bool A;
    bool B;
    bool Q;
};

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

sum half_adder(bool A, bool B);
sum full_adder(bool A, bool B, bool c_in);
sum_arr reg_adder(bool A[], bool B[], bool c_in);