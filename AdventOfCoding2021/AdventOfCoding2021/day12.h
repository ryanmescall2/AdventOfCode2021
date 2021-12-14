#pragma once
#include "Methods.h"
#include "pyStr.h"
#include <bitset>

struct Day12
{
	Day12() {
		//Problem12a();
		Problem12b();
	};

	void Problem12a();
	void Problem12b();
	void ExplorePaths(std::unordered_map<std::string, std::vector<pyStr>> conn, pyStr next_cave, std::vector<std::vector<pyStr>>& all_paths);
	void ExplorePathsPart2(std::unordered_map<std::string, std::vector<pyStr>> conn, pyStr next_cave, std::vector<std::vector<pyStr>>& all_paths);

	~Day12() {};
};
