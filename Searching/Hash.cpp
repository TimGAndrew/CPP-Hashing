/*
Hash.cpp

AUTHOR:			Tim Andrew
DATE:			April 11th, 2016
CLASS:			PROG2400-701 - Assignment #5
INSTRUCTOR:		Hal O'Connell
DESCRIPTION:	The Hash Class
*/
#include "Hash.h"

Hash::Hash() 
{
	for (int i = 0; i < TableSize; i++)
	{
		HashTable[i] = new Node;
		HashTable[i]->word = "";
		HashTable[i]->next = NULL;
	}
}

	//return the hash for the string
int Hash::hash(string key) 
{
	int hash = 0;
	int index;

	for (int i = 0; i < key.length(); ++i) 
	{
			//add the hash values for the key:
		hash += (int)key[i];
	}

		//get remainder from hash function stored as index;
	index = hash % TableSize;

	return index;
}

	//get the number of bucket (collision items)
int Hash::NumberOfBucketItems(int index)
{
		//set up a counter
	int count = 0;

		//if there is a word:
	if (HashTable[index]->word != "")
	{
			//set this pointer as that words pointer:
		Node* pointer = HashTable[index];

			//count the # of elements in that linked list:
		while (pointer->next != NULL)
		{
			++count;
				//increment the pointer:
			pointer = pointer->next;
		}
	}

		
	return count;
		
}

	//search the hashtable for a string
bool Hash::search(string word) 
{
		//hash in the data
	int index = hash(word);

	bool foundWord = false;

	Node* pointer = HashTable[index];

		//search it here:
	while (pointer != NULL)
	{
		if (pointer->word == word)
		{
			foundWord = true;
			break;
		}
		pointer = pointer->next;
	}
	return foundWord;
}

	//a function to insert a node:
void Hash::insert(string word)
{
	//find the index size of the word:
	int index = hash(word);

		//if the hash doesn't have a word:
	if (HashTable[index]->word == "")
	{
		HashTable[index]->word = word;
	}
		//otherwose create an item to add to the end:
	else
	{
		Node* node = HashTable[index];
		Node* newNode = new Node;
		newNode->word = word;
		newNode->next = NULL;

			//find the end of the list:
		while (node->next != NULL)
		{
			node = node->next; 
		}
			//plug the new node in it:
		node->next = newNode;
	}

}

string Hash::PrintHash()
{
	int number;
	int totalCollisions = 0;
	string hashPrintOut = "HashTable:\n";

	for (int i = 0; i < TableSize; ++i)
	{
		number = NumberOfBucketItems(i);
		hashPrintOut += "----[" + to_string(i) + "]";
		if (number > 0)
			hashPrintOut += " (Collisions: " + to_string(number) + ")";
		totalCollisions += number;
		hashPrintOut+="----\n";
		hashPrintOut += PrintHashItem(i);

	}
	hashPrintOut += "Total Collisions: " + to_string(totalCollisions) + "\n";

	return hashPrintOut;
}

	//method to print out the items of a hash (the collisions)
string Hash::PrintHashItem(int index)
{
	string hashPrintOut = "";

	Node* node = HashTable[index];

	if (node->word != "")
	{
		while (node != NULL)
		{
			hashPrintOut += "\t" + node->word;
			node = node->next;
		}
	}
	hashPrintOut += "\n";

	return hashPrintOut;
}