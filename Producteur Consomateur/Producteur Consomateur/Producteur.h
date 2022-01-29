#pragma once
#include<iostream>
#include <mutex>
#include <deque>
#include <string>
#include <thread>

class Producteur
{
public:

	Producteur(std::string nom, std::deque<int>& queue, std::mutex& mtx, int quantity, int ms);


	void start();
	void wait();


private:

	void run();

	std::thread th;
	std::string nom;
	std::deque<int>& queue;
	std::mutex& mtx;
	int N_prod;
	int dure ;




};

