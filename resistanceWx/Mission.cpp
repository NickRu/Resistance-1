#include "Mission.h"
#include "Agent.h"
#include "Game.h"
#include "GameRound.h"
#include "GameAgents.h"
#include "MissionCommand.h"
#include "AgentVoteFor.h"

using namespace std;

Mission::Mission(GameRound* round, Agent* lider, int missionNumber)
{
	_round = round;
	_lider = lider;
	_missionNumber = missionNumber;
	_command = new MissionCommand(this);

	for (int i = 0; i < _command->GetCommand().size(); i++)
	{
		AgentVoteFor<VoteforCreation> avf = AgentVoteFor<VoteforCreation>();
		avf.SetAgent(_command->GetCommand()[i]->GetAgent());
		avf.SetVote(VoteforCreation::UnknownCreate);
		_missionVotes.push_back(avf);
	}
}

Mission::~Mission()
{
}

GameRound* Mission::GetCurrentGameRound()
{
	return _round;
}

int Mission::GetMissionNumber()
{
	return _missionNumber;
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
	vector<AgentVoteFor<VoteforCreation>> lst = _missionVotes;
	for (int i = 0; i < _missionVotes.size(); i++)
	{
		auto a = _missionVotes[i].GetVote();
		AgentVoteFor<VoteforCreation> ag = _missionVotes[i];
		if (_missionVotes[i].GetVote() == VoteforCreation::UnknownCreate)
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
	vector<AgentVoteFor<VoteforExecution>> lstExecution = GetMissionExecuteVotes();
	for (int i = 0; i < lstExecution.size(); i++)
	{
		AgentVoteFor<VoteforExecution> ag = lstExecution[i];
		if (ag.GetVote() == VoteforExecution::UnknownExec)
		{
			return VoteforExecution::UnknownExec;
		}
	}

	int t = 0;
	for (int i = 0; i < lstExecution.size() - 1; i++)
	{
		AgentVoteFor<VoteforExecution> ag = lstExecution[i];
		if (ag.GetVote() == VoteforExecution::Fail)
		{
			t++;
		}
	}

	if (t > 0)
	{
		return VoteforExecution::UnknownExec;
	}
	else
	{
		return VoteforExecution::Fail;
	}
}

void Mission::CreationVote(bool forCreate, Agent ag)
{
	VoteforCreation vtc = forCreate ? VoteforCreation::Create : VoteforCreation::Break;
	for (auto avf : _missionVotes)
	{
		if (avf.GetAgent().GetPlayer().GetID() == ag.GetPlayer().GetID())
		{
			avf.SetVote(vtc);
		}
	}
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
	if (ResultofVotesforCreation() == VoteforCreation::Create && ResultofVotesforExecution() == VoteforExecution::Fail)
		return MissionResult::Failed;
	if (ResultofVotesforCreation() == VoteforCreation::Create && ResultofVotesforExecution() == VoteforExecution::Execute)
		return MissionResult::Executed;
	if (ResultofVotesforCreation() == VoteforCreation::Create && ResultofVotesforExecution() == VoteforExecution::UnknownExec)
		return MissionResult::VoteUp;
	return MissionResult::UnknownRes;
}

