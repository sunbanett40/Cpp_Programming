/*
Project:    Sudoku Solver
Author:     Joseph Butterworth
License:    This work is licensed under the Creative Commons Attribution-ShareAlike License.
            View this license at https://creativecommons.org/licenses/
*/

#include <iostream>
#include <fstream>
using namespace std;

#define SIZE 9
int grid[SIZE][SIZE] = {0};

int *import_board(void);

int main()
{
    int *board = import_board();

    return 0;
}

int *import_board(void)
{
    fstream inputStream;
    char input;
    int number;
    int row = 0;
    int col = 0;

    inputStream.open("SUDOKU.txt");

    while (!inputStream.eof())
    {
        inputStream >> input;
        
        //convert character into number
        number = input - 48;
        if (number < 0 || number > SIZE)
        {
            number = 0;
        }

        //update row position
        if (col == SIZE)
        {
            row++;
            col = 0;
        }

        //set position to number
        grid[row][col] = number;
        col++;
    }

    return (int *)grid;
}