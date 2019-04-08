#pragma once
#include <vector>
#include "Agent.h"
#include "AgentVoteFor.h"
#include "AllEnum.h"

using namespace std;
class GameRound; //Forward Declare
class MissionCommand; //Forward Declare

class Mission
{
private:
	int _missionNumber;
	GameRound* _round;
	Agent* _lider;
	MissionCommand* _command;
	MissionResult _result;
	bool _isActive;
	vector<AgentVoteFor<VoteforCreation>> _missionVotes;
	vector<AgentVoteFor<VoteforExecution>> _missionExecuteVotes;
public:
	Mission(GameRound* round, Agent* lider, int missionNumber);
	~Mission();

	GameRound* GetCurrentGameRound();
	int GetMissionNumber();

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

