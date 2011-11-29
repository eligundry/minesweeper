#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

typedef char* minesweeper_board; 	
// Data type that will store our minesweeper board

minesweeper_board make_board(int dimensions, int mines);
// Creates minessweeper board with live mines

bool minesweep(minesweeper_board board, int dimensions);
// Uses user input to sweep for mines

int main()
{
	int board_size = 0,
		num_of_mines = 0;
	bool guess = false;
	minesweeper_board board;

	cout << "How large will your board be?" << endl;
	cin >> board_size;
	cout << "How many mines do you want to sweep for?" << endl;
	cin >> num_of_mines;

	board = make_board(board_size, num_of_mines);

	do {
		guess = minesweep(board, board_size);
	} while (guess == false);

	return 0;
}

minesweeper_board make_board(int dimensions, int mines)
{
	int mine_location [mines];

	minesweeper_board board = new char [((dimensions * dimensions) - 1)];
	// Generate blank array to store mines in based upon user's input

	srand(time(NULL));

	for (int i = 0; i < mines; i++) {
		mine_location[i] = rand() % 100;
		board[mine_location[i]] = 'm';
	}

	return board;
}

bool minesweep(minesweeper_board board, int dimensions)
{
	bool did_user_find_mine = false;
	int user_guess = 0;

	// Display board
	for (int i = 0; i < (dimensions * dimensions); i++) {

		if (i % 10 == 0) {
			cout << endl;
		}

		if (board[i] == 'm' || board[i] == '\0') {
			cout << '?';
		} else {
			cout << board[i];
		}
	}
	
	// Get user's guess
	cout << endl << "Where would you like to sweep?";
	cin >> user_guess;
	
	// Determine if there is a mine
	if (board[user_guess] == 'm') {
		did_user_find_mine = true;
		cout << "BOOM!!!" << endl;
	} else {
		board[user_guess] = 'g';
	}

	return did_user_find_mine;
}
