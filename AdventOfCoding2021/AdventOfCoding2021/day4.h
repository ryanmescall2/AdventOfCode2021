#pragma once
#include "Methods.h"
#include "pyStr.h"
#include <bitset>

struct Day4
{
	Day4() {
		Problem4ab();
	};

	void Problem4ab();
	~Day4() {};
};

struct Board
{
	Board() {};
	Board(std::vector<int> data, int rows, int cols);

	std::vector<int> _data; // row major order
	std::vector<bool> _hits;
	int _rows;
	int _cols;
	int _winning_number;

	std::vector<int> GetRow(int j);
	std::vector<int> GetColumn(int j);
	bool RowWins(int j);
	bool ColWins(int j);
	int GetEntry(int row, int col);
	bool won();

	~Board() {};
};


struct BingoBoards
{
	BingoBoards() {};
	BingoBoards(int num_cols, int num_rows);

	int _num_cols;
	int _num_rows;
	std::vector<pyStr> raw_input_data;
	std::vector<int> call_numbers;
	std::vector<Board> boards;
	std::vector<Board> winning_boards;

	void FileLinesToStr(std::string& file_name);
	std::vector<int> PyStrVecToInt(std::vector<pyStr> vec_pys);
	void GetCallNumbers();
	void ReadBoards();
	Board FindWinningBoards(bool parta);
};

