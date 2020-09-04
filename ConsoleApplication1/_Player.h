#pragma once
#include <string>

class _Player
{
private:
	string _name;
	int _step = 0;
public:
	string getName();
	void inputName();
	void setName(string);
	int getStep();
	void increaseStep();
	void setStep(int );
};

string _Player::getName()
{
	return _name;
}

void _Player::inputName()
{
	getline(cin, _name);
}

void _Player::increaseStep()
{
	_step++;
}

int _Player::getStep()
{
	return _step;
}

void _Player::setStep(int step )
{
	_step = step;
}

void _Player::setName(string name1)
{
	_name = name1;
}