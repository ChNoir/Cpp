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

// Variable globale 
int curseur_Y		= 0;
int curseur_X		= 0;
int curseur_Ymax	= 39 ;



using namespace termcolor;
using namespace std;


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

void curseurCoutString( string text) {
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

void curseurCoutInt( int text) {
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

void curseurToMove(int x , int y) { 
	// Require variable globale : curseur_X , curseur_Y

	COORD CRD;
	CRD.X = x ;
	CRD.Y = y ;
	curseur_X = x;
	curseur_Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), CRD);
}

void curseurMove(int x, int y) {
	// Require variable globale : curseur_X , curseur_Y

	COORD CRD;
	CRD.X = x + curseur_X;
	CRD.Y = y + curseur_Y;
	curseur_X += x ;
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
	CRD.Y = curseur_Y ;
	curseur_X += x;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), CRD);
}

void Menu_Pac_Man() {

	int Y_0 = 16 ;
	int X_0 = 60 ;
	curseurToMove(X_0, Y_0);

	for (int i = 0; i < 30; i++) {
		cout << on_white << " " << reset;
		curseurMoveCol(1);
		
	}
	for (int i = 0; i < 6; i++) {
		cout << on_white << " " << reset;
		curseurMoveLin(1);
		
	}

	curseurToMove(X_0, Y_0);

	for (int i = 0; i < 6; i++) {
		cout << on_white << " " << reset;
		curseurMoveLin(1);

	}
	for (int i = 0; i < 31; i++) {
		cout << on_white << " " << reset;
		curseurMoveCol(1);

	}

	curseurToMove(X_0, Y_0);
	curseurMoveLin(2);
	curseurMoveCol(12);
	curseurCoutString("Pac-Man");

	curseurMoveCol(-14);
	curseurMoveLin(2);
	curseurCoutString("[ ] Play      [ ] Exit");

	curseurDefault();
}

void Tab_Pac_Man(int Ymax , int Xmax) {
	char c;
	curseurDefault();
	curseurCoutChar(201);
	for (int i = 0; i < Xmax; i++) {
		curseurCoutChar(205);
	}
	c = 187;
	cout << c;
	c = 186;
	for (int i = 0; i < Ymax; i++) {
		curseurMoveLin(1);
		cout << c;

	}
	curseurMoveLin(1);
	c = 188;
	cout << c;
	c = 186;
	curseurDefault();
	for (int i = 0; i < Ymax; i++) {
		curseurMoveLin(1);
		cout << c;

	}
	curseurMoveLin(1);
	curseurCoutChar(200);
	for (int i = 0; i < Xmax; i++) {
		curseurCoutChar(205);
	}
	curseurDefaultDown();
	
}


int main()
{
	
	bool Boucle_run = true;
	bool Boucle_Play = true;
	          //  X   Y //
	system("mode 150,40");
	srand(time(NULL));
	

	/*
	for (int i = 0; i < 300; i++) {
		char c = i;
		wcout << i << " : " << c << "    ";
	}

	*/
	
	
	 Menu_Pac_Man();

	curseurToMove(66, 20);
	cout << "X";
	curseurDefaultDown();

	while (Boucle_run)
	{
		if (_kbhit()) {
			
			int e = event_key();

			switch (e)
			{
			case Key_presse::LEFT :
				curseurToMove(80, 20);
				cout << " ";
				curseurToMove(66,20);
				Boucle_Play = true;
				cout << "X";
				curseurDefaultDown();
				break;
			case Key_presse::RIGHT:
				curseurToMove(66, 20);
				cout << " ";
				curseurToMove(80, 20);
				Boucle_Play = false;
				cout << "X";
				curseurDefaultDown();
				break;
			case Key_presse::ENTRE:
				Boucle_run = false;
				break;
			default:
				break;
			}
		
		}
	}
	Boucle_run = true;
	system("cls");
	curseurDefault();

	while (Boucle_Play)
	{
		const int Ymax = 35;
		const int Xmax = 125;
		char tab_G[Ymax][Xmax];
		int Tab_G[Ymax][Xmax];
		int N_case = 1;


		for (int Y = 1; Y  < Ymax; Y += 2) {
			for (int X = 1; X < Xmax; X += 2) {
				Tab_G[Y][X] = 1;
				// N_case++;
				Tab_G[(Y + 1)][X] = 0;
				Tab_G[(Y - 1)][X] = 0;
				Tab_G[Y][(X + 1)] = 0;
				Tab_G[Y][(X - 1)] = 0;
				Tab_G[(Y + 1)][(X + 1)] = 0;
				Tab_G[(Y - 1)][(X + 1)] = 0;
				Tab_G[(Y + 1)][(X - 1)] = 0;
				Tab_G[(Y - 1)][(X - 1)] = 0;
			}
		}

		/////////////////////////////////

		for (int Y = 0; Y < Ymax; Y++) {
			for (int X = 0; X < Xmax; X++) {

				if (Tab_G[Y][X] == 0) {
					cout << on_white << " " << reset;
				}
				else
				{
					cout << " ";
				}

			}
			cout << endl;
		}

		system("pause");
		system("cls");

		////////////////////////////////////

		/// good 

		int Ymax_incre = (Ymax / 2)-1;
		int Xmax_incre = (Xmax / 2)-1;
		int Numero_case_max = N_case;
		
		int h = 0;
		int k = 0; 

		int random;


		for (int Y = 1; Y < Ymax; Y += 2) {

			for (int X = 1; X < Xmax; X += 2) {


				random = rand() % 4 + 1;

				switch (random)
				{
				case 1:
					if (!((X - 1) == 0)) {
						if (Tab_G[Y][(X - 1)] == 0) {
							Tab_G[Y][(X - 1)] = 1;
						}
					}

					break;
				case 2:
					if (!((Y - 1) == 0)) {
						if (Tab_G[(Y - 1)][X] == 0) {
							Tab_G[(Y - 1)][X] = 1;
							
						}
					}

					break;
				case 3:
					if (!(X == (Xmax - 2))) {
						if (Tab_G[Y][(X + 1)] == 0) {
							Tab_G[Y][(X + 1)] = 1 ;
							

						}
					}

					break;
				case 4:
					if (!(Y == (Ymax - 2))) {
						if (Tab_G[(Y + 1)][X] == 0) {
							Tab_G[(Y + 1)][X] = 1;
							
						}
					}

					break;

				}

			}

		}

		for (int Y = 0; Y < Ymax; Y++) {
			for (int X = 0; X < Xmax; X++) {

				if (Tab_G[Y][X] == 0) {
					cout << on_white << " " << reset;
				}
				else
				{
					cout << " ";
				}

			}
			cout << endl;
		}

		system("pause");
		system("cls");

		for (int Y = 2; Y < Ymax; Y++) {
			for (int X = 2; X < Xmax; X++) {
				int j = 0;
				if (Tab_G[Y][X] == 0) {
					if (!(Tab_G[Y][(X - 1)] == 0)) {
						j++;
					}
					if (!(Tab_G[Y][(X + 1)] == 0)) {
						j++;
					}
					if (!(Tab_G[(Y - 1)][X] == 0)) {
						j++;
					}
					if (!(Tab_G[(Y + 1)][X] == 0)) {
						j++;
					}
					if (!(Tab_G[(Y - 1)][(X + 1)] == 0)) {
						j++;
					}
					if (!(Tab_G[(Y - 1)][(X - 1)] == 0)) {
						j++;
					}
					if (!(Tab_G[(Y + 1)][(X + 1)] == 0)) {
						j++;
					}
					if (!(Tab_G[(Y + 1)][(X - 1)] == 0)) {
						j++;
					}
					if (j == 8) {
						Tab_G[Y][X] = 1;
					}
				}
			}
		}

		for (int Y = 0; Y < Ymax; Y++) {
			for (int X = 0; X < Xmax; X++) {

				if (Tab_G[Y][X] == 0) {
					cout << on_white << " " << reset;
				}
				else
				{
					cout << " ";
				}

			}
			cout << endl;
		}

		system("pause");
		system("cls");

		for (int Y = 0; Y < Ymax; Y++) {
			for (int X = 0; X < Xmax; X++){

				if (Tab_G[Y][X] == 0) {
					Tab_G[Y][X] = 1;
				}
				else
				{
					Tab_G[Y][X] = 0;
				}
			}
		}
		
		for (int Y = 0; Y < Ymax; Y++) {
			for (int X = 0; X < Xmax; X++) {

				if (Tab_G[Y][X] == 0) {
					cout << on_white << " " << reset;
				}
				else
				{
					cout << " ";
				}

			}
			cout << endl;
		}

		system("pause");
		system("cls");

		curseurToMove(1, 1);
		for (int Y = 0; Y < Ymax; Y++) {
			for (int X = 0; X < Xmax; X++) {

				if (Tab_G[Y][X] == 0) {
					cout << on_white << " " << reset;
				}
				else
				{
					cout << " ";
				}

			}
			curseurMoveLin(1);
		}

		
		
		Tab_Pac_Man(Ymax,Xmax);
		
		

		char c ;
		for (int Y = 1; Y < Ymax; Y++) {
			for (int X = 1; X < Xmax; X++) {
				curseurToMove((X + 1), (Y + 1));
				if (Tab_G[Y][X] == 1) {
					curseurToMove((X+1), (Y+1));
					c = 46;
					Tab_G[Y][X]++;
					 
				}

				
				if (Tab_G[Y][X] == 0) {
					curseurToMove((X + 1), (Y + 1));
					c = 206;

					if (Tab_G[Y][(X - 1)] == 0) {
						c = 205;
					}
					if (Tab_G[Y][(X + 1)] == 0) {
						c = 205;
					}
					if (Tab_G[(Y + 1)][X] == 0) {
						c = 186;
					}
					if (Tab_G[(Y - 1)][X] == 0) {
						c = 186;
					}

					if (Tab_G[Y][(X - 1)] == 0) {
						if (Tab_G[(Y + 1)][X] == 0) {
							c = 187;
						}
						if (Tab_G[(Y - 1)][X] == 0) {
							c = 188;
						}
					}

					if (Tab_G[Y][(X + 1)] == 0) {
						if (Tab_G[(Y - 1)][X] == 0) {
							c = 200;
						}
						if (Tab_G[(Y + 1)][X] == 0) {
							c = 201;
						}
					}

					if (Tab_G[Y][(X - 1)] == 0) {
						if (Tab_G[(Y + 1)][X] == 0) {
							if (Tab_G[Y][(X + 1)] == 0) {
								c = 203;
							}
						}
						if (Tab_G[(Y - 1)][X] == 0) {
							if (Tab_G[Y][(X + 1)] == 0) {
								c = 202;
							}
						}
					}

					if (Tab_G[(Y - 1)][X] == 0) {
						if (Tab_G[Y][(X + 1)] == 0) {
							if (Tab_G[(Y + 1)][X] == 0) {
								c = 204;
							}
						}
						if (Tab_G[Y][(X - 1)] == 0) {
							if (Tab_G[(Y + 1)][X] == 0) {
								c = 185;
							}
						}
					}

					
					if (Tab_G[(Y - 1)][X] == 0) {
						if (Tab_G[(Y + 1)][X] == 0) {
							if (Tab_G[Y][(X - 1)] == 0) {
								if (Tab_G[Y][(X + 1)] == 0) {
									c = 206;
								}
							}
						}
					}
					

					


				}
				cout << c;
				
			}
		}



		curseurDefaultDown();
		system("pause");



	}
	
	
	
	
}
