#include "Agent.h"
#include "Player.h"

Agent::Agent(Player player, AgentStatus status)
{
	_player = player;			//в конструкторе присваиваем всем частным переменным значения
	_status = AgentStatus::Fighter;
	//_codeName = code;
}

Agent::Agent()
{
}

Agent::~Agent()
{
}

Player Agent::GetPlayer()
{
	return _player;
}

int Agent::GetRandomNumber()
{
	return _randomNumber;
}

void Agent::SetRandomNumber(int randNumb)
{
	_randomNumber = randNumb;
}

int Agent::GetOrderNumber()
{
	return _orderNumber;
}

void Agent::SetOrderNumber(int ordNumb)
{
	_orderNumber = ordNumb;
}

AgentStatus Agent::GetStatus()
{
	return _status;
}

void Agent::SetStatus(AgentStatus status)
{
	_status = status;
}

bool Agent::GetIsLider()
{
	return _isLider;
}

void Agent::SetIsLider(bool isLider)
{
	_isLider = isLider;
}

bool Agent::Comp(Agent* lhs, Agent* rhs)
{
	return (*lhs)._randomNumber < (*rhs)._randomNumber;
}

