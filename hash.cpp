#include <iostream>
#include <string>
#include "hash.h"

using namespace std;

hash_h::hash_h()
{
	for (int i = 0; i < tableSize ; i++)
	{
		HashTable[i] = new item;
		HashTable[i]->name = "empty";
		HashTable[i]->drink = "empty";
		HashTable[i]->next = nullptr;
	}
}

int hash_h::HASH(string key)
{
	int hash = 0, index = 0;

	for (int i = 0; i < key.length(); i++) {
		hash = (hash + (int)key[i]) * 17;
	}

	index = hash % tableSize;

	return index;
}

void hash_h::AddItem(string name, string drink)
{
	int index = HASH(name);
	
	if (HashTable[index]->name == "empty")
	{
		HashTable[index]->name = name;
		HashTable[index]->drink = drink;
	}
	else
	{
		item* ptr = HashTable[index];
		item* tmp = new item;
		tmp->name = name;
		tmp->drink = drink;
		tmp->next = NULL;
		while (ptr->next != NULL)
		{
			ptr = ptr->next;
		}
		ptr->next = tmp;
	}
}

int hash_h::NumberOfItemsInIndex(int index)
{
	int count = 0;

	if (HashTable[index]->name == "empty")
	{
		return count;
	}
	else
	{
		count++;
		item* ptr = HashTable[index];
		while (ptr->next != NULL)
		{
			ptr = ptr->next;
			count++;
		}
		return count;
	}
}

void hash_h::PrintTable()
{
	int number;

	for (int i = 0; i < tableSize; i ++)
	{
		number = NumberOfItemsInIndex(i);
		printf("-------------\n");
		printf("index = %d\n", i);
		printf("%s\n", (HashTable[i]->name).c_str());
		printf("%s\n", (HashTable[i]->drink).c_str());
		printf(" # of items = %d\n", number);
	}
}

void hash_h::PrintItemsInIndex(int index)
{
	item* tmp = HashTable[index];
	
	if (tmp->name == "empty")
	{
		printf("index %d is empty\n", index);
	}
	else
	{
		printf("index %d contains the following items \n", index);
		while (tmp != NULL)
		{
			printf("-------------\n");
			printf("%s\n", (tmp->name).c_str());
			printf("%s\n", (tmp->drink).c_str());
			tmp = tmp->next;
		}
	}
}

void hash_h::FindDrink(string name)
{
	int index = HASH(name);
	bool foundName = false;
	string drink;

	item* tmp = HashTable[index];

	while (tmp != nullptr)
	{
		if (tmp->name == name.c_str())
		{
			foundName = true;
			drink = tmp->drink;
		}
		tmp = tmp->next;
	}

	if (foundName)
	{
		printf("Favorite drink = %s\n", drink.c_str());
	}
	else
	{
		printf("%s was not found in Hash Table \n", name.c_str());
	}
}

void hash_h::RemoveItem(string name)
{
	int index = HASH(name);

	item* delPtr;
	item* ptr_1;
	item* ptr_2;

		// case 1 - Bucket is Empty
	if (HashTable[index]->name == "empty" && HashTable[index]->drink == "empty")
	{
		printf("%s was not found in the hash table\n", name.c_str());
	}	// case 2 - only 1 item contain in bucket and that has matching name
	else if (HashTable[index]->name == name && HashTable[index]->next == NULL)
	{
		HashTable[index]->name = "empty";
		HashTable[index]->drink = "empty";
		printf("%s was removed from hash table", name.c_str());
	}	// case 3 - there match but there are more item in the bucket;
	else if (HashTable[index]->name == name)
	{
		delPtr = HashTable[index];
		HashTable[index] = HashTable[index]->next;
		delete delPtr;
		printf("%s was removed from hash table", name.c_str());
	}	// case 4 -  bucket does contain item but first item is not a match
	else
	{
		ptr_1 = HashTable[index]->next;
		ptr_2 = HashTable[index];

		while (ptr_1 != NULL && ptr_1->name != name)
		{
			ptr_2 = ptr_1;
			ptr_1 = ptr_1->next;
		}

		if (ptr_1 == NULL)
		{
			printf("%s was not found in the hash table\n", name.c_str());
		}
		else
		{
			delPtr = ptr_1;
			ptr_1 = ptr_1->next;
			ptr_2->next = ptr_1;
			delete delPtr;

			printf("%s was removed from hash table", name.c_str());
		}
	}
}
