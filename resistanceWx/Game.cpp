#include "Game.h"
#include "GameAgents.h"
#include "GameRound.h"

Game::Game()
{
	_gameAgents = new GameAgents(this);
	SetStartCondition();
}

Game::~Game()
{
	// Это пока не надо
	delete(_gameAgents);
	int s = _gameRounds.size();
	for (size_t i = 0; i < s; i++)
	{
		//delete(_gameRounds[i]);
		GameRound* ag = _gameRounds[i];
		delete(ag);
	}
}

GameAgents* Game::GetGameAgents()
{
	return _gameAgents;
}

bool Game::CanStartGame()
{
	return (GetGameAgents()->GetAgents().size() > _lowBorderAgents);
}

bool Game::CanRegistryAgents()
{
	return (GetGameAgents()->GetAgents().size() < _highBorderAgents);
}

map<int, int> Game::GetSpyNumbers()
{
	return _spyNumbers;
}

vector<GameRound*> Game::GetGameRounds()
{
	return _gameRounds;
}

GameRound * Game::GetCurrentGameRound()
{
	for (size_t i = 0; i < this->GetGameRounds().size(); i++)
	{
		if (this->GetGameRounds()[i]->GetIsActiveRound())
		{
			return  GetGameRounds()[i];
		}
	}

	return nullptr;
}

MissionResult Game::Result()
{
	int fl = 0, ex = 0;
	for (int i = 0; i < 5; i++)
	{
		MissionResult res = _gameRounds[i]->GetResult();
		if (res == MissionResult::Failed)
		{
			fl++;
		}
		if (res == MissionResult::Executed)
		{
			ex++;
		}
	}
	if (fl > 2)
	{
		return MissionResult::Failed;
	}
	if (ex > 2)
	{
		return MissionResult::Executed;
	}
	return MissionResult::UnknownRes;
}

bool Game::RegistryGameAgent(Player* pl)
{
	return GetGameAgents()->RegistryAgent(pl);
}

bool Game::UnregistryGameAgent(Agent ag)
{
	return GetGameAgents()->UnregistryAgent(ag);
}
void Game::ExecuteStart()
{
	GetGameAgents()->ExecuteStart();

	for (int i = 0; i < 5; i++)
	{
		GameRound* gr = new GameRound(this, _missionNumbers[GetGameAgents()->GetAgents().size()][i],(i+1));
		_gameRounds.push_back(gr);
	}

	_gameRounds.at(0)->SetIsActiveRound(true);	//первый раунд активный
}

void Game::CheckRound()
{
	//GameRound gr = GameRounds.First(n = > n.IsActiveRound == true);
	//int num = gr.RoundNumber;
	//gr.IsActiveRound = false;
	//this.CheckGame();
	//if (num < GameRounds.Count)
	//	GameRounds[num].IsActiveRound = true;
	int r = 0;
	for (size_t i = 0; i < this->GetGameRounds().size(); i++)
	{
		if (this->GetGameRounds()[i]->GetIsActiveRound())
		{
			r = GetGameRounds()[i]->GetRoundNumber();
			GetGameRounds()[i]->SetIsActiveRound(false);
			break;
		}
	}
	this->CheckGame();
	if(r <= GetGameRounds().size())
		GetGameRounds()[r]->SetIsActiveRound(true);
}

void Game::CheckGame()
{
	if (Result() == (MissionResult::Executed | MissionResult::Failed))
	{
		ExecuteStop();
	}
}

void Game::ExecuteStop()
{
}

void Game::SetStartCondition()
{
	_lowBorderAgents = 4;
	_highBorderAgents = 11;
	_spyNumbers = { {5, 2}, {6, 2}, {7, 3}, {8, 3}, {9, 3}, {10, 4} };
	_missionNumbers =
	{
		{5, {2, 3, 2, 3, 3}},
		{6, {2, 3, 4, 3, 4}},
		{7, {2, 3, 3, 4, 4}}, 
		{8, {3, 4, 4, 5, 5}},
		{9, {3, 4, 4, 5, 5}},
		{10, {3, 4, 4, 5, 5}}
	};
}
//
////void Game::SetAgents(GameAgents agents)
////{
////}
