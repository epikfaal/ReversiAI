#pragma once
#include <iostream>
#include <thread>
#define MAX_X 8
#define MAX_Y 8
struct Move {
	int x;
	int y;
	bool pass = false;
};
struct MoveList {
	Move move;
	MoveList* nextMove;
	~MoveList() {
		delete nextMove;
	}
};
class Game
{
public:
	Game();
	void makeMove(Move m);
	MoveList* getAllMoves();
	int** getBoard();
	int getActivePlayer() { return activePlayer; }
	void printBoard();
	bool isGameFinished();
	void printScore();
protected:
	int** board;
	int activePlayer;
	int startposition[8][8] =
	{   
		{0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0},
		{0,0,0,1,2,0,0,0},
		{0,0,0,2,1,0,0,0},
		{0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0} 
	};
	bool checkrow(int startx, int starty, int dirx, int diry);
	void fliprow(int startx, int starty, int dirx, int diry);
	MoveList* MadeMoves;
	
};

