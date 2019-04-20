#include "MissionCommand.h"
#include "Mission.h"
#include "GameRound.h"
#include "Game.h"
#include "GameAgents.h"
#include "Agent.h"

MissionCommand::MissionCommand(Mission* ms)
{
	_mission = ms;
	vector<Agent*> vc = GetMission()->GetCurrentGameRound()->GetGame()->GetGameAgents()->GetAgents();
	for (int i = 0; i < vc.size(); i++)
	{
		_command.push_back(new AgentInMission(this, *vc[i]));
	}
}


MissionCommand::~MissionCommand()
{
}

Mission* MissionCommand::GetMission()
{
	return _mission;
}

vector<AgentInMission*> MissionCommand::GetCommand()
{
	return _command;
}

int MissionCommand::NumberofSelected()
{
	int cnt = 0;
	vector<AgentInMission*> vc = GetCommand();
	for (int i = 0; i < vc.size(); i++)
	{
		if (vc[i]->GetIsSelected())
		{
			cnt++;
		}
	}
	return cnt;
}
