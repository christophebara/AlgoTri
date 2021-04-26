// AlgoTri.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include <iostream>
#include <conio.h>
#include <string>
#include <fstream>
#include <set>
#include "Helper.h"


using namespace std;

// Display How AlgoTri has to be used
void UseCase()
{
	cout << "AlgoTri using\n";
	cout << "AlgoTri.exe <word1> word<2> ... \n";
	cout << "AlgoTri.exe -inverse  <word1> word<2> ...\n";
	cout << "AlgoTri.exe -file <filename> \n";
	cout << "AlgoTri.exe -inverse -file <filename>\n";
}

int ExitWithCode(int code)
{
	if (code != 0)
	{
		UseCase();
	}

	cout << "Press key to exit from application";
	_getch();

	return code;
}



int main(int argc, char *argv[])
{
	string fileName;
	bool inverse = false;
	
	switch (argc)
	{
		case 1:
		{
			cout << "Argumentq list must contain at least one word or -file <filename>.\nThe -inverse optional parameter could be use to indicate an alphabetic sort\n";
			return ExitWithCode(-1);
		}
		case 2:
		{
			if (string(argv[1]).substr(0, 1) != "-")
			{
				// There is only one word to sort then
				return ExitWithCode(0);
			}
			else
			{
				cout << "Argument list eror\n";
				return ExitWithCode(-1);
			}
		}
		break;
		case 3:
		{
			if (string(argv[1]).substr(0, 1) != "-")
			{
				set<string> retVal;
				retVal.insert(argv[1]);
				retVal.insert(argv[2]);

				for (set<string>::iterator it = retVal.begin(); it != retVal.end(); it++)
				{
					cout << (*it) << "\n";
				}
				return ExitWithCode(0);
			}

			if ((string(argv[1]) == "-file" && string(argv[2]) == "-inverse") || (string(argv[1]) == "-inverse" && string(argv[2]) == "-file"))
			{

				cout << "Argument list eror\n";
				cout << "the argument list has to be called with -file <filename>\n";
				return ExitWithCode(-1);
			}
			else if (argv[1] == "-inverse")
			{
				// There is only one word to sort then
				cout << argv[2];
				return ExitWithCode(0);
			}
			else if (string(argv[1]) == "-file")
			{
				fileName = argv[2];
			}
		}
		break;
		default:
		{
			if (string(argv[1]).compare("-inverse")==0)
			{
				inverse = true;
				if (string(argv[2]).compare("-file")==0)
				{
					fileName = string(argv[3]);
				}
			}
			else
			{
				if (string(argv[1]).compare("-file")==0)
				{
					fileName = argv[2];
				}

				if (string(argv[3]) == "-inverse")
				{
					inverse = true;
				}
			}
		}
	}

	if (inverse)
	{
		set <string, greater<string>> InvRetVal;
		Helper<set <string, greater<string>>> helper;

		if (fileName.length() > 0)
		{
			
			InvRetVal = helper.GetData(fileName);
		}
		else
		{
			for (int i = 2; i < argc; i++)
			{
				InvRetVal.insert(argv[i]);
			}
		}
		//display
		helper.Display(InvRetVal);
	}
	else
	{
		set <string> RetVal;
		Helper<set<string>> helper;
		if (fileName.length() > 0)
		{
			RetVal = helper.GetData(fileName);
		}
		else
		{
			for (int i = 2; i < argc; i++)
			{
				RetVal.insert(argv[i]);
			}
		}
		//display
		helper.Display(RetVal);
	}

	return ExitWithCode(0);
}




