#pragma once
#include <iostream>

class Button
{
private:
	const char *text;
	int i;
	void(*callback_function)(Button *);

public:
	void createButton(void(*callback_function)(Button *), const char *text)
	{
		this->callback_function = callback_function;
		this->text = text;
	}
	void createButton(void(*callback_function)(Button *), const char *text, int i)
	{
		this->callback_function = callback_function;
		this->text = text;
		this->i = i;
	}
	void clickButton()
	{
		std::cout << "Emulating button cluck.." << std::endl;
		callback_function(this);
	}
	const char* getText()
	{
		return text;
	}
	int getInt()
	{
		return i;
	}
};