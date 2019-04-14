#pragma once
#include "Agent.h"

template<typename T>
class AgentVoteFor
{
private:
	Agent _agent;				//�����, � ������ ������ ����������� (����� ����� ���� �������� ����������)
	T _vote;					//������ ��� �������
public:
	AgentVoteFor();
	AgentVoteFor(T x, Agent ag);
	AgentVoteFor(Agent ag);
	~AgentVoteFor();
	T GetVote();				//�������� �����
	void SetVote(T vt);			//���� �����
	Agent GetAgent();			//���� ������
	void SetAgent(Agent agt);	//����� �� �����
};
