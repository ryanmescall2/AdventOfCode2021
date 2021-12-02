#pragma once
#include "Methods.h"

struct Day1
{
	Day1() {
		Problem1a();
		Problem1b();
	};

	int CountLarger(std::vector<int> vals);
	void Problem1a();
	void Problem1b();
	~Day1() {};
};