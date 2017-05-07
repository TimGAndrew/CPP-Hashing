/*
Hash.h

AUTHOR:			Tim Andrew
DATE:			April 11th, 2016
CLASS:			PROG2400-701 - Assignment #5
INSTRUCTOR:		Hal O'Connell
DESCRIPTION:	The Hash Class Header File
*/
#include <string>

using namespace std;


#ifndef HASH_H
#define HASH_H

class Hash
{
private:
	static const int TableSize = 53;
	int Collisions = 0;

		//a node structure:
	struct Node {
		string word;
		Node* next;
	};
		//set up a node array:
	Node* HashTable[TableSize];

public:
	Hash();
	int hash(string key);
	int NumberOfBucketItems(int index);
	bool search(string data);
	void insert(string data);
	string PrintHash();
	string PrintHashItem(int index);
};

#endif
