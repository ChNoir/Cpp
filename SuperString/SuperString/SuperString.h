#pragma once
#include <iostream>
#include <cstdio>
#define MAX 1000

class SuperString
{
public:

	char display();
	void saisir();
	int size();

	//////////////////////

	SuperString operator = ( SuperString SuperS ) {

	}

	///////////////////////
	SuperString();
	SuperString(char* SuperS);
	~SuperString();
	
private :

	char* tab;

};

