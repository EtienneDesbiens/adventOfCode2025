// AdventOfCode.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <string>
#include <list>

void Challenge1_1()
{
	std::cout << "Challenge 1_1\n";

	std::ifstream file("1_input.txt");

	if (!file.is_open()) {
		std::cerr << "Error opening file!" << std::endl;
		return;
	}

	int val = 50;
	int password = 0;

	std::string line;
	while (std::getline(file, line)) {
		
		if (line[0] == 'L')
		{
			line.erase(0, 1);
			val -= std::stoi(line);
		}
		else
		{
			line.erase(0, 1);
			val += std::stoi(line);
		}
		if (val > 99 || val < 0)
			val = val % 100;
		
		if (val == 0)
			password++;
	}
	std::cout << password << std::endl;
}

void Challenge1_2()
{
	std::cout << "Challenge 1_2\n";

	std::ifstream file("1_input.txt");

	if (!file.is_open()) {
		std::cerr << "Error opening file!" << std::endl;
		return;
	}

	int val = 50;
	int password = 0;

	std::string line;
	while (std::getline(file, line)) {
		int move = 0;
		if (line[0] == 'L')
		{
			line.erase(0, 1);
			move = -std::stoi(line);
			//val -= move;
		}
		else
		{
			line.erase(0, 1);
			move = std::stoi(line);
			//val += move;
		}
	
		while(move != 0)
		{
			if (move > 0)
			{
				val++;
				move--;
			}
			else
			{
				val--;
				move++;
			}

			if (val == -1)
				val = 99;
			else if (val == 100)
				val = 0;

			if (val == 0)
				password++;
		}

	}
	std::cout << password << std::endl;
}

int main()
{
    //Challenge1_1();
	Challenge1_2();
}