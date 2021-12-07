#pragma once
#include "day6.h"
#include "Methods.h"
#include <bitset>
#include "pyStr.h"
#include <array>

void Day6::Problem6a()
{
	std::string file_in = "day6_in.txt";
	std::vector<pyStr> lines = FileLinesToPyStr(file_in);
	std::vector<pyStr> first_line = lines[0].split(",");
	std::vector<int> fish = PyStrToIntVec(first_line);

	U64 sol = (U64)FishSex(fish, 80).size();
	std::cout << "Solution 6a = " << sol << std::endl;
}

void Day6::Problem6b()
{
	std::string file_in = "day6_in.txt";
	std::vector<pyStr> lines = FileLinesToPyStr(file_in);
	std::vector<pyStr> first_line = lines[0].split(",");
	std::vector<int> fish = PyStrToIntVec(first_line);

	std::array<U64, 9> fish_count = { 0 };
	for (auto& i : fish)
		fish_count[i] += 1;

	U64 sol = FishSexOnSteroids(fish_count, 256);
	std::cout << "Solution 6b = " << sol << std::endl;
}

std::vector<int> Day6::FishSex(std::vector<int> fish, int days)
{
	for (int day = 1; day < days+1; day++)
	{ // For each day: (No more fish can spawn after 80 days)
		U64 size = (U64)fish.size();
		for (int i = 0; i < size; i++)
		{ // For each fish, fish_i:
			int& fish_i = fish[i];
			if (fish_i == 0)
			{ // oh boy... this fish had sex.
				fish_i = 6;
				fish.push_back(8); // Baby fish is born
			}
			else
				fish_i -= 1; // subtract a day to the value of the fish

		}
	}
	return fish;
}

U64 Day6::FishSexOnSteroids(std::array<U64, 9> fish, U64 days)
{ // The previous solution I had, FishSex(), ran into memory issues for many more days.
  // I peaked at zmeadows for this solution and then tried to do it on my own.
  // Instead of keeping track of every fish on every day, just keep track of the total number of 
  // fish with each rebirth value. We know all the ones that will be reborn have a value of zero.
  // So count all of those zero fish up, and add to the total number of fish with value 6 and 8.
  // Then reset the zero fish value to zero because all those fish turned into 8s.
  // For other values, they just get docked a day.
 	for(int day = 0; day < days; day++)
	{
		U64 give_birth_to = fish[0];
		fish[0] = 0;

		for (U64 i = 1; i < 9; i++)
			fish[i - 1] = fish[i];

		fish[8] = give_birth_to;
		fish[6] += give_birth_to;

	}
	U64 sol = 0;
	for (auto& val : fish)
		sol += val;
	return sol;
}