#pragma once
#include <iostream>
using namespace std;

class TextEditor
{
public:
	void CreateCode(string& code)
	{
		code = "new.cpp";
		cout << "witing code\n";
	}
	string Save(string& code)
	{
		code = "prog.cpp";
		cout << "save code\n";
		return code;
	}
};

class Compiller
{
public:
	string Compile(string& code)
	{
		cout << "compile code to execute app\n";
		return "prog.exe";
	}
};

class Debugger
{
public:
	void Step(string& code)
	{
		cout << "execute step of code\n";
	}
	string Save(string& code)
	{
		cout << "save debugging code\n";
		return code;
	}
};

class RunTime
{
public:
	void Execute(string app)
	{
		cout << "execute of app: " << app << "\n";
	}
	int Finish(string app)
	{
		cout << "Finish of app: " << app << "\n";
		return 0;
	}
};


class VisualStudioFacade
{
	TextEditor* editor;
	Compiller* compiller;
	Debugger* debugger;
	RunTime* runtime;

	string code;
	string app;
public:
	VisualStudioFacade(TextEditor* editor,
						Compiller* compiller,
						Debugger* debugger,
						RunTime* runtime)
		: editor{ editor },
		compiller{ compiller },
		debugger{ debugger },
		runtime{ runtime } {};
	void Start()
	{
		editor->CreateCode(code);
		code = editor->Save(code);
		app = compiller->Compile(code);
		debugger->Step(code);
		debugger->Save(code);
		app = compiller->Compile(code);
		runtime->Execute(app);
	}

	void Finish()
	{
		int code = runtime->Finish(app);
		cout << "error code: " << code << "\n";
	}
};

