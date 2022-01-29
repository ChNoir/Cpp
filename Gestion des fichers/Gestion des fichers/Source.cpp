#include<iostream>
#include<fstream>
#include<string>

int main() {

	std::string name_1, name_2, name_3,linge;
	std::ifstream fichie_1, fichie_2,fichie_4;
	std::ofstream fichie_3;

	do {

		std::cout << "Postion du fichie 1 : ";
		std::cin >> name_1;
		std::cout << std::endl;
		std::cout << std::endl;
		fichie_1.open(name_1, std::ios::in);
		if (!fichie_1) { std::cout << "Erreur" << std::endl ; }
	} 
	while (!fichie_1);

	do {

		std::cout << "Position du fichie 2 : ";
		std::cin >> name_2;
		std::cout << std::endl;
		std::cout << std::endl;
		fichie_2.open(name_2, std::ios::in);
		if (!fichie_2) { std::cout << "Erreur" << std::endl; }

	} 	while (!fichie_2);

	do {

		std::cout << "nom du fichie 3 : ";
		std::cin >> name_3;
		std::cout << std::endl;
		std::cout << std::endl;
		fichie_3.open(name_3, std::ios::out | std::ios::app );
		if (!fichie_3) { std::cout << "Erreur" << std::endl; }

	} while (!fichie_3);
	
	
	while (std::getline(fichie_1,linge))
	{
		fichie_3 << linge << std::endl ;

	}

	while (std::getline(fichie_2, linge))
	{
		fichie_3 << linge << std::endl;

	}

	fichie_2.close();
	fichie_1.close();
	fichie_3.close();

	char lol  ;
	std::cout << "-----------" << std::endl;
	std::cin >> lol ;

	fichie_4.open(name_3, std::ios::in);

	int n_linge = 0;
	while (std::getline(fichie_4, linge))
	{
		n_linge++;
		std::cout << linge << std::endl;

	}

	fichie_4.close();

	char tmap;
	int n_voyelle = 0 ;
	fichie_4.open(name_3, std::ios::in);
	while (fichie_4.get(tmap))
	{
		if (tmap == 'a' || tmap == 'e' || tmap == 'i' || tmap == 'o' || tmap == 'u' || tmap == 'y') { n_voyelle++; }

	}

	

	std::cout << std::endl << "n_ling    : " << n_linge;
	std::cout << std::endl << "n_voyelle : " << n_voyelle;

}