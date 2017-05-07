/*
Main.cpp

AUTHOR:			Tim Andrew
DATE:			April 11th, 2016
CLASS:			PROG2400-701 - Assignment #5
INSTRUCTOR:		Hal O'Connell
DESCRIPTION:	A driver program for Assignment 4
This program will allow the user to build a dynamic array
and then will time the sorts.
*/
#include <iostream>
#include <fstream>
#include <string>
#include <conio.h>

#include "Hash.h"
//#include "BinarySearchTree.h"

using namespace std;

int main()
{
	time_t timeTaken;
	time_t start;
	time_t stop;
	
	cout << "Tim Andrew (W0212032@nscc.ca) C++ Assignment #5" << endl << flush;
	cout << "-----------------------------------------------" << endl << flush;

	
/*PART1*/
	cout << "Part 1: Hashing :" << endl << flush;
	cout << "\tPress any key to read the dictionary into the HashTable.\n"<< flush;
	_getch();
	cout << "\t\tReading/building...\n";

		//set up a new hash:
	Hash hash;
	//cout << hash.PrintHash();

		//some variables to handle file locations:
	string dictionary = "dictionary.txt";
	string document = "mispelled.txt";

	//set up a var to handle the reading of each dictionary word:
	string dictionaryWord;

		//set up an input stream for the dictionary:
	fstream dictionaryInput;
		//open it:
	dictionaryInput.open(dictionary, ios::in);

	if (dictionaryInput) 
	{
			//loop while there is input:
		while (dictionaryInput >> dictionaryWord)
		{

				//add the word to the bst:
			hash.insert(dictionaryWord);
		}
	}
		//end reading and close file:
	dictionaryInput.close();

	cout << "\tHash Table read!\nPress any key to display the HashTable..." << flush;
	_getch();
	cout << endl << endl;

	//print it out:
	cout << hash.PrintHash() << endl << endl;
	cout << "\tPress any key to display the dictionary errors in " << document << "..." << flush;
	_getch();
	cout << endl << endl;

	//set up a var to handle the reading of each dictionary word:
	string documentWord;

		//set up a variable to build the error list:
	string errorList = "  Spelling errors in " + document + ":\n\n";
	int wordCount = 0;

		//set up an input stream for the dictionary:
	fstream documentInput;
		//open it:
	documentInput.open(document, ios::in);

	if (documentInput)
	{
		//parse the input and strip  it of puncutation.
		//loop while there is input:
		while (documentInput >> documentWord)
		{
			string checkWord = "";
			for (char& c : documentWord)
					//skip if the char is not alpha or is blank:
				if (!isalpha(c) || isblank(c))
					continue;
				else
					checkWord += tolower(c);

			++wordCount;

				//search if word isn't emppty and doesn't exist:
			if (!checkWord.empty() && !hash.search(checkWord))
			{
					//append it:
				errorList += "Word " + to_string(wordCount) + ": " + checkWord + "\n";
			}
		}
	}
	//end reading and close file:
	documentInput.close();

		//display word errors:
	cout << errorList;
	

	
	cout << endl << endl << "\tThat's it!  Press any key to quit!" << flush;
	_getch();
	return 0;
}