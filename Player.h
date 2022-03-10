#pragma once
#include<iostream>
#include<string>
#include<fstream>
#include<string.h>

using namespace std;
    class Player
    {
    private:
        string firstName;
        string secondName;
        int points;

    public:
    	Player();
    	Player(string  , string , int);
    	Player(const Player&);
    	Player & operator=(const Player &);
    	~Player();
    	void afis()const;
    	int getPo()const;
    	string getFina();
    	string getSena();
    	void fafis(ofstream &)const;
    	//seteri

    	void setPo(int);
    	void setFina(string );
	void setSena(string );
	
	

    };

