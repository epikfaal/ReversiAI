#include "ComputerPlayer.h"
//void ComputerPlayer::threadedMove(MoveList* currentmove) {
//	SimulatedGame* simgame = new SimulatedGame();
//	simgame->ChangeBoardState(current_game->getBoard(), current_game->getActivePlayer());
//	simgame->makeMove(currentmove->move);
//	int eval = 0;
//	if (simgame->getActivePlayer() == 1) {
//		eval = minimax(global_depth, -1000000, 1000000, simgame->getActivePlayer() == 1, simgame);
//
//	}
//	else {
//		eval = minimax(global_depth, -1000000, 1000000, simgame->getActivePlayer() == 1, simgame);
//	}
//	simgame->UndoMove();
//	EvaluatedMove* moveeval = new EvaluatedMove();
//	moveeval->move = currentmove->move;
//	moveeval->eval = eval;
//	evaluatedmoves.push(moveeval);
//	//std::cout << "visited nodes: " << visited_nodes << std::endl;
//}
ComputerPlayer::ComputerPlayer() {
	global_depth = 7;
	playernumber = 1;
}
void ComputerPlayer::connectToGame(Game* game) {
	current_game = game;
	sg = new SimulatedGame();
	sg->ChangeBoardState(current_game->getBoard(), current_game->getActivePlayer());
}
int ComputerPlayer::getEval() {
	int eval = 0;
	int** currentboard = sg->getBoard();
	for (int i = 0; i < MAX_X; i++) {
		for (int j = 0; j < MAX_Y; j++) {
			if (currentboard[i][j] != 0)
				eval += currentboard[i][j] == 1 ? heuristicBoard[i][j] : -heuristicBoard[i][j];
		}
	}
	return eval;
}
void ComputerPlayer::MakeMove() {
	visited_nodes = 0;
	sg->ChangeBoardState(current_game->getBoard(), current_game->getActivePlayer());
	if (sg->getActivePlayer() != playernumber) {
		return;
	}

	std::cout << "computer is thinking... " << std::endl;

	
	int eval = sg->getActivePlayer() == 1 ? -999999 : 999999;
	Move chosenmove;
	MoveList* allmoves = sg->getAllMoves();
	MoveList* currentmove = allmoves;
	std::queue<std::thread*> threads;
	int alpha = -1000000;
	int beta = 1000000;
	while (currentmove != nullptr) {
		

		visited_nodes++;
		
		sg->makeMove(currentmove->move);
		/*vector<char> white_captured, black_captured;
		white_captured = current_game->white_captured;
		black_captured = current_game->black_captured;*/
		//sg->printBoard();
		
		int	debug = minimax(global_depth, alpha, beta, sg->getActivePlayer() == 1);

		int neweval = sg->getActivePlayer() == 1 ? std::min(eval, debug) : std::max(eval, debug);
		

		if (neweval != eval) {
			eval = neweval;
			chosenmove = currentmove->move;
		}
		sg->getActivePlayer() != 1 ? alpha = std::max(alpha, eval) : beta = std::min(beta, eval);

		sg->UndoMove();
		currentmove = currentmove->nextMove;
	}

	
	current_game->makeMove(chosenmove);
	delete allmoves;
   	std::cout << "eval (?): " << eval << std::endl;
	//current_game->logMove(moveToGameLog(chosenmove->move));
	//current_game->movePiece(chosenmove->move.presentP.position, chosenmove->move.newP, &chosenmove->move.ep, &chosenmove->move.cs, &chosenmove->move.pr);
	//deleteMoveLinkedList(allmoves);
	//return true;
}

int ComputerPlayer::minimax(int depth, int alpha, int beta, bool whitesmove) {
	visited_nodes++;

	if (depth == 0) {
		return getEval();
	}
	//fillPieceVectors();
	MoveList* allmoves = sg->getAllMoves();
	MoveList* currentmove = allmoves;
	int bestmove = whitesmove ? -999999 : 999999;
	while (currentmove != nullptr) {
		
		sg->makeMove(currentmove->move);
		if (whitesmove) {
			int newmove = minimax(depth - 1, alpha, beta, !whitesmove);

			bestmove = std::max(bestmove, newmove);
			alpha = std::max(alpha, bestmove);
			sg->UndoMove();
			if (beta <= alpha) {
				break;
			}

		}
		else {
			int newmove = minimax(depth - 1, alpha, beta, !whitesmove);

			bestmove = std::min(bestmove, newmove);
			beta = std::min(beta, bestmove);
			sg->UndoMove();
			if (beta <= alpha) {
				break;
			}
		}
		currentmove = currentmove->nextMove;
	}
	delete allmoves;
	return bestmove;
}

//std::thread* ComputerPlayer::spawn(MoveList* currentmove) {
//	return new std::thread(&ComputerPlayer::threadedMove, this, currentmove);
//}
