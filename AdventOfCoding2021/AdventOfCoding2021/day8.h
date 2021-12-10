#pragma once
#include "Methods.h"
#include "pyStr.h"
#include <bitset>

struct Day8
{
	Day8() {
		Problem8a();
		Problem8b();
	};

	void Problem8a();
	void Problem8b();

	~Day8() {};
};

struct Mapping
{
	Mapping();
	void AddSignal(int idx, std::string val);

	std::unordered_map<int, std::array<bool,7>> _this_mapping;
	std::unordered_map<int, std::array<bool,7>> _correct_mapping; // each key is a number (1-9 on the screen) and the value is an array with the segments that make up that number
	std::unordered_map<int, std::vector<char> > _possible_chars;
	//std::array<char, 7> idx_to_char;
};