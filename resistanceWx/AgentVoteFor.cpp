#include "AgentVoteFor.h"

template<typename T>
AgentVoteFor<T>::AgentVoteFor()
{
}

template<typename T>
AgentVoteFor<T>::AgentVoteFor(T x, Agent ag)
{
	_agent = ag;
	_vote = x;
}

template<typename T>
AgentVoteFor<T>::AgentVoteFor(Agent ag)
{
	_agent = ag;
	_vote = (T)0;
}

template<typename T>
AgentVoteFor<T>::~AgentVoteFor()
{

}

template<typename T>
T AgentVoteFor<T>::GetVote()
{
	return _vote;
}

template<typename T>
void AgentVoteFor<T>::SetVote(T vt)
{
	_vote = vt;
}

template<typename T>
Agent AgentVoteFor<T>::GetAgent()
{
	return _agent;
}

template<typename T>
void AgentVoteFor<T>::SetAgent(Agent agt)
{
	_agent = agt;
}

template class AgentVoteFor<int>;
template class AgentVoteFor<VoteforCreation>;
template class AgentVoteFor<VoteforExecution>;