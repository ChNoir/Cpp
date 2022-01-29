#include "Producteur.h"


Producteur::Producteur(
	std::string nom,
	std::deque<int>& queue,
	std::mutex& mtx,
	int quantity,
	int ms
	):	
	nom(nom),
	queue(queue), 
	mtx(mtx),
	N_prod(quantity), 
	dure(ms)
{
	srand(time(NULL));
}

void Producteur::start()
{
	th = std::thread(&Producteur::run, this);
}

void Producteur::wait()
{
	if (th.joinable()) {
		th.join();
	}

}

void Producteur::run()
{

	for (int i = 0; i < N_prod; i++)
	{
		mtx.lock();
		queue.push_front(i);
		std::cout << "commande :" << i << std::endl;
		mtx.unlock();

		int delai = (rand() % dure) + 1;

		std::this_thread::sleep_for(std::chrono::milliseconds(delai));

	}

	mtx.lock();
	std::cout << "commandes terminees " << std::endl;
	mtx.unlock();
}


