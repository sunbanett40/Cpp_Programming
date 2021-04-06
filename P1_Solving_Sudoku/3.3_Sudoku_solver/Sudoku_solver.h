/*
Project:    Sudoku Solver
Author:     Joseph Butterworth
License:    This work is licensed under the Creative Commons Attribution-ShareAlike License.
            View this license at https://creativecommons.org/licenses/
*/

#ifndef SUDOKU_SOLVE
#define SUDOKU_SOLVE
//header code here
int *import_board(void);
void display_board(int *board);
bool solve_sudoku(int *board, int boardPos);
bool valid_number(int *board, int row, int col, int num);

#endif