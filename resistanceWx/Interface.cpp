#include <SFML/Graphics.hpp>
#include <TGUI/TGUI.hpp>
#include "ButtonManage.h"
#include "Game.h"
#include "GameAgents.h"
#include "GameFiller.h"

void change_player(ButtonManage* bm, Agent* i) // Команда, чтобы поменять выбранного игрока по нажатию
{
	bm->ChangePlayer(i);
}

int main()
{
	Game* gm = new Game();
	GameFiller gmf = GameFiller(gm);
	gmf.Fill();

	gm->ExecuteStart();
	sf::RenderWindow window{ {800, 600}, "Window" };
	tgui::Gui gui{ window };
	ButtonManage bm = ButtonManage(gm);
	bm.FillButtons(&gui, &window);

	tgui::MenuBar::Ptr menu = tgui::MenuBar::create();
	gui.add(menu);
	menu->addMenu("Players");
	for (auto p : gm->GetGameAgents()->GetAgents())
	{
		menu->addMenuItem(p->GetPlayer().GetFirstName());//Добавляем менюшку с именами игроков. На саму менюшку кликать нельзя, поэтому добавляем подменю
		menu->connectMenuItem("Players", p->GetPlayer().GetFirstName(), change_player, &bm, p);
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
		bm.ChangeVisualElements();
		window.clear(sf::Color(230, 230, 230));
		gui.draw(); // Draw all widgets
		window.display();
	}
}