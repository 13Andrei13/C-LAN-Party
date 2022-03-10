#pragma once
#include<iostream>
#include<string>
#include<fstream>
#include<string.h>
#include "ListaEchipe.h"

using namespace std;


ListaEchipe::ListaEchipe(ifstream & date)
{	

	/*while(!date.eof())
	{
		string s,fi,se;
		int n,po;
		int i;

		date>>nr;
		date>>n;

		getline(date,s);
		if(s.empty())
			return;

		s = s.substr(1, s.length() - 1);

		e=new Echipa();

		e->setNr(n);

		Player *aux=new Player[n];
		for(i=0;i<n;i++)
		{
			date>>fi;
			date>>se;
			date>>po;
			aux[i].setPo(po);
			aux[i].setFina(fi);
			aux[i].setSena(se);
		}
		e->setPl(aux);

		this->add_position(0, e);
	}*/


	string s,fi,se;
	int n,po;
	int i;


	date>>nr;
	date>>n;


	e=new Echipa();

	e->setNr(n);

	getline(date,s);

	
	s = s.substr(1, s.length() - 1);
	while(s[s.length()-1] == ' ')
		s = s.substr(0,s.length()-1);

	e->setNu(s);
	
	Player *aux=new Player[n];
	for(i=0;i<n;i++)
	{
		date>>fi;
		date>>se;
		date>>po;
		aux[i].setPo(po);
		aux[i].setFina(fi);
		aux[i].setSena(se);
		

	}

	e->setPl(aux);
	
	e->setNext();

	
	
	Echipa *temp=e;

	for(i=1;i<nr;i++)
	{
		
		

		Echipa *new_nod =new Echipa();
		date>>n;

		new_nod->setNr(n);

		getline(date,s);

		if(s.empty())
			break;

		
			s = s.substr(1, s.length() - 1);
		while(s[s.length()-1] == ' ')
			s = s.substr(0,s.length()-1);



		new_nod->setNu(s);
		
		Player *aux=new Player[n];

		for(int j=0;j<n;j++)
		{
			date>>fi;
			date>>se;
			date>>po;
			aux[j].setPo(po);
			aux[j].setFina(fi);
			aux[j].setSena(se);
			


		}

		new_nod->setPl(aux);


		this->add_position(0, new_nod);
		/*new_nod->setNext();

		temp->setNe(new_nod);
		temp=new_nod;
		*/

	}

}

void ListaEchipe::add_position(int pos,Echipa* n)
{
  Echipa *pre = new Echipa();
  Echipa *cur = new Echipa();
  Echipa *temp = new Echipa();
  
  if(pos==0)
  {
    temp->setNr(n->getNr());
    temp->setNu(n->getNu());
    temp->setPl(n->getPl());
    temp->next = this->getE();
    this->setE(temp);
  }
  else
  {
    cur=this->getE();
    for (int i = 0; i < pos ; i++)
    {
      pre = cur;
      cur = cur->next;
    }
    temp->setNr(n->getNr());
    temp->setNu(n->getNu());
    temp->setPl(n->getPl());
    temp->next = cur;
    pre->next = temp;
  }
  //this->nr++;
}

 void ListaEchipe::fafis(ofstream & date,Echipa *head )
{
	
	
	if(head->getNe()==nullptr)
	{
		date<<head->getNu()<< endl ;
		return;
	}
	fafis(date,head->getNe());

		date<<head->getNu()<<endl ;
	

}

void ListaEchipe::delete_position(int pos)
{
  Echipa *pre = new Echipa();
  Echipa *cur = new Echipa();
  cur = this->e;

  if(pos == 0)
  {
    pre = this->e;
    e = e->next;
  }
  else
  {
    for (int i = 0; i < pos; i++)
      {
	pre = cur;
	cur = cur->next;
      }
    pre->next = cur->next;
  }
  this->nr--;
}




void ListaEchipe::getMin(Echipa * head)
{/*
	float fMin = 9999999;
	Echipa* eMinIter = head;
	Echipa* aux = head;
	Echipa* headcopy =head;

	while(aux != nullptr)
	{
		if(aux->getPoe(aux->getPl(), aux->getNr()) <= fMin)
		{
			eMinIter = aux;
			fMin = aux->getPoe(aux->getPl(), aux->getNr());
		}
		aux = aux->getNe();
	}
	
	
	if(headcopy == eMinIter)
	{
		head = head->getNe();
		headcopy->setNext();
		delete headcopy;
		return ;
	}
	aux=head;
	while(aux != nullptr)
	{
		if(aux->getNe() == eMinIter)
		{
			aux->setNe(eMinIter->getNe());
			delete eMinIter; 
			return;
		}
		aux = aux->getNe();
		
	}
*/
	float min=999999;

	Echipa * headcopy=head;

	int i=0;
	int j=0;
	while(headcopy!=NULL)
	{
		if(headcopy->getPoe(headcopy->getPl() , headcopy->getNr()) < min )
			{	
				i=j;
				min=headcopy->getPoe(headcopy->getPl() , headcopy->getNr());
				
		
		}
		j++;
		headcopy = headcopy->getNe();
	}

	delete_position(i);
/*
	headcopy = this->getE();

	if(headcopy == desters)
	{
		
		headcopy = headcopy->getNe();
		return ;
	}

	Echipa * aux = head;
	while(aux->getNe() != NULL)
	{
		if(aux->getNe() == desters )
		{	
			Echipa* tmp = aux->getNe();
			aux->setNe(aux->getNe()->getNe());

			free(tmp);
			return;
			//headcopy = headcopy->getNe();

		}
		else
		{  
			aux = aux->getNe();
	
		
		}
	}
	*/
}

 void ListaEchipe::fafisf(ofstream & date , Echipa* head)
 {
 	while(head!=NULL)
 	{
 		date<<head->getNu()<<endl;
 		head=head->getNe();
 	}
 }
