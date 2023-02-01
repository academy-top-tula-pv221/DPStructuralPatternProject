#pragma once
#include <vector>

using namespace std;

class IPlayer
{

};

class IImplementation
{
public:
	virtual void SetupImpl(vector<IPlayer*>&) = 0;
	virtual void StepImpl(vector<IPlayer*>) = 0;
	virtual void ShowImpl(vector<IPlayer*>) = 0;
	virtual bool ValidateImpl() = 0;
};

class IGame
{
protected:
	IImplementation* impl;
public:
	IGame(IImplementation* impl) : impl{ impl } {}
	virtual IImplementation*& Implementation() { return impl; }

	virtual void Setup() = 0;
	virtual void Step() = 0;
	virtual void Process() = 0;
	virtual bool Validate() = 0;
	virtual void Show() = 0;

	virtual ~IGame() {}
};




