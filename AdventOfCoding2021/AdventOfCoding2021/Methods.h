#pragma once

#include <cstdint>
#include <cstdio>
#include <fstream>
#include <ios>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>

template <typename T>
std::vector<T> FileToVector(std::string& file_name)
{
	std::string input_path = std::string(_SOLUTIONDIR) + "AdventOfCoding2021\\" +  file_name;
	
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