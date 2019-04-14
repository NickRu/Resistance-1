#pragma once
#include "Agent.h"

template<typename T>
class AgentVoteFor
{
private:
	Agent _agent;				//знает, к какому агенту принадлежит (чтобы можно было смотреть статистику)
	T _vote;					//разный тип голосов
public:
	AgentVoteFor();
	AgentVoteFor(T x, Agent ag);
	AgentVoteFor(Agent ag);
	~AgentVoteFor();
	T GetVote();				//получаем голос
	void SetVote(T vt);			//даем голос
	Agent GetAgent();			//даем агента
	void SetAgent(Agent agt);	//может не нужен
};
