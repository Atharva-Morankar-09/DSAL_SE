// C++ program to solve N Queen Problem using backtracking

#include <bits/stdc++.h>
#define N 4
using namespace std;

// A utility function to print solution
void printSolution(int board[N][N])
{
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++)
		if(board[i][j])
			cout << "Q ";
		else cout<<". ";
		printf("\n");
	}
}

// A utility function to check if a queen can
// be placed on board[row][col]. Note that this
// function is called when "col" queens are
// already placed in columns from 0 to col -1.
// So we need to check only left side for
// attacking queens
bool isSafe(int board[N][N], int row, int col)
{
	int i, j;

	// Check this row on left side
	for (i = 0; i < col; i++)
		if (board[row][i])
			return false;

	// Check upper diagonal on left side
	for (i = row, j = col; i >= 0 && j >= 0; i--, j--)
		if (board[i][j])
			return false;

	// Check lower diagonal on left side
	for (i = row, j = col; j >= 0 && i < N; i++, j--)
		if (board[i][j])
			return false;

	return true;
}

// A recursive utility function to solve N
// Queen problem
bool solveNQUtil(int board[N][N], int col)
{
	// base case: If all queens are placed
	// then return true
	if (col >= N)
		return true;

	// Consider this column and try placing
	// this queen in all rows one by one
	for (int i = 0; i < N; i++) {
		
		// Check if the queen can be placed on
		// board[i][col]
		if (isSafe(board, i, col)) {
			
			// Place this queen in board[i][col]
			board[i][col] = 1;

			// recur to place rest of the queens
			if (solveNQUtil(board, col + 1))
				return true;

			// If placing queen in board[i][col]
			// doesn't lead to a solution, then
			// remove queen from board[i][col]
			board[i][col] = 0; // BACKTRACK
		}
	}

	// If the queen cannot be placed in any row in
	// this column col then return false
	return false;
}

// This function solves the N Queen problem using
// Backtracking. It mainly uses solveNQUtil() to
// solve the problem. It returns false if queens
// cannot be placed, otherwise, return true and
// prints placement of queens in the form of 1s.
// Please note that there may be more than one
// solutions, this function prints one of the
// feasible solutions.
bool solveNQ()
{
	int board[N][N] = { { 0, 0, 0, 0 },
						{ 0, 0, 0, 0 },
						{ 0, 0, 0, 0 },
						{ 0, 0, 0, 0 } };

	if (solveNQUtil(board, 0) == false) {
		cout << "Solution does not exist";
		return false;
	}

	printSolution(board);
	return true;
}

// Driver program to test above function
int main()
{
	solveNQ();
	return 0;
}

// This code is contributed by Aditya Kumar (adityakumar129)

// Output
// . . Q . 
// Q . . . 
// . . . Q 
// . Q . . 








// second code


#include <bits/stdc++.h>
using namespace std;

// Store all the possible answers
vector<vector<string> > answer;

// Print the board
void print_board()
{
	for (auto& str : answer[1]) {
		for (auto& letter : str)
			cout << letter << " ";
		cout << endl;
	}
	return;
}
// We need to check in three directions
// 1. in the same column above the current position
// 2. in the left top diagonal from the given cell
// 3. in the right top diagonal from the given cell
int safe(int row, int col, vector<string>& board)
{
	for (int i = 0; i < board.size(); i++) {
		if (board[i][col] == 'Q')
			return false;
	}
	int i = row, j = col;
	while (i >= 0 && j >= 0)
		if (board[i--][j--] == 'Q')
			return false;
	i = row, j = col;
	while (i >= 0 && j < board.size())
		if (board[i--][j++] == 'Q')
			return false;
	return true;
}
// rec function here will fill the queens
// 1. there can be only one queen in one row
// 2. if we filled the final row in the board then row will
// be equal to total number of rows in board
// 3. push that board configuration in answer set because
// there will be more than one answers for filling the board
// with n-queens
void rec(vector<string> board, int row)
{
	if (row == board.size()) {
		answer.push_back(board);
		return;
	}
	for (int i = 0; i < board.size(); i++) {
		
		// For each position check if it is safe and if it
		// safe make a recursive call with
		// row+1,board[i][j]='Q' and then revert the change
		// in board that is make the board[i][j]='.' again to
		// generate more solutions
		if (safe(row, i, board)) {
			board[row][i] = 'Q';
			rec(board, row + 1);
			board[row][i] = '.';
		}
	}
	return;
}
// Function to solve n queens
vector<vector<string> > solveNQueens(int n)
{
	string s;
	for (int i = 0; i < n; i++)
		s += '.';
	
	// Vector of string will make our board which is
	// initially all empty
	vector<string> board(n, s);
	rec(board, 0);
	return answer;
}

// Driver code
int main()
{
	clock_t start, end;
	start = clock();
	// size 4x4 is taken and we can pass some other
	// dimension for chess board as well
	cout << solveNQueens(4).size() << endl;
	cout << "Out of " << answer.size()
		<< " solutions one is following" << endl;
	print_board();
	
	return 0;
}


// Output
// 2
// Out of 2 solutions one is following
// . . Q . 
// Q . . . 
// . . . Q 
// . Q . . 







