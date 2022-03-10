#pragma once
#include<iostream>
#include<string>
#include<fstream>
#include<string.h>
#include<math.h>
#include"Meciuri.h"
#include"Stiva.h"
#include"BST.h"
using namespace std;

int main(int argc , char** argv)
{	//1

	int k=0,i=1,q=1;
	int t[5];
	ifstream fi1(argv[1]);
	ifstream fi(argv[2]);
	ofstream fo(argv[3]);

	ListaEchipe le(fi);

	for(i=0;i<5;i++)
		fi1>>t[i];
		


	if(t[0]==1 && t[1]==0)
	{
		le.fafisf(fo,le.getE());
	}
	else if(t[1]==1&&t[0]==1)
	{
		k=le.getNr();
	
		while(q<=k)
		{
			q=q*2;
		}
		q=q/2;
		
		for(int j=0;j<k-q;j++)
			{ 
				le.getMin(le.getE());
			}
		le.fafisf(fo,le.getE());
		
	}
	BST* tree = new BST();

	if(t[2]==1)
	{
		fo << endl;
		int round = 1;
		
		Meciuri *matches = new Meciuri(le.getE(),0);

		int r=q;
		
		while( r> 1)
		{
			fo << "--- ROUND NO:" << round << endl;
			matches->fafisf(fo);
			fo << endl;

			Stiva* s = new Stiva(matches, 0);
			
			
			fo << "WINNERS OF ROUND NO:" << round << endl;
			
			
			s->fafisf(fo);
			
				

			if(r != 2)
				fo << endl;
			
			if(s->get()->next!=NULL) {
				matches = new Meciuri(s->get());
				if(r == 16)
				{
					Echipa* aux = s->get();
					while(aux != nullptr)
					{
						tree->insert(aux->getPoe(aux->getPl(), aux->getNr()), aux->getNu());
						aux = aux->next;
					}
				}
			}

			delete s;
			r=r/2; 
			round++;
		}
	}

	if(t[3] == 1 && t[4] == 0)
	{
		fo << endl;
		fo << "TOP 8 TEAMS:" << endl;
		tree->display(fo);
	}
	
	
	fi1.close();
	fi.close();
	fo.close();
	
	return 0;
}