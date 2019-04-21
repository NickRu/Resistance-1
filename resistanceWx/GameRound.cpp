#include "AllEnum.h"
#include "GameRound.h"
#include "Game.h"
#include "GameAgents.h"
#include "Agent.h"
#include "Mission.h"


GameRound::GameRound(Game* gm, int sizeofCommand, int roundNumber)
{
	_commandSize = sizeofCommand;
	_roundNumber = roundNumber;
	_game = gm;

	for (int i = 0; i < 5; i++)
	{
		Mission* ms = new Mission(this, GetGame()->GetGameAgents()->GetAgents()[0], i + 1);
		_propMissions.push_back(ms);
	}

	_currentPropMission = _propMissions.at(0); // первая миссия активна
	_currentPropMission->SetIsActiveMission(true);

}


GameRound::~GameRound()
{
	for (int i = 0; i < _propMissions.size(); i++)
	{
		delete(_propMissions[i]);
	}
}

MissionResult GameRound::GetResult()
{
	if(_propMissions.size() == 0)
		return MissionResult::UnknownRes;
	if (GetCurrentPropMission()->GetMissionNumber() == 5 && _currentPropMission->GetMissionResult() == MissionResult::VoteDown)
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
	return _currentPropMission;
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
	if ((GetResult() == MissionResult::Executed) || (GetResult() == MissionResult::Failed))
	{
		Agent * ld = FindNextLider();
		GetGame()->CheckRound();
		GetGame()->GetCurrentGameRound()->SetCurrentLider(ld);
	}
	if (GetResult() == MissionResult::VoteDown)
	{
		int missionNumber = _currentPropMission->GetMissionNumber();
		if (missionNumber == GetPropMission().size())
			throw 1;
		Agent * ld = FindNextLider();
		SetCurrentPropMission(GetPropMission()[missionNumber]);
		SetCurrentLider(ld);
	}
}

void GameRound::SetCurrentLider(Agent* lider)
{
	GetCurrentPropMission()->SetLider(lider);
	GetCurrentPropMission()->GetLider()->SetIsLider(true);
	GetCurrentPropMission()->SetIsActiveMission(true);
}

Agent * GameRound::FindNextLider()
{
	int LiderId = _currentPropMission->GetLider()->GetOrderNumber() + 1;
	GetCurrentPropMission()->GetLider()->SetIsLider(false);
	GetCurrentPropMission()->SetIsActiveMission(false);
	if (LiderId == GetGame()->GetGameAgents()->GetAgents().size())
	{
		LiderId = 0;
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
	return lider;
}
