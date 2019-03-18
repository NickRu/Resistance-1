#pragma once
#include <vector>
#include "AllEnum.h"

using namespace std;

class Game;
class Mission;

class GameRound
{
private:
	int _roundNumber;
	bool _isActiveRound;
	int _commandSize;
	Game* _game;
	vector<Mission*> _propMissions;
	Mission* _currentPropMission;
	MissionResult _result;
public:
	GameRound();
	GameRound(Game* gm, int sizeofCommand, int roundNumber);
	~GameRound();

	MissionResult GetResult();

	Mission* GetCurrentPropMission();
	void SetCurrentPropMission(Mission* mission);

	vector<Mission*> GetPropMission();
	void SetPropMission(vector<Mission*> propMission);

	Game* GetGame();

	int GetRoundNumber();

	int GetCommandSize();

	bool GetIsActiveRound();
	void SetIsActiveRound(bool isActive);

	void CheckProposalMission();
	void CreateNewProposalMission();
};

