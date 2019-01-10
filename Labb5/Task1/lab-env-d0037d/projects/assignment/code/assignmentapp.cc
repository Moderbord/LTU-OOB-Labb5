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
	if (!action)
	{
		switch (key)
		{
		case 49:		// 1
		{ 
			Shape* square = new Square(0.3f);
			renderQueue.push_back(square);
			break;
		}
		case 50:		// 2
		{
			Shape* circle = new Circle(0.5f);
			renderQueue.push_back(circle);
			break;
		}
		case 51:		// 3
		{
			Shape* triangle = new Triangle(0.4f, 0.5f);
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

	ExtMatrix2D main;
	ExtMatrix2D sub;

	main * sub;


}

//------------------------------------------------------------------------------
/**
*/
void
AssignmentApp::Update()
{
	/*renderQueue[0]->updateShapeRotation(0.08f);
	renderQueue[0]->updateShapePosition(0.002f, 0.001f);

	renderQueue[1]->updateShapeRotation(4.4f);
	renderQueue[1]->updateShapePosition(-0.002f, 0.0f);

	renderQueue[2]->updateShapeRotation(-1.4f);
	renderQueue[2]->updateShapePosition(0.002f, -0.002f);*/

	for (auto *s : renderQueue)
	{
		s->drawShape();
	}
}

} // namespace Assignment
