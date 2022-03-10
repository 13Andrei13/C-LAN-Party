#pragma once
#include<iostream>
#include<string>
#include<fstream>
#include<string.h>
#include"Player.h"



using namespace std;

Player::Player()
{

	firstName;
	secondName;
	points =0;
}
Player::Player(string fi, string se, int po)
{
	firstName=fi;
	secondName=se;
	points=po;
}

int Player::getPo()const
{
	return points;
}
string Player::getFina()
{
    return firstName;
}
string Player::getSena()
{
	return secondName;
}
void Player::fafis(ofstream & date) const
{
	date<<firstName<<" ";
	date<<secondName<<" ";
	date<<points;
}
Player::~Player()
{
	firstName="";
	secondName="";
	points=0;
}

void Player::setPo(int i)
{
    points=i;
}
void Player::setFina(string s)
{
 firstName=s;
}
void Player::setSena(string s)
{
  secondName=s;
}
Player & Player::operator=(const Player & p)
{
	firstName= p.firstName;
	secondName= p.secondName;
	points = p.points;

	return *this;
}