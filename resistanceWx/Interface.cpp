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

void change_player(std::string* player_choosen, Game** gm, const sf::String& param) // �������, ����� �������� ���������� ������ �� �������
{
	for (auto p : (*gm)->GetGameAgents()->GetAgents())
	{
		if ((param == p->GetPlayer().GetNickName()) && (p->GetIsLider()))
		{
			(*player_choosen) = param.toAnsiString();
			(*player_choosen) += " W";
			return;
		}
	}
	(*player_choosen) = param.toAnsiString();
	return;
}

int main()
{
	Game* gm = new Game();


	#pragma region InitRegion
	string first0 = "Alex";
	string sec0 = "�";
	string code0 = "Alex";
	int rate0 = 100;
	int age0 = 48;
	Player* pl0 = new Player(first0, sec0, code0, rate0, age0);
	gm->GetGameAgents()->RegistryAgent(pl0);

	string first1 = "Oleg";
	string sec1 = "�";
	string code1 = "Oleg";
	int rate1 = 100;
	int age1 = 45;
	Player* pl1 = new Player(first1, sec1, code1, rate1, age1);
	gm->GetGameAgents()->RegistryAgent(pl1);

	string first2 = "Masha";
	string sec2 = "�";
	string code2 = "Masha";
	int rate2 = 100;
	int age2 = 18;
	Player* pl2 = new Player(first2, sec2, code2, rate2, age2);
	gm->GetGameAgents()->RegistryAgent(pl2);


	string first3 = "Anna";
	string sec3 = "�";
	string code3 = "Anna";
	int rate3 = 100;
	int age3 = 15;
	Player* pl3 = new Player(first3, sec3, code3, rate3, age3);
	gm->GetGameAgents()->RegistryAgent(pl3);
	if (!gm->CanStartGame())
		cout << "������� ������������\n";
	else
		cout << "������� ����������\n";

	string first4 = "Anastasia";
	string sec4 = "�";
	string code4 = "Anastasia";
	int rate4 = 100;
	int age4 = 65;
	Player* pl4 = new Player(first4, sec4, code4, rate4, age4);
	gm->GetGameAgents()->RegistryAgent(pl4);

	string first5 = "Rita";
	string sec5 = "�";
	string code5 = "Rita";
	int rate5 = 100;
	int age5 = 18;
	Player* pl5 = new Player(first5, sec5, code5, rate5, age5);
	gm->GetGameAgents()->RegistryAgent(pl5);

	string first6 = "Slava";
	string sec6 = "�";
	string code6 = "Slava";
	int rate6 = 100;
	int age6 = 18;
	Player* pl6 = new Player(first6, sec6, code6, rate6, age6);
	gm->GetGameAgents()->RegistryAgent(pl6);

	string first7 = "Nastya";
	string sec7 = "�";
	string code7 = "Nastya";
	int rate7 = 100;
	int age7 = 18;
	Player* pl7 = new Player(first7, sec7, code7, rate7, age7);
	gm->GetGameAgents()->RegistryAgent(pl7);

	gm->ExecuteStart();
	sf::RenderWindow window{ {800, 600}, "Window" };
	tgui::Gui gui{ window };


	//// ������ �������. ����� ������ ����� � ������������ � ���� �������. ����� ���� ������������� ������� �� 4 �� 10
	//std::vector<std::string> players_vector;
	//// ���������
	//players_vector.push_back("Jhon");
	//players_vector.push_back("Ivan");
	//players_vector.push_back("Henry");
	//players_vector.push_back("Dart Vaider");
	//players_vector.push_back("Fred");
	//players_vector.push_back("Ginny");
	//players_vector.push_back("Peter");
	//players_vector.push_back("Lisa");
	////players_vector.push_back("Molly");
	////players_vector.push_back("Gerald");

	std::string player_choosen = gm->GetGameAgents()->GetAgents()[0]->GetPlayer().GetNickName() + " W"; //������ ������ ���������� �� ������. �� ��������� �������.
	//// ����� ����������

	////��������� �������� ��������� �� �����, ����� �������������� ��� ������ �������
	gui.loadWidgetsFromFile("interface.txt");

	tgui::Label::Ptr label_curr_player;
	label_curr_player = gui.get<tgui::Label>("label_curr_player");
	label_curr_player->setPosition(window.getSize().x * 0.5 - 0.3 * label_curr_player->getSize().x, 25);

	tgui::Button::Ptr button_r_1;
	button_r_1 = gui.get<tgui::Button>("button_r_1");
	tgui::Button::Ptr button_r_2;
	button_r_2 = gui.get<tgui::Button>("button_r_2");
	tgui::Button::Ptr button_r_3;
	button_r_3 = gui.get<tgui::Button>("button_r_3");
	tgui::Button::Ptr button_r_4;
	button_r_4 = gui.get<tgui::Button>("button_r_4");
	tgui::Button::Ptr button_r_5;
	button_r_5 = gui.get<tgui::Button>("button_r_5");

	tgui::Button::Ptr button_m_1;
	button_m_1 = gui.get<tgui::Button>("button_m_1");
	tgui::Button::Ptr button_m_2;
	button_m_2 = gui.get<tgui::Button>("button_m_2");
	tgui::Button::Ptr button_m_3;
	button_m_3 = gui.get<tgui::Button>("button_m_3");
	tgui::Button::Ptr button_m_4;
	button_m_4 = gui.get<tgui::Button>("button_m_4");
	tgui::Button::Ptr button_m_5;
	button_m_5 = gui.get<tgui::Button>("button_m_5");

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
	}

	menu->connect("MenuItemClicked", change_player, &player_choosen, &gm); // �������, ����� �������� ���������� ������ �� �������
	//����� �����, �� ����� ���� ������ ������������ �����. ��� ���������� ������ ������ ������������ ������
	////////////////////////

	//// ������� ������ � ������� ������� ///////
	std::vector<tgui::CheckBox::Ptr> player_buttons; //������ ���� ������
	std::vector<tgui::Label::Ptr> label_player_name_vector; //������ ���� ������� � ������� ������� (������� ������)

	for (auto p : gm->GetGameAgents()->GetAgents())
	{
		tgui::CheckBox::Ptr chbx = tgui::CheckBox::create();
		chbx->setSize(21, 21);
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

	//������ �������� ���������

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
		label_curr_player->setText(player_choosen);



		window.clear(sf::Color(230, 230, 230));
		gui.draw(); // Draw all widgets
		window.display();
	}
}