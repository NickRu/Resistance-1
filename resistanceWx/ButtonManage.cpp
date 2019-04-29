#include "ButtonManage.h"

ButtonManage::ButtonManage()
{
}

ButtonManage::ButtonManage(Game * gmm)
{
	gm = gmm;
}

ButtonManage::~ButtonManage()
{
}

void ButtonManage::FillButtons(tgui::Gui* gui, sf::RenderWindow* window)
{
	agent_choosen = gm->GetGameAgents()->GetAgents()[0]; //Какого игрока отображать на экране. По умолчанию первого.

	////Загружаем основной интерфейс из файла, после инициализируем все нужные виджеты
	gui->loadWidgetsFromFile("interface.txt");

	//tgui::Label::Ptr label_curr_player;
	label_curr_player = gui->get<tgui::Label>("label_curr_player");
	label_curr_player->setPosition(window->getSize().x * 0.5 - 0.3 * label_curr_player->getSize().x, 25);


	buttons_r[0] = gui->get<tgui::Button>("button_r_1");
	buttons_r[1] = gui->get<tgui::Button>("button_r_2");
	buttons_r[2] = gui->get<tgui::Button>("button_r_3");
	buttons_r[3] = gui->get<tgui::Button>("button_r_4");
	buttons_r[4] = gui->get<tgui::Button>("button_r_5");
					  
	buttons_m[0] = gui->get<tgui::Button>("button_m_1");
	buttons_m[1] = gui->get<tgui::Button>("button_m_2");
	buttons_m[2] = gui->get<tgui::Button>("button_m_3");
	buttons_m[3] = gui->get<tgui::Button>("button_m_4");
	buttons_m[4] = gui->get<tgui::Button>("button_m_5");


	//tgui::ChildWindow::Ptr window_round;
	window_round = gui->get<tgui::ChildWindow>("window_round");
	//tgui::ChildWindow::Ptr window_missions_panel;
	window_missions_panel = gui->get<tgui::ChildWindow>("window_missions_panel");
	//tgui::ChildWindow::Ptr window_team;
	window_team = gui->get<tgui::ChildWindow>("window_team");
	//tgui::ChildWindow::Ptr window_work;
	window_work = gui->get<tgui::ChildWindow>("window_work");

	//tgui::RadioButton::Ptr rad_but_accept;
	rad_but_accept = gui->get<tgui::RadioButton>("rad_but_accept");
	rad_but_accept->connect("checked", &ButtonManage::create_mission, this, &(gm), &agent_choosen, true);

	//tgui::RadioButton::Ptr rad_but_refuse;
	rad_but_refuse = gui->get<tgui::RadioButton>("rad_but_refuse");
	rad_but_refuse->connect("checked", &ButtonManage::create_mission, this, &(gm), &agent_choosen, false);

	//tgui::RadioButton::Ptr rad_but_unknown_create;
	rad_but_unknown_create = gui->get<tgui::RadioButton>("rad_but_unknown_create");
	rad_but_unknown_create->setVisible(false);

	//tgui::RadioButton::Ptr rad_but_help;
	rad_but_help = gui->get<tgui::RadioButton>("rad_but_help");
	rad_but_help->connect("checked", &ButtonManage::exec_mission, this, &(gm), &agent_choosen, true);

	//tgui::RadioButton::Ptr rad_but_hinder;
	rad_but_hinder = gui->get<tgui::RadioButton>("rad_but_hinder");
	rad_but_hinder->connect("checked", &ButtonManage::exec_mission, this, &(gm), &agent_choosen, false);

	//tgui::RadioButton::Ptr rad_but_unknown_exec;
	rad_but_unknown_exec = gui->get<tgui::RadioButton>("rad_but_unknown_exec");
	rad_but_unknown_exec->setVisible(false);
	////////////////////////////



	//////////MENU///////////
	//// Выбор интерфейса от игрока зависит от кнопки в меню. Зададим по менюшке для каждого игрока. Менюшки будут лежать в массиве менюшек
	//tgui::MenuBar::Ptr menu = tgui::MenuBar::create();
	//gui->add(menu);
	//menu->addMenu("Players");

	//for (auto p : gm->GetGameAgents()->GetAgents())
	//{
	//	menu->addMenuItem(p->GetPlayer().GetFirstName());//Добавляем менюшку с именами игроков. На саму менюшку кликать нельзя, поэтому добавляем подменю
	//	menu->connectMenuItem("Players", p->GetPlayer().GetFirstName(), &ButtonManage::change_player, this, &agent_choosen, p, &gui);
	//}

	//Далее знаем, от чьего лица сейчас показывается экран. Имя выбранного игрока должно показываться сверху
////////////////////////

//// Добавим кнопки с именами игроков ///////
	//std::vector<tgui::CheckBox::Ptr> player_buttons; //Вектор всех кнопок
	//std::vector<tgui::Label::Ptr> label_player_name_vector; //Вектор всех ярлыков с именами игроков (Подписи кнопок)

	for (auto p : gm->GetGameAgents()->GetAgents())
	{
		tgui::CheckBox::Ptr chbx = tgui::CheckBox::create();
		chbx->setSize(21, 21);
		chbx->connect("checked", &ButtonManage::checkPlayer, this, &(gm), p->GetPlayer().GetNickName());
		chbx->connect("unchecked", &ButtonManage::uncheckPlayer, this, &(gm), p->GetPlayer().GetNickName());
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

}

void ButtonManage::ChangeRoundButton(int i, MissionResult res)
{
	switch (res)
	{
	case MissionResult::UnknownRes:
		buttons_r[i]->setText("Round " + std::to_string(i + 1) + " unk");
		buttons_r[i]->getRenderer()->setBackgroundColor(sf::Color(230, 230, 230));
		break;
	case MissionResult::VoteUp:
		buttons_r[i]->setText("Round " + std::to_string(i + 1) + " up");
		buttons_r[i]->getRenderer()->setBackgroundColor(sf::Color::Cyan);
		break;
	case MissionResult::VoteDown:
		buttons_r[i]->setText("Round " + std::to_string(i + 1) + " dw");
		buttons_r[i]->getRenderer()->setBackgroundColor(sf::Color::Magenta);
		break;
	case MissionResult::Executed:
		buttons_r[i]->setText("Round " + std::to_string(i + 1) + " ex");
		buttons_r[i]->getRenderer()->setBackgroundColor(sf::Color::Blue);
		break;
	case MissionResult::Failed:
		buttons_r[i]->setText("Round " + std::to_string(i + 1) + " fl");
		buttons_r[i]->getRenderer()->setBackgroundColor(sf::Color::Red);
		break;
	default:
		break;
	}
}

void ButtonManage::ChangeMissionButton(int j, MissionResult res)
{
	switch (res)
	{
	case MissionResult::UnknownRes:
		buttons_m[j]->setText("Mission " + std::to_string(j + 1) + " unk");
		buttons_m[j]->getRenderer()->setBackgroundColor(sf::Color(230, 230, 230));
		break;
	case MissionResult::VoteUp:
		buttons_m[j]->setText("Mission " + std::to_string(j + 1) + " up");
		buttons_m[j]->getRenderer()->setBackgroundColor(sf::Color::Cyan);
		break;
	case MissionResult::VoteDown:
		buttons_m[j]->setText("Mission " + std::to_string(j + 1) + " dw");
		buttons_m[j]->getRenderer()->setBackgroundColor(sf::Color::Magenta);
		break;
	case MissionResult::Executed:
		buttons_m[j]->setText("Mission " + std::to_string(j + 1) + " ex");
		buttons_m[j]->getRenderer()->setBackgroundColor(sf::Color::Blue);
		break;
	case MissionResult::Failed:
		buttons_m[j]->setText("Mission " + std::to_string(j + 1) + " fl");
		buttons_m[j]->getRenderer()->setBackgroundColor(sf::Color::Red);
		break;
	default:
		break;
	}

}

void ButtonManage::ChangeVisualElements()
{

	////Интерфейс////
	if (agent_choosen->GetIsLider()) //Выбранному в интерфейсе Лидеру корону
		label_curr_player->setText(agent_choosen->GetPlayer().GetFirstName() + "[^^^]");
	else
		label_curr_player->setText(agent_choosen->GetPlayer().GetFirstName());
	////////////////


	////Основной алгоритм////
	for (int i = 0; i < gm->GetGameRounds().size(); i++) //Блокируем кнопки неактивных раундов
	{
		if (gm->GetGameRounds()[i]->GetIsActiveRound())
		{
			for (int j = 0; j < gm->GetGameRounds()[i]->GetPropMission().size(); j++) //Блокируем кнопки неактивных миссий
			{
				ChangeMissionButton(j, gm->GetGameRounds()[i]->GetPropMission()[j]->GetMissionResult());
			}
		}
		ChangeRoundButton(i, gm->GetGameRounds()[i]->GetResult());
	}


	if (agent_choosen->GetIsLider())
	{
		for (int i = 0; i < player_buttons.size(); i++)
		{
			player_buttons[i]->setEnabled(true);
		}

		if (gm->GetCurrentGameRound()->GetCommandSize() == gm->GetCurrentGameRound()->GetCurrentPropMission()->GetMissionCommand()->NumberofSelected())
		{
			for (int i = 0; i < player_buttons.size(); i++)
			{
				if (!player_buttons[i]->isChecked())
					player_buttons[i]->setEnabled(false);
			}
		}
		else if (gm->GetCurrentGameRound()->GetCommandSize() > gm->GetCurrentGameRound()->GetCurrentPropMission()->GetMissionCommand()->NumberofSelected())
		{
			for (int i = 0; i < player_buttons.size(); i++)
			{
				player_buttons[i]->setEnabled(true);
			}
		}
	}
	else
	{
		for (int i = 0; i < player_buttons.size(); i++)
		{
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

	if (gm->GetCurrentGameRound()->GetCurrentPropMission()->ResultofVotesforCreation() == VoteforCreation::Create)
	{
		if (gm->GetCurrentGameRound()->GetCurrentPropMission()->GetMissionCommand()->CheckAgentforSelect(*agent_choosen))
		{
			rad_but_help->setEnabled(true);
			rad_but_hinder->setEnabled(true);
		}
		else
		{
			rad_but_help->setEnabled(false);
			rad_but_hinder->setEnabled(false);
		}
	}
	else
	{
		rad_but_help->setEnabled(false);
		rad_but_hinder->setEnabled(false);
	}

}

void ButtonManage::ChangePlayer(Agent* i) // Команда, чтобы поменять выбранного игрока по нажатию
{
	agent_choosen = i;

	rad_but_accept->setChecked(false);
	rad_but_refuse->setChecked(false);
	rad_but_unknown_create->setChecked(false);
	rad_but_help->setChecked(false);
	rad_but_hinder->setChecked(false);
	rad_but_unknown_exec->setChecked(false);
}

void ButtonManage::create_mission(Game** gm, Agent** agent_choosen, bool b) // Команда, чтобы поменять выбранного игрока по нажатию
{
	(*gm)->GetCurrentGameRound()->GetCurrentPropMission()->CreationVote(b, ** agent_choosen);
}

void ButtonManage::exec_mission(Game** gm, Agent** agent_choosen, bool b) // Команда, чтобы поменять выбранного игрока по нажатию
{
	(*gm)->GetCurrentGameRound()->GetCurrentPropMission()->ExecutionVote(b, ** agent_choosen);
}

void ButtonManage::checkPlayer(Game** gm, std::string nickN) // Команда, чтобы поменять выбранного игрока по нажатию
{
	for (int k = 0; k < (*gm)->GetCurrentGameRound()->GetCurrentPropMission()->GetMissionCommand()->GetCommand().size(); k++) //Блокируем кнопки неактивных миссий
	{
		AgentInMission* aim = ((*gm)->GetCurrentGameRound()->GetCurrentPropMission()->GetMissionCommand()->GetCommand()[k]);
		if (nickN == aim->GetAgent().GetPlayer().GetNickName())
			aim->SetIsSelected(true);
	}
}

void ButtonManage::uncheckPlayer(Game** gm, std::string nickN) // Команда, чтобы поменять выбранного игрока по нажатию
{
	for (int k = 0; k < (*gm)->GetCurrentGameRound()->GetCurrentPropMission()->GetMissionCommand()->GetCommand().size(); k++) //Блокируем кнопки неактивных миссий
	{
		AgentInMission* aim = (*gm)->GetCurrentGameRound()->GetCurrentPropMission()->GetMissionCommand()->GetCommand()[k];
		if (nickN == aim->GetAgent().GetPlayer().GetNickName())
			aim->SetIsSelected(false);
	}
}

