#pragma once
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Unit
{
protected:
	string name;
	int attack;
public:
	string& Name() { return name; }
	Unit(string name) : name{ name }, attack{} {}
	virtual string ToString()
	{
		return "Unit: " + name + " " + to_string(Attack());
	}

	virtual int Attack()
	{
		return attack;
	}

	virtual ~Unit() {};
};

// abstract interface Factory
class Factory
{
public:
	virtual Unit* CreateUnit() = 0;
	virtual ~Factory() {};
};

// Infantry
class InfantryUnit : public Unit
{
public:
	InfantryUnit() : Unit("Infantry") 
	{
		attack = 2;
	}
};

class InfantryFactory : public Factory
{
public:
	Unit* CreateUnit() override
	{
		return new InfantryUnit();
	}
};

// Archer
class ArcherUnit : public Unit
{
public:
	ArcherUnit() : Unit("Archer") 
	{
		attack = 5;
	}
};

class ArcherFactory : public Factory
{
public:
	Unit* CreateUnit() override
	{
		return new ArcherUnit();
	}
};

// Cavalry
class CavalryUnit : public Unit
{
public:
	CavalryUnit() : Unit("Cavalry") 
	{
		attack = 7;
	}
};

class CavalryFactory : public Factory
{
public:
	Unit* CreateUnit() override
	{
		return new CavalryUnit();
	}
};

class UnitGroup : public Unit
{
	vector<Unit*> group;
public:
	UnitGroup(string name) : Unit(name) {}
	int Attack() override
	{
		int attackFull = 0;
		for (Unit* item : group)
			attackFull += item->Attack();
		return attackFull;
	}

	string ToString() override
	{
		string str = Unit::ToString() + "\n";
		for (Unit* unit : group)
			str += "\t" + unit->ToString() + "\n";
		//str += "Total attack: " + to_string(Attack());
		return str;
	}

	void Add(Unit* unit)
	{
		group.push_back(unit);
	}
};

