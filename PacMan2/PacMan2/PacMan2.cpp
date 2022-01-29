// Lib externes
#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include <sstream>
#include <string>
#include <time.h>
#include <cstdlib>
#include <conio.h>
#include <Windows.h>


// Lib interne  
#include "../lib/termcolor.hpp" // couleur console
using namespace termcolor;
using namespace std;

// Variable globale 
int curseur_Y = 0;
int curseur_X = 0;
int curseur_Ymax = 39;
int Game_speed = 1;
const int Plateaux_Ymax = 37;
const int Plateaux_Xmax = 109;
int Plateaux[Plateaux_Ymax][Plateaux_Xmax][2]; // Y , X , Z 
int pac_bell = 0 ;

bool Random_Generation = true;




enum couleurs {

	DEFAULT = 0,
	RED = 1,
	GREEN = 2,
	YELLOW = 3,
	BLUE = 4,
	MAGENTA = 5,
	CYAN = 6,
	WHITE = 7
};

enum Key_presse {


	UP = 72,
	DOWN = 80,
	LEFT = 75,
	RIGHT = 77,
	ECHAP = 27,
	SPACE = 32,
	Z = 122,
	S = 115,
	Q = 113,
	D = 100,
	ENTRE = 13,

};

int cout_c(char text, int couleur, int on_couleur) {
	// text | couleur text | couleur background 

	// couleur du texte 
	switch (couleur) {

	case 1:
		cout << red;
		break;
	case 2:
		cout << green;
		break;
	case 3:
		cout << yellow;
		break;
	case 4:
		cout << blue;
		break;
	case 5:
		cout << magenta;
		break;
	case 6:
		cout << cyan;
		break;
	case 7:
		cout << white;
		break;

	default:
		break;

	}
	// couleur du background
	switch (on_couleur) {

	case 1:
		cout << on_red << text << reset;
		break;
	case 2:
		cout << on_green << text << reset;
		break;
	case 3:
		cout << on_yellow << text << reset;
		break;
	case 4:
		cout << on_blue << text << reset;
		break;
	case 5:
		cout << on_magenta << text << reset;
		break;
	case 6:
		cout << on_cyan << text << reset;
		break;
	case 7:
		cout << on_white << text << reset;
		break;

	default:
		cout << text << reset;
		break;

	}

	return 0;
}

int event_key() {

	int c = _getch();
	if (c == 224 || c == 0) {
		int b = _getch();
		return b;
	}
	else {
		return c;
	}

	/*

	if (_kbhit()) { }

	*/

}

int cooldown(float seconds)
{
	clock_t start = clock();
	clock_t period = seconds * CLOCKS_PER_SEC;
	clock_t elapsed;

	do {
		elapsed = clock() - start;
	} while (elapsed < period);
	return 0;
}

void curseurCoutString(string text) {
	// Require variable globale : curseur_X , curseur_Y

	cout << text;
	int x = text.length();

	COORD CRD;
	CRD.X = x + curseur_X;
	CRD.Y = curseur_Y;
	curseur_X += x;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), CRD);

}

void curseurCoutChar(char text) {
	// Require variable globale : curseur_X , curseur_Y

	cout << text;
	COORD CRD;
	CRD.X = 1 + curseur_X;
	CRD.Y = curseur_Y;
	curseur_X++;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), CRD);
}

void curseurCoutInt(int text) {
	// Require variable globale : curseur_X , curseur_Y

	cout << text;
	int x = to_string(text).length();

	COORD CRD;
	CRD.X = x + curseur_X;
	CRD.Y = curseur_Y;
	curseur_X += x;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), CRD);

}

void curseurDefault() {
	// Require variable globale : curseur_X , curseur_Y

	COORD CRD;
	CRD.X = 0;
	CRD.Y = 0;
	curseur_X = 0;
	curseur_Y = 0;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), CRD);
}

void curseurDefaultDown() {
	// Require variable globale : curseur_Xmax , curseur_Ymax

	COORD CRD;
	CRD.X = 0;
	CRD.Y = curseur_Ymax;

	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), CRD);
}

void curseurToMove(int x, int y) {
	// Require variable globale : curseur_X , curseur_Y

	COORD CRD;
	CRD.X = x;
	CRD.Y = y;
	curseur_X = x;
	curseur_Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), CRD);
}

void curseurMove(int x, int y) {
	// Require variable globale : curseur_X , curseur_Y

	COORD CRD;
	CRD.X = x + curseur_X;
	CRD.Y = y + curseur_Y;
	curseur_X += x;
	curseur_Y += y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), CRD);
}

void curseurMoveLin(int y) {
	// Require variable globale : curseur_X , curseur_Y

	COORD CRD;
	CRD.X = curseur_X;
	CRD.Y = y + curseur_Y;
	curseur_Y += y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), CRD);
}

void curseurMoveCol(int x) {
	// Require variable globale : curseur_X , curseur_Y

	COORD CRD;
	CRD.X = x + curseur_X;
	CRD.Y = curseur_Y;
	curseur_X += x;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), CRD);
}

void Menu() {

	int Y_0 = 10;
	int X_0 = 60;
	curseurToMove(X_0, Y_0);

	for (int i = 0; i < 20; i++) {
		cout << on_white << " " << reset;
		curseurMoveCol(1);

	}
	for (int i = 0; i < 15; i++) {
		cout << on_white << " " << reset;
		curseurMoveLin(1);

	}

	curseurToMove(X_0, Y_0);

	for (int i = 0; i < 15; i++) {
		cout << on_white << " " << reset;
		curseurMoveLin(1);

	}
	for (int i = 0; i < 21; i++) {
		cout << on_white << " " << reset;
		curseurMoveCol(1);

	}

	curseurToMove(X_0, Y_0);
	curseurMoveLin(2);
	curseurMoveCol(7);
	cout << "Pac Man";
	curseurMove(-4, 3);
	cout << "[X] Play";
	curseurMoveLin(2);
	cout << "[ ] Option";
	curseurMoveLin(2);
	cout << "[ ] Score board";
	curseurMoveLin(2);
	cout << "[ ] Exit";
	curseurDefaultDown();
	
	
}

void Menu_Option( int info) {

	int Y_0 = 10;
	int X_0 = 30;
	curseurToMove(X_0, Y_0);

	if (info == 0) {

		for (int i = 0; i < 81; i++) {
			cout << on_white << " " << reset;
			curseurMoveCol(1);

		}
		for (int i = 0; i < 15; i++) {
			cout << on_white << " " << reset;
			curseurMoveLin(1);

		}

		curseurToMove(X_0, Y_0);

		for (int i = 0; i < 15; i++) {
			cout << on_white << " " << reset;
			curseurMoveLin(1);

		}
		for (int i = 0; i < 82; i++) {
			cout << on_white << " " << reset;
			curseurMoveCol(1);

		}
		curseurToMove(X_0, Y_0);
		curseurMoveCol(40);

		for (int i = 0; i < 15; i++) {
			cout << on_white << " " << reset;
			curseurMoveLin(1);

		}

		curseurToMove(X_0, Y_0);
		curseurMoveLin(2);
		curseurMoveCol(7);
		cout << "Option :";
		curseurMove(-5, 3);
		cout << ">[";
		if (Random_Generation) {
			cout << "X";
		}
		else{
			cout << " ";
		}
		cout <<"] Generation aleatoire";
		curseurMove(1, 1);
		cout << "["<< Game_speed <<"] Speed Game";
		curseurMoveLin(1);
		cout << "    Exit";
	}
	
	if (info == 1) {
		curseurMove(42, 2);
		for (int i = 0; i < 13; i++) {
			for (int j = 0; j < 38; j++) {
				cout << " ";
			}
			curseurMoveLin(1);
		}
		curseurToMove(X_0, Y_0);
		curseurMove(42, 2);
		cout << "Activer pour generer une carte";
		curseurMoveLin(1);
		cout << "aleatoire";
	}
	if (info == 2) {
		curseurMove(42, 2);
		for (int i = 0; i < 13; i++) {
			for (int j = 0; j < 38; j++) {
				cout << " ";
			}
			curseurMoveLin(1);
		}
		curseurToMove(X_0, Y_0);
		curseurMove(42, 2);
		cout << "Vitesse de deplacement";
	}
	if (info == 3) {
		curseurMove(42, 2);
		for (int i = 0; i < 13; i++) {
			for (int j = 0; j < 38; j++) {
				cout << " ";
			}
			curseurMoveLin(1);
		}
	}


	curseurDefaultDown();
}

void Menu_Play() {

	curseurDefault();
	for (int i = 0; i < 149; i++) {
		cout << on_white << " " << reset;
	}
	for (int i = 0; i < 38; i++) {
		cout << on_white << " " << reset;
		curseurMoveLin(1);
	}
	for (int i = 0; i < 149; i++) {
		cout << on_white << " " << reset;
	}
	curseurToMove(110,0);
	for (int i = 0; i < 38; i++) {
		cout << on_white << " " << reset;
		curseurMoveLin(1);
	}
	curseurToMove(149, 0);
	for (int i = 0; i < 39; i++) {
		cout << on_white << " " << reset;
		curseurMoveLin(1);
	}
	curseurDefaultDown();
}

void init_Plateaux() {

	if (Random_Generation) {
		
		bool UnDeux = true;
		int buffer_1 = 1;
		for (int i = 0; i < Plateaux_Ymax; i++) {
			
			if (UnDeux) {
				for (int j = 0; j < Plateaux_Xmax; j++) {
					Plateaux[i][j][0] = 0;
				}
				UnDeux = false;
			}
			else {

				bool UnDeux_1 = true;
				for (int j = 0; j < Plateaux_Xmax; j++) {
					
					if (UnDeux_1) {
						Plateaux[i][j][0] = 0;
						UnDeux_1 = false;
					}
					else {
						Plateaux[i][j][0] = buffer_1;
						buffer_1++;
						UnDeux_1 = true;
					}
					
				}
				UnDeux = true;
			}
		}
		bool plateaux_build = true;

		while (plateaux_build)
		{
			
			


			int buffer_2;
			int buffer_3;

			int random_Y = rand() % (Plateaux_Ymax - 2) + 1;
			int random_X = rand() % (Plateaux_Xmax - 2) + 1;
			
			for (; (random_Y % 2) == (random_X % 2);) {
				random_Y = rand() % (Plateaux_Ymax - 2) + 1;
				random_X = rand() % (Plateaux_Xmax - 2) + 1;
			}

			if (Plateaux[random_Y][random_X][0] == 0) {
				

				if (random_Y % 2 == 1) {
					buffer_2 = Plateaux[random_Y][(random_X + 1)][0];
					buffer_3 = Plateaux[random_Y][(random_X - 1)][0];
				}
				else {
					buffer_2 = Plateaux[(random_Y + 1)][random_X][0];
					buffer_3 = Plateaux[(random_Y - 1)][random_X][0];
				}

				if (buffer_2 != buffer_3) {

					Plateaux[random_Y][random_X][0] = 1;

					if (buffer_2 < buffer_3) {
						for (int i = 1; i < Plateaux_Ymax; i += 2) {
							for (int j = 1; j < Plateaux_Xmax; j += 2) {
								if (Plateaux[i][j][0] == buffer_3) {
									Plateaux[i][j][0] = buffer_2;
								}
							}
						}
						
					}
					else {
						for (int i = 1; i < Plateaux_Ymax; i += 2) {
							for (int j = 1; j < Plateaux_Xmax; j += 2) {
								if (Plateaux[i][j][0] == buffer_2) {
									Plateaux[i][j][0] = buffer_3;
								}
							}
						}

					}


					int buffer_4 = 1;

					for (int i = 1; i < Plateaux_Ymax; i += 2) {
						for (int j = 1; j < Plateaux_Xmax; j += 2) {
							if (Plateaux[i][j][0] > 1) {
								buffer_4 = Plateaux[i][j][0];
							}
						}
					}
					if (buffer_4 == 1) {
						plateaux_build = false;
					}


				}

			}

		}

		// braek les mur

		for (int i = 0; i < 100; i++) {


			int random_Y = rand() % (Plateaux_Ymax - 2) + 1;
			int random_X = rand() % (Plateaux_Xmax - 2) + 1;
			int good;
			
			
			while (true) {
				good = 0;
				
				random_Y = rand() % (Plateaux_Ymax - 2) + 1;
				random_X = rand() % (Plateaux_Xmax - 2) + 1;

				if (Plateaux[random_Y][random_X][0] == 0) {
					if ( (Plateaux[random_Y][(random_X + 1)][0] == 1) ) {
						good++;
					}
					if (Plateaux[random_Y][(random_X - 1)][0] == 1) {
						good++;
					}
					if (Plateaux[(random_Y + 1)][random_X][0] == 1) {
						good++;
					}
					if (Plateaux[(random_Y - 1)][random_X][0] == 1) {
						good++;
					}
					
					if (good == 2) { 
						break; 
					}

				}
			} 
			
			Plateaux[random_Y][random_X][0] = 1;
			
		}

		for (int Y = 0; Y < Plateaux_Ymax; Y++ ) {
			for (int X = 0; X < Plateaux_Xmax; X++) {
				if (Plateaux[Y][X][0] == 1) {
					Plateaux[Y][X][1] = 250;
					pac_bell++;
					
				}
				else
				{
					if (Y == 0 && X == 0) {
						Plateaux[Y][X][1] = 218;
					}
					else if (Y == (Plateaux_Ymax - 1) && X == 0) {
						Plateaux[Y][X][1] = 192;
					}
					else if (Y == 0 && X == (Plateaux_Xmax - 1)) {
						Plateaux[Y][X][1] = 191;
					}
					else if (Y == (Plateaux_Ymax - 1) && X == (Plateaux_Xmax - 1)) {
						Plateaux[Y][X][1] = 217;
					}

					if ( (( Y == 0 ) && ( X >= 1 )) && ( X < (Plateaux_Xmax - 1 )) ) {
						if (Plateaux[(Y + 1)][X][0] == 0) {
							Plateaux[Y][X][1] = 194;
						}
						else
						{
							Plateaux[Y][X][1] = 196;
						}

					}
					if ( ((Y == (Plateaux_Ymax - 1)) && (X >= 1)) && (X < (Plateaux_Xmax - 1)) ) {
						if (Plateaux[(Y - 1)][X][0] == 0) {
							Plateaux[Y][X][1] = 193;
						}
						else
						{
							Plateaux[Y][X][1] = 196;
						}

					}
					if ( ((X == 0) && (Y >= 1)) && (Y < (Plateaux_Ymax - 1)) ) {
						if (Plateaux[Y][(X + 1)][0] == 0) {
							Plateaux[Y][X][1] = 195;
						}
						else
						{
							Plateaux[Y][X][1] = 179;
						}
					}
					if ( (( X == (Plateaux_Xmax - 1)) && (Y >= 1)) && ( Y < (Plateaux_Ymax - 1)) ) {
						if (Plateaux[Y][(X - 1)][0] == 0) {
							Plateaux[Y][X][1] = 180;
						}
						else
						{
							Plateaux[Y][X][1] = 179;
						}
					}
					
					

					
				}

			}
		}
		
		for (int Y = 1; Y < (Plateaux_Ymax -1); Y++) {
			for (int X = 1; X < (Plateaux_Xmax -1); X++) { 

				if (Plateaux[Y][X][0] == 0) {

					if (Plateaux[Y][(X - 1)][0] == 0) {
						Plateaux[Y][X][1] = 196;
					}
					if (Plateaux[Y][(X + 1)][0] == 0) {
						Plateaux[Y][X][1] = 196;
					}
					if (Plateaux[(Y + 1)][X][0] == 0) {
						Plateaux[Y][X][1] = 179;
					}
					if (Plateaux[(Y - 1)][X][0] == 0) {
						Plateaux[Y][X][1] = 179;
					}

					if (Plateaux[Y][(X - 1)][0] == 0) {
						if (Plateaux[(Y + 1)][X][0] == 0) {
							Plateaux[Y][X][1] = 191;
						}
						if (Plateaux[(Y - 1)][X][0] == 0) {
							Plateaux[Y][X][1] = 217;
						}
					}

					if (Plateaux[Y][(X + 1)][0] == 0) {
						if (Plateaux[(Y - 1)][X][0] == 0) {
							Plateaux[Y][X][1] = 192;
						}
						if (Plateaux[(Y + 1)][X][0] == 0) {
							Plateaux[Y][X][1] = 218;
						}
					}

					if (Plateaux[Y][(X - 1)][0] == 0) {
						if (Plateaux[(Y + 1)][X][0] == 0) {
							if (Plateaux[Y][(X + 1)][0] == 0) {
								Plateaux[Y][X][1] = 194;
							}
						}
						if (Plateaux[(Y - 1)][X][0] == 0) {
							if (Plateaux[Y][(X + 1)][0] == 0) {
								Plateaux[Y][X][1] = 193;
							}
						}
					}

					if (Plateaux[(Y - 1)][X][0] == 0) {
						if (Plateaux[Y][(X + 1)][0] == 0) {
							if (Plateaux[(Y + 1)][X][0] == 0) {
								Plateaux[Y][X][1] = 195;
							}
						}
						if (Plateaux[Y][(X - 1)][0] == 0) {
							if (Plateaux[(Y + 1)][X][0] == 0) {
								Plateaux[Y][X][1] = 180;
							}
						}
					}


					if (Plateaux[(Y - 1)][X][0] == 0) {
						if (Plateaux[(Y + 1)][X][0] == 0) {
							if (Plateaux[Y][(X - 1)][0] == 0) {
								if (Plateaux[Y][(X + 1)][0] == 0) {
									Plateaux[Y][X][1] = 197;
								}
							}
						}
					}

					if (Plateaux[(Y - 1)][X][0] != 0) {
						if (Plateaux[(Y + 1)][X][0] != 0) {
							if (Plateaux[Y][(X - 1)][0] != 0) {
								if (Plateaux[Y][(X + 1)][0] != 0) {
									Plateaux[Y][X][1] = 43;
								}
							}
						}
					}



				}

			}
		}


		



		
	}
	else
	{

	}


}

void display_Plateaux(int Z ) {

	curseurDefault();
	curseurMove(1, 1);
	char c;
	for (int i = 0; i < Plateaux_Ymax; i++) {
		for (int j = 0; j < Plateaux_Xmax; j++) {
			
			
			if ( Z == 1) {
				c = Plateaux[i][j][Z];
			    cout << c;
			}
			else
			{
				if (Plateaux[i][j][Z] == 1) {

					cout << on_blue << " " << reset;
				}
				else if (Plateaux[i][j][Z] > 1) {

					cout << on_red << " " << reset;
				}
				else if (Plateaux[i][j][Z] == 0)
				{

					cout << on_white << " " << reset;
				}
				else
				{
					cout << on_green << " " << reset;
				}
			}
			
			
			
			

		
		}
		curseurMoveLin(1);
	}
}


int main()
{
	system("mode 150,40");
	srand(time(NULL));
	
	bool Game_loop = true;



	while (Game_loop) // Game Loop
	{ 
		// Menu 
		
		Menu();
		bool Menu_boucle = true;
		int Menu_choix = 0;
		int Menu_max = 3;

		// systeme Event_Key 
		while (Menu_boucle)
		{
			if (_kbhit()) {
				
				int e = event_key(); 

				switch (e)
				{
				case Key_presse::DOWN:

					if (Menu_choix != Menu_max) {
						curseurToMove(64, (15 + (Menu_choix * 2)));
						cout << " ";
						curseurMoveLin(2);
						cout << "X";
						Menu_choix++;
					}

					break;
				case Key_presse::UP:

					if (Menu_choix != 0) {
						curseurToMove(64, (15 + (Menu_choix * 2)));
						cout << " ";
						curseurMoveLin(-2);
						cout << "X";
						Menu_choix--;
					}

					break;
				case Key_presse::S:

					if (Menu_choix != Menu_max) {
						curseurToMove(64, (15 + (Menu_choix * 2)));
						cout << " ";
						curseurMoveLin(2);
						cout << "X";
						Menu_choix++;
					}

					break;
				case Key_presse::Z:

					if (Menu_choix != 0) {
						curseurToMove(64, (15 + (Menu_choix * 2)));
						cout << " ";
						curseurMoveLin(-2);
						cout << "X";
						Menu_choix--;
					}

					break;
				case Key_presse::ENTRE:
					Menu_boucle = false;
					system("cls");
					break;
				default:
					break;
				}
			
				curseurDefaultDown();
			}

		}

		char mots[10];
		int index = 0;

		while (true)
		{
			int c = 0;
			if (_kbhit()) {
			
				c = _getch();
				if (c == 224 || c == 0) {
					c = _getch();	
				}
				mots[index] = c;
				index++;
			}

			if (c == 13) { break; }


		}






		
		
		if (Menu_choix == 0) { // Play 
			bool Play_boucle = true;

			Menu_Play();
			init_Plateaux();
			display_Plateaux(1);

			int Pac_Man[2];
			int Fantome[4][2];
			int random_Y;
			int random_X;

			for (int i = 0; i < 4; i++) {

				random_Y = rand() % (Plateaux_Ymax - (Plateaux_Ymax /2)) + 1;
				random_X = rand() % (Plateaux_Xmax - (Plateaux_Xmax / 2)) + 1;

				for (; Plateaux[random_Y][random_X][0] == 0;) {
					random_Y = rand() % (Plateaux_Ymax - 2) + (Plateaux_Ymax / 2);
					random_X = rand() % (Plateaux_Xmax - 2) + (Plateaux_Xmax / 2);
				}

				Fantome[i][0] = random_Y;
				Fantome[i][1] = random_X;

			}
			
			random_Y = rand() % (Plateaux_Ymax - 2) + 1;
			random_X = rand() % (Plateaux_Xmax - 2) + 1;

			for (; Plateaux[random_Y][random_X][0] == 0;) {
				random_Y = rand() % (Plateaux_Ymax - 2) + 1;
				random_X = rand() % (Plateaux_Xmax - 2) + 1;
			}

			Pac_Man[0] = random_Y;
			Pac_Man[1] = random_X;

			

			while (Play_boucle)
			{
				
			}

		}

		if (Menu_choix == 1) { // Option 
			bool Option_boucle = true;
			int Option_choix = 0;
			int Option_choix_exit = 2;
			Menu_Option(0);
			Menu_Option(1);
			while (Option_boucle)
			{
				if (_kbhit()) {

					int e = event_key();

					switch (e)
					{
					case Key_presse::DOWN:

						if (Option_choix != Option_choix_exit) {
							curseurToMove(32, (15 + Option_choix));
							cout << " ";
							curseurMoveLin(1);
							cout << ">";
							Option_choix++;
							Menu_Option(Option_choix + 1);
						}

						break;
					case Key_presse::UP:

						if (Option_choix != 0) {
							curseurToMove(32, (15 + Option_choix));
							cout << " ";
							curseurMoveLin(-1);
							cout << ">";
							Option_choix--;
							Menu_Option(Option_choix + 1);
						}

						break;
					case Key_presse::S:

						if (Option_choix != Option_choix_exit) {
							curseurToMove(32, (15 + Option_choix));
							cout << " ";
							curseurMoveLin(1);
							cout << ">";
							Option_choix++;
							Menu_Option(Option_choix + 1);
						}

						break;
					case Key_presse::Z:

						if (Option_choix != 0) {
							curseurToMove(32, (15 + Option_choix));
							cout << " ";
							curseurMoveLin(-2);
							cout << ">";
							Option_choix--;
							Menu_Option(Option_choix + 1);
						}

						break;
					case Key_presse::ENTRE:

						if (Option_choix == 0) {
							if (Random_Generation) {
								Random_Generation = false;
								curseurToMove(34, (15 + Option_choix));
								cout << " ";
							}
							else
							{
								Random_Generation = true;
								curseurToMove(34, (15 + Option_choix));
								cout << "X";
							}
						}

						if (Option_choix == 1) {
							if (Game_speed == 1) {
								Game_speed = 2;
								curseurToMove(34, (15 + Option_choix));
								cout << "2";
							}
							else
							{
								Game_speed = 1;
								curseurToMove(34, (15 + Option_choix));
								cout << "1";
							}
						}

						if (Option_choix == Option_choix_exit) { 
							Option_boucle = false; 
							system("cls");
						}


						break;
					default:
						break;
					}

					curseurDefaultDown();
				}
			}
		}

		if (Menu_choix == 2) { // Score borde 
			bool ScoreBorde_boucle = true;
			while (ScoreBorde_boucle)
			{

			}
		}

		if (Menu_choix == 3) { // Exite 

			Game_loop = false;
		}
		
	}
	

	


}
