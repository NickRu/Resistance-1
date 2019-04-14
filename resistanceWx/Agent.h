#pragma once
#include "AllEnum.h"
#include "Player.h"
#include "OrderAgent.h"

using namespace std;

class Agent : public OrderAgent	//игрок, закреплен за игрой
{
private:
	Player* _player;					//принадлежность к игроку
	//string _codeName;				//кодовое имя (не под своим именем, возможно не нужно)
	int _randomNumber;				//случайное число (нужно, чтобы перемешивать игроков)
	SpyAgentStatus _status;			//шпион или сопротивленец
	bool _isLider;					//другие полномочия
	//int _orderNumber;				//порядок в игре после перемешивания
public:
	Agent();
	Agent(Player* player);
	~Agent();

	Player GetPlayer();		//получить игрока

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