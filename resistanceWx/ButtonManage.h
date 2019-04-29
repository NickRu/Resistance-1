#pragma once
#include <TGUI/TGUI.hpp>
#include "Agent.h"
#include "Game.h"
#include "GameRound.h"
#include "GameAgents.h"
#include "Mission.h"
#include "MissionCommand.h"
#include "AgentInMission.h"
#include "AgentVoteFor.h"
#include "Player.h"
#include "AllEnum.h"


class ButtonManage
{
private:
	Game* gm;
	Agent *agent_choosen;
	tgui::Button::Ptr buttons_r[5];
	tgui::Button::Ptr buttons_m[5];
	std::vector<tgui::CheckBox::Ptr> player_buttons; //Вектор всех кнопок
	std::vector<tgui::Label::Ptr> label_player_name_vector; //Вектор всех ярлыков с именами игроков (Подписи кнопок)
	
	tgui::Label::Ptr label_curr_player;

	tgui::ChildWindow::Ptr window_round;
	tgui::ChildWindow::Ptr window_missions_panel;
	tgui::ChildWindow::Ptr window_team;
	tgui::ChildWindow::Ptr window_work;

	tgui::RadioButton::Ptr rad_but_accept;
	tgui::RadioButton::Ptr rad_but_refuse;
	tgui::RadioButton::Ptr rad_but_unknown_create;
	tgui::RadioButton::Ptr rad_but_help;
	tgui::RadioButton::Ptr rad_but_hinder;
	tgui::RadioButton::Ptr rad_but_unknown_exec;

public:
	ButtonManage();
	ButtonManage(Game* gm);
	~ButtonManage();

	void FillButtons(tgui::Gui* gui, sf::RenderWindow* window);
	void ChangeRoundButton(int i, MissionResult res);
	void ChangeMissionButton(int j, MissionResult res);
	void ChangeVisualElements();
	void ChangePlayer(Agent* i);
	void create_mission(Game** gm, Agent** agent_choosen, bool b); // Команда, чтобы поменять выбранного игрока по нажатию
	void exec_mission(Game** gm, Agent** agent_choosen, bool b); // Команда, чтобы поменять выбранного игрока по нажатию
	void checkPlayer(Game** gm, std::string nickN); // Команда, чтобы поменять выбранного игрока по нажатию
	void uncheckPlayer(Game** gm, std::string nickN); // Команда, чтобы поменять выбранного игрока по нажатию
};

