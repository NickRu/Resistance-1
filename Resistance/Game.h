#pragma once
#include <vector>
#include <map>
#include "Agent.h"
#include "Player.h"
#include "AllEnum.h"

using namespace std;

class GameRound;
class GameAgents;

class Game
{
private:
	int _lowBorderAgents;
	int _highBorderAgents;
	GameAgents* _agents;
	vector<GameRound*> _gameRounds;
	map<int, int> _spyNumbers;
	map<int, vector<int>> _missionNumbers;
public:
	Game();
	~Game();

	GameAgents* GetGameAgents();

	bool CanStartGame();

	bool CanRegistryAgents();

	map<int, int> GetSpyNumbers();

	vector<GameRound*> GetGameRounds();

	MissionResult Result();
	
	bool RegistryGameAgent(Player pl);
	bool UnregistryGameAgent(Agent ag);

	void ExecuteStart();
	void CheckRound();
	void CheckGame();

	void ExecuteStop();
	void SetStartCondition();
};

