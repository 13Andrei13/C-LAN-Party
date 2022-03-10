#pragma once
#include<iostream>
#include<string>
#include<fstream>
#include<string.h>

class Stiva;

#include"Meciuri.h"
using namespace std;

class Stiva {
private:
	Echipa* e = NULL;

	Stiva* next;

public:
	Stiva() { this->e = nullptr; this->next = nullptr; }
	Stiva(Meciuri*,int);
	~Stiva();

	void add_position(int pos,Echipa* n);
	void clear();
	void push(Echipa*);
	Echipa * get(){return e ;}
	void set(Echipa* s) { this->e = s; }
	Stiva* getNext(){return next;}
	void fafis(ofstream&);
	void fafisf(ofstream&);

	
};