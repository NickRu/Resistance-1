#include "Player.h"

Player::Player(string first, string sec, string nick, int rate, int age)
{
	_firstName = first;
	_secondName = sec;
	_nickName = nick;
	_rating = rate;
	_age = age;
	CoCreateGuid(&_id);
}

Player::Player()
{

}

Player::~Player()
{
}

string Player::GetNickName()
{
	return _nickName;
}

string Player::GetFirstName()
{
	return _firstName;
}
GUID Player::GetID()
{
	return _id;
}
//гетеры-сетеры

