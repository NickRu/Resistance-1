#pragma once
#include "Agent.h"

class MissionCommand;

class AgentInMission					//����� � ���������� ������
{
private:
	Agent _agent;
	bool _isSelected;					//������ �� � ����� � ������
	MissionCommand* _command;			//���� ������� ������
public:
	AgentInMission(MissionCommand* cm, Agent ag);
	~AgentInMission();

	void CreateMission(bool b);			//������ ����� ����� �� �������� ������ (����� ��� ���������� ������)
	void ExecuteMission(bool b);		//�� ���������� ������, ���� ���� � ������ (����� ��� ��������� ������)

	void SetAgent(Agent ag);			//���� ������, ������� ������ ����� � ������?? (����� � ...)
	Agent GetAgent();					//�������� ������?? (����� � ...)

	void SetCommand(MissionCommand* cm);//���� �������?? (����� � ...)
	MissionCommand* GetCommand();		//�������� �������?? (����� � ...)

	void SetIsSelected(bool b);			//������ ������ ����
	bool GetIsSelected();				//�������� (����� ��� ExecuteVote)

};

