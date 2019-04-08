#pragma once
#include <vector>
#include "Player.h"
#include "Agent.h"

using namespace std;

class Game; //Forward Declare

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

	bool RegistryAgent(Player* pl);
	bool UnregistryAgent(Agent& ag);

	void ExecuteStart();

	string CreateRandomName();
	//bool Comp(const Agent& lhs, const Agent& rhs);
};

