#include <iostream>
#include <thread>
#include <string>
#include <mutex>
#include "MyTheread.h"

void lol() {
	std::cout << "ok : 1" << std::endl;
}
void xd() {
	std::cout << "ok : 2" << std::endl;
}



int main() {


	///*MyTheread th1;
	//MyTheread th2;
	//MyTheread th3;

	//std::thread t1(&MyTheread::Fun, &th1, 1000);
	//std::thread t2(&MyTheread::Fun, &th2, 2000);
	//std::thread t3(&MyTheread::Fun, &th3, 4000);

	//t1.join();
	//t2.join();
	//t3.join();*/


	
	std::thread *t1;

	t1 = new std::thread(xd);
	t1->join();
	t1 = new std::thread(lol);
	t1->join();



	//std::cout << MyTheread::compteur;

	return 0;
}