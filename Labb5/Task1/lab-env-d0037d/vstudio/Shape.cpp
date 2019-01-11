#include "config.h"
#include "../../projects/assignment/code/assignmentapp.h"
#include "Shape.h"

const float aspectRatio = (3.0f/4.0f);

// Shape
Shape::~Shape()
{
}

Square::~Square()
{
}

// Square
Square::Square(float s) : Shape(), size(s)
{
	colour.r = 1.0f;										// Sqaure is magenta
	//colour.r = randomColour();
	//colour.g = randomColour();
	//colour.b = randomColour();

	transform = transform.rotationMatrix(4.1f);
	velocity = Vector2D(0.001f, 0.001f);

	vertices[0] = Vector2D(-s, -s);							// Inits vertices
	vertices[1] = Vector2D(s, -s);
	vertices[2] = Vector2D(s, s);
	vertices[3] = Vector2D(-s, s);

};

void Square::updateShape()
{
	ExtMatrix2D rotation = transform.getRotation();
	for (Vector2D &v : vertices)
	{
		Vector2D rotationCenter = v - transform.getPosition();			// Moves vertice to center of rotation
		Vector2D newPosition = rotation * rotationCenter;				// Rotates vertice around point
		v = newPosition + transform.getPosition() + velocity;			// Returns vertice to new position
	}
	Vector2D curPos = transform.getPosition();
	transform.setPosition(curPos + velocity);
}

void Square::drawShape()									// Draw 
{
	Assignment::AssignmentApp::LineData line;				// Line
	line.c1 = colour;										// Colour
	line.c2 = colour;

	for (int i = 0; i < 4; i++)								// Creates lines from vertices
	{
		line.x1 = vertices[i].getX() * aspectRatio;			// Takes aspect ratio into account
		line.y1 = vertices[i].getY();
		line.x2 = vertices[i + 1].getX() * aspectRatio;
		line.y2 = vertices[i + 1].getY();

		if (i == 3)											// Last vertice connects to the first one
		{
			line.x2 = vertices[0].getX() * aspectRatio;
			line.y2 = vertices[0].getY();
		}

		Assignment::AssignmentApp::DrawLine(line);
	}
};

Triangle::~Triangle()
{
}

// Triangle
Triangle::Triangle(float b, float h) : Shape(), base(b), height(h)
{
	colour.g = 1.0f;											// Triangle is cyan

	transform = transform.rotationMatrix(-1.1f);
	velocity = Vector2D(0.0001f, -0.002f);

	vertices[0] = Vector2D(-base / 2, -height / M_PI);			// Inits vertices
	vertices[1] = Vector2D(base / 2, -height / M_PI);
	vertices[2] = Vector2D(0, height / 2);
};

void Triangle::updateShape()
{
	ExtMatrix2D rotation = transform.getRotation();
	for (Vector2D &v : vertices)
	{
		Vector2D rotationCenter = v - transform.getPosition();			// Moves vertice to center of rotation
		Vector2D newPosition = rotation * rotationCenter;				// Rotates vertice around point
		v = newPosition + transform.getPosition() + velocity;			// Returns vertice to new position
	}
	Vector2D curPos = transform.getPosition();
	transform.setPosition(curPos + velocity);
};

void Triangle::drawShape()										// Draw 
{
	Assignment::AssignmentApp::LineData line;					// Line
	line.c1 = colour;											// Colour
	line.c2 = colour;

	for (int i = 0; i < 3; i++)									// Creates lines from vertices
	{
		line.x1 = vertices[i].getX() * aspectRatio;				// Takes aspect ratio into account
		line.y1 = vertices[i].getY();
		line.x2 = vertices[i + 1].getX() * aspectRatio;
		line.y2 = vertices[i + 1].getY();

		if (i == 2)												// Last vertice connects to the first one
		{
			line.x2 = vertices[0].getX() * aspectRatio;
			line.y2 = vertices[0].getY();
		}

		Assignment::AssignmentApp::DrawLine(line);
	}
}

Circle::~Circle()
{
}

// Circle
Circle::Circle(float rad) : Shape(), radius(rad)
{
	colour.r = 1.0f;											// circle is yellow
	colour.g = 1.0f;
	colour.b = 0.0f;

	transform = transform.rotationMatrix(10.1f);
	velocity = Vector2D(-0.001f, 0.000f);

	roundness = 10;												// Number of vertices (set in shape.h)

	for (int i = 0; i < roundness; i++)							// Inits vertices
	{
		vertices[i].setX(radius * cosf(i * 2 * M_PI / roundness));
		vertices[i].setY(radius * sinf(i * 2 * M_PI / roundness));
	}

};

void Circle::updateShape()
{
	ExtMatrix2D rotation = transform.getRotation();
	for (Vector2D &v : vertices)
	{
		Vector2D rotationCenter = v - transform.getPosition();			// Moves vertice to center of rotation
		Vector2D newPosition = rotation * rotationCenter;				// Rotates vertice around point
		v = newPosition + transform.getPosition() + velocity;			// Returns vertice to new position
	}
	Vector2D curPos = transform.getPosition();
	transform.setPosition(curPos + velocity);
};

void Circle::drawShape()										// Draw 
{
	Assignment::AssignmentApp::LineData line;					// Line
	line.c1 = colour;											// Colour
	line.c2 = colour;

	for (int i = 0; i < roundness; i++)							// Creates lines from vertices
	{
		line.x1 = vertices[i].getX() * aspectRatio;				// Takes aspect ratio into account
		line.y1 = vertices[i].getY();

		line.x2 = vertices[i + 1].getX() * aspectRatio;
		line.y2 = vertices[i + 1].getY();
		
		if (i == roundness - 1)									// Last vertice connects to the first one
		{
			line.x2 = vertices[0].getX() * aspectRatio;
			line.y2 = vertices[0].getY();
		}

		Assignment::AssignmentApp::DrawLine(line);
	}
}