#pragma once
#include "day4.h"
#include "Methods.h"
#include <bitset>
#include "pyStr.h"

void Day4::Problem4ab()
{
	for (int j = 0; j < 2; j++)
	{
		std::string file_in = "day4_in.txt";
		BingoBoards boards(5, 5);

		boards.FileLinesToStr(file_in);
		boards.GetCallNumbers();
		boards.ReadBoards();
		
		bool parta = true;
		if (j == 1)
			parta = false;

		Board winning_board = boards.FindWinningBoards(parta);

		int sum = 0;
		for (int i = 0; i < winning_board._data.size(); i++)
		{
			if (!winning_board._hits[i])
				sum += winning_board._data[i];
		}

		std::string string1 = "";
		if (j == 0)
			string1 = "Solution 4a = ";
		else
			string1 = "Solution 4b = ";
		std::cout <<  string1 << sum * winning_board._winning_number << std::endl;
	}
}


void BingoBoards::FileLinesToStr(std::string& file_name)
{
	std::string input_path = std::string(_SOLUTIONDIR) + "AdventOfCoding2021\\" + file_name;

	std::ifstream infile(input_path);

	std::string line;
	while (std::getline(infile, line)) 
		raw_input_data.push_back(pyStr(line));
}

void BingoBoards::GetCallNumbers()
{
	pyStr line1 = raw_input_data[0];
	std::vector<pyStr> calls = line1.split(",");
	call_numbers = PyStrVecToInt(calls);
}

void BingoBoards::ReadBoards()
{
	std::vector<int> board_data;
	std::string empty_str = " ";

	for (int i = 1; i < raw_input_data.size(); i++) {
		pyStr line = raw_input_data[i];
		if (line.std_string() == "")
		{
			if (board_data.size() > 0)
			{
				Board new_board(board_data, _num_rows, _num_cols);
				boards.push_back(new_board);
				board_data.clear();
			}
		}
		else
		{
			std::vector<pyStr> line_split = line.split(empty_str);
			std::vector<int> lines_int = PyStrVecToInt(line_split);
			for (int j = 0; j < lines_int.size(); j++)
				board_data.push_back(lines_int[j] );
		}
	}

	if (board_data.size() > 0)
	{
		Board new_board(board_data, _num_rows, _num_cols);
		boards.push_back(new_board);
		board_data.clear();
	}
}

Board::Board(std::vector<int> data, int rows, int cols) 
	: _rows(rows)
	, _cols(cols)
	, _data(data)
{
	for (int i = 0; i < rows * cols; i++)
		_hits.push_back(false);
}

std::vector<int> Board::GetRow(int j)
{
	std::vector<int> row;
	int start_idx = _cols*(j);
	for (int i = start_idx; i < start_idx+_cols; i++){
		row.push_back(_data[i]);
	}
	return row;
}

bool Board::RowWins(int j)
{
	int start_idx = _cols * (j);
	for (int i = start_idx; i < start_idx + _cols; i++)
	{
		if (!_hits[i])
			return false; // not a row winner
	}
	return true; // winner!
}

std::vector<int> Board::GetColumn(int j)
{
	std::vector<int> col;
	for (int i = j; i < j + _rows * _cols; i += _rows) {
		col.push_back(_data[i]);
	}
	return col;
}

bool Board::ColWins(int j)
{
	for (int i = j; i < j + _rows * _cols; i += _rows) {
		if (!_hits[i])
			return false; // not a column winner
	}
	return true; // winner!
}

int Board::GetEntry(int row, int col)
{
	return _data[row * (_rows - 1) + (col - 1)];
}

std::vector<int> BingoBoards::PyStrVecToInt(std::vector<pyStr> vec_pys)
{
	std::vector<int> vec_ints;
	for (int i = 0; i < vec_pys.size(); i++)
		vec_ints.push_back(atoi(vec_pys[i].std_string().c_str()));
	return vec_ints;
}

BingoBoards::BingoBoards(int num_cols, int num_rows)
	: _num_cols(num_cols)
	, _num_rows(num_rows)
{}

Board BingoBoards::FindWinningBoards(bool parta)
{
	std::vector<int> remove_at_j;
	Board partb_winning_board;
	for (int i = 0; i < call_numbers.size(); i++)
	{ // A number is called. Players check your boards for a hit
		int call_number = call_numbers[i];

		if (!parta)
		{ // Remove winning boards
			std::vector<Board> board_minus_j;
			for (int ijk = 0; ijk < boards.size(); ijk++)
			{ // for every board on the existing board
				bool remove = false;
				for (int w = 0; w < remove_at_j.size(); w++)
				{ // loop through indexes to remove, w
					if (remove_at_j[w] == ijk) {
						// remove this board. It won already
						remove = true;
						break;
					}
				}
				if (!remove)
					board_minus_j.push_back(boards[ijk]);
			}
			boards = board_minus_j;
			remove_at_j.clear();
		}

		for (int j = 0; j < boards.size(); j++)
		{ // Player j is selected
			Board *board_j = &boards[j];

			for (int k = 0; k < board_j->_data.size(); k++)
			{ // Player j checks every number on their board
				if (board_j->_data[k] == call_number)
				{ // The player has a hit. Mark as a hit and check for win
					board_j->_hits[k] = true;
					if (board_j->won())
					{   // Player j wins! Return the winning board
						board_j->_winning_number = call_number;
						if (parta)
							return *board_j;
						else 
						{ // remove this board from the set for part b. We know this is a winner.
							remove_at_j.push_back(j);
							partb_winning_board = *board_j;
						}
					}
				}

			}
		}

	}
	return partb_winning_board; // part b solution is the last one
}

bool Board::won()
{
	for (int i = 0; i < _rows; i++)
	{ // check if any row is full of hits
		if (RowWins(i))
			return true; // winner!
	}

	for (int i = 0; i < _cols; i++)
	{ // check if any column is full of hits
		if (ColWins(i))
			return true; // winner!
	}

	return false; // this board is not a winner yet
}