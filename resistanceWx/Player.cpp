#include "Player.h"

Player::Player(char* first, char* sec, char* nick, int rate, int age)
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

//гетеры-сетеры

