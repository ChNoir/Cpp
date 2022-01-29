#include "MyTheread.h"

MyTheread::MyTheread()
{
}



void MyTheread::Fun(int max)
{
	mu_compteur.lock();
	for (int i = 0; i < max; i++) {
	 	compteur++;
	}
	mu_compteur.unlock();
}

std::mutex MyTheread::mu_compteur;
int MyTheread::compteur = 0;