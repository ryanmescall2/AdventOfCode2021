#pragma once
#include "day13.h"
#include "Methods.h"
#include <bitset>
#include "pyStr.h"
#include <array>

typedef std::tuple<int, int> tup_int;

void Day13::Problem13a()
{
	std::string file_in = "day13_in.txt";
	std::vector<pyStr> lines = FileLinesToPyStr(file_in);
	std::string comma = ",";

	// Determine size of input
	int num_cols = 0;
	int num_rows = 0;
	for (auto& line : lines)
	{
		if (line.in(comma))
		{
			std::vector<pyStr> val = line.split(comma);
			if (val[0].to_int() + 1 > num_rows)
				num_rows = val[0].to_int() + 1;
			if (val[1].to_int() + 1 > num_cols)
				num_cols = val[1].to_int() + 1;
		}
	}
	
	std::vector<int> one_row(num_rows);
	for (auto& r : one_row)
		r = 0;

	std::vector<std::vector<int>> paper(num_cols);
	std::vector<tup_int> folds;

	for (auto& c : paper)
		c = one_row;

	// Read the file into the vector paper.
	std::string fol_al = "fold along ";
	for (auto& line : lines)
	{
		if (line.in(comma))
		{
			int idx1 = 0;
			int idx2 = 0;
			std::vector<pyStr> val = line.split(comma);
			idx2 = val[0].to_int();
			idx1 = val[1].to_int();
			paper[idx1][idx2] = 1;
		}
		else if (line.in(fol_al))
		{
			pyStr command = line.split(fol_al)[0];
			std::vector<pyStr> both_cmd = command.split("=");
			int fold_type = both_cmd[0].std_string() == "x" ? 0 : 1;
			folds.push_back(std::make_tuple(fold_type, both_cmd[1].to_int()));
		}
		else
			continue; // blank space
	}

	// Fold the paper.
	//for (auto& fold : folds)
	//{
	tup_int fold = folds[0];
		int seem = get<1>(fold);
		if (get<0>(fold) == 0)
		{ // fold along the x axis
			for (int y = seem + 1; y < num_rows; y++)
			{
				for (int x = 0; x < num_cols; x++)
				{
					paper[x][seem - (y - seem)] += paper[x][y];
				}
			}
			num_rows = seem;
		}
		else if (get<0>(fold) == 1)
		{ // fold along the y axis
			for (int x = seem + 1; x < num_cols; x++)
			{
				for (int y = 0; y < num_rows; y++)
				{
					paper[seem - (x - seem)][y] += paper[x][y];
				}
			}
			num_cols = seem;
		}

	//}

	int sol = 0;
	for (int x = 0; x < num_cols; x++)
	{
		for (int y = 0; y < num_rows; y++)
		{
			if (paper[x][y] >= 1)
				sol += 1;
		}
	}

	std::cout << "Solution 13a = " << sol << std::endl;
}

void Day13::Problem13b()
{
	std::string file_in = "day13_in.txt";
	std::vector<pyStr> lines = FileLinesToPyStr(file_in);
	std::string comma = ",";

	// Determine size of input
	int num_cols = 0;
	int num_rows = 0;
	for (auto& line : lines)
	{
		if (line.in(comma))
		{
			std::vector<pyStr> val = line.split(comma);
			if (val[0].to_int() + 1 > num_rows)
				num_rows = val[0].to_int() + 1;
			if (val[1].to_int() + 1 > num_cols)
				num_cols = val[1].to_int() + 1;
		}
	}

	std::vector<int> one_row(num_rows);
	for (auto& r : one_row)
		r = 0;

	std::vector<std::vector<int>> paper(num_cols);
	std::vector<tup_int> folds;

	for (auto& c : paper)
		c = one_row;

	// Read the file into the vector paper.
	std::string fol_al = "fold along ";
	for (auto& line : lines)
	{
		if (line.in(comma))
		{
			int idx1 = 0;
			int idx2 = 0;
			std::vector<pyStr> val = line.split(comma);
			idx2 = val[0].to_int();
			idx1 = val[1].to_int();
			paper[idx1][idx2] = 1;
		}
		else if (line.in(fol_al))
		{
			pyStr command = line.split(fol_al)[0];
			std::vector<pyStr> both_cmd = command.split("=");
			int fold_type = both_cmd[0].std_string() == "x" ? 0 : 1;
			folds.push_back(std::make_tuple(fold_type, both_cmd[1].to_int()));
		}
		else
			continue; // blank space
	}

	// Fold the paper.
	for (auto& fold : folds)
	{
	int seem = get<1>(fold);
	if (get<0>(fold) == 0)
	{ // fold along the x axis
		for (int y = seem + 1; y < num_rows; y++)
		{
			for (int x = 0; x < num_cols; x++)
			{
				paper[x][seem - (y - seem)] += paper[x][y];
			}
		}
		num_rows = seem;
	}
	else if (get<0>(fold) == 1)
	{ // fold along the y axis
		for (int x = seem + 1; x < num_cols; x++)
		{
			for (int y = 0; y < num_rows; y++)
			{
				paper[seem - (x - seem)][y] += paper[x][y];
			}
		}
		num_cols = seem;
	}

	}

	std::cout << "Solution 13b = " << std::endl;

	std::string line = "";
	for (int x = 0; x < num_cols; x++)
	{
		for (int y = 0; y < num_rows; y++)
		{
			if (paper[x][y] >= 1)
				line += "#";
			else
				line += ".";
		}
		std::cout << line << std::endl;
		line = "";
	}

	
}