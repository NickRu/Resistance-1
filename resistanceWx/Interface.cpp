//#define SFML_NO_DEPRECATED_WARNINGS
#include <SFML/Graphics.hpp>
#include <TGUI/TGUI.hpp>
#include <vector>
#include <string>
#include "Game.h"
#include "GameAgents.h"
#include "GameRound.h"
#include "Mission.h"
#include "MissionCommand.h"
#include "AgentInMission.h"
#include "AgentVoteFor.h"
#include "Player.h"
#include <iostream>

void change_player(Agent** agent_choosen, Agent* i) // �������, ����� �������� ���������� ������ �� �������
{
	(*agent_choosen) = i;
}

void checkPlayer(Game** gm, std::string nickN) // �������, ����� �������� ���������� ������ �� �������
{
	for (int k = 0; k < (*gm)->GetCurrentGameRound()->GetCurrentPropMission()->GetMissionCommand()->GetCommand().size(); k++) //��������� ������ ���������� ������
	{
		AgentInMission aim = (*gm)->GetCurrentGameRound()->GetCurrentPropMission()->GetMissionCommand()->GetCommand()[k];
		if (nickN == aim.GetAgent().GetPlayer().GetNickName())
			aim.SetIsSelected(true);
	}
}

void uncheckPlayer(Game** gm, std::string nickN) // �������, ����� �������� ���������� ������ �� �������
{
	for (int k = 0; k < (*gm)->GetCurrentGameRound()->GetCurrentPropMission()->GetMissionCommand()->GetCommand().size(); k++) //��������� ������ ���������� ������
	{
		AgentInMission aim = (*gm)->GetCurrentGameRound()->GetCurrentPropMission()->GetMissionCommand()->GetCommand()[k];
		if (nickN == aim.GetAgent().GetPlayer().GetNickName())
			aim.SetIsSelected(false);
	}
}

int main()
{
	Game* gm = new Game();


	#pragma region InitRegion
	char first0[] = "Alex";
	char sec0[] = "�";
	char code0[] = "Jhon";
	int rate0 = 100;
	int age0 = 48;
	Player* pl0 = new Player(first0, sec0, code0, rate0, age0);
	gm->GetGameAgents()->RegistryAgent(pl0);

	char first1[] = "Oleg";
	char sec1[] = "�";
	char code1[] = "Ivan";
	int rate1 = 100;
	int age1 = 45;
	Player* pl1 = new Player(first1, sec1, code1, rate1, age1);
	gm->GetGameAgents()->RegistryAgent(pl1);

	char first2[] = "Masha";
	char sec2[] = "�";
	char code2[] = "Henry";
	int rate2 = 100;
	int age2 = 18;
	Player* pl2 = new Player(first2, sec2, code2, rate2, age2);
	gm->GetGameAgents()->RegistryAgent(pl2);


	char first3[] = "Anna";
	char sec3[] = "�";
	char code3[] = "Fred";
	int rate3 = 100;
	int age3 = 15;
	Player* pl3 = new Player(first3, sec3, code3, rate3, age3);
	gm->GetGameAgents()->RegistryAgent(pl3);
	if (!gm->CanStartGame())
		cout << "������� ������������\n";
	else
		cout << "������� ����������\n";

	char first4[] = "Anastasia";
	char sec4[] = "�";
	char code4[] = "Dart Vaider";
	int rate4 = 100;
	int age4 = 65;
	Player* pl4 = new Player(first4, sec4, code4, rate4, age4);
	gm->GetGameAgents()->RegistryAgent(pl4);

	char first5[] = "Rita";
	char sec5[] = "�";
	char code5[] = "Ginny";
	int rate5 = 100;
	int age5 = 18;
	Player* pl5 = new Player(first5, sec5, code5, rate5, age5);
	gm->GetGameAgents()->RegistryAgent(pl5);

	char first6[] = "Slava";
	char sec6[] = "�";
	char code6[] = "Peter";
	int rate6 = 100;
	int age6 = 18;
	Player* pl6 = new Player(first6, sec6, code6, rate6, age6);
	gm->GetGameAgents()->RegistryAgent(pl6);

	char first7[] = "Nastya";
	char sec7[] = "�";
	char code7[] = "Lisa";
	int rate7 = 100;
	int age7 = 18;
	Player* pl7 = new Player(first7, sec7, code7, rate7, age7);
	gm->GetGameAgents()->RegistryAgent(pl7);

	gm->ExecuteStart();
	sf::RenderWindow window{ {800, 600}, "Window" };
	tgui::Gui gui{ window };

	Agent *agent_choosen = gm->GetGameAgents()->GetAgents()[0]; //������ ������ ���������� �� ������. �� ��������� �������.

	////��������� �������� ��������� �� �����, ����� �������������� ��� ������ �������
	gui.loadWidgetsFromFile("interface.txt");

	tgui::Label::Ptr label_curr_player;
	label_curr_player = gui.get<tgui::Label>("label_curr_player");
	label_curr_player->setPosition(window.getSize().x * 0.5 - 0.3 * label_curr_player->getSize().x, 25);

	tgui::Button::Ptr buttons_r[5]; // ������ ������ �������. ��� ����, ����� ��������� �� �����
	buttons_r[0] = gui.get<tgui::Button>("button_r_1");
	buttons_r[1] = gui.get<tgui::Button>("button_r_2");
	buttons_r[2] = gui.get<tgui::Button>("button_r_3");
	buttons_r[3] = gui.get<tgui::Button>("button_r_4");
	buttons_r[4] = gui.get<tgui::Button>("button_r_5");

	tgui::Button::Ptr buttons_m[5]; // ������ ������ ������. ��� ����, ����� ��������� �� �����
	buttons_m[0] = gui.get<tgui::Button>("button_m_1");
	buttons_m[1] = gui.get<tgui::Button>("button_m_2");
	buttons_m[2] = gui.get<tgui::Button>("button_m_3");
	buttons_m[3] = gui.get<tgui::Button>("button_m_4");
	buttons_m[4] = gui.get<tgui::Button>("button_m_5");


	tgui::ChildWindow::Ptr window_round;
	window_round = gui.get<tgui::ChildWindow>("window_round");
	tgui::ChildWindow::Ptr window_missions_panel;
	window_missions_panel = gui.get<tgui::ChildWindow>("window_missions_panel");
	tgui::ChildWindow::Ptr window_team;
	window_team = gui.get<tgui::ChildWindow>("window_team");
	tgui::ChildWindow::Ptr window_work;
	window_work = gui.get<tgui::ChildWindow>("window_work");

	tgui::RadioButton::Ptr rad_but_accept;
	rad_but_accept = gui.get<tgui::RadioButton>("rad_but_accept");
	tgui::RadioButton::Ptr rad_but_refuse;
	rad_but_refuse = gui.get<tgui::RadioButton>("rad_but_refuse");
	tgui::RadioButton::Ptr rad_but_help;
	rad_but_help = gui.get<tgui::RadioButton>("rad_but_help");
	tgui::RadioButton::Ptr rad_but_hinder;
	rad_but_hinder = gui.get<tgui::RadioButton>("rad_but_hinder");
	////////////////////////////



	////////MENU///////////
	// ����� ���������� �� ������ ������� �� ������ � ����. ������� �� ������� ��� ������� ������. ������� ����� ������ � ������� �������
	tgui::MenuBar::Ptr menu = tgui::MenuBar::create();
	gui.add(menu);

	for (auto p : gm->GetGameAgents()->GetAgents())
	{
		menu->addMenu(p->GetPlayer().GetFirstName());
		menu->addMenuItem(p->GetPlayer().GetFirstName());//��������� ������� � ������� �������. �� ���� ������� ������� ������, ������� ��������� �������
		menu->connectMenuItem(p->GetPlayer().GetFirstName(), p->GetPlayer().GetFirstName(), change_player, &agent_choosen, p);
	}

	//����� �����, �� ����� ���� ������ ������������ �����. ��� ���������� ������ ������ ������������ ������
	////////////////////////

	//// ������� ������ � ������� ������� ///////
	std::vector<tgui::CheckBox::Ptr> player_buttons; //������ ���� ������
	std::vector<tgui::Label::Ptr> label_player_name_vector; //������ ���� ������� � ������� ������� (������� ������)

	for (auto p : gm->GetGameAgents()->GetAgents())
	{
		tgui::CheckBox::Ptr chbx = tgui::CheckBox::create();
		chbx->setSize(21, 21);
		chbx->connect("checked", checkPlayer, &(gm), p->GetPlayer().GetNickName());
		chbx->connect("unchecked", uncheckPlayer, &(gm), p->GetPlayer().GetNickName());
		player_buttons.push_back(chbx);
		window_missions_panel->add(player_buttons[player_buttons.size() - 1]); //��������� �� �� ��������� ����

		tgui::Label::Ptr lbl = tgui::Label::create();
		lbl->setText(p->GetPlayer().GetNickName()); //����������� ���������� ����� ������� �������
		label_player_name_vector.push_back(lbl);
		window_missions_panel->add(label_player_name_vector[label_player_name_vector.size() - 1]);
	}

	float delta = 0.9 * window_missions_panel->getSize().x / (player_buttons.size() + 0.3); //���������� ����� ��������
	int k = 1;

	for (auto p : player_buttons) // ����������� ������ � ������
	{
		p->setPosition(k * delta - p->getSize().x / 2, window_missions_panel->getSize().y * 0.15);
		k++;
	}

	k = 1;

	for (auto p : label_player_name_vector) // ����������� ������ � ������
	{
		p->setPosition(k * delta - p->getSize().x / 2, window_missions_panel->getSize().y * 0.05);
		k++;
	}

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
			gui.handleEvent(event);
		}

		////�������� ��������////

		////���������////
		if (agent_choosen->GetIsLider()) //���������� � ���������� ������ ������
			label_curr_player->setText(agent_choosen->GetPlayer().GetFirstName() + "[^^^]");
		else
			label_curr_player->setText(agent_choosen->GetPlayer().GetFirstName());
		////////////////

		////�������� ��������////
		for (int i = 0; i < gm->GetGameRounds().size(); i++) //��������� ������ ���������� �������
		{
			for (int j = 0; j < gm->GetGameRounds()[i]->GetPropMission().size(); j++) //��������� ������ ���������� ������
			{
				buttons_m[j]->setEnabled(gm->GetGameRounds()[i]->GetPropMission()[j]->GetIsActiveMission());
			}
			buttons_r[i]->setEnabled(gm->GetGameRounds()[i]->GetIsActiveRound());
		}

		for (int i = 0; i < player_buttons.size(); i++)
		{
			player_buttons[i]->setEnabled(agent_choosen->GetIsLider());
			//sf::String nickN = label_player_name_vector[i]->getText();
			//for (int k = 0; k < gm->GetCurrentGameRound()->GetCurrentPropMission()->GetMissionCommand()->GetCommand().size(); k++) //��������� ������ ���������� ������
			//{
			//	AgentInMission aim = gm->GetCurrentGameRound()->GetCurrentPropMission()->GetMissionCommand()->GetCommand()[k];
			//	if(nickN == aim.GetAgent().GetPlayer().GetNickName())
			//		player_buttons[i]->setChecked(aim.GetIsSelected());
			//}
		}

		if (gm->GetCurrentGameRound()->GetCommandSize() == gm->GetCurrentGameRound()->GetCurrentPropMission()->GetMissionCommand()->NumberofSelected())
		{
			for (int i = 0; i < player_buttons.size(); i++)
			{
				if(!player_buttons[i]->isChecked())
					player_buttons[i]->setEnabled(false);
			}
		}


		if (gm->GetCurrentGameRound()->GetCommandSize() == gm->GetCurrentGameRound()->GetCurrentPropMission()->GetMissionCommand()->NumberofSelected())
		{
			rad_but_accept->setEnabled(true);
			rad_but_refuse->setEnabled(true);
		}
		else
		{
			rad_but_accept->setEnabled(false);
			rad_but_refuse->setEnabled(false);
		}


		window.clear(sf::Color(230, 230, 230));
		gui.draw(); // Draw all widgets
		window.display();
	}
}