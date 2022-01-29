#include "Consommateur.h"

Consommateur::Consommateur(
	std::string nom, 
	std::deque<int>& queue, 
	std::mutex& mtx, 
	int ms
	):
	nom(nom),
	queue(queue),
	mtx(mtx),
	dure(ms)
{

}

void Consommateur::start()
{
	th = std::thread(&Consommateur::run, this);
}

void Consommateur::wait()
{
	if (th.joinable()) {
		th.join();
	}
}

void Consommateur::stop()
{
	if (Stop)
	{
		Stop = false;
	}
	else
	{
		Stop = true;
	}
}

void Consommateur::run()
{
	
	//std::this_thread::sleep_for(std::chrono::seconds(1));

	while (true)
	{
		bool go = false;

		mtx.lock();
		if (queue.size() > 0) { go = true; }
		if ( (queue.size() == 0) && Stop ) { 
			mtx.unlock();
			break; 
		}
		mtx.unlock();

		if (go) {

			mtx.lock();
			std::cout << nom << "en traitement" << queue.back() << std::endl;
			queue.pop_back();
			std::cout << std::endl << "file d'attente : " << queue.size() << std::endl;
			mtx.unlock();

			int random = rand() % (dure - 150) + 150;
			
			std::this_thread::sleep_for(std::chrono::milliseconds(random));
		}

		
		
	}

	
	return;
}
