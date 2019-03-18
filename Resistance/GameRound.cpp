#include "GameRound.h"
#include "GameAgents.h"
#include "Agent.h"
#include "Game.h"
#include "Mission.h"
#include "AllEnum.h"


GameRound::GameRound()
{
}

GameRound::GameRound(Game* gm, int sizeofCommand, int roundNumber)
{
	_commandSize = sizeofCommand;
	_roundNumber = roundNumber;
	_game = gm;
}


GameRound::~GameRound()
{
}

MissionResult GameRound::GetResult()
{
	if (_propMissions.size() == 0)
	{
		return MissionResult::UnknownRes;
	}
	if (_propMissions.size() == 5 && _currentPropMission->GetMissionResult() == MissionResult::VoteDown)
	{
		return MissionResult::Failed;
	}
	else
	{
		return _currentPropMission->GetMissionResult();
	}
}

Mission* GameRound::GetCurrentPropMission()
{
	return _currentPropMission;;
}

void GameRound::SetCurrentPropMission(Mission* mission)
{
	_currentPropMission = mission;
}

vector<Mission*> GameRound::GetPropMission()
{
	return _propMissions;
}

void GameRound::SetPropMission(vector<Mission*> propMission)
{
	_propMissions = propMission;
}

Game* GameRound::GetGame()
{
	return _game;
}

int GameRound::GetRoundNumber()
{
	return _roundNumber;
}

int GameRound::GetCommandSize()
{
	return _commandSize;
}

bool GameRound::GetIsActiveRound()
{
	return _isActiveRound;
}

void GameRound::SetIsActiveRound(bool isActive)
{
	_isActiveRound = isActive;
}

void GameRound::CheckProposalMission()
{
	if (GetResult() == (MissionResult::Executed || MissionResult::Failed))
	{
		SetIsActiveRound(false);
		GetGame()->CheckRound();
	}
	if (GetResult() == MissionResult::VoteDown)
	{
		CreateNewProposalMission();
	}
}

void GameRound::CreateNewProposalMission()
{
	int LiderId = _currentPropMission->GetLider()->GetOrderNumber() + 1;
	GetCurrentPropMission()->GetLider()->SetIsLider(false);
	if (LiderId == GetGame()->GetGameAgents()->GetAgents().size())
	{
		LiderId == 0;
	}

	Agent* lider = nullptr;
	for (int i = 0; i < GetGame()->GetGameAgents()->GetAgents().size(); i++)
	{
		if (GetGame()->GetGameAgents()->GetAgents()[i]->GetOrderNumber() == LiderId)
		{
			GetGame()->GetGameAgents()->GetAgents()[i]->SetIsLider(true);
			lider = GetGame()->GetGameAgents()->GetAgents()[i];
		}
	}
	_currentPropMission->SetIsActiveMission(false);
	_currentPropMission = new Mission(this, lider);
	_propMissions.push_back(_currentPropMission);
}
