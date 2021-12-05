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


template <typename T>
std::vector<T> FileToVector(std::string& file_name)
{
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
}; 