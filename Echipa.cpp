   #pragma once
#include<iostream>
#include<string>
#include<fstream>
#include<string.h>
#include"Echipa.h"



using namespace std;


Echipa::Echipa()
{
		nume="";
		nr =0;

		this->p=new Player;
		this->next=NULL;
		


}
string Echipa::getNu()const
{
	return nume;
}
	int Echipa::getNr()const
	{
		return nr;
	}
	Player* Echipa::getPl()const
	{
		return p;
	}
	Echipa* Echipa::getNe()const
	{
		return next;
	}
	
	void Echipa::setNext()
	{
		next=NULL;
	}

void Echipa::setNu(string  s)
{
		nume=s;
}
	void Echipa::setNr(int  n)
	{
		nr=n;
	}
	void Echipa::setPl(Player* v)
	{
		p=v;

	}

	void Echipa::setNe(Echipa* v)
	{
		next=v;
	}
	



Echipa::~Echipa()
{

		delete [] p;
		delete next;

}
float Echipa::getPoe(Player * p,int nr)
{
	int i;
	float m=0;
	for(i=0;i<nr;i++)
		m=m+p[i].getPo();

	return float(m/nr);


}
void Echipa::setPoe(Player * p,int nr)
{
	int i;
	
	for(i=0;i<nr;i++)
		p[i].setPo(p[i].getPo()+1);

	


}