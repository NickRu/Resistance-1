#include "Mission.h"
#include "Agent.h"
#include "MissionCommand.h"
#include "GameRound.h"

using namespace std;

Mission::Mission(GameRound* rnd, Agent* lider)
{
	_round = rnd;
	_lider = lider;
}

Mission::~Mission()
{
}

//Game Mission::GetGame()
//{
//	return _game;
//}

GameRound* Mission::GetCurrentGameRound()
{
	return _round;
}

Agent* Mission::GetLider()
{
	return _lider;
}

void Mission::SetLider(Agent* _lider)
{
}

vector<AgentVoteFor<VoteforCreation>> Mission::GetMissionVotes()
{
	return _missionVotes;
}

void Mission::SetMissionVotes(vector<AgentVoteFor<VoteforCreation>> missionVotes)
{
}

vector<AgentVoteFor<VoteforExecution>> Mission::GetMissionExecuteVotes()
{
	return _missionExecuteVotes;
}

void Mission::SetMissionExecuteVotes(vector<AgentVoteFor<VoteforExecution>> _missionExecuteVotes)
{
}


MissionCommand* Mission::GetMissionCommand()
{
	return _command;
}

void Mission::SetMissionCommand(MissionCommand* command)
{
	_command = command;
}

bool Mission::GetIsActiveMission()
{
	return _isActive;
}

void Mission::SetIsActiveMission(bool isActive)
{
	_isActive = isActive;
}

VoteforCreation Mission::ResultofVotesforCreation()
{
	int s = 0;
	vector<AgentVoteFor<VoteforCreation>> lst = GetMissionVotes();
	for (int i = 0; i < lst.size() - 1; i++)
	{
		AgentVoteFor<VoteforCreation> ag = lst[i];
		if (ag.GetVote() == VoteforCreation::UnknownCreate)
		{
			s++;
		}
	}
	if (s > 0)
	{
		return VoteforCreation::UnknownCreate;
	}

	s = 0;
	for (int i = 0; i < lst.size() - 1; i++)
	{
		AgentVoteFor<VoteforCreation> ag = lst[i];
		if (ag.GetVote() == VoteforCreation::Break)
		{
			s++;
		}
	}
	if (s > 0)
	{
		return VoteforCreation::Break;
	}
	else
	{
		return VoteforCreation::Create;
	}

}

VoteforExecution Mission::ResultofVotesforExecution()
{
	int t = 0;
	vector<AgentVoteFor<VoteforExecution>> lstExecution = GetMissionExecuteVotes();
	for (int i = 0; i < lstExecution.size(); i++)
	{
		AgentVoteFor<VoteforExecution> ag = lstExecution[i];
		if (ag.GetVote() == VoteforCreation::UnknownCreate)
		{
			t++;
		}
	}
	return VoteforExecution();
}

void Mission::CreationVote(bool forCreate, Agent ag)
{
	AgentVoteFor<VoteforCreation> avf = AgentVoteFor<VoteforCreation>();
	avf.SetAgent(ag);
	if (forCreate)
	{
		avf.SetVote(VoteforCreation::Create);
	}
	else
	{
		avf.SetVote(VoteforCreation::Break);
	}
	GetMissionVotes().push_back(avf);

	GetCurrentGameRound()->CheckProposalMission();
}

void Mission::ExecutionVote(bool forExecute, Agent ag)
{
	AgentVoteFor<VoteforExecution> avf = AgentVoteFor<VoteforExecution>();
	avf.SetAgent(ag);
	if (forExecute)
	{
		avf.SetVote(VoteforExecution::Execute);
	}
	else
	{
		avf.SetVote(VoteforExecution::Fail);
	}
	GetMissionExecuteVotes().push_back(avf);
	
	GetCurrentGameRound()->CheckProposalMission();
}

MissionResult Mission::GetMissionResult()
{
	if (ResultofVotesforCreation() == VoteforCreation::UnknownCreate)
		return MissionResult::UnknownRes;
	if (ResultofVotesforCreation() == VoteforCreation::Break)
		return MissionResult::VoteDown;
	if (ResultofVotesforCreation() == VoteforCreation::Create && ResultofVotesforCreation() == VoteforExecution::Fail)
		return MissionResult::Failed;
	if (ResultofVotesforCreation() == VoteforCreation::Create && ResultofVotesforCreation() == VoteforExecution::Execute)
		return MissionResult::Executed;
	if (ResultofVotesforCreation() == VoteforCreation::Create && ResultofVotesforCreation() == VoteforExecution::UnknownExec)
		return MissionResult::VoteUp;
	return MissionResult::UnknownRes;
}

