#pragma once
#include "Game.h"
#include <stack>
class SimulatedGame : public Game
{
public:
	SimulatedGame();
	void ChangeBoardState(int** board, int activeplayer);
	void UndoMove();
	void makeMove(Move m);
private:
	std::stack<int**> pastboardstates;
	int moves_undone;
};

