#pragma once
#include "day8.h"
#include "Methods.h"
#include <bitset>
#include "pyStr.h"
#include <array>

void Day8::Problem8a()
{
	std::string file_in = "day8_in.txt";
	std::vector<pyStr> lines = FileLinesToPyStr(file_in);
	int sol = 0;

	for (auto& line : lines)
	{
		pyStr line_out = line.split(" | ")[1];
		std::vector<pyStr> numbers = line_out.split(" ");

		for (auto& number : numbers)
		{
			int size = number.len();
			if (size == 2 || size == 3 || size == 4 || size == 7)
				sol += 1;
		}
	}

	std::cout << "Solution 8a = " << sol << std::endl;
}

void Day8::Problem8b()
{
	std::string file_in = "day8_in.txt";
	std::vector<pyStr> lines = FileLinesToPyStr(file_in);
	int sol = 0;

	for (auto& line : lines)
	{
		// Read this line
		std::vector<pyStr> info = line.split(" | ");
		std::vector<pyStr> input = info[0].split(" ");
		std::vector<pyStr> output = info[1].split(" ");

		// Determine the arrangement of digits
		for (auto& chars : input)
		{
			Mapping mapping;
			
			int size = chars.len();
			if (size == 2) {
				mapping.AddSignal(2, chars.std_string());
			}
			else if (size == 3) {

			}
			else if (size == 4) {

			} 
			else if (size == 7) {
				sol += 1;
			}
		}
	}

	std::cout << "Solution 8b = " << sol << std::endl;
}

Mapping::Mapping()
{
	std::array<bool, 7> available_chars = { true };
	std::array<bool, 7> empty_chars = { false };

	std::vector<char> pos_cs;
	pos_cs.push_back('a');
	pos_cs.push_back('b');
	pos_cs.push_back('c');
	pos_cs.push_back('d');
	pos_cs.push_back('e');
	pos_cs.push_back('f');
	pos_cs.push_back('g');
	for (int i = 1; i < 8; i++)
		_possible_chars[i] = pos_cs;

	for (int i = 0; i < 7; i++)
		_this_mapping[i] = available_chars;

	//   correct_mapping order:
			//			 -1-
			//		  0 |   | 2
			//			 -3-
			//		  4 |   | 6
			//           -5-
			//
	// a value of true means that number (segment) is active
	// 
	// number 1
	_correct_mapping[1] = empty_chars;
	_correct_mapping[1][2] = true;
	_correct_mapping[1][6] = true;
	// number 2
	_correct_mapping[2] = empty_chars;
	_correct_mapping[2][1] = true;
	_correct_mapping[2][2] = true;
	_correct_mapping[2][3] = true;
	_correct_mapping[2][4] = true;
	_correct_mapping[2][5] = true;
	// number 3
	_correct_mapping[3] = empty_chars;
	_correct_mapping[3][1] = true;
	_correct_mapping[3][2] = true;
	_correct_mapping[3][3] = true;
	_correct_mapping[3][5] = true;
	_correct_mapping[3][6] = true;
	// number 4
	_correct_mapping[4] = empty_chars;
	_correct_mapping[4][0] = true;
	_correct_mapping[4][3] = true;
	_correct_mapping[4][2] = true;
	_correct_mapping[4][6] = true;
	// number 5
	_correct_mapping[5] = empty_chars;
	_correct_mapping[5][0] = true;
	_correct_mapping[5][1] = true;
	_correct_mapping[5][3] = true;
	_correct_mapping[5][5] = true;
	_correct_mapping[5][6] = true;
	// number 6
	_correct_mapping[6] = empty_chars;
	_correct_mapping[6][0] = true;
	_correct_mapping[6][1] = true;
	_correct_mapping[6][3] = true;
	_correct_mapping[6][4] = true;
	_correct_mapping[6][5] = true;
	_correct_mapping[6][6] = true;
	// number 7
	_correct_mapping[7] = empty_chars;
	_correct_mapping[7][1] = true;
	_correct_mapping[7][2] = true;
	_correct_mapping[7][6] = true;
	// number 8
	_correct_mapping[8] = available_chars;
	// number 9
	_correct_mapping[8] = available_chars;
	_correct_mapping[8][4] = false;
}

void Mapping::AddSignal(int idx, std::string val)
{
	// we have a map of all the segments and there possible values
	// for the idx we have, look at the actual location of where those segments are. 
	// Keep all the letters in val. Discard the rest:
	for (int i = 0; i < _possible_chars[idx].size(); i++)
	{
		bool remove = true;
		for (auto& c : val)
		{
			if (_possible_chars[idx][i] == c)
			{
				remove = false;
				break;
			}
		}
		//if (remove)
			//_possible_chars[idx].
	}
	// for all other segments, get rid of the letters in val.
}
