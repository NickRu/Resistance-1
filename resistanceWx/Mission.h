#pragma once
#include <vector>
#include "Agent.h"
#include "AgentVoteFor.h"
#include "AllEnum.h"

using namespace std;

class MissionCommand;
class GameRound;

class Mission
{
private:
	GameRound* _round;
	Agent* _lider;
	MissionCommand* _command;
	MissionResult _result;
	bool _isActive;
	vector<AgentVoteFor<VoteforCreation>> _missionVotes;
	vector<AgentVoteFor<VoteforExecution>> _missionExecuteVotes;
public:
	Mission(GameRound* rnd, Agent* lider);
	~Mission();

	//Game GetGame();

	GameRound* GetCurrentGameRound();

	Agent* GetLider();
	void SetLider(Agent* lider);

	vector<AgentVoteFor<VoteforCreation>> GetMissionVotes();
	void SetMissionVotes(vector<AgentVoteFor<VoteforCreation>> missionVotes);

	vector<AgentVoteFor<VoteforExecution>> GetMissionExecuteVotes();
	void SetMissionExecuteVotes(vector<AgentVoteFor<VoteforExecution>> missionExecuteVotes);

	MissionResult GetMissionResult();

	MissionCommand* GetMissionCommand();
	void SetMissionCommand(MissionCommand* mission);

	bool GetIsActiveMission();
	void SetIsActiveMission(bool isActive);

	VoteforCreation ResultofVotesforCreation();

	VoteforExecution ResultofVotesforExecution();

	void CreationVote(bool forCreate, Agent ag);
	void ExecutionVote(bool forExecute, Agent ag);
};

