#pragma once
#include "Methods.h"
#include <bitset>

struct Day3
{
	Day3() {
		Problem3a();
		Problem3b();
	};

	typedef std::bitset<12> bits;
	bits Find2bLines(std::vector<bits> lines_bit, bool gamma);
	bits MostCommonBit(std::vector<bits> lines_bit, bool gamma);
	void Problem3a();
	void Problem3b();
	~Day3() {};
};