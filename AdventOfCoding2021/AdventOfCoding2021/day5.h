#pragma once
#include "Methods.h"
#include "pyStr.h"
#include <bitset>

struct Day5
{
	Day5() {
		Problem5a();
		Problem5b();
	};

	void Problem5a();
	void Problem5b();

	std::vector<pyStr> FileLinesToStr(std::string& file_name);

	~Day5() {};
};