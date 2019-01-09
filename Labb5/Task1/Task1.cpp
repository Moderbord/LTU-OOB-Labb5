#include "pch.h"
#include "Button.h"
#include <iostream>
#include <cmath>
#include <string>

namespace
{
	using std::cout;
	using std::endl;
	using std::cin;
	using std::string;
}

void callback(Button *btn);
void powerOf(Button *btn);
void alduinHotness(Button *btn);

int main()
{
	Button a;
	a.createButton(&alduinHotness, "Yeah baby", 3);

	/*void(*function)(int);
	function = &alduinHotness;
	function(3);*/

	Button b;
	b.createButton(&alduinHotness, "Click me!", 1);
	//b.clickButton();

	/*Button c;
	c.createButton(&callback, "This is text");
	c.clickButton();*/

	auto lambda = [&a, &b] { a.clickButton(); cout << "Swapping function.." << endl; b.clickButton(); };
	lambda();
}

void callback(Button *btn)
{
	cout << "Button was clicked: " << btn->getText() << endl;
}

void powerOf(Button *btn)
{
	cout << pow(2, btn->getInt());
}

void alduinHotness(Button *btn)
{
	cout << "Dragon button was clicked.." << endl;

	switch (btn->getInt())
	{
	case 0:
		cout << "Gray and dull" << endl;
		break;
	case 1:
		cout << "Large and intimidating" << endl;
		break;
	case 2:
		cout << "Speckled but fair" << endl;
		break;
	case 3:
		cout << "Rough but handsome" << endl;
		break;
	default:
		cout << "A dragon is a dragon.." << endl;
		break;
	}
}