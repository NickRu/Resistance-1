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
		AgentVoteFor<VoteforCreation>* avf = new AgentVoteFor<VoteforCreation>();
		avf->SetAgent(_command->GetCommand()[i]->GetAgent());
		avf->SetVote(VoteforCreation::UnknownCreate);
		_missionVotes.push_back(avf);
	}

	for (int i = 0; i < _command->GetCommand().size(); i++)
	{
		AgentVoteFor<VoteforExecution>* avf = new AgentVoteFor<VoteforExecution>();
		avf->SetAgent(_command->GetCommand()[i]->GetAgent());
		avf->SetVote(VoteforExecution::UnknownExec);
		_missionExecuteVotes.push_back(avf);
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

void Mission::SetLider(Agent* lider)
{
	_lider = lider;
}

vector<AgentVoteFor<VoteforCreation>*> Mission::GetMissionVotes()
{
	return _missionVotes;
}

void Mission::SetMissionVotes(vector<AgentVoteFor<VoteforCreation>*> missionVotes)
{
}

vector<AgentVoteFor<VoteforExecution>*> Mission::GetMissionExecuteVotes()
{
	return _missionExecuteVotes;
}

void Mission::SetMissionExecuteVotes(vector<AgentVoteFor<VoteforExecution>*> _missionExecuteVotes)
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
	vector<AgentVoteFor<VoteforCreation>*> lst = _missionVotes;
	for (int i = 0; i < _missionVotes.size(); i++)
	{
		auto a = _missionVotes[i]->GetVote();
		AgentVoteFor<VoteforCreation>* ag = _missionVotes[i];
		if (_missionVotes[i]->GetVote() == VoteforCreation::UnknownCreate)
		{
			s++;
		}
	}
	if (s > 0)
	{
		return VoteforCreation::UnknownCreate;
	}

	s = 0;
	int size_of_comm = GetMissionCommand()->GetCommand().size();
	for (int i = 0; i < lst.size(); i++)
	{
		AgentVoteFor<VoteforCreation>* ag = lst[i];
		if (ag->GetVote() == VoteforCreation::Break)
		{
			s++;
		}
	}
	if (2*s > size_of_comm)
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
	int tr = 0;
	int fl = 0;
	vector<AgentVoteFor<VoteforExecution>*> lstExecution = GetMissionExecuteVotes();
	for (int i = 0; i < lstExecution.size(); i++)
	{
		AgentVoteFor<VoteforExecution>* ag = lstExecution[i];
		if (ag->GetVote() == VoteforExecution::Fail)
		{
			fl++;
		}
		if (ag->GetVote() == VoteforExecution::Execute)
		{
			tr++;
		}
	}

	int size_of_select = GetMissionCommand()->NumberofSelected();
	if (tr + fl == size_of_select)
	{
		return (fl > 0) ? VoteforExecution::Fail : VoteforExecution::Execute;
	}
	else
	{
		return VoteforExecution::UnknownExec;
	}


	//vector<AgentVoteFor<VoteforExecution>*> lstExecution = GetMissionExecuteVotes();
	//for (int i = 0; i < lstExecution.size(); i++)
	//{
	//	AgentVoteFor<VoteforExecution>* ag = lstExecution[i];
	//	if (ag->GetVote() == VoteforExecution::UnknownExec)
	//	{
	//		return VoteforExecution::UnknownExec;
	//	}
	//}

	//int t = 0;
	//for (int i = 0; i < lstExecution.size(); i++)
	//{
	//	AgentVoteFor<VoteforExecution>* ag = lstExecution[i];
	//	if (ag->GetVote() == VoteforExecution::Fail)
	//	{
	//		t++;
	//	}
	//}

	//if (t > 0)
	//{
	//	return VoteforExecution::UnknownExec;
	//}
	//else
	//{
	//	return VoteforExecution::Fail;
	//}
}

void Mission::CreationVote(bool forCreate, Agent ag)
{
	VoteforCreation vtc = forCreate ? VoteforCreation::Create : VoteforCreation::Break;
	for (auto avf : _missionVotes)
	{
		if (avf->GetAgent().GetPlayer().GetID() == ag.GetPlayer().GetID())
		{
			avf->SetVote(vtc);
		}
	}
	GetCurrentGameRound()->CheckProposalMission();
}

void Mission::ExecutionVote(bool forExecute, Agent ag)
{
	VoteforExecution vtc = forExecute ? VoteforExecution::Execute : VoteforExecution::Fail;
	for (auto avf : _missionExecuteVotes)
	{
		if (avf->GetAgent().GetPlayer().GetID() == ag.GetPlayer().GetID())
		{
			avf->SetVote(vtc);
		}
	}
	GetCurrentGameRound()->CheckProposalMission();


	//AgentVoteFor<VoteforExecution>* avf = new AgentVoteFor<VoteforExecution>();
	//avf->SetAgent(ag);
	//if (forExecute)
	//{
	//	avf->SetVote(VoteforExecution::Execute);
	//}
	//else
	//{
	//	avf->SetVote(VoteforExecution::Fail);
	//}
	//GetMissionExecuteVotes().push_back(avf);
	//
	//GetCurrentGameRound()->CheckProposalMission();
}

VoteforCreation Mission::GetAgentCreationVote(Agent ag)
{
	for (auto avf : _missionVotes)
	{
		if (avf->GetAgent().GetPlayer().GetID() == ag.GetPlayer().GetID())
		{
			return avf->GetVote();
		}
	}
	return VoteforCreation::UnknownCreate;
}

VoteforExecution Mission::GetAgentExecutionVote(Agent ag)
{
	for (auto avf : _missionExecuteVotes)
	{
		if (avf->GetAgent().GetPlayer().GetID() == ag.GetPlayer().GetID())
		{
			return avf->GetVote();
		}
	}
	return VoteforExecution::UnknownExec;
}

MissionResult Mission::GetMissionResult()
{
	VoteforCreation res = ResultofVotesforCreation();
	VoteforExecution res_exec = ResultofVotesforExecution();
	if (res == VoteforCreation::UnknownCreate)
		return MissionResult::UnknownRes;
	if (res == VoteforCreation::Break)
		return MissionResult::VoteDown;
	if (res == VoteforCreation::Create && res_exec == VoteforExecution::Fail)
		return MissionResult::Failed;
	if (res == VoteforCreation::Create && res_exec == VoteforExecution::Execute)
		return MissionResult::Executed;
	if (res == VoteforCreation::Create && res_exec == VoteforExecution::UnknownExec)
		return MissionResult::VoteUp;
	return MissionResult::UnknownRes;
}

