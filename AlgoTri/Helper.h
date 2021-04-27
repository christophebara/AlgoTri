#pragma once


#ifndef HELPER_H
#define HELPER_H

#include <string>
#include <fstream>
#include <iostream>

using namespace std;

// template class to manage to kind of std::set with less r greater compare
// Get words from a file into a set to be sort
// Display words sorted by te set
template<typename DATA>
class Helper
{
public:
	Helper() {};

	DATA GetData(string fileName) {
		DATA retVal;
		ifstream file;
		file.open(fileName);
		if (!file.is_open())
		{
			cout << "error while opening file";
		}
		else
		{
			string word;
			while (file >> word)
			{
				retVal.insert(word);
			}

			file.close();
		}

		return retVal;
	};

	void Display(DATA val)
	{
		for (typename DATA::iterator it = val.begin(); it != val.end(); it++)
		{
			cout << (*it) << "\n";
		}
	}
};
#endif
