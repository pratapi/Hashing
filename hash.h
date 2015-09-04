#include <iostream>
#include <string>

using namespace std;

#ifndef HASH_H
#define HASH_H

class hash_h {

public:
	hash_h();
	int HASH(string key);
	void AddItem(string name, string drink);
	int NumberOfItemsInIndex(int index);
	void PrintTable();
	void PrintItemsInIndex(int index);
	void FindDrink(string name);
	void RemoveItem(string name);

private:
	static const int tableSize = 40;

	struct item {
		string name;
		string drink;
		item* next;
	};

	item * HashTable[tableSize];
};

#endif
