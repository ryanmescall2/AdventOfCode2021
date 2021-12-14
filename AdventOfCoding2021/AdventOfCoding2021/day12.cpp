#pragma once
#include "day12.h"
#include "Methods.h"
#include <bitset>
#include "pyStr.h"
#include <array>

void Day12::Problem12a()
{
	std::string file_in = "day12_in.txt";
	std::vector<std::string> lines = FileToVector<std::string>(file_in);

	// Add all the connections to a map
	std::unordered_map<std::string, std::vector<pyStr>> conn;
	for (auto& line : lines)
	{
		std::vector<pyStr> one_con = pyStr(line).split("-");
		conn[one_con[0].std_string()].push_back(one_con[1]);
		conn[one_con[1].std_string()].push_back(one_con[0]);
	}

	// Solve for the total number of paths
	std::vector<std::vector<pyStr>> all_paths;
	std::vector<pyStr> start = { pyStr("start") };
	all_paths.push_back(start);
	ExplorePaths(conn, pyStr("start"), all_paths);
	
	// Only get the complete paths
	int sol = 0;
	for (auto& path : all_paths)
	{
		if (path[path.size()-1] == pyStr("end") && path[0] == pyStr("start"))
			sol += 1;
	}

	std::cout << "Solution 12a = " << sol << std::endl;
}

void Day12::ExplorePaths(std::unordered_map<std::string, std::vector<pyStr>> conn, pyStr at_cave, std::vector<std::vector<pyStr>>& all_paths)
{
	if (at_cave.std_string() == "end")
		return;

	std::vector<std::vector<pyStr>> *copy_all_paths = new std::vector<std::vector<pyStr>>(all_paths);
	for (auto& path : *copy_all_paths)
	{ // loop through all our current paths
		pyStr last_cave = path[path.size() - 1];
		if (last_cave.std_string() != at_cave.std_string())
			continue; // only consider those paths which are at the cave we are currently at
		
		// Delete this value so we don't get to this call again in the future
		for (int idx = 0; idx < (int)(all_paths.size()); idx++)
		{
			if (PyStrToStrVec(all_paths[idx]) == PyStrToStrVec(path))
			{
				all_paths.erase(all_paths.begin()+idx);
				break;
			}
		}

		// Explore all the next possible caves
		for (auto& next_cave : conn[at_cave.std_string()])
		{
			if (next_cave.std_string() == "start")
				continue; // not allowed to go back to the start
			else if (!next_cave.is_upper() && ValInVec<pyStr>(path, next_cave))
				continue; // can't visit a lower case cave twice
			else
			{
				std::vector<pyStr> new_path = path;
				new_path.push_back(next_cave);
				all_paths.push_back(new_path);
				ExplorePaths(conn, next_cave, all_paths);
			}
		}
	}
	delete copy_all_paths;
}

void Day12::ExplorePathsPart2(std::unordered_map<std::string, std::vector<pyStr>> conn, pyStr at_cave, std::vector<std::vector<pyStr>>& all_paths)
{
	if (at_cave.std_string() == "end")
		return;

	std::vector<std::vector<pyStr>>* copy_all_paths = new std::vector<std::vector<pyStr>>(all_paths);
	for (auto& path : *copy_all_paths)
	{ // loop through all our current paths
		pyStr last_cave = path[path.size() - 1];
		if (last_cave.std_string() != at_cave.std_string())
			continue; // only consider those paths which are at the cave we are currently at

		// Delete this value so we don't get to this call again in the future
		for (int idx = 0; idx < (int)(all_paths.size()); idx++)
		{
			if (PyStrToStrVec(all_paths[idx]) == PyStrToStrVec(path))
			{
				all_paths.erase(all_paths.begin() + idx);
				break;
			}
		}

		// Explore all the next possible caves
		for (auto& next_cave : conn[at_cave.std_string()])
		{
			if (next_cave.std_string() == "start")
				continue; // not allowed to go back to the start
			else if (!next_cave.is_upper() && OccurencesInVec<pyStr>(path, next_cave) >= 2)
				continue; // can't visit a lower case cave thrice
			else
			{
				std::vector<pyStr> new_path = path;
				new_path.push_back(next_cave);
				all_paths.push_back(new_path);
				ExplorePathsPart2(conn, next_cave, all_paths);
			}
		}
	}
	delete copy_all_paths;
}

void Day12::Problem12b()
{
	std::string file_in = "day12_in.txt";
	std::vector<std::string> lines = FileToVector<std::string>(file_in);

	// Add all the connections to a map
	std::unordered_map<std::string, std::vector<pyStr>> conn;
	for (auto& line : lines)
	{
		std::vector<pyStr> one_con = pyStr(line).split("-");
		conn[one_con[0].std_string()].push_back(one_con[1]);
		conn[one_con[1].std_string()].push_back(one_con[0]);
	}

	// Solve for the total number of paths
	std::vector<std::vector<pyStr>> all_paths;
	std::vector<pyStr> start = { pyStr("start") };
	all_paths.push_back(start);
	ExplorePathsPart2(conn, pyStr("start"), all_paths);

	// Only get the complete paths
	int sol = 0;
	for (auto& path : all_paths)
	{
		if (path[path.size() - 1] == pyStr("end") && path[0] == pyStr("start"))
			sol += 1;
	}

	std::cout << "Solution 12b = " << sol << std::endl;
}