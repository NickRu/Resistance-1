#include "AgentInMission.h"
#include "MissionCommand.h"
#include "Mission.h"
#include "GameRound.h"


AgentInMission::AgentInMission(MissionCommand* cm, Agent ag)
{
	_command = cm;
	_agent = ag;
}


AgentInMission::~AgentInMission()
{
}

void AgentInMission::CreateMission(bool forCreate)
{
	GetCommand()->GetMission()->CreationVote(forCreate, GetAgent());
}

void AgentInMission::ExecuteMission(bool forExecute)
{
	if (GetIsSelected())
	{
		GetCommand()->GetMission()->ExecutionVote(forExecute, GetAgent());
	}
}

void AgentInMission::SetAgent(Agent ag)
{
	_agent = ag;
}

Agent AgentInMission::GetAgent()
{
	return _agent;
}

void AgentInMission::SetCommand(MissionCommand* cm)
{
	_command = cm;
}

MissionCommand* AgentInMission::GetCommand()
{
	return _command;
}

void AgentInMission::SetIsSelected(bool b)
{
	if (GetCommand()->GetMission()->GetCurrentGameRound()->GetCommandSize() > GetCommand()->NumberofSelected())
	{
		_isSelected = b;
	}
}

bool AgentInMission::GetIsSelected()
{
	return _isSelected;
}
