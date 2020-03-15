#include "Game.h"

Game::Game() {
	board = new int*[MAX_X];
	for (int i = 0; i < MAX_X; i++) {
		board[i] = new int[MAX_Y];
		for (int j = 0; j < MAX_Y; j++) {
			board[i][j] = startposition[i][j];
		}
	}
	activePlayer = 1;
	MoveList* ml = getAllMoves();
	/*while (true) {
		printBoard();
		do{
			std::cout << "possible move x: " << ml->move.x << " y: " << ml->move.y << std::endl;
			ml = ml->nextMove;
		} while (ml != nullptr);
		std::cout << std::endl << "Please enter a value for x:" << std::endl;
		int x,y;
		std::cin >> x;
		std::cout << std::endl << "x = " << x <<" Please enter a value for y:" << std::endl;
		std::cin >> y;
		makeMove(x, y);
		activePlayer = activePlayer == 1 ? 2 : 1;
		ml = getAllMoves();

	}*/
}

MoveList* Game::getAllMoves() {
	MoveList* basenode = nullptr;
	MoveList* previousnode = nullptr;
	MoveList* currentnode = nullptr;
	if (board[0][0] == 0) {
		bool possiblemove = false;
		possiblemove = possiblemove || checkrow(0, 0, 1, 1);
		possiblemove = possiblemove || checkrow(0, 0, 0, 1);
		possiblemove = possiblemove || checkrow(0, 0, 1, 0);
		if (possiblemove) {
			previousnode = currentnode;
			currentnode = new MoveList();
			currentnode->move = Move();
			currentnode->move.x = 0;
			currentnode->move.y = 0;

			if (basenode == nullptr) {
				basenode = currentnode;
			}
			if (previousnode != nullptr) {
				previousnode->nextMove = currentnode;
			}
		}
	}
	if (board[0][7] == 0) {
		bool possiblemove = false;
		possiblemove = possiblemove || checkrow(0, 7, 1, 0);
		possiblemove = possiblemove || checkrow(0, 7, 1, -1);
		possiblemove = possiblemove || checkrow(0, 7, 0, -1);
		if (possiblemove) {
			previousnode = currentnode;
			currentnode = new MoveList();
			currentnode->move = Move();
			currentnode->move.x = 0;
			currentnode->move.y = 7;

			if (basenode == nullptr) {
				basenode = currentnode;
			}
			if (previousnode != nullptr) {
				previousnode->nextMove = currentnode;
			}
		}
	}
	if (board[7][0] == 0) {
		bool possiblemove = false;
		possiblemove = possiblemove || checkrow(7, 0, 0, 1);
		possiblemove = possiblemove || checkrow(7, 0, -1, 1);
		possiblemove = possiblemove || checkrow(7, 0, -1, 0);
		if (possiblemove) {
			previousnode = currentnode;
			currentnode = new MoveList();
			currentnode->move = Move();
			currentnode->move.x = 7;
			currentnode->move.y = 0;

			if (basenode == nullptr) {
				basenode = currentnode;
			}
			if (previousnode != nullptr) {
				previousnode->nextMove = currentnode;
			}
		}
	}
	if (board[7][7] == 0) {
		bool possiblemove = false;
		possiblemove = possiblemove || checkrow(7, 7, -1, -1);
		possiblemove = possiblemove || checkrow(7, 7, -1, 0);
		possiblemove = possiblemove || checkrow(7, 7, 0, -1);
		if (possiblemove) {
			previousnode = currentnode;
			currentnode = new MoveList();
			currentnode->move = Move();
			currentnode->move.x = 7;
			currentnode->move.y = 7;

			if (basenode == nullptr) {
				basenode = currentnode;
			}
			if (previousnode != nullptr) {
				previousnode->nextMove = currentnode;
			}
		}
	}

	for (int i = 0; i < MAX_X; i++)
	{
		for (int j = 0; j < MAX_Y; j++) {
			int bools = 0;
			bools += i == 0;
			bools += i == 7;
			bools += j == 7;
			bools += j == 0;
			if (bools != 1) continue;

			if (board[i][j] == 0) {
				bool possiblemove = false;
				possiblemove = possiblemove || checkrow(i, j, 1, 1);
				possiblemove = possiblemove || checkrow(i, j, 0, 1);
				possiblemove = possiblemove || checkrow(i, j, 1, 0);
				possiblemove = possiblemove || checkrow(i, j, -1, 1);
				possiblemove = possiblemove || checkrow(i, j, 1, -1);
				possiblemove = possiblemove || checkrow(i, j, -1, -1);
				possiblemove = possiblemove || checkrow(i, j, -1, 0);
				possiblemove = possiblemove || checkrow(i, j, 0, -1);
				if (possiblemove) {
					previousnode = currentnode;
					currentnode = new MoveList();
					currentnode->move = Move();
					currentnode->move.x = i;
					currentnode->move.y = j;

					if (basenode == nullptr) {
						basenode = currentnode;
					}
					if (previousnode != nullptr) {
						previousnode->nextMove = currentnode;
					}
				}
			}
		}
	}
	for (int i = 1; i < MAX_X - 1; i++)
	{
		for (int j = 1; j < MAX_Y - 1; j++) {
			if (board[i][j] == 0) {
				bool possiblemove = false;
				possiblemove = possiblemove || checkrow(i, j, 1, 1);
				possiblemove = possiblemove || checkrow(i, j, 0, 1);
				possiblemove = possiblemove || checkrow(i, j, 1, 0);
				possiblemove = possiblemove || checkrow(i, j, -1, 1);
				possiblemove = possiblemove || checkrow(i, j, 1, -1);
				possiblemove = possiblemove || checkrow(i, j, -1, -1);
				possiblemove = possiblemove || checkrow(i, j, -1, 0);
				possiblemove = possiblemove || checkrow(i, j, 0, -1);
				if (possiblemove) {
					previousnode = currentnode;
					currentnode = new MoveList();
					currentnode->move = Move();
					currentnode->move.x = i;
					currentnode->move.y = j;

					if (basenode == nullptr) {
						basenode = currentnode;
					}
					if (previousnode != nullptr) {
						previousnode->nextMove = currentnode;
					}
				}
			}
		}
	}
	if (basenode == nullptr) {
		basenode = new MoveList();
		basenode->move.pass = true;
	}
	return basenode;
}
bool Game::checkrow(int startx, int starty, int dirx, int diry) {
	bool ret = false;
	int x = dirx;
	int y = diry;
	while ((startx + x >= 0 && startx + x < MAX_X) && (starty + y >= 0 && starty + y < MAX_Y)) {
		if (board[startx + x][starty + y] == activePlayer) {
			return ret;
		}
		if (board[startx + x][starty + y] == 0) {
			return false;
		}
		ret = true;
		x += dirx;
		y += diry;
	}
	return false;
}

void Game::makeMove(Move m) {
	if (m.pass) {
		activePlayer = activePlayer == 1 ? 2 : 1;
		return;
	}
	for (int i = -1; i <= 1; i++) {
		for (int j = -1; j <= 1; j++) {
			if ((!(i == 0 && j == 0)) && checkrow(m.x, m.y, i, j)) {
				fliprow(m.x, m.y, i, j);
			}
		}
	}
	board[m.x][m.y] = activePlayer;
	activePlayer = activePlayer == 1 ? 2 : 1;
}

void Game::fliprow(int startx, int starty, int dirx, int diry) {
	int x = dirx;
	int y = diry;
	while (true) {
		if (board[startx + x][starty + y] == activePlayer) {
			return;
		}
		board[startx + x][starty + y] = activePlayer;
		x += dirx;
		y += diry;
	}
	return;
}

void Game::printBoard() {
	for (int j = 0; j < MAX_X; j++) {
		std::cout << "|";
		for (int i = 0; i < MAX_Y; i++) {
			std::cout << board[i][j] << "|";
		}
		std::cout << std::endl;
	}
}

int** Game::getBoard() {
	return board;
}
bool Game::isGameFinished() {
	for (int j = 0; j < MAX_X; j++) {
		for (int i = 0; i < MAX_Y; i++) {
			if (board[i][j] == 0)
				return false;
		}
	}
	return true;
}
void Game::printScore() {
	int scorep1 = 0;
	int scorep2 = 0;
	for (int j = 0; j < MAX_X; j++) {
		for (int i = 0; i < MAX_Y; i++) {
			if (board[i][j] == 1) {
				scorep1++;
			}
			if (board[i][j] == 2) {
				scorep2++;
			}
		}
	}
	std::cout << "Player1 scored " << scorep1 << " points and Player2 scored " << scorep2 << " points." << std::endl;
}