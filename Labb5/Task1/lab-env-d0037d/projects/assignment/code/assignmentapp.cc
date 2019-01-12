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
AssignmentApp::RemoveShapes(const type_info & type)
{
	for (Shape *s : renderQueue)
	{
		if (typeid(*s) == type && s->destructuble)						// Matching shapes that is destructable
		{
			s->destroyed = true;
		}
	}
}
//------------------------------------------------------------------------------
/**
*/
void 
AssignmentApp::CleanRenderQueue()
{
	std::vector<Shape*> tmpQueue;

	for (Shape *s : renderQueue) {
		if (s->destroyed) {
			delete(s);
		}
		else
		{
			tmpQueue.push_back(s);
		}
	}
	renderQueue = tmpQueue;
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
			Shape* square = new Square(0.1f);
			renderQueue.push_back(square);
			break;
		}
		case 50:		// 2
		{
			Shape* circle = new Circle(0.1f);
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
			RemoveShapes(typeid(Square));
			break;
		}
		case 87:		// W
			RemoveShapes(typeid(Circle));
			break;
		case 69:		// E
			RemoveShapes(typeid(Triangle));
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

	Circle* ball = new Ball();
	renderQueue.push_back(ball);

	Shape* squareA = new Square(0.1f);
	renderQueue.push_back(squareA);

	Shape* squareB = new Square(0.1f);
	renderQueue.push_back(squareB);

	Shape* squareC = new Square(0.1f);
	renderQueue.push_back(squareC);

	Shape* circleA = new Circle(0.1f);
	renderQueue.push_back(circleA);

	Shape* circleB = new Circle(0.1f);
	renderQueue.push_back(circleB);

	Shape* circleC = new Circle(0.1f);
	renderQueue.push_back(circleC);

	Shape* triangleA = new Triangle(0.2f, 0.25f);
	renderQueue.push_back(triangleA);

	Shape* triangleB = new Triangle(0.2f, 0.25f);
	renderQueue.push_back(triangleB);

	Shape* triangleC = new Triangle(0.2f, 0.25f);
	renderQueue.push_back(triangleC);
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
		s->distanceToBall(renderQueue[0]);
	}
	CleanRenderQueue();
}

} // namespace Assignment
