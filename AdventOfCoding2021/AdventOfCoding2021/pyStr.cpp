# pragma once

# include "pyStr.h"
# include <vector>
# include <string>
# include <unordered_map>

pyStr::pyStr(std::string str) // constructor
	: _str(str)
{}

pyStr::pyStr(char ch) // constructor
{
	_str = ch;
}

pyStr::pyStr() // default constructor
	: _str("")
{}

std::string pyStr::std_string() // convert back to std::string
{
	return _str;
}

void pyStr::init(std::string str) // assign an std::string to initialize
{
	_str = str;
}

/////////////////////////////////////////
// Replicated Python string functions: //
/////////////////////////////////////////

pyStr pyStr::operator+(pyStr& s) // add two pyStrs
{
	return std_string() + s.std_string();
}

int pyStr::len() // length - size of pyStr
{
	return (int) std_string().size();
}

pyStr pyStr::substr(int start, int end) // equivalent to string[start:end] in python
{
	std::string subString = "";
	for (int i = 0; i < len(); i++)
	{
		if (i >= start && i <= end)
			subString += _str[i];
	}

	return pyStr(subString);
}

pyStr pyStr::startat(int start) // equivalent to string[start:] in python
{
	std::string subString = "";
	if (start >= 0)
	{
		for (int i = start; i < len(); i++)
				subString += _str[i];
		return pyStr(subString);
	}
	else
	{
		return endat(-start);
	}
}

pyStr pyStr::endat(int end) // equivalent to string[:end] in python
{
	std::string subString = "";
	if (end >= 0)
	{
		for (int i = 0; i < end; i++)
			subString += _str[i];
		return pyStr(subString);
	}
	else
	{
		return startat(-end);
	}
}


std::vector<pyStr> pyStr::split(std::string split_at) // equivalent to python split
{
	std::vector<pyStr> split_return;
	std::string stack_chars;
	std::string _str_copy;

	int j = 0;
	int last_idx = 0;
	for (int i = 0; i < len(); i++) { // loop through all chars in _str
		if (split_at[j] == _str[i])
		{
			stack_chars += split_at[j];
			j += 1;

			if (stack_chars == split_at)
			{
				pyStr pyStr_str = pyStr(_str);
				split_return.push_back(pyStr_str.substr(last_idx, i - (int)split_at.size()));
				_str_copy = pyStr_str.startat(i + 1).std_string();

				last_idx = i+1;
				j = 0;
				stack_chars = "";

				if (_str_copy.size() == 0)
					return RemoveEmptyStrs(split_return);
			}
		}
		else
		{
			j = 0;
			stack_chars = "";
		}
		
	}
	if (split_return.size() != 0)
		split_return.push_back(pyStr(_str_copy));
	return RemoveEmptyStrs(split_return);
}

pyStr pyStr::at(int i) // returns value at index
{
	return pyStr(_str[i]);
}

pyStr pyStr::strip() // Not working yet
{
	pyStr stripped_str = pyStr(_str);
	std::unordered_map<std::string, bool> remove_chars;
	remove_chars["\t"] = true;
	remove_chars["\n"] = true;
	remove_chars[" "] = true;
	
	return stripped_str;
}

std::vector<pyStr> pyStr::RemoveEmptyStrs(std::vector<pyStr> in_vec)
{
	std::vector<pyStr> return_vec;
	for (int i = 0; i < in_vec.size(); i++) {
		if (in_vec[i].std_string() != "")
			return_vec.emplace_back(in_vec[i]);
	}
	return return_vec;

}