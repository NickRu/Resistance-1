#include <time.h>
#include <algorithm>
#include "GameAgents.h"
#include "Game.h"
//#include "Agent.h"

GameAgents::GameAgents()
{
}

GameAgents::GameAgents(Game* game)
{
	_game = game;
}

GameAgents::~GameAgents()
{
	// Это пока не надо
	int s = _agents.size();
	for (int i = 0; i < s; i++)
	{
		Agent* ag = _agents[i];
		delete(ag);
	}
}

vector<Agent*> GameAgents::GetAgents()
{
	return _agents;
}

Game* GameAgents::GetGame()
{
	return _game;
}

bool GameAgents::RegistryAgent(Player* pl)
{
	Agent* ag = new Agent(pl);
	_agents.push_back(ag);
	return false;
}

bool GameAgents::UnregistryAgent(Agent& ag)
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
	for (int i = 0; i < GetGame()->GetSpyNumbers()[_agents.size()-1]; i++)//here was an update
	{
		_agents[i]->SetStatus(SpyAgentStatus::Spy);
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
