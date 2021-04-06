/*
Project:    Sudoku Solver
Author:     Joseph Butterworth
License:    This work is licensed under the Creative Commons Attribution-ShareAlike License.
            View this license at https://creativecommons.org/licenses/
*/

#include <iostream>
#include <fstream>
#include "Sudoku_solver.h"
using namespace std;

#define SUBSIZE 3
#define SIZE 9
int grid[SIZE][SIZE] = {0};

int main()
{
    int *board = import_board();
    display_board(board);
    cout << endl;

    if (solve_sudoku(board, 0))
    {
        display_board(board);
    }
    else
    {
        cout << "you're sudoku board has no solutions!" << endl;
    }

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

void display_board(int *board)
{
/*
 ------- ------- ------- 
| 1 2 3 | 4 5 6 | 7 8 9 |
| 4 5 6 | 7 8 9 | 1 2 3 |
| 7 8 9 | 1 2 3 | 4 5 6 |
 ------- ------- -------
| _ _ _ | _ _ _ | _ _ _ |
| _ _ _ | _ _ _ | _ _ _ |
| _ _ _ | _ _ _ | _ _ _ |
 ------- ------- -------
| _ _ _ | _ _ _ | _ _ _ |
| _ _ _ | _ _ _ | _ _ _ |
| _ _ _ | _ _ _ | _ _ _ |
 ------- ------- -------
*/

    for (int row = 0; row < SIZE; row++)
    {
        if (row % SUBSIZE == 0)
        {
            cout << " ------- ------- ------- " << endl;
        }

        for (int col = 0; col < SIZE; col++)
        {
            if (col % SUBSIZE == 0)
            {
                cout << "| ";
            }

            int boardPos = (SIZE * row + col);
            if (board[boardPos] == 0)
            {
                cout << "_ ";
            }
            else
            {
                cout << board[boardPos] << " ";
            }
        }
        cout << "|" << endl;
    }

    cout << " ------- ------- ------- " << endl;
}

bool solve_sudoku(int *board, int boardPos)
{
    int row = boardPos / 9;
    int col = boardPos % 9;

    //is the sudoku complete
    if (row == SIZE)
    {
        return true;
    }

    //is it the end of the row
    if (col == SIZE)
    {
        row++;
        col = 0;
    }

    //is the value greater than zero
    if (board[boardPos] > 0)
    {
        if (solve_sudoku(board, boardPos + 1))
        {
            return true;
        }
    }

    //check if new value is valid
    for (int number = 1; number <= SIZE; number++)
    {
        if (valid_number(board, row, col, number))
        {
            board[boardPos] = number;
            if (solve_sudoku(board, boardPos + 1))
            {
                return true;
            }
        }
    }

    board[boardPos] = 0;
    return false;
}

bool valid_number(int *board, int row, int col, int num)
{
    //check if row is valid
    for (int i = 0; i < SIZE; i++)
    {
        if (board[(SIZE * row) + i] == num)
        {
            return false;
        }
    }

    //check if column is valid
    for (int i = 0; i < SIZE; i++)
    {
        if (board[(SIZE * i) + col] == num)
        {
            return false;
        }
    }

    //check if sub-board is valid
    int startRow = row - row % SUBSIZE;
    int startCol = col - col % SUBSIZE;
    for (int i = 0; i < SUBSIZE; i++)
    {
        for (int j = 0; j < SUBSIZE; j++)
        {
            if (board[(startRow + i) * SIZE + startCol + j] == num)
            {
                return false;
            }
        }
    }

    return true;
}