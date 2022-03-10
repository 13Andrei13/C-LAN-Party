#pragma once
#include<iostream>
#include<string>
#include<fstream>
#include<string.h>


#include"Echipa.h"

using namespace std;

class ListaEchipe{

private:
	Echipa * e;
	int nr;

public:

	
	 ListaEchipe(ifstream &);

	 void fafis(ofstream &, Echipa*);
	 void fafisf(ofstream &, Echipa*);
	 void delete_position(int );
	void add_position(int, Echipa*);

	

	//getere
	 Echipa* getE(){ return e;}
	 int getPoe();
	 int getNr(){return nr;}
	 void getMin(Echipa*);
	//setere
	void setE(Echipa *temp) { this->e = temp; }
	



};