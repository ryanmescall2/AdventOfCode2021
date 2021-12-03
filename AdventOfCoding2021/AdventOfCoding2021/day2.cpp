#pragma once
#include "day2.h"
#include "Methods.h"

void Day2::Problem2a()
{
	std::string file_in = "day2_in.txt";
	std::vector<std::string> lines = FileToVector<std::string>(file_in);

	int horizontal = 0;
	int depth = 0;

	for (int i = 0; i < lines.size(); i += 2) {
		std::string direction = lines[i];
		int val = atoi(lines[i + 1].c_str());
		if (direction == "forward") 
			horizontal += val;
		else if (direction == "down")
			depth += val;
		else if (direction == "up")
			depth -= val;
	}

	std::cout << "Solution 2a = " << horizontal * depth << std::endl;
}


void Day2::Problem2b()
{
	std::string file_in = "day2_in.txt";
	std::vector<std::string> lines = FileToVector<std::string>(file_in);

	int horizontal = 0;
	int depth = 0;
	int aim = 0;

	for (int i = 0; i < lines.size(); i += 2) {
		std::string direction = lines[i];
		int val = atoi(lines[i + 1].c_str());
		if (direction == "forward") {
			horizontal += val;
			depth += val * aim;
		}
		else if (direction == "down") {
			aim += val;
		}
		else if (direction == "up") {
			aim -= val;
		}
	}

	std::cout << "Solution 2b = " << horizontal * depth << std::endl;
}