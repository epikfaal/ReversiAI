#pragma once
#include "Player.h"
#include "SimulatedGame.h"
#include <queue>
#include <iostream>
struct EvaluatedMove {
	Move move;
	int eval;
};
class ComputerPlayer : public Player
{
public:
	ComputerPlayer();
	void connectToGame(Game* game);
	void MakeMove();
private:
	int getEval();
	int minimax(int depth, int alpha, int beta, bool whitesmove);
	SimulatedGame* sg;
	Game* current_game;
	int heuristicBoard[8][8] = {
		{ 300, 40, 40, 40, 40, 40, 40, 300 },
		{ 40,  1,  1,  1,  1,  1,  1,  40  },
		{ 40,  1,  1,  1,  1,  1,  1,  40  },
		{ 40,  1,  1,  1,  1,  1,  1,  40  },
		{ 40,  1,  1,  1,  1,  1,  1,  40  },
		{ 40,  1,  1,  1,  1,  1,  1,  40  },
		{ 40,  1,  1,  1,  1,  1,  1,  40  },
		{ 300, 40, 40, 40, 40, 40, 40, 300 }
	};
	int global_depth;
	int visited_nodes;
	std::queue<EvaluatedMove*> evaluatedmoves;
};

