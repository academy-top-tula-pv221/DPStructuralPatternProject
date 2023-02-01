#pragma once
#include <iostream>

#include "Bridge.h"

using namespace std;

class SPlayer : public IPlayer
{
	string name;
public:
	string& Name() { return name; }
};

class StrategyGame : public IGame
{
	vector<IPlayer*> players;

public:
	StrategyGame(IImplementation* impl) : IGame(impl) 
	{
		players.resize(2);
	}

	void Setup() override
	{
		impl->SetupImpl(players);
	}

	void Step() override
	{
		impl->StepImpl(players);
	}

	void Process() override
	{
		char ch;
		int step{ 0 };
		do {
			cout << " ============= " << ++step << " raund ===============\n";
			Step();
			Show();
		} while (Validate());
	}

	bool Validate() override
	{
		return impl->ValidateImpl();
	}

	void Show() override
	{
		impl->ShowImpl(players);
	}
};


class KeyboardImpl : public IImplementation
{
public:
	void SetupImpl(vector<IPlayer*>& players) override
	{
		cout << "console input\n";
		for (int i = 0; i < players.size(); i++)
		{
			players[i] = new SPlayer();

			cout << "input " << i + 1 << " player's name: ";
			cin >> ((SPlayer*)players[i])->Name();
		}
	}

	void StepImpl(vector<IPlayer*> players) override
	{
		cout << "console step\n";
		for (int i = 0; i < players.size(); i++)
			cout << i + 1 << " player step " << ((SPlayer*)players[i])->Name() << "\n";
	}

	void ShowImpl(vector<IPlayer*> players) override
	{
		cout << "console show\n";
		for (int i = 0; i < players.size(); i++)
			cout << "********" << i + 1 << " player " << ((SPlayer*)players[i])->Name() << "\n";
	}

	bool ValidateImpl() override
	{
		char ch;
		cout << "continue? <y/n>: ";
		cin >> ch;
		return ch != 'n';
	}
};