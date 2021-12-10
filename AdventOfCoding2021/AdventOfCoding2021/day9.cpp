#pragma once
#include "day9.h"
#include "Methods.h"
#include <bitset>
#include "pyStr.h"
#include <array>

void Day9::Problem9a()
{
	std::string file_in = "day9_in.txt";	
	std::vector<std::string> lines = FileToVector<std::string>(file_in);
	
	int sol = 0;
	ln_sz = (int)(lines[0].size());

	for (int i = 0; i < (int)lines.size(); i++)
	{
		for (int j = 0; j < ln_sz; j++)
		{
			if (IsLowPoint(lines, i, j))
			{
				int entry = CharToInt(lines[i][j]);
				sol += 1 + entry;
			}
		}
	}

	std::cout << "Solution 9a = " << sol << std::endl;

}

void Day9::Problem9b()
{
	std::string file_in = "day9_in.txt";
	std::vector<std::string> lines = FileToVector<std::string>(file_in);

	int biggest_basins[3] = { 0 };
	ln_sz = (int)lines[0].size();

	for (int i = 0; i < (int)lines.size(); i++)
	{
		for (int j = 0; j < ln_sz; j++)
		{
			if (!IsLowPoint(lines, i, j))
				continue;

			int count = 1;
			std::vector<std::tuple<int, int>> visited;
			int sol_ij = FindBasin(lines, i, j, count, visited);

			int smallest_idx_thus_far = 0;
			int smallest_thus_far = 10000000;
			for (int k = 0; k < 3; k++)
			{
				if (biggest_basins[k] < smallest_thus_far) {
					smallest_idx_thus_far = k;
					smallest_thus_far = biggest_basins[k];
				}
			}

			if (sol_ij > smallest_thus_far)
					biggest_basins[smallest_idx_thus_far] = sol_ij;

			
		}
	}

	int sol = biggest_basins[0]*biggest_basins[1]*biggest_basins[2];

	std::cout << "Solution 9b = " << sol << std::endl;
}

int Day9::FindBasin(std::vector<std::string> lines, int i, int j, int count, std::vector<std::tuple<int,int>>& visited)
{
	int entry = (int)(lines[i][j]) - 48;

	if (j + 1 < ln_sz && CharToInt(lines[i][j + 1]) > entry && CharToInt(lines[i][j + 1]) != 9 && !HaveVisited(visited, i,j+1)) {// the value to the right
		std::tuple<int, int> just_visited = { i,j+1 };
		visited.push_back(just_visited);
		count = FindBasin(lines, i, j + 1, count + 1, visited);
	}
	if (j - 1 >= 0 && CharToInt(lines[i][j - 1]) > entry  && CharToInt(lines[i][j - 1]) != 9 && !HaveVisited(visited, i, j - 1)) {// the value to the left
		std::tuple<int, int> just_visited = { i,j-1 };
		visited.push_back(just_visited);
		count = FindBasin(lines, i, j - 1, count + 1, visited);
	}
	if (i - 1 >= 0 && CharToInt(lines[i - 1][j]) > entry && CharToInt(lines[i - 1][j]) != 9 && !HaveVisited(visited, i-1, j)) {// the value above
		std::tuple<int, int> just_visited = { i-1,j };
		visited.push_back(just_visited);
		count = FindBasin(lines, i - 1, j, count + 1, visited);
	}
	if (i + 1 < (int)(lines.size()) && CharToInt(lines[i + 1][j]) > entry && CharToInt(lines[i + 1][j]) != 9 && !HaveVisited(visited, i+1, j)) {// the value below
		std::tuple<int, int> just_visited = { i+1,j };
		visited.push_back(just_visited);
		count = FindBasin(lines, i + 1, j, count + 1, visited);
	}

	return count;

}

bool Day9::IsLowPoint(std::vector<std::string> lines, int i, int j) 
{
	int entry = (int)(lines[i][j]) - 48;

	if (j + 1 < ln_sz && CharToInt(lines[i][j + 1]) <= entry) // the value to the right
		return false;
	if (j - 1 >= 0 && CharToInt(lines[i][j - 1]) <= entry) // the value to the left
		return false;
	if (i - 1 >= 0 && CharToInt(lines[i - 1][j]) <= entry) // the value above
		return false;
	if (i + 1 < (int)(lines.size()) && CharToInt(lines[i + 1][j]) <= entry) // the value below
		return false;

	return true;

}

bool Day9::HaveVisited(std::vector<std::tuple<int, int>>& visited, int i, int j)
{
	std::tuple<int, int> just_visited = { i,j };
	for (auto& v : visited)
	{
		if (v == just_visited)
			return true;
	}
	return false;
}
