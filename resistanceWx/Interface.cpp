//#define SFML_NO_DEPRECATED_WARNINGS
#include <SFML/Graphics.hpp>
#include <TGUI/TGUI.hpp>
#include <vector>
#include <string>

#include <iostream>

void change_player(std::string* player_choosen, const sf::String& param) // �������, ����� �������� ���������� ������ �� �������
{
	(*player_choosen) = param.toAnsiString();
}

int main()
{
	sf::RenderWindow window{ {800, 600}, "Window" };
	tgui::Gui gui{ window };

	// ��� ����?)

	// ������ �������. ����� ������ ����� � ������������ � ���� �������. ����� ���� ������������� ������� �� 4 �� 10
	std::vector<std::string> players_vector;
	// ���������
	players_vector.push_back("Jhon");
	players_vector.push_back("Ivan");
	players_vector.push_back("Henry");
	players_vector.push_back("Dart Vaider");
	players_vector.push_back("Fred");
	players_vector.push_back("Ginny");
	players_vector.push_back("Peter");
	players_vector.push_back("Lisa");
	//players_vector.push_back("Molly");
	//players_vector.push_back("Gerald");

	std::string player_choosen = players_vector[0]; //������ ������ ���������� �� ������. �� ��������� �������.
	// ����� ����������

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

	for (auto p : players_vector)
	{
		menu->addMenu(p);
		menu->addMenuItem(p);//��������� ������� � ������� �������. �� ���� ������� ������� ������, ������� ��������� �������
	}

	menu->connect("MenuItemClicked", change_player, &player_choosen); // �������, ����� �������� ���������� ������ �� �������
	//����� �����, �� ����� ���� ������ ������������ �����. ��� ���������� ������ ������ ������������ ������
	////////////////////////

	//// ������� ������ � ������� ������� ///////
	std::vector<tgui::CheckBox::Ptr> player_buttons; //������ ���� ������
	std::vector<tgui::Label::Ptr> label_player_name_vector; //������ ���� ������� � ������� ������� (������� ������)

	for (auto p : players_vector)
	{
		tgui::CheckBox::Ptr chbx = tgui::CheckBox::create();
		chbx->setSize(21, 21);
		player_buttons.push_back(chbx);
		window_missions_panel->add(player_buttons[player_buttons.size() - 1]); //��������� �� �� ��������� ����

		tgui::Label::Ptr lbl = tgui::Label::create();
		lbl->setText(p); //����������� ���������� ����� ������� �������
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
		label_curr_player->setText(player_choosen);



		window.clear(sf::Color(230, 230, 230));
		gui.draw(); // Draw all widgets
		window.display();
	}
}