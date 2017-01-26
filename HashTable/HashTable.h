#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <string>
#include <stdlib.h>
#include <string.h>
#include <list>
#include <iostream>

using namespace std;

struct itemNode
{
	string name;
	string team;
	itemNode *next;
};

struct item
{
	int count;
	itemNode *Table;
};

class HashTable
{
	private : 
	
	int num;
	item *Hash;
	
	itemNode **Hash2;
	
	public : 
	int Hashing(string);
	HashTable(int);
	void Print();
	void AddItem(string,string);
	string Search(string);
	
};

#endif
