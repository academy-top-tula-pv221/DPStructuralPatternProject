#pragma once
#include <iostream>
#include <map>
using namespace std;

class BookBad
{
	string title;
	string authorFirstName;
	string authorLastName;
public:
	BookBad(string title,
		string authorFirstName,
		string authorLastName)
		: title{ title },
		authorFirstName{ authorFirstName },
		authorLastName{ authorLastName } {}
	
};

class Author
{
	string authorFirstName;
	string authorLastName;
public:
	Author(string authorFirstName,
		string authorLastName)
		: authorFirstName{ authorFirstName },
		authorLastName{ authorLastName } {}
};

class BookGood
{
	string title;
	Author* author;
public:
	BookGood(string title, Author* author) 
		: title{ title }, author{ author } {};
};

class House
{
protected:
	int stages;
public:
	virtual void Build(double longitude, double latitude) = 0;
};

class PanelHouse : public House
{
public:
	PanelHouse()
	{
		this->stages = 9;
	}

	void Build(double longitude, double latitude) override
	{
		cout << "Panel house is build:\n";
		cout << "\tStages: " << stages << "\n";
		cout << "\tLongitude" << longitude << "\n";
		cout << "\tlatitude" << latitude << "\n";
	}
};

class BrickHouse : public House
{
public:
	BrickHouse()
	{
		this->stages = 5;
	}

	void Build(double longitude, double latitude) override
	{
		cout << "Brick house is build:\n";
		cout << "\tStages: " << stages << "\n";
		cout << "\tLongitude" << longitude << "\n";
		cout << "\tlatitude" << latitude << "\n";
	}
};

class HouseFactory
{
	map<string, House*> houses;
public:
	HouseFactory()
	{
		houses.insert(make_pair("Panel", new PanelHouse()));
		houses.insert(make_pair("Brick", new BrickHouse()));
	}

	House* GetHouse(string key)
	{
		if (houses.find(key) != houses.end())
			return houses[key];
		else
			return nullptr;
	}
};