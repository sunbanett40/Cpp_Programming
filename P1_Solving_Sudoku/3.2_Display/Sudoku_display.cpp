/*
Project:    Sudoku Solver
Author:     Joseph Butterworth
License:    This work is licensed under the Creative Commons Attribution-ShareAlike License.
            View this license at https://creativecommons.org/licenses/
*/

#include <iostream>
#include <fstream>
using namespace std;

#define subSIZE 3
#define SIZE 9

int grid[SIZE][SIZE] = {0};

int *import_board(void);
void display_board(int *board);

int main()
{
    int *board = import_board();
    display_board(board);

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
        if (row % subSIZE == 0)
        {
            cout << " ------- ------- ------- " << endl;
        }

        for (int col = 0; col < SIZE; col++)
        {
            if (col % subSIZE == 0)
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