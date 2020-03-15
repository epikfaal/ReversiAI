#include "SimulatedGame.h"

SimulatedGame::SimulatedGame() {
	moves_undone = 0;

}
void SimulatedGame::UndoMove() {
	moves_undone++;
	for (int i = 0; i < MAX_X; i++) {
		delete[] board[i];
	}
	delete[] board;
	board = pastboardstates.top();
	pastboardstates.pop();
	activePlayer = activePlayer == 1 ? 2 : 1;
}
void SimulatedGame::ChangeBoardState(int** board, int activeplayer) {
	for (int i = 0; i < MAX_X; i++) {
		delete[] this->board[i];
	}
	delete[] this->board;
	this->board = new int*[MAX_X];
	for (int i = 0; i < MAX_X; i++) {
		this->board[i] = new int[MAX_Y];
		for (int j = 0; j < MAX_Y; j++) {
			this->board[i][j] = board[i][j];
		}
	}
	this->activePlayer = activeplayer;
}
void SimulatedGame::makeMove(Move m) {
	if (m.pass)
		int x = 0;
	int** tempboard = new int*[MAX_X];
	for (int i = 0; i < MAX_X; i++) {
		tempboard[i] = new int[MAX_Y];
		for (int j = 0; j < MAX_Y; j++) {
			tempboard[i][j] = board[i][j];
		}
	}
	pastboardstates.push(tempboard);
	Game::makeMove(m);
}