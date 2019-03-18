#pragma once
#include "AllEnum.h"
#include "Player.h"

using namespace std;

class Agent		//�����, ��������� �� �����
{
private:
	Player _player;					//�������������� � ������
	//string _codeName;				//������� ��� (�� ��� ����� ������, �������� �� �����)
	int _randomNumber;				//��������� ����� (�����, ����� ������������ �������)
	AgentStatus _status;			//����� ��� �������������
	bool _isLider;					//������ ����������
	int _orderNumber;				//������� � ���� ����� �������������
public:
	Agent();
	Agent(Player player, AgentStatus status);
	~Agent();

	Player GetPlayer();					//�������� ������

	int GetRandomNumber();				//�������� ��������� �����
	void SetRandomNumber(int randNumb);	//���� ��������� �����

	int GetOrderNumber();				//�������� ���������� �����
	void SetOrderNumber(int ordNumb);	//���� ���������� �����

	AgentStatus GetStatus();			//�������� ������
	void SetStatus(AgentStatus status);	//���� ������

	bool GetIsLider();					//�������� ����� ��
	void SetIsLider(bool isLider);		//���� ����� 

	static bool Comp(Agent* lhs, Agent* rhs);	//��� ���������� �������
};

