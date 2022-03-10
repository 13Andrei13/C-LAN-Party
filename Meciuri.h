#pragma once
#include<iostream>
#include<string>
#include<fstream>
#include<string.h>

class Meciuri;

#include"ListaEchipe.h"
#include"Stiva.h"

using namespace std;
class Meciuri{

private:
	Echipa * a;
	Echipa *b;
	Meciuri *next, *prev;
	int initType;

public:

	Meciuri();
	Meciuri(Echipa *,int);
	Meciuri(Echipa*);
	Meciuri(Stiva*);
	//getere
	Echipa* getEc1(){return a;}
	Echipa* getEc2(){return b;}
	Meciuri* getNex(){ return next;}
	int getType() { return initType; }
	


	//setere
	void setEc1(Echipa *);
	void setEc2(Echipa *);
	void setNex(Meciuri *);
	void setNex();

	void pushMeci(Echipa *, Echipa *);
	void popMeci();
	void fafis(ofstream&);
	void fafisf(ofstream &  );
};