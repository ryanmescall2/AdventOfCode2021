#pragma once
#include "day3.h"
#include "Methods.h"
#include <bitset>

void Day3::Problem3a()
{
	std::string file_in = "day3_in.txt";
	std::vector<std::string> lines = FileToVector<std::string>(file_in);
	std::vector<bits> lines_bit;
	for (int i = 0; i < lines.size(); i++)
		lines_bit.push_back(bits(lines[i]));

	bits gamma = MostCommonBit(lines_bit, true);
	bits epsilon = MostCommonBit(lines_bit, false);
	
	int solution = (int)(epsilon.to_ulong()) * (int)(gamma.to_ulong());
	std::cout << "Solution 3a = " << solution << std::endl;
}

void Day3::Problem3b()
{
	std::string file_in = "day3_in.txt";
	std::vector<std::string> lines = FileToVector<std::string>(file_in);
	std::vector<bits> lines_bit;
	for (int i = 0; i < lines.size(); i++)
		lines_bit.push_back(bits(lines[i]));

	bits oxyegn = Find2bLines(lines_bit, true);
	bits co2 = Find2bLines(lines_bit, false);

	int solution = (int)(oxyegn.to_ulong()) * (int)(co2.to_ulong());
	std::cout << "Solution 3a = " << solution << std::endl;
}


typedef std::bitset<12> bits;

bits Day3::Find2bLines(std::vector<bits> lines_bit, bool gamma)
{
	std::vector<bits> return_bits;
	bits most_com = MostCommonBit(lines_bit, gamma);

	for (int i = (int)most_com.size()-1; i >= 0; i--) {
		bool bit = most_com[i];
		// Find lines with common bit
		for (int j = 0; j < lines_bit.size(); j++) {
			if (bit == lines_bit[j][i])
				return_bits.push_back(lines_bit[j]);
		}

		if (return_bits.size() == 1)
			return return_bits[0];
		else if (return_bits.size() != 0) {
			lines_bit = return_bits;
			return_bits.clear();
			most_com = MostCommonBit(lines_bit, gamma);
		}
		else
			return lines_bit[1];
	}

	return 0;
}


bits Day3::MostCommonBit(std::vector<bits> lines_bit, bool gamma)
{
	std::vector<int> sum(12);
	bits most_com_bits;
	// if the index j at bit[i] equals 1, add 1 to sum[j]. If 0, subtract 1 to sum[j]. 
	// After going through all bits, if the sum[j] > 0, we know 1 was the most common number at the jth index.
	// If the index
	for (int i = 0; i < lines_bit.size(); i++) {
		bits line = lines_bit[i];
		for (int j = 0; j < line.size();j++) {
			if (line.test(j))
				sum[j] += 1;
			else
				sum[j] -= 1;
		}
	}

	for (int i = 0; i < sum.size();i++) {
		if (sum[i] >= 0)
			most_com_bits[i] = 1;
		else 
			most_com_bits[i] = 0;
	}

	if (!gamma) {
		bits epsilon;
		for (int i = 0; i < most_com_bits.size();i++) {
			epsilon[i] = !most_com_bits.test(i);
		}
		return epsilon;
	}
	else
		return most_com_bits;
}