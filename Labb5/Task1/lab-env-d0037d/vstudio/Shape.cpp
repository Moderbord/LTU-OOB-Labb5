#include "config.h"
#include "../../projects/assignment/code/assignmentapp.h"
#include "Shape.h"

const float aspectRatio = (3.0f/4.0f);

// Shape
Shape::~Shape() {
	delete this;
}

// Square
Square::Square(float n) : Shape(), size(n)
{
	colour.r = 1.0f;										// Sqaure is magenta

	vertices[0] = Vector2D(-n, -n);							// Inits vertices
	vertices[1] = Vector2D(n, -n);
	vertices[2] = Vector2D(n, n);
	vertices[3] = Vector2D(-n, n);
};

void Square::updateShapePosition(float x, float y)			// Position
{
	anchorPoint = anchorPoint + Vector2D(x, y);				// Updates position of anchorpoint (center of object)

	for (Vector2D &v : vertices)							// Updates vertices tied to object
	{	
		v.setX(v.getX() + x);
		v.setY(v.getY() + y);
	}
};

void Square::updateShapeRotation(float x)					// Rotation
{
	rotation = Matrix2D::rotationMatrix(x);					// Updates the rotation matrix (

	for (Vector2D &v : vertices)							// Updates vertices tied to object
	{
		Vector2D rotationCenter = v - anchorPoint;			// Moves vertice to center of rotation
		Vector2D newPosition = rotation * rotationCenter;	// Rotates vertice around point
		v = newPosition + anchorPoint;						// Returns vertice to new position
	}
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

	char buffer[32];										// Following prints cordinates to anchorpoint

	int tmp = snprintf(buffer, sizeof buffer, "%f", anchorPoint.getX());
	Assignment::AssignmentApp::GetInstance().PrintText(buffer, 0.3f, 0.3f, 20.0f, colour);

	tmp = snprintf(buffer, sizeof buffer, "%f", anchorPoint.getY());
	Assignment::AssignmentApp::GetInstance().PrintText(buffer, 0.38f, 0.3f, 20.0f, colour);

};

// Triangle
Triangle::Triangle(float b, float h) : Shape(), base(b), height(h)
{
	colour.g = 1.0f;											// Triangle is cyan

	vertices[0] = Vector2D(-base / 2, -height / M_PI);			// Inits vertices
	vertices[1] = Vector2D(base / 2, -height / M_PI);
	vertices[2] = Vector2D(0, height / 2);
};

void Triangle::updateShapePosition(float x, float y)			// Position
{
	anchorPoint = anchorPoint + Vector2D(x, y);					// Updates position of anchorpoint (center of object)

	for (Vector2D &v : vertices)								// Updates vertices tied to object
	{
		v.setX(v.getX() + x);
		v.setY(v.getY() + y);
	}
}

void Triangle::updateShapeRotation(float x)						// Rotation
{
	rotation = Matrix2D::rotationMatrix(x);						// Updates the rotation matrix (

	for (Vector2D &v : vertices)								// Updates vertices tied to object
	{
		Vector2D rotationCenter = v - anchorPoint;				// Moves vertice to center of rotation
		Vector2D newPosition = rotation * rotationCenter;		// Rotates vertice around point
		v = newPosition + anchorPoint;							// Returns vertice to new position
	}
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

// Circle
Circle::Circle(float rad) : Shape(), radius(rad)
{
	colour.r = 1.0f;											// circle is yellow
	colour.g = 1.0f;
	colour.b = 0.0f;

	roundness = 10;												// Number of vertices (set in shape.h)

	for (int i = 0; i < roundness; i++)							// Inits vertices
	{
		vertices[i].setX(radius * cosf(i * 2 * M_PI / roundness));
		vertices[i].setY(radius * sinf(i * 2 * M_PI / roundness));
	}

};

void Circle::updateShapePosition(float x, float y)				// Position
{
	anchorPoint = anchorPoint + Vector2D(x, y);					// Updates position of anchorpoint (cente

	for (Vector2D &v : vertices)								// Updates vertices tied to object
	{
		v.setX(v.getX() + x);
		v.setY(v.getY() + y);
	}
}

void Circle::updateShapeRotation(float x)						// Rotation
{
	rotation = Matrix2D::rotationMatrix(x);						// Updates the rotation matrix (

	for (Vector2D &v : vertices)								// Updates vertices tied to object
	{
		Vector2D rotationCenter = v - anchorPoint;				// Moves vertice to center of rotation
		Vector2D newPosition = rotation * rotationCenter;		// Rotates vertice around point
		v = newPosition + anchorPoint;							// Returns vertice to new position
	}
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