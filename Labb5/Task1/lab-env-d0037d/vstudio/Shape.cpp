#include "config.h"
#include "../../projects/assignment/code/assignmentapp.h"
#include "Shape.h"

const float aspectRatio = (3.0f/4.0f);


float rFloat()												// range: 0.0f - 0.99f
{
	float f = rand() % 100;							
	return f / 100;
}

float rRotation()											// range: -(1.98f) - 1.98f
{
	float f = rFloat() * 2;
	return rand() % 10 > 5 ? f : -f;
}

Vector2D rPosition()										// range: -(0.98f) - 0.98f
{
	Vector2D vector;

	float f = rFloat();
	vector.setX(rand() % 10 > 5 ? f : -f);

	f = rFloat();
	vector.setY(rand() % 10 > 5 ? f : -f + 0.85f);

	return vector;
}

Vector2D rVelocity()										// range: -(0.0099f) - 0.0099f
{
	Vector2D vector;

	float f = rFloat() / 100;
	vector.setX(rand() % 10 > 5 ? f : -f);

	f = rFloat() / 100;
	vector.setY(rand() % 10 > 5 ? f : -f);

	return vector;
}


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
	destructuble = false;

	transform = transform.rotationMatrix(rRotation());
	transform.setPosition(rPosition());
	//velocity = Vector2D(rVelocity());

	float posX = transform.getPosition().getX();
	float posY = transform.getPosition().getY();

	vertices[0] = Vector2D(-s + posX, -s + posY);							// Inits vertices
	vertices[1] = Vector2D(s + posX, -s + posY);
	vertices[2] = Vector2D(s + posX, s + posY);
	vertices[3] = Vector2D(-s + posX, s + posY);

	colour.r = rFloat();
	colour.g = rFloat();
	colour.b = rFloat();
};

void Square::updateShape()
{
	for (Vector2D &v : vertices)
	{
		Vector2D rotationCenter = v - transform.getPosition();			// Moves vertice to center of rotation
		Vector2D newPosition = transform.getRotation() * rotationCenter;				// Rotates vertice around point
		v = newPosition + transform.getPosition() + velocity;			// Returns vertice to new position
	}
	transform.setPosition(transform.getPosition() + velocity);
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
	destructuble = true;

	transform = transform.rotationMatrix(rRotation());
	transform.setPosition(rPosition());
	//velocity = Vector2D(rVelocity());

	float posX = transform.getPosition().getX();
	float posY = transform.getPosition().getY();

	vertices[0] = Vector2D(-base / 2 + posX, -height / M_PI + posY);			// Inits vertices
	vertices[1] = Vector2D(base / 2 + posX, -height / M_PI + posY);
	vertices[2] = Vector2D(0 + posX, height / 2 + posY);

	colour.r = rFloat();
	colour.g = rFloat();
	colour.b = rFloat();
};

void Triangle::updateShape()
{
	for (Vector2D &v : vertices)
	{
		Vector2D rotationCenter = v - transform.getPosition();			// Moves vertice to center of rotation
		Vector2D newPosition = transform.getRotation() * rotationCenter;				// Rotates vertice around point
		v = newPosition + transform.getPosition() + velocity;			// Returns vertice to new position
	}
	transform.setPosition(transform.getPosition() + velocity);
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
	destructuble = true;

	transform = transform.rotationMatrix(rRotation());
	transform.setPosition(rPosition());
	//velocity = Vector2D(rVelocity());

	roundness = 10;												// Number of vertices (set in shape.h)

	for (int i = 0; i < roundness; i++)							// Inits vertices
	{
		vertices[i].setX(radius * cosf(i * 2 * M_PI / roundness) + transform.getPosition().getX());
		vertices[i].setY(radius * sinf(i * 2 * M_PI / roundness) + transform.getPosition().getY());
	}

	colour.r = rFloat();
	colour.g = rFloat();
	colour.b = rFloat();
};

void Circle::updateShape()
{
	for (Vector2D &v : vertices)
	{
		Vector2D rotationCenter = v - transform.getPosition();			// Moves vertice to center of rotation
		Vector2D newPosition = transform.getRotation() * rotationCenter;				// Rotates vertice around point
		v = newPosition + transform.getPosition() + velocity;			// Returns vertice to new position
	}
	transform.setPosition(transform.getPosition() + velocity);
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