#pragma once
#include "Agent.h"

class MissionCommand;

class AgentInMission					//агент в конкретной миссии
{
private:
	Agent _agent;
	bool _isSelected;					//выбран ли в поход в миссию
	MissionCommand* _command;			//сама команда миссии
public:
	AgentInMission(MissionCommand* cm, Agent ag);
	~AgentInMission();

	void CreateMission(bool b);			//всегда имеет голос за создание миссии (нужен для результата миссии)
	void ExecuteMission(bool b);		//за исполнение миссии, если идет в миссию (нужен для резльтата миссии)

	void SetAgent(Agent ag);			//даем агента, который данный агент в миссии?? (нужен в ...)
	Agent GetAgent();					//получаем агента?? (нужен в ...)

	void SetCommand(MissionCommand* cm);//даем команду?? (нужен в ...)
	MissionCommand* GetCommand();		//получаем команду?? (нужен в ...)

	void SetIsSelected(bool b);			//статус выбора даем
	bool GetIsSelected();				//получаем (нужно для ExecuteVote)

};

