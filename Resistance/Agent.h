#pragma once
#include "AllEnum.h"
#include "Player.h"

using namespace std;

class Agent		//игрок, закреплен за игрой
{
private:
	Player _player;					//принадлежность к игроку
	//string _codeName;				//кодовое имя (не под своим именем, возможно не нужно)
	int _randomNumber;				//случайное число (нужно, чтобы перемешивать игроков)
	AgentStatus _status;			//шпион или сопротивленец
	bool _isLider;					//другие полномочия
	int _orderNumber;				//порядок в игре после перемешивания
public:
	Agent();
	Agent(Player player, AgentStatus status);
	~Agent();

	Player GetPlayer();					//получить игрока

	int GetRandomNumber();				//получили рандомный номер
	void SetRandomNumber(int randNumb);	//дали рандомный номер

	int GetOrderNumber();				//получили порядковый номер
	void SetOrderNumber(int ordNumb);	//дали порядковый номер

	AgentStatus GetStatus();			//получили статус
	void SetStatus(AgentStatus status);	//дали статус

	bool GetIsLider();					//получили лидер ли
	void SetIsLider(bool isLider);		//дали лидер 

	static bool Comp(Agent* lhs, Agent* rhs);	//для сортировки игроков
};

