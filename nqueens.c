
#define N 6
#include <stdio.h>
#include <stdbool.h>

//print solution 
void printSolution(int board[N][N])
{
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++){
			printf(" %d ", board[i][j]);
		}
		printf("\n");
	}
}

// to check if a queen can be placed on board[row][col]. Note that this function is called when "row" queens are
//already placed in rows from 0 to row -1. So we need to check only left side for attacking queens
bool isSafe(int board[N][N], int row, int col)
{
	int i, j;

	/* Check this col on down side */
	for(i = 0; i < row; i++){
		if(board[i][col]){
			return false;
		}
	}
	/* Check upper diagonal on left side */
	for(i = row, j = col; i >= 0 && j >= 0; i--, j--){
		if(board[i][j]){
			return false;
		}
	}
	/* Check lower diagonal on left side */
	for(i = row, j = col; j >= 0 && i < N; i++, j--){
		if(board[i][j]){
			return false;
		}
	}
	return true;
}

// to solve N Queen problem 
bool solveNQUtil(int board[N][N], int row)
{
	/* base case: If all queens are placed
	then return true */
	if (row >= N)
		return true;

	/* Consider this row and try placing
	this queen in all cols one by one */
	for (int i = 0; i < N; i++) {
		/* Check if the queen can be placed on
		board[i][row] */
		if (isSafe(board, row, i)) {
			/* Place this queen in board[i][row] */
			board[row][i] = 1;

			/* recur to place rest of the queens */
			if (solveNQUtil(board, row + 1))
				return true;

			/* If placing queen in board[i][row]
			doesn't lead to a solution, then
			remove queen from board[i][row] */
			board[row][i] = 0; // BACKTRACK
		}
	}

	/* If the queen cannot be placed in any col in
		this row then return false */
	return false;
}

/* This function solves the N Queen problem using
Backtracking. It mainly uses solveNQUtil() to
solve the problem. It returns false if queens
cannot be placed, otherwise, return true and
prints placement of queens in the form of 1s.
Please note that there may be more than one
solutions, this function prints one of the
feasible solutions.*/
bool solveNQ()
{
	int board[N][N] = { { 0, 0, 0, 0 },
						{ 0, 0, 0, 0 },
						{ 0, 0, 0, 0 },
						{ 0, 0, 0, 0 } };

	if (solveNQUtil(board, 0) == false){
		printf("Solution does not exist");
		return false;
	}

	printSolution(board);
	return true;
}


int main(){
	solveNQ();
	return 0;
}
