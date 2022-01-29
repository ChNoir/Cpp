#include "SuperString.h"

char SuperString::display(){

}

void SuperString::saisir(){
	fgets(SuperString::tab , MAX , stdin );
}

int SuperString::size() {

}

SuperString SuperString::operator = (SuperString SuperS) {

	char tab = SuperS.display();

	for (int i = 0; ; i++) {
		
	}
}

SuperString::SuperString() {
	
	tab = new char[(MAX + 1)];
	tab[0] = '\0';

}

SuperString::SuperString(char* SuperS) {


}

SuperString::~SuperString() {
	delete[] tab;
}