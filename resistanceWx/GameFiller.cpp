#include "GameFiller.h"
#include "GameAgents.h"

GameFiller::GameFiller()
{
}

GameFiller::GameFiller(Game * gmm)
{
	gm = gmm;
}

GameFiller::~GameFiller()
{
}

void GameFiller::Fill()
{

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

	//if (!gm->CanStartGame())
	//	cout << "Игроков недостаточно\n";
	//else
	//	cout << "Игроков достаточно\n";

	char first4[] = "Anastasia";
	char sec4[] = "Ф";
	char code4[] = "Dart Vaider";
	int rate4 = 100;
	int age4 = 65;
	Player* pl4 = new Player(first4, sec4, code4, rate4, age4);
	gm->GetGameAgents()->RegistryAgent(pl4);

	//char first5[] = "Rita";
	//char sec5[] = "Ф";
	//char code5[] = "Ginny";
	//int rate5 = 100;
	//int age5 = 18;
	//Player* pl5 = new Player(first5, sec5, code5, rate5, age5);
	//gm->GetGameAgents()->RegistryAgent(pl5);

	//char first6[] = "Slava";
	//char sec6[] = "Ф";
	//char code6[] = "Peter";
	//int rate6 = 100;
	//int age6 = 18;
	//Player* pl6 = new Player(first6, sec6, code6, rate6, age6);
	//gm->GetGameAgents()->RegistryAgent(pl6);

	//char first7[] = "Nastya";
	//char sec7[] = "Ф";
	//char code7[] = "Lisa";
	//int rate7 = 100;
	//int age7 = 18;
	//Player* pl7 = new Player(first7, sec7, code7, rate7, age7);
	//gm->GetGameAgents()->RegistryAgent(pl7);

}
