#pragma once
#include <vector>
#include <map>
#include "Player.h"
#include "Agent.h"
#include "AllEnum.h"

using namespace std;

class GameAgents; //Forward Declare
class GameRound; //Forward Declare

class Game
{
private:
	int _lowBorderAgents;
	int _highBorderAgents;
	GameAgents* _gameAgents;
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

	GameRound* GetCurrentGameRound();

	MissionResult Result();
	
	bool RegistryGameAgent(Player* pl);
	bool UnregistryGameAgent(Agent ag);

	void ExecuteStart();
	void CheckRound();
	void CheckGame();

	void ExecuteStop();
	void SetStartCondition();
};

