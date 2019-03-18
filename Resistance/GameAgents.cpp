#include <time.h>
#include <algorithm>
#include "GameAgents.h"
#include "Game.h"
#include "AllEnum.h"

GameAgents::GameAgents()
{
}

GameAgents::GameAgents(Game* game)
{
	_game = game;
}

GameAgents::~GameAgents()
{
}

vector<Agent*> GameAgents::GetAgents()
{
	return _agents;
}

Game* GameAgents::GetGame()
{
	return _game;
}

bool GameAgents::RegistryAgent(Player& pl)
{
	Agent* ag = new Agent(pl, AgentStatus::Fighter);
	_agents.push_back(ag);
	return true;
}

bool GameAgents::UnregistryAgent(Agent* ag)
{
	return false;
}

void GameAgents::ExecuteStart()
{
	srand(time(0));
	for (int i = 0; i < _agents.size(); i++)
	{
		_agents[i]->SetRandomNumber(rand());
	}

	std::sort(_agents.begin(), _agents.end(), Agent::Comp);
	for (int i = 0; i < GetGame()->GetSpyNumbers()[_agents.size()]; i++)
	{
		_agents[i]->SetStatus(AgentStatus::Spy);
	}

	for (int i = 0; i < _agents.size(); i++)
	{
		_agents[i]->SetRandomNumber(rand());
	}

	std::sort(_agents.begin(), _agents.end(), Agent::Comp);
	_agents[0]->SetIsLider(true);

	for (int i = 0; i < _agents.size(); i++)
	{
		_agents[i]->SetOrderNumber(i);
	}
}

string GameAgents::CreateRandomName()
{
	return string();
}