#pragma once
#include "Player.h"
#include "Game.h"
class ConsolePlayer : Player
{
public:
	ConsolePlayer();
	void MakeMove();
	Game* game;
};

