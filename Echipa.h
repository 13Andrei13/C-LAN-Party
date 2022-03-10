#pragma once
#include<iostream>
#include<string>
#include<fstream>
#include<string.h>

#include"Player.h"


using namespace std;
class Echipa{
private:
	string nume;
	int nr;
	Player * p;
	

public:

	Echipa* next;
	Echipa();
	~Echipa();
		//seteri
	
	void setPoe(Player *,int );
	void setNu(string );
	void setNr(int );
	void setPl(Player*);

	void setNe(Echipa*);
	void setNext();
	void setPr(Echipa*);

		//getere


	string getNu()const;
	int getNr()const;
	float getPoe(Player *,int );


	Player* getPl()const;
	Echipa* getNe()const;
	Echipa* getPr()const;

};