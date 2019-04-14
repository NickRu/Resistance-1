#pragma once
#include "AllEnum.h"
#include "Player.h"
#include "OrderAgent.h"

using namespace std;

class Agent : public OrderAgent	//�����, ��������� �� �����
{
private:
	Player* _player;					//�������������� � ������
	//string _codeName;				//������� ��� (�� ��� ����� ������, �������� �� �����)
	int _randomNumber;				//��������� ����� (�����, ����� ������������ �������)
	SpyAgentStatus _status;			//����� ��� �������������
	bool _isLider;					//������ ����������
	//int _orderNumber;				//������� � ���� ����� �������������
public:
	Agent();
	Agent(Player* player);
	~Agent();

	Player GetPlayer();		//�������� ������

	int GetRandomNumber();
	void SetRandomNumber(int randNumb);

	//int GetOrderNumber();
	//void SetOrderNumber(int ordNumb);

	int GetNumberOfAgent();

	SpyAgentStatus GetStatus();
	void SetStatus(SpyAgentStatus status);

	bool GetIsLider();
	void SetIsLider(bool isLider);

	static bool Comp(Agent* lhs, Agent* rhs);
};