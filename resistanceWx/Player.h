#include <string>
#include <Windows.h>

using namespace std;

#pragma once
class Player
{
private:
	string _secondName;
	string _nickName;
	string _firstName;
	GUID _id;
	int _rating;
	int _age;
public:
	Player();
	Player(string first, string sec, string nick, int rate, int age);
	~Player();
	string GetNickName();
	string GetFirstName();
};

