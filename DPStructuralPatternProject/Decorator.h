#pragma once
#include <iostream>

using namespace std;

class IMessage
{
protected:
	string text;
	string from;
	string to;
public:
	IMessage()
	{
		text = "Example message. Hello world";
		from = "Foma";
		to = "Erema";
	}
	virtual string& Text() { return text; }
	virtual string& From() { return from; }
	virtual string& To() { return to; }
	virtual void Send() = 0;
};

class MessangerMessage : public IMessage
{
	string smile;
public:
	MessangerMessage()
	{
		smile = ":-)";
	}
	string& Smile() { return smile; }
	void Send() override
	{
		cout << "Messanger send from: " << from
			<< "\nto: " << to << "\ntext: " << text 
			<< "\n" << smile << "\n";
	}
};

class EmailMessage : public IMessage
{
	string subject;
public:
	EmailMessage()
	{
		subject = "my message";
	}
	string& Subject() { return subject; }
	void Send() override
	{
		cout << "Email send from: " << from
			<< "\nto: " << to
			<< "\nsubject: " << subject
			<< "\ntext: " << text
			<< "\n";
	}
};

class IMessageDecorator : public IMessage
{
protected:
	IMessage* message;
public:
	IMessageDecorator(IMessage* message) : message{ message } {}
};

class FileMessage : public IMessageDecorator
{
	string file;
public:
	FileMessage(IMessage* message, string file)
		: IMessageDecorator(message), file{ file } {}
	void Send() override
	{
		message->Send();
		cout << "with file: " << file << "\n";
	}
};

class ContactMessage : public IMessageDecorator
{
	string contact;
public:
	ContactMessage(IMessage* message, string contact)
		: IMessageDecorator(message), contact{ contact } {}
	void Send() override
	{
		message->Send();
		cout << "with contact: " << contact << "\n";
	}
};