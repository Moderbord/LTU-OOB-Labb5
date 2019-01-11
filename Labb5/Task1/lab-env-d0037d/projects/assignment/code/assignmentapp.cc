//------------------------------------------------------------------------------
// assignmentapp.cc
// (C) 2015-2017 Individual contributors, see AUTHORS file
//------------------------------------------------------------------------------
#include "config.h"
#include "assignmentapp.h"
#include "Shape.h"
#include <typeinfo>

namespace Assignment
{

//------------------------------------------------------------------------------
/**
*/
AssignmentApp::AssignmentApp()
{
	// empty
}

//------------------------------------------------------------------------------
/**
*/
AssignmentApp::~AssignmentApp()
{
	// empty
}

//------------------------------------------------------------------------------
/**
*/
void
AssignmentApp::ClearByShape(const type_info & type)
{
	std::vector<Shape*> tmp;

	for (Shape *s : renderQueue)
	{
		if (typeid(*s) != type)
		{
			tmp.push_back(s);
		}
		else
		{
			delete(s);
		}
	}
	renderQueue = tmp;
}
//------------------------------------------------------------------------------
/**
*/
void
AssignmentApp::KeyEvent(int key, int action, int modifier)
{
	// does something with the key. action == 1 means key has been pressed
	// action == 0 means it was released
	if (action)
	{
		switch (key)
		{
		case 49:		// 1
		{ 
			Shape* square = new Square(0.15f);
			renderQueue.push_back(square);
			break;
		}
		case 50:		// 2
		{
			Shape* circle = new Circle(0.2f);
			renderQueue.push_back(circle);
			break;
		}
		case 51:		// 3
		{
			Shape* triangle = new Triangle(0.2f, 0.25f);
			renderQueue.push_back(triangle);
			break;
		}
		case 81:		// Q
		{
			ClearByShape(typeid(Square));
			break;
		}
		case 87:		// W
			ClearByShape(typeid(Circle));
			break;
		case 69:		// E
			ClearByShape(typeid(Triangle));
			break;
		default:
			break;
		}
	}
}
//------------------------------------------------------------------------------
/**
*/
void 
AssignmentApp::Setup()
{
	Display::Window * window = this->GetWindow();
	window->SetKeyPressFunction(
			[this](int key, int, int action, int mod)
			{
				this->KeyEvent(key, action, mod);
			}
	);
}

//------------------------------------------------------------------------------
/**
*/
void
AssignmentApp::Update()
{
	for (auto *s : renderQueue)
	{
		s->updateShape();
		s->drawShape();
	}
}

} // namespace Assignment
