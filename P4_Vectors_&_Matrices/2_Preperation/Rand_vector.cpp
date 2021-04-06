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

    std::vector<double> v;
    int vec_size;
    
    cout << "Enter the size of your vector." << endl;
    cin >> vec_size;
    for (int i = 0; i < vec_size; i++)
    {
        v.push_back(dr(dre));
    }

    for (int i = 0; i < vec_size; i++)
    {
        cout << v[i] << ", ";
    }
}