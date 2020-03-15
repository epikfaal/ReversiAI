#pragma once
class Player {
	
public:
	Player() {
	}
	virtual void MakeMove() = 0;
	int playernumber;
};