#pragma once
#include "Game.h"

class GameFiller
{
private:
	Game* gm;
public:
	GameFiller();
	GameFiller(Game* _gm);
	~GameFiller();

	void Fill();
};

