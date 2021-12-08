#pragma once
#include "day7.h"
#include "Methods.h"
#include <bitset>
#include "pyStr.h"
#include <array>

void Day7::Problem7a()
{
	std::string file_in = "day7_in.txt";
	std::vector<long> line = FileToVector<long>(file_in);

	std::unordered_map<long, long> sol_map;
	std::unordered_map<long, bool> already_done;
	long sol = 1000000000;
	long sol_i = 0;

	for (auto& i : line)
	{ // For each value in the input file:
		if (already_done[i]) // check for repeating numbers already computed
			continue;
		else
			already_done[i] = true; // mark as worked on (we are about to)

		sol_i = 0; // initialize

		// Compute the total amount of fuel
		for (auto& k : line)
		{ // For each value in the input file:
			if (sol_i > sol)
				break; // no need to keep going
			else
				sol_i += abs(i - k);
		}

		if (sol_i < sol)
			sol = sol_i; // best solution so far
	}

	std::cout << "Solution 7a = " << sol << std::endl;
}

void Day7::Problem7b()
{
	std::string file_in = "day7_in.txt";
	std::vector<long> line = FileToVector<long>(file_in);

	std::unordered_map<long, long> sol_map;
	std::unordered_map<long, bool> already_done;
	long sol = 1000000000;
	long sol_i = 0;

	for (auto& i : line)
	{ // For each value in the input file:
		if (already_done[i]) // check for repeating numbers already computed
			continue;
		else
			already_done[i] = true; // mark as worked on (we are about to)

		sol_i = 0; // initialize

		// Compute the total amount of fuel
		for (auto& k : line)
		{ // For each value in the input file:
			if (sol_i > sol)
				break; // no need to keep going
			else {
				long dif = abs(i - k);
				sol_i += dif * (dif + 1) / 2;
			}
		}

		if (sol_i < sol)
			sol = sol_i; // best solution so far
	}

	std::cout << "Solution 7b = " << sol << std::endl;
}
