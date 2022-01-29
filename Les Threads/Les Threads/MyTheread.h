#pragma once
#include <string>
#include <iostream>
#include <mutex>

class MyTheread
{
public:
	
	MyTheread();
	void Fun(int max );

	static int compteur ;
	static std::mutex mu_compteur;

};

