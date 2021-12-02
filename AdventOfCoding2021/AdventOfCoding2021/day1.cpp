#pragma once
#include "day1.h"
#include "Methods.h"


void Day1::Problem1a()
{
	std::string file_in = "day1_in.txt";
	std::vector<int> lines = FileToVector<int>(file_in);
	int sol1a = CountLarger(lines);
	std::cout << "Solution 1a = " << sol1a << std::endl;
}

void Day1::Problem1b() 
{
	std::string file_in = "day1_in.txt";
	std::vector<int> lines = FileToVector<int>(file_in);

	std::vector<int> slide_lines;
	for (int i = 0; i < lines.size()-2; i++)
	{
		slide_lines.push_back(lines[i] + lines[i + 1] + lines[i + 2]);
	}

	int sol1b = CountLarger(slide_lines);
	std::cout << "Solution 1b = " << sol1b << std::endl;
}

int Day1::CountLarger(std::vector<int> vals)
{
	int lines_larger = 0;
	for (int i = 1; i < vals.size(); i++) {
		if (vals[i] > vals[i - 1])
			lines_larger += 1;
	}
	return lines_larger;
}