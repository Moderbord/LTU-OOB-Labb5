//------------------------------------------------------------------------------
// assignmentapp.cc
// (C) 2015-2017 Individual contributors, see AUTHORS file
//------------------------------------------------------------------------------
#include "config.h"
#include "assignmentapp.h"
#include "Shape.h"

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
AssignmentApp::Setup()
{

	Shape* square = new Square(0.3f);
	renderQueue.push_back(square);

	Shape* circle = new Circle(0.5f);
	renderQueue.push_back(circle);

	Shape* triangle = new Triangle(0.4f, 0.5f);
	renderQueue.push_back(triangle);
}

//------------------------------------------------------------------------------
/**
*/
void
AssignmentApp::Update()
{
	renderQueue[0]->updateShapeRotation(0.08f);
	renderQueue[0]->updateShapePosition(0.002f, 0.001f);

	renderQueue[1]->updateShapeRotation(4.4f);
	renderQueue[1]->updateShapePosition(-0.002f, 0.0f);

	renderQueue[2]->updateShapeRotation(-1.4f);
	renderQueue[2]->updateShapePosition(0.002f, -0.002f);

	for (auto s : renderQueue)
	{
		s->drawShape();
	}
}

} // namespace Assignment
