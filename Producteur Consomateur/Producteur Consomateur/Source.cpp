#include "Consommateur.h"
#include "Producteur.h"

int main() {


	std::deque<int> jobQ;
	std::mutex mtx;


	Producteur p("p1", jobQ,mtx,200,150);
	Consommateur c1("Prepa1 ", jobQ, mtx, 300);
	Consommateur c2("Prepa2 ", jobQ, mtx, 300);

	p.start();
	c1.start();
	c2.start();

	p.wait();

	c2.stop();
	c1.stop();

	c2.wait();
	c1.wait();

	return 0;
}