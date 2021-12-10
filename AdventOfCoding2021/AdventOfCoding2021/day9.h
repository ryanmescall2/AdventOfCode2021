#pragma once
#include "Methods.h"
#include "pyStr.h"
#include <bitset>

struct Day9
{
	Day9() {
		Problem9a();
		Problem9b();
	};

	void Problem9a();
	void Problem9b();
	bool IsLowPoint(std::vector<std::string> lines, int i, int j);
	int FindBasin(std::vector<std::string> lines, int i, int j, int count, std::vector<std::tuple<int, int>>& visited);
	bool HaveVisited(std::vector<std::tuple<int, int>>& visited, int i, int j);
	int ln_sz;

	~Day9() {};
};
