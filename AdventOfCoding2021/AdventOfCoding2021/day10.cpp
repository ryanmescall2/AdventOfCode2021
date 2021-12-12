#pragma once
#include "day10.h"
#include "Methods.h"
#include <bitset>
#include "pyStr.h"
#include <array>

void Day10::Problem10a()
{
	std::string file_in = "test.txt";
	std::vector<std::string> lines = FileToVector<std::string>(file_in);

	std::unordered_map<char, int> points;
	points['('] = 3;
	points['['] = 57;
	points['{'] = 1197;
	points['<'] = 25137;

	std::unordered_map<char, char> pairs;
	pairs[')'] = '(';
	pairs[']'] = '[';
	pairs['}'] = '{';
	pairs['>'] = '<';

	std::unordered_map<char, int> count;
	count['('] = 0;
	count['['] = 0;
	count['{'] = 0;
	count['<'] = 0;

	int sol = 0;


	for (auto& line : lines)
	{ // For each line:
		if (line.size() % 2 != 0) // don't consider incomplete lines
			continue;

		for (auto& c : line)
		{ // For each character in the line
			if (count.find(c) != count.end()) // if it is an opening character, count it
				count[c] += 1;
			else
				count[pairs[c]] -= 1;
		}

		// check for incompleteness
		char first_missing_char = ' ';
		int first_missing_idx = -1;
		for (auto& key: count)
		{ // iterate through each of the four characters
			if (count[key.first] > 0)
			{ // if this character has a missing closer character:
				for (int i = 0; i < line.size(); i++)
				{ // find the index for the opening character
					if (line[i] == key.first)
					{
						if (i < first_missing_idx)
							break;

						first_missing_idx = i;
						first_missing_char = key.first;
						break;
					}
						
				}
			}

			// add to solution
			sol += points[first_missing_char];
		}
	}

	std::cout << "Solution 10a = " << sol << std::endl;

}

void Day10::Problem10b()
{
	std::string file_in = "day10_in.txt";
	std::vector<std::string> lines = FileToVector<std::string>(file_in);

	
	int sol = 0;

	std::cout << "Solution 10b = " << sol << std::endl;
}