// AdventOfCode.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <string>
#include <list>
#include <algorithm>
#include <vector>

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

void Challenge3_1()
{
	std::cout << "Challenge 3_1\n";

	std::ifstream file("3_input.txt");

	if (!file.is_open()) {
		std::cerr << "Error opening file!" << std::endl;
		return;
	}
	int total = 0;

	std::string line;

	while (std::getline(file, line)) {
		std::string firstNumber = "";
		std::string secondNumber = "";

		int index = 0;
		for (int i = 0; i < line.size() - 1; i++)
		{
			if (line[i] > firstNumber[0])
			{
				firstNumber = line[i];
				index = i;
			}
		}

		for (int j = index + 1; j < line.size(); j++)
		{
			if (line[j] > secondNumber[0])
			{
				secondNumber = line[j];
			}
		}
		//std::cout << std::stoi(firstNumber + secondNumber) << std::endl;
		total += std::stoi(firstNumber + secondNumber);
	}

	std::cout << total << std::endl;
}

void Challenge3_2()
{
	std::cout << "Challenge 3_2\n";

	std::ifstream file("3_input.txt");

	if (!file.is_open()) {
		std::cerr << "Error opening file!" << std::endl;
		return;
	}
	long long total = 0;

	std::string line;

	while (std::getline(file, line)) {
	std::string number = "";

		int lastChosenIndex = -1;

		while (number.size() <= 12)
		{
			number += "0";
			for (int i = lastChosenIndex + 1; i < line.size() - (12 - number.size()); i++)
			{
				if (line[i] > number[number.size()-1])
				{
					number[number.size() - 1] = line[i];
					lastChosenIndex = i;
				}
			}
		}
		number.pop_back();
		total += std::stoll(number);
	}

	std::cout << total << std::endl;
}

void Challenge4_1()
{
	std::cout << "Challenge 4_1\n";

	std::ifstream file("4_input.txt");

	if (!file.is_open()) {
		std::cerr << "Error opening file!" << std::endl;
		return;
	}
	int total = 0;

	std::vector<std::string> readfile;

	std::vector<std::vector<int>> gridAdjacent;
	std::string line;
	int nbLines = 0;
	int lineWidth = 0;

	while (std::getline(file, line))
	{
		readfile.push_back(line);
	}
	
	lineWidth = readfile[0].size();
	nbLines = readfile.size();

	gridAdjacent.resize(lineWidth, std::vector<int>(nbLines));

	int adjacentRolls = 0;

	for (int x = 0; x < lineWidth; x++)
	{
		for (int y = 0; y < nbLines; y++)
		{
			if (!(x < 0 || x >= lineWidth || y < 0 || y >= nbLines))
			{
				if (readfile[y][x] == '@')
				{
					if (x > 0 && y > 0)
						gridAdjacent[x - 1][ y - 1]++;
					if (x > 0)
						gridAdjacent[x - 1][ y]++;
					if (x > 0 && y < nbLines - 1)
						gridAdjacent[x - 1][ y + 1]++;
					if (y > 0)
						gridAdjacent[x][ y - 1]++;
					if (y < nbLines - 1)
						gridAdjacent[x][ y + 1]++;
					if (x < lineWidth - 1 && y > 0)
						gridAdjacent[x + 1][ y - 1]++;
					if (x < lineWidth - 1)
						gridAdjacent[x + 1][ y]++;
					if (x < lineWidth - 1 && y < nbLines - 1)
						gridAdjacent[x + 1][ y + 1]++;
				}
			}
		}
	}

	for (int x = 0; x < lineWidth; x++)
	{
		for (int y = 0; y < nbLines; y++)
		{
			if (gridAdjacent[x][y] < 4 && readfile[y][x] == '@')
				total++;
		}
	}

	std::cout << total << std::endl;
}

int ProcessRolls(std::string filepath)
{
	std::ifstream file(filepath);

	if (!file.is_open()) {
		std::cerr << "Error opening file!" << std::endl;
		return 0;
	}
	int total = 0;

	std::vector<std::string> readfile;

	std::vector<std::vector<int>> gridAdjacent;
	std::string line;
	int nbLines = 0;
	int lineWidth = 0;

	while (std::getline(file, line))
	{
		readfile.push_back(line);
	}

	lineWidth = readfile[0].size();
	nbLines = readfile.size();

	gridAdjacent.resize(lineWidth, std::vector<int>(nbLines));

	int adjacentRolls = 0;

	for (int x = 0; x < lineWidth; x++)
	{
		for (int y = 0; y < nbLines; y++)
		{
			if (!(x < 0 || x >= lineWidth || y < 0 || y >= nbLines))
			{
				if (readfile[y][x] == '@')
				{
					if (x > 0 && y > 0)
						gridAdjacent[x - 1][y - 1]++;
					if (x > 0)
						gridAdjacent[x - 1][y]++;
					if (x > 0 && y < nbLines - 1)
						gridAdjacent[x - 1][y + 1]++;
					if (y > 0)
						gridAdjacent[x][y - 1]++;
					if (y < nbLines - 1)
						gridAdjacent[x][y + 1]++;
					if (x < lineWidth - 1 && y > 0)
						gridAdjacent[x + 1][y - 1]++;
					if (x < lineWidth - 1)
						gridAdjacent[x + 1][y]++;
					if (x < lineWidth - 1 && y < nbLines - 1)
						gridAdjacent[x + 1][y + 1]++;
				}
			}
		}
	}

	std::ofstream outputFile("4_temp.txt");

	for (int x = 0; x < lineWidth; x++)
	{
		std::string tempLine = "";
		for (int y = 0; y < nbLines; y++)
		{
			if (gridAdjacent[x][y] < 4 && readfile[y][x] == '@')
			{
				total++;
				tempLine+=(".");
			}
			else if (readfile[y][x] == '.')
			{
				tempLine += (".");
			}
			else
			{
				tempLine += ("@");
			}
		}
		outputFile << tempLine << std::endl;
	}
	
	outputFile.close();
	return total;
}

void Challenge4_2()
{
	std::cout << "Challenge 4_2\n";
	int total = ProcessRolls("4_input.txt");
	while (1)
	{
		int temp = ProcessRolls("4_temp.txt");
		if (temp == 0)
		{
			break;
		}
		else
		{
			total += temp;
		}
	}

	std::cout << total << std::endl;
}

void Challenge5_1()
{
	std::cout << "Challenge 5_1\n";

	std::ifstream file("5_input.txt");

	if (!file.is_open()) {
		std::cerr << "Error opening file!" << std::endl;
		return;
	}

	std::string line;
	std::vector<std::vector<long long>> ingredients;
	
	int total = 0;

	bool isFirstStage = true;

	while (std::getline(file, line))
	{
		if (line == "")
		{
			isFirstStage = false;
			continue;
		}

		if (isFirstStage)
		{
			long long startIndex;
			long long endIndex;

			int posComma = line.find('-');
			startIndex = stoll(line.substr(0, posComma));
			endIndex = stoll(line.substr(posComma + 1));

			ingredients.push_back({ startIndex, endIndex });
		}
		else
		{
			for (int i = 0; i < ingredients.size(); i++)
			{
				long long lineNumber = stoll(line);
				if (lineNumber >= ingredients[i][0] && lineNumber <= ingredients[i][1])
				{
					total++;
					break;
				}
			}
		}
	}
	std::cout << total << std::endl;
}

void Challenge5_2()
{
	std::cout << "Challenge 5_2\n";

	std::ifstream file("5_input.txt");

	if (!file.is_open()) {
		std::cerr << "Error opening file!" << std::endl;
		return;
	}

	std::string line;
	std::vector<std::vector<long long>> ingredients;

	long long total = 0;
	bool isFirstStage = true;

	long long biggestIndex = 0;
	long long smallestIndex = -1;

	while (std::getline(file, line))
	{
		if (isFirstStage)
		{
			if (line == "")
			{
				isFirstStage = false;
				continue;
			}

			long long startIndex;
			long long endIndex;

			int posComma = line.find('-');
			startIndex = stoll(line.substr(0, posComma));
			endIndex = stoll(line.substr(posComma + 1));

			ingredients.push_back({ startIndex, endIndex });
			if (endIndex > biggestIndex)
			{
				biggestIndex = endIndex;
			}
			if (startIndex < smallestIndex || smallestIndex == -1)
			{
				smallestIndex = startIndex;
			}
		}
	}
		
	while (1)
	{
		bool shouldBreak = false;
		for (int i = 0; i < ingredients.size(); i++)
		{
			for (int j = 0; j < i; j++)
			{
				if (i == j)
				{
					continue;
				}
				if (((ingredients[i][0] <= ingredients[j][0]) && (ingredients[i][1] >= ingredients[j][0])) || ((ingredients[i][1] >= ingredients[j][1]) && (ingredients[i][0] <= ingredients[j][1])) || ((ingredients[i][0] >= ingredients[j][0]) && (ingredients[i][1] <= ingredients[j][1])) || ((ingredients[i][0] <= ingredients[j][0]) && (ingredients[i][1] >= ingredients[j][1])))
				{
					//Chevauche
					long long bottomBoundary = ingredients[i][0] < ingredients[j][0] ? ingredients[i][0] : ingredients[j][0];
					long long topBoundary = ingredients[i][1] > ingredients[j][1] ? ingredients[i][1] : ingredients[j][1];
					ingredients[i] = { bottomBoundary, topBoundary };
					ingredients.erase(ingredients.begin() + j);
					shouldBreak = true;
					break;
				}
			}
			if (shouldBreak)
				break;
		}
		if (!shouldBreak)
		{
			break;
		}
	}

	for (int i = 0; i < ingredients.size(); i++)
	{
		total += ingredients[i][1] - ingredients[i][0] + 1;
	}

	std::cout << total << std::endl;
}

int main()
{
    //Challenge1_1();
	//Challenge1_2();
	//Challenge2_1();
	//Challenge2_2();
	//Challenge3_1();
	//Challenge3_2();
	//Challenge4_2();
	//Challenge5_1();
	Challenge5_2();
}