#pragma once
#include <vector>
#include "Agent.h"
#include "Player.h"

using namespace std;

class Game;

class GameAgents
{
private:
	vector<Agent*> _agents;
	Game* _game;
public:
	GameAgents();
	GameAgents(Game* game);
	~GameAgents();

	vector<Agent*> GetAgents();
	Game* GetGame();

	bool RegistryAgent(Player& pl);
	bool UnregistryAgent(Agent* ag);

	void ExecuteStart();

	string CreateRandomName();
};

