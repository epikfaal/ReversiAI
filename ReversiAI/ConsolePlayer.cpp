#include "ConsolePlayer.h"
ConsolePlayer::ConsolePlayer() {
	playernumber = 2;
}
void ConsolePlayer::MakeMove() {
	MoveList* ml = game->getAllMoves();
	game->printBoard();
	do {
		std::cout << "possible move x: " << ml->move.x << " y: " << ml->move.y << std::endl;
		ml = ml->nextMove;
	} while (ml != nullptr);
	std::cout << std::endl << "Please enter a value for x:" << std::endl;
	char x= 'a', y= 'a';
	while(x < '0' || x >'7')
	std::cin >> x;
	std::cout << std::endl << "x = " << x << " Please enter a value for y:" << std::endl;
	while (y < '0' || y >'7')
	std::cin >> y;
	Move m;
	m.x = (int)x - 48;
	m.y = (int)y - 48;
	game->makeMove(m);
}
