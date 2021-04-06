/*
Project:    Reading Files
Author:     Joseph Butterworth
License:    This work is licensed under the Creative Commons Attribution-ShareAlike License.
            View this license at https://creativecommons.org/licenses/
*/

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
    fstream inputStream;
    string text;

    inputStream.open("lazy_doggo.txt");

    while(!inputStream.eof())
    {
        inputStream >> text;
        cout << text << " ";
    }
    
    return 0;
}