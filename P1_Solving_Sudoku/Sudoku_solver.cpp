/*
Project:    Sudoku Solver
Author:     Joseph Butterworth
License:    This work is licensed under the Creative Commons Attribution-ShareAlike License.
            View this license at https://creativecommons.org/licenses/
*/

#include <iostream>
#include <fstream>
using namespace std;

#define subsize 3
#define size 9
int grid[size][size] = {0};

int *import_board(void);
void display_board(int *board);
bool solve_sudoku(int *board, int boardPos);
bool valid_number(int *board, int row, int col, int num);

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
        number = input - 48;

        if (number < 0 || number > size)
        {
            number = 0;
        }

        if (col == size)
        {
            row++;
            col = 0;
        }

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

    for (int row = 0; row < size; row++)
    {
        if (row % subsize == 0)
        {
            cout << " ------- ------- ------- " << endl;
        }

        for (int col = 0; col < size; col++)
        {
            if (col % subsize == 0)
            {
                cout << "| ";
            }

            int boardPos = (size * row + col);
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

    //is it the end of the row
    if (col == size)
    {
        row++;
        col = 0;
    }

    //is the value greater than zero
    if (board[boardPos] > 0)
    {
        return solve_sudoku(board, boardPos+1);
    }

    //check if new value is valid
    for (int number = 0; number < size; number++)
    {
        if (valid_number(board, row, col, number))
        {
            board[boardPos] = number;
            return solve_sudoku(board, boardPos+1);
        }
    }

    //is the sudoku complete
    if(row == size && col == size)
    {
        return true;
    }

    board[boardPos] = 0;
    return false;
}

bool valid_number(int *board, int row, int col, int num)
{
    //check if row is valid
    for (int i = 0; i < size; i++)
    {
        if (board[(size * row) + i] == num)
        {
            return false;
        }
    }

    //check if column is valid
    for (int i = 0; i < size; i++)
    {
        if (board[(size * i) + col] == num)
        {
            return false;
        }
    }


    //check if sub-board is valid
    int sub_row = row - row % subsize;
    int sub_col = col - col / subsize;

    for(int i = 0; i < subsize; i++)
    {
        for(int j = 0; j < subsize; j++)
        {
            int sub_boardPos = (size * (sub_row + i)) +(sub_col + j);
            if(board[sub_boardPos] == num)
            {
                return false;
            }
        }
    }

    return true;
}