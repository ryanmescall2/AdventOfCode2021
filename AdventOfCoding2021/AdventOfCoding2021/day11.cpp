#pragma once
#include "day11.h"
#include "Methods.h"
#include <bitset>
#include "pyStr.h"
#include <array>

void Day11::Problem11a()
{
	std::string file_in = "day11_in.txt";
	std::vector<std::string> lines = FileToVector<std::string>(file_in);

	int sol = 0;

	// convert to int
	int lines_int[10][10];
	int ln_sz = 10;
	for (int i = 0; i < (int)lines.size(); i++) {
		for (int j = 0; j < 10; j++) {
			lines_int[i][j] = CharToInt(lines[i][j]);
		}
	}

	// Add energy to each value
	for (int step = 1; step <= 10*10; step++)
	{
		for (int i = 0; i < ln_sz; i++)
		{ // traverse columns
			for (int j = 0; j < ln_sz; j++)
			{ // traverse rows
				lines_int[i][j] += 1; // add one energy
			}
		}

		bool more_to_light = true;
		bool blew_up[10][10];
		for (int i = 0; i < ln_sz; i++){
			for (int j = 0; j < ln_sz; j++) {
				blew_up[i][j] = false;
			}
		}

		while(more_to_light)
		{ 
			more_to_light = false;
			// Expand the light 
			for (int i = 0; i < ln_sz; i++)
			{ // traverse columns
				for (int j = 0; j < ln_sz; j++)
				{ // traverse rows

					if (lines_int[i][j] > 9 && !blew_up[i][j])
					{ // it is lit. Add one more to the surrounding values
						more_to_light = true;
						blew_up[i][j] = true;

						if (j + 1 < ln_sz) // the value to the right
							lines_int[i][j + 1] += 1;
						if (j - 1 >= 0) // the value to the left
							lines_int[i][j - 1] += 1;
						if (i - 1 >= 0) // the value above
							lines_int[i - 1][j] += 1;
						if (i + 1 < ln_sz) // the value below
							lines_int[i + 1][j] += 1;
						if (j + 1 < ln_sz && i - 1 >= 0) // the value to the top right
							lines_int[i - 1][j + 1] += 1;
						if (j - 1 >= 0 && i - 1 >= 0) // the value to the top left
							lines_int[i - 1][j - 1] += 1;
						if (j - 1 >= 0 && i + 1 < ln_sz) // the value to the bottom left
							lines_int[i + 1][j - 1] += 1;
						if (j + 1 < ln_sz && i + 1 < ln_sz) // the value to the bottom right
							lines_int[i + 1][j + 1] += 1;
					}
				}
			}
		}

		// Reset lit values back to zero 
		for (int i = 0; i < ln_sz; i++)
		{ // traverse columns
			for (int j = 0; j < ln_sz; j++)
			{ // traverse rows
				if (lines_int[i][j] > 9)
				{
					sol += 1;
					lines_int[i][j] = 0;
				}
			}
		}
	}
	std::cout << "Solution 11a = " << sol << std::endl;
}



void Day11::Problem11b()
{
	std::string file_in = "day11_in.txt";
	std::vector<std::string> lines = FileToVector<std::string>(file_in);

	int sol = 0;

	// convert to int
	int lines_int[10][10];
	int ln_sz = 10;
	for (int i = 0; i < (int)lines.size(); i++) {
		for (int j = 0; j < 10; j++) {
			lines_int[i][j] = CharToInt(lines[i][j]);
		}
	}

	// Add energy to each value
	for (int step = 1; step <= 10*10*10*10; step++)
	{
		for (int i = 0; i < ln_sz; i++)
		{ // traverse columns
			for (int j = 0; j < ln_sz; j++)
			{ // traverse rows
				lines_int[i][j] += 1; // add one energy
			}
		}

		bool more_to_light = true;
		bool blew_up[10][10];
		for (int i = 0; i < ln_sz; i++) {
			for (int j = 0; j < ln_sz; j++) {
				blew_up[i][j] = false;
			}
		}

		while (more_to_light)
		{
			more_to_light = false;
			// Expand the light 
			for (int i = 0; i < ln_sz; i++)
			{ // traverse columns
				for (int j = 0; j < ln_sz; j++)
				{ // traverse rows

					if (lines_int[i][j] > 9 && !blew_up[i][j])
					{ // it is lit. Add one more to the surrounding values
						more_to_light = true;
						blew_up[i][j] = true;

						if (j + 1 < ln_sz) // the value to the right
							lines_int[i][j + 1] += 1;
						if (j - 1 >= 0) // the value to the left
							lines_int[i][j - 1] += 1;
						if (i - 1 >= 0) // the value above
							lines_int[i - 1][j] += 1;
						if (i + 1 < ln_sz) // the value below
							lines_int[i + 1][j] += 1;
						if (j + 1 < ln_sz && i - 1 >= 0) // the value to the top right
							lines_int[i - 1][j + 1] += 1;
						if (j - 1 >= 0 && i - 1 >= 0) // the value to the top left
							lines_int[i - 1][j - 1] += 1;
						if (j - 1 >= 0 && i + 1 < ln_sz) // the value to the bottom left
							lines_int[i + 1][j - 1] += 1;
						if (j + 1 < ln_sz && i + 1 < ln_sz) // the value to the bottom right
							lines_int[i + 1][j + 1] += 1;
					}
				}
			}
		}

		// Reset lit values back to zero 
		bool sync = true;
		for (int i = 0; i < ln_sz; i++)
		{ // traverse columns
			for (int j = 0; j < ln_sz; j++)
			{ // traverse rows
				if (lines_int[i][j] > 9)
				{
					lines_int[i][j] = 0;
				}
				else
				{
					sync = false;
				}
			}
		}
		if (sync)
		{
			sol = step;
			break;
		}
	}

	std::cout << "Solution 11b = " << sol << std::endl;
}