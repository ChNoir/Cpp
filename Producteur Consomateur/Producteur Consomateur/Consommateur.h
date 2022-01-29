#pragma once
#include<iostream>
#include <mutex>
#include <deque>
#include <string>
#include <thread>

class Consommateur
{
public:

	Consommateur(std::string nom, std::deque<int>& queue, std::mutex& mtx, int ms);

	void start();
	void wait();
	void stop();


private:

	void run();

	std::thread th;
	std::string nom;
	std::deque<int>& queue;
	std::mutex& mtx;
	bool Stop = false;

	int dure;



};

