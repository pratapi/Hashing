#include <iostream>
#include <string>
#include "hash.h"
using namespace std;

int main()
{
	hash_h Hashy;
	string name = "";

	Hashy.AddItem("Paul", "Locha");
	Hashy.AddItem("Kim", "Iced Mocha");
	Hashy.AddItem("Emma", "Strawberry Smoothy");
	Hashy.AddItem("Annie", "Hot Choclate");
	Hashy.AddItem("Sarah", "Passion Tea");
	Hashy.AddItem("Pepper", "Charmel Mocha");
	Hashy.AddItem("Mike", "Chai Tea");
	Hashy.AddItem("Steve", "Apple Cider");
	Hashy.AddItem("Bill", "Root Beer");
	Hashy.AddItem("Marie", "Skinny Latte");
	Hashy.AddItem("Susan", "Water");
	Hashy.AddItem("Joe", "Green Tea");

	Hashy.PrintTable()

	// Searching Operation
	while (name != "exit")
	{
		printf("Search for ");
		cin >> name;
		if (name != "exit")
		{
			Hashy.FindDrink(name);
		}

	}

	// Remove Operation
	while (name != "exit")
	{
		printf("Remove ");
		cin >> name;
		if (name != "exit")
		{
			Hashy.RemoveItem(name);
		}

	}

	Hashy.PrintTable();

	return 0;
}
