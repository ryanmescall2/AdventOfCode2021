#pragma once
#include "Methods.h"
#include "pyStr.h"
#include <bitset>

struct Day6
{
	Day6() {
		//Problem6a();
		Problem6b();
	};

	void Problem6a();
	void Problem6b();

	std::vector<int> FishSex(std::vector<int> fish, int days);
	U64 FishSexOnSteroids(std::array<U64, 9> fish, U64 days);

	~Day6() {};
};