#pragma once

#include <cassert>
#include <cstdint>
#include <cstdio>
#include <format>
#include <fstream>
#include <ios>
#include <iostream>
#include <sstream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include "pyStr.h"

using U64 = uint64_t;
static_assert(sizeof(U64) == 8);

template <typename T>
inline std::vector<T> FileToVector(std::string& file_name)
{ // Read file and put every value seperated by a space or comma into a new index of a vector
	std::string input_path = std::string(_SOLUTIONDIR) + "AdventOfCoding2021\\" + file_name;

	std::ifstream infile(input_path);
	std::vector<T> contents;

	std::string line;
	T val = {};
	while (std::getline(infile, line)) {
		std::stringstream ss(line);
		while (ss >> val) {
			contents.push_back(val);
		}
	}

	return contents;
}

inline std::vector<pyStr> FileLinesToPyStr(std::string& file_name)
{ // Read file. Each line is a new entry in vector
	std::vector<pyStr> lines_out;

	std::string input_path = std::string(_SOLUTIONDIR) + "AdventOfCoding2021\\" + file_name;
	std::ifstream infile(input_path);
	std::string line;
	while (std::getline(infile, line))
		lines_out.push_back(pyStr(line));

	return lines_out;
}

inline std::vector<int> PyStrToIntVec(std::vector<pyStr>& pyStr_vec)
{ // Convert a pyStr vector to an int vector
	std::vector<int> int_vec;
	for (int i = 0; i < pyStr_vec.size(); i++)
		int_vec.push_back(atoi(pyStr_vec[i].std_string().c_str()));
	return int_vec;
}

inline int CharToInt(char c)
{
	return (int)(c) - 48;
}