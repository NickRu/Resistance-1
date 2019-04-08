#include <Windows.h>

#pragma once
class Player
{
private:
	char* _firstName;
	char* _secondName;
	char* _nickName;
	GUID _id;
	int _rating;
	int _age;
public:
	Player();
	Player(char* first, char* sec, char* nick, int rate, int age);
	~Player();
};

