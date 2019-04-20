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

void change_player(Agent** agent_choosen, Agent* i) // Команда, чтобы поменять выбранного игрока по нажатию
{
	(*agent_choosen) = i;
}

void checkPlayer(Game** gm, std::string nickN) // Команда, чтобы поменять выбранного игрока по нажатию
{
	for (int k = 0; k < (*gm)->GetCurrentGameRound()->GetCurrentPropMission()->GetMissionCommand()->GetCommand().size(); k++) //Блокируем кнопки неактивных миссий
	{
		AgentInMission aim = (*gm)->GetCurrentGameRound()->GetCurrentPropMission()->GetMissionCommand()->GetCommand()[k];
		if (nickN == aim.GetAgent().GetPlayer().GetNickName())
			aim.SetIsSelected(true);
	}
}

void uncheckPlayer(Game** gm, std::string nickN) // Команда, чтобы поменять выбранного игрока по нажатию
{
	for (int k = 0; k < (*gm)->GetCurrentGameRound()->GetCurrentPropMission()->GetMissionCommand()->GetCommand().size(); k++) //Блокируем кнопки неактивных миссий
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
	char sec0[] = "Ф";
	char code0[] = "Jhon";
	int rate0 = 100;
	int age0 = 48;
	Player* pl0 = new Player(first0, sec0, code0, rate0, age0);
	gm->GetGameAgents()->RegistryAgent(pl0);

	char first1[] = "Oleg";
	char sec1[] = "Ф";
	char code1[] = "Ivan";
	int rate1 = 100;
	int age1 = 45;
	Player* pl1 = new Player(first1, sec1, code1, rate1, age1);
	gm->GetGameAgents()->RegistryAgent(pl1);

	char first2[] = "Masha";
	char sec2[] = "Ф";
	char code2[] = "Henry";
	int rate2 = 100;
	int age2 = 18;
	Player* pl2 = new Player(first2, sec2, code2, rate2, age2);
	gm->GetGameAgents()->RegistryAgent(pl2);


	char first3[] = "Anna";
	char sec3[] = "Ф";
	char code3[] = "Fred";
	int rate3 = 100;
	int age3 = 15;
	Player* pl3 = new Player(first3, sec3, code3, rate3, age3);
	gm->GetGameAgents()->RegistryAgent(pl3);
	if (!gm->CanStartGame())
		cout << "Игроков недостаточно\n";
	else
		cout << "Игроков достаточно\n";

	char first4[] = "Anastasia";
	char sec4[] = "Ф";
	char code4[] = "Dart Vaider";
	int rate4 = 100;
	int age4 = 65;
	Player* pl4 = new Player(first4, sec4, code4, rate4, age4);
	gm->GetGameAgents()->RegistryAgent(pl4);

	char first5[] = "Rita";
	char sec5[] = "Ф";
	char code5[] = "Ginny";
	int rate5 = 100;
	int age5 = 18;
	Player* pl5 = new Player(first5, sec5, code5, rate5, age5);
	gm->GetGameAgents()->RegistryAgent(pl5);

	char first6[] = "Slava";
	char sec6[] = "Ф";
	char code6[] = "Peter";
	int rate6 = 100;
	int age6 = 18;
	Player* pl6 = new Player(first6, sec6, code6, rate6, age6);
	gm->GetGameAgents()->RegistryAgent(pl6);

	char first7[] = "Nastya";
	char sec7[] = "Ф";
	char code7[] = "Lisa";
	int rate7 = 100;
	int age7 = 18;
	Player* pl7 = new Player(first7, sec7, code7, rate7, age7);
	gm->GetGameAgents()->RegistryAgent(pl7);

	gm->ExecuteStart();
	sf::RenderWindow window{ {800, 600}, "Window" };
	tgui::Gui gui{ window };

	Agent *agent_choosen = gm->GetGameAgents()->GetAgents()[0]; //Какого игрока отображать на экране. По умолчанию первого.

	////Загружаем основной интерфейс из файла, после инициализируем все нужные виджеты
	gui.loadWidgetsFromFile("interface.txt");

	tgui::Label::Ptr label_curr_player;
	label_curr_player = gui.get<tgui::Label>("label_curr_player");
	label_curr_player->setPosition(window.getSize().x * 0.5 - 0.3 * label_curr_player->getSize().x, 25);

	tgui::Button::Ptr buttons_r[5]; // массив кнопок раундов. Для того, чтобы проходить по циклу
	buttons_r[0] = gui.get<tgui::Button>("button_r_1");
	buttons_r[1] = gui.get<tgui::Button>("button_r_2");
	buttons_r[2] = gui.get<tgui::Button>("button_r_3");
	buttons_r[3] = gui.get<tgui::Button>("button_r_4");
	buttons_r[4] = gui.get<tgui::Button>("button_r_5");

	tgui::Button::Ptr buttons_m[5]; // массив кнопок миссий. Для того, чтобы проходить по циклу
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
	// Выбор интерфейса от игрока зависит от кнопки в меню. Зададим по менюшке для каждого игрока. Менюшки будут лежать в массиве менюшек
	tgui::MenuBar::Ptr menu = tgui::MenuBar::create();
	gui.add(menu);

	for (auto p : gm->GetGameAgents()->GetAgents())
	{
		menu->addMenu(p->GetPlayer().GetFirstName());
		menu->addMenuItem(p->GetPlayer().GetFirstName());//Добавляем менюшку с именами игроков. На саму менюшку кликать нельзя, поэтому добавляем подменю
		menu->connectMenuItem(p->GetPlayer().GetFirstName(), p->GetPlayer().GetFirstName(), change_player, &agent_choosen, p);
	}

	//Далее знаем, от чьего лица сейчас показывается экран. Имя выбранного игрока должно показываться сверху
	////////////////////////

	//// Добавим кнопки с именами игроков ///////
	std::vector<tgui::CheckBox::Ptr> player_buttons; //Вектор всех кнопок
	std::vector<tgui::Label::Ptr> label_player_name_vector; //Вектор всех ярлыков с именами игроков (Подписи кнопок)

	for (auto p : gm->GetGameAgents()->GetAgents())
	{
		tgui::CheckBox::Ptr chbx = tgui::CheckBox::create();
		chbx->setSize(21, 21);
		chbx->connect("checked", checkPlayer, &(gm), p->GetPlayer().GetNickName());
		chbx->connect("unchecked", uncheckPlayer, &(gm), p->GetPlayer().GetNickName());
		player_buttons.push_back(chbx);
		window_missions_panel->add(player_buttons[player_buttons.size() - 1]); //Добавляем всё во внутренне окно

		tgui::Label::Ptr lbl = tgui::Label::create();
		lbl->setText(p->GetPlayer().GetNickName()); //Присваиваем поочередно имена игроков ярлыкам
		label_player_name_vector.push_back(lbl);
		window_missions_panel->add(label_player_name_vector[label_player_name_vector.size() - 1]);
	}

	float delta = 0.9 * window_missions_panel->getSize().x / (player_buttons.size() + 0.3); //Расстояние между кнопками
	int k = 1;

	for (auto p : player_buttons) // Расстявляем кнопки в окошке
	{
		p->setPosition(k * delta - p->getSize().x / 2, window_missions_panel->getSize().y * 0.15);
		k++;
	}

	k = 1;

	for (auto p : label_player_name_vector) // Расстявляем кнопки в окошке
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

		////Основной алгоритм////

		////Интерфейс////
		if (agent_choosen->GetIsLider()) //Выбранному в интерфейсе Лидеру корону
			label_curr_player->setText(agent_choosen->GetPlayer().GetFirstName() + "[^^^]");
		else
			label_curr_player->setText(agent_choosen->GetPlayer().GetFirstName());
		////////////////

		////Основной алгоритм////
		for (int i = 0; i < gm->GetGameRounds().size(); i++) //Блокируем кнопки неактивных раундов
		{
			for (int j = 0; j < gm->GetGameRounds()[i]->GetPropMission().size(); j++) //Блокируем кнопки неактивных миссий
			{
				buttons_m[j]->setEnabled(gm->GetGameRounds()[i]->GetPropMission()[j]->GetIsActiveMission());
			}
			buttons_r[i]->setEnabled(gm->GetGameRounds()[i]->GetIsActiveRound());
		}

		for (int i = 0; i < player_buttons.size(); i++)
		{
			player_buttons[i]->setEnabled(agent_choosen->GetIsLider());
			//sf::String nickN = label_player_name_vector[i]->getText();
			//for (int k = 0; k < gm->GetCurrentGameRound()->GetCurrentPropMission()->GetMissionCommand()->GetCommand().size(); k++) //Блокируем кнопки неактивных миссий
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