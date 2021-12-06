#pragma once
#include "day5.h"
#include "Methods.h"
#include <bitset>
#include "pyStr.h"

void Day5::Problem5a()
{
	std::string file_in = "day5_in.txt";
	std::vector<pyStr> lines = FileLinesToStr(file_in);

	int(*board)[1000] = new int[1000][1000];

	// initialize board with zeros
	for (int i = 0; i < 1000; i++) {
		for (int j = 0; j < 1000; j++) {
			board[i][j] = 0;
		}
	}

	for (int i = 0; i < lines.size(); i++)
	{ // for each line, line_i:
		pyStr line_i = lines[i];

		std::vector<pyStr> line_data = line_i.split(" -> ");

		// starting two values
		std::vector<pyStr> start = line_data[0].split(",");
		int start_x = atoi(start[0].std_string().c_str());
		int start_y = atoi(start[1].std_string().c_str());

		// ending two values
		std::vector<pyStr> end = line_data[1].split(",");
		int end_x = atoi(end[0].std_string().c_str());
		int end_y = atoi(end[1].std_string().c_str());

		// add to the board:

		// one line option
		if (start_x == end_x)
		{
			if (start_y > end_y) {
				int a = start_y;
				int b = end_y;
				start_y = b;
				end_y = a;
			}
			for (int j = start_y; j <= end_y; j++)
				board[start_x][j] += 1;
		}
		// second line option
		else if (start_y == end_y)
		{
			if (start_x > end_x) {
				int a = start_x;
				int b = end_x;
				start_x = b;
				end_x = a;
			}
			for (int j = start_x; j <= end_x; j++)
				board[j][start_y] += 1;
		}
		// diagonal
		else
		{
			continue;
		}
	}

	int sol = 0;
	for (int i = 0; i < 1000; i++) {
		for (int j = 0; j < 1000; j++) {
			if (board[i][j] >= 2)
				sol += 1;
		}
	}

	delete& board[0][0];

	std::cout << "Solution 5a = " << sol << std::endl;
}


void Day5::Problem5b()
{
	std::string file_in = "day5_in.txt";
	std::vector<pyStr> lines = FileLinesToStr(file_in);

	int (*board)[1000] = new int[1000][1000];

	// initialize board with zeros
	for (int i = 0; i < 1000; i++) {
		for (int j = 0; j < 1000; j++) {
			board[i][j] = 0;
		}
	}

	for (int i = 0; i < lines.size(); i++)
	{ // for each line, line_i:
		pyStr line_i = lines[i];

		std::vector<pyStr> line_data = line_i.split(" -> ");

		// starting two values
		std::vector<pyStr> start = line_data[0].split(",");
		int start_x = atoi(start[0].std_string().c_str());
		int start_y = atoi(start[1].std_string().c_str());

		// ending two values
		std::vector<pyStr> end = line_data[1].split(",");
		int end_x = atoi(end[0].std_string().c_str());
		int end_y = atoi(end[1].std_string().c_str());

		// add to the board:

		if ((start_x != end_x) && (start_y != end_y))
		{
			if (start_x > end_x) {
				int a = start_x;
				int b = end_x;
				start_x = b;
				end_x = a;
				int c = start_y;
				int d = end_y;
				start_y = d;
				end_y = c;
			}
			int up = 1;
			int itr = start_y;
			
			if (end_y < start_y) {
				up = -1;
				itr += 1;
			}
			else
				itr -= 1;

			for (int k = start_x; k <= end_x; k++){
				itr += up;
				board[k][itr] += 1;
			}
		}
		// one line option
		else if (start_x == end_x)
		{
			if (start_y > end_y) {
				int a = start_y;
				int b = end_y;
				start_y = b;
				end_y = a;
			}
			for (int j = start_y; j <= end_y; j++)
				board[start_x][j] += 1;
		}
		// second line option
		else if (start_y == end_y)
		{
			if (start_x > end_x) {
				int a = start_x;
				int b = end_x;
				start_x = b;
				end_x = a;
			}
			for (int j = start_x; j <= end_x; j++)
				board[j][start_y] += 1;
		}
	}

	int sol = 0;
	for (int i = 0; i < 1000; i++) {
		for (int j = 0; j < 1000; j++) {
			if (board[i][j] >= 2)
				sol += 1;
		}
	}

	delete &board[0][0];

	std::cout << "Solution 5b = " << sol << std::endl;
}


std::vector<pyStr> Day5::FileLinesToStr(std::string& file_name)
{
	std::vector<pyStr> lines_out;

	std::string input_path = std::string(_SOLUTIONDIR) + "AdventOfCoding2021\\" + file_name;

	std::ifstream infile(input_path);

	std::string line;
	while (std::getline(infile, line))
		lines_out.push_back(pyStr(line));

	return lines_out;
}
