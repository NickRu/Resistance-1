#pragma once
#include <vector>
#include "AgentInMission.h"

using namespace std;

class Mission;

class MissionCommand
{
private:
	vector<AgentInMission> _command;	//вектор агент в миссии
	Mission* _mission;					//сама миссия
public:
	MissionCommand(Mission* ms);
	~MissionCommand();

	Mission* GetMission();				//дать миссию

	vector<AgentInMission> GetCommand();//дать команду миссии

	int NumberofSelected();				//количество выбранных игроков
};

