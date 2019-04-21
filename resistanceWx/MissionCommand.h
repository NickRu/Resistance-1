#pragma once
#include <vector>
#include "AgentInMission.h"

using namespace std;

class Mission; //Forward Declare

class MissionCommand
{
private:
	vector<AgentInMission*> _command;
	Mission* _mission;
public:
	MissionCommand(Mission* ms);
	~MissionCommand();

	Mission* GetMission();

	vector<AgentInMission*> GetCommand();

	bool CheckAgentforSelect(Agent ag);

	int NumberofSelected();
};

