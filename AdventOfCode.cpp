// AdventOfCode.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <string>
#include <list>
#include <algorithm>

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

void Challenge2_1()
{
	std::cout << "Challenge 2_1\n";

	std::ifstream file("2_input.txt");

	if (!file.is_open()) {
		std::cerr << "Error opening file!" << std::endl;
		return;
	}
	long long total = 0;

	std::string line;
	std::string tempString;

	long long firstNumber;
	long long secondNumber;

	std::getline(file, line);

	for (int i = 0; i < line.size(); i++)
	{
		if (line[i] == '-')
		{
			firstNumber = stoll(tempString);
			tempString = "";
		}
		else if (line[i] == ',')
		{
			secondNumber = stoll(tempString);
			tempString = "";
			for (long long j = firstNumber; j <= secondNumber; j++)
			{
				std::string numberString = std::to_string(j);
				if (numberString.size() % 2 != 0)
				{
					continue;
				}
				
				std::string firstHalf = numberString.substr(0, numberString.size() / 2);
				std::string secondHalf = numberString.substr(numberString.size() / 2);

				if (firstHalf.compare(secondHalf) == 0)
				{
					std::cout << j << std::endl;
					total += j;
				}
			}
			firstNumber = 0;
			secondNumber = 0;
		}
		else
		{
			tempString += line[i];
		}
	}

	std::cout << "Password :" << std::endl;
	std::cout << total << std::endl;
}

void Challenge2_2()
{
	std::cout << "Challenge 2_2\n";

	std::ifstream file("2_input.txt");

	if (!file.is_open()) {
		std::cerr << "Error opening file!" << std::endl;
		return;
	}
	long long total = 0;

	std::string line;
	std::string tempString;

	long long firstNumber;
	long long secondNumber;

	std::getline(file, line);

	for (int i = 0; i < line.size(); i++)
	{
		if (line[i] == '-')
		{
			firstNumber = stoll(tempString);
			tempString = "";
		}
		else if (line[i] == ',')
		{
			secondNumber = stoll(tempString);
			tempString = "";
			for (long long j = firstNumber; j <= secondNumber; j++)
			{
				std::string numberString = std::to_string(j);
				if (numberString.size() <= 1)
					continue;
				for (int k = 1; k <= numberString.size() / 2; k++)
				{
					if (numberString.size() % k > 0)
						continue;

					std::string subString = numberString.substr(0, k);
					std::string compareString = subString;
					while (compareString.size() < numberString.size())
					{
						compareString += subString;
					}

					if (compareString.compare(numberString) == 0)
					{
						total += j;
						break;
					}



				}

			}
			firstNumber = 0;
			secondNumber = 0;
		}
		else
		{
			tempString += line[i];
		}
	}
	std::cout << "Password :" << std::endl;
	std::cout << total << std::endl;
}

int main()
{
    //Challenge1_1();
	//Challenge1_2();
	//Challenge2_1();
	Challenge2_2();
}