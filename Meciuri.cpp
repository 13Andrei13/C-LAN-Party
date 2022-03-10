#pragma once
#include<iostream>
#include<string>
#include<fstream>
#include<iomanip>
#include<string.h>


#include"Meciuri.h"

using namespace std;
void Meciuri::setEc1(Echipa * e)
{
	a=e;
}
void Meciuri::setEc2(Echipa *e)
{
	b=e;
}
void Meciuri::setNex(Meciuri * m)
{
	next=m;
}
void Meciuri::setNex()
{
	next = NULL;
}

Meciuri::Meciuri()
{
	this->a = nullptr;
	this->b = nullptr;

	this->next = nullptr;
	this->prev = nullptr;
}

Meciuri::Meciuri(Echipa * e, int i)
{	
	if(e->getNe() == NULL)
		return;
	
	this->initType = 0;
	this->a = e;
	this->b = e->getNe();

	if(e->getNe()->getNe() != NULL)
		this->next = new Meciuri(e->getNe()->getNe(),0);
	
	
}


Meciuri::Meciuri(Stiva * s)
{	
	if(s->getNext() == NULL)
		return;

	if(s->getNext()->getNext() != NULL)
		this->next = new Meciuri(s->getNext()->getNext());

	this->b = s->get();
	this->a = s->getNext()->get();
	
	this->initType = 1;
	
}

Meciuri::Meciuri(Echipa * s)
{	

	this->a = s;
	this->b = s->next;


	if(s->next->next != NULL)
		this->next = new Meciuri(s->next->next);

	/*Stiva* aux = s;
	Meciuri* meci = this;
	while (aux != nullptr)
	{
		meci->setEc1(aux->get());
		meci->setEc2(aux->getNext()->get());
		meci->next = new Meciuri();

		meci = meci->next;
		aux = aux->getNext()->getNext();
	}*/
	
	
}

void Meciuri::pushMeci(Echipa *echipa1, Echipa *echipa2)
{
	this->a = echipa1;
	this->b = echipa2;
}

void Meciuri::popMeci()
{
	this->prev->next = nullptr;
}

 void Meciuri::fafis(ofstream & out )
{
	if(this->getNex()!=nullptr)
		this->next->fafis(out);
	out << this->a->getNu() << setw(34 - this->a->getNu().length()) << "-" << setw(35 - 2) <<this->b->getNu() << endl;
	
}

void Meciuri::fafisf(ofstream & out )
{
	Meciuri* aux = this;
	while(aux != nullptr)
	{
		out << aux->a->getNu() << setw(34 - aux->a->getNu().length()) << "-" << setw(35 - 2) <<aux->b->getNu() << endl;
		aux = aux->next;
	}
}
	

