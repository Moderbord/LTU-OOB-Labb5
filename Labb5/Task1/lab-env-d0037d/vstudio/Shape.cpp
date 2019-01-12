#include "config.h"
#include "../../projects/assignment/code/assignmentapp.h"
#include "Shape.h"
#include "ShapeTools.h"

const float aspectRatio = (3.0f/4.0f);
const float wallX = (1.28f);
const float wallY = (0.95f);
const float ballRadius = (0.05f);
Vector2D ballSpeed(-0.01f, 0.012f);
Vector2D ballPosition(0.0f, -0.5f);


// SHAPE
Shape::~Shape()
{
}

void Shape::updateShape(Vector2D vertices[], int numVertices)
{
	for (int i = 0; i < numVertices; i++)
	{
		Vector2D rotationCenter = vertices[i] - transform.getPosition();			// Moves vertice to center of rotation
		Vector2D newPosition = transform.getRotation() * rotationCenter;			// Rotates vertice around point
		vertices[i] = newPosition + transform.getPosition() + velocity;				// Returns vertice to new position
	}
	transform.setPosition(transform.getPosition() + velocity);
}

void Shape::drawShape(Vector2D vertices[], int numVertices)
{
	Assignment::AssignmentApp::LineData line;				// Line
	line.c1 = colour;										// Colour
	line.c2 = colour;

	for (int i = 0; i < numVertices; i++)					// Creates lines from vertices
	{
		line.x1 = vertices[i].getX() * aspectRatio;			// Takes aspect ratio into account
		line.y1 = vertices[i].getY();
		line.x2 = vertices[i + 1].getX() * aspectRatio;
		line.y2 = vertices[i + 1].getY();

		if (i == numVertices - 1)							// Last vertice connects to the first one
		{
			line.x2 = vertices[0].getX() * aspectRatio;
			line.y2 = vertices[0].getY();
		}

		Assignment::AssignmentApp::DrawLine(line);
	}
}

void Shape::distanceToBall(Shape* ball, Vector2D vertices[], int numVertices)
{
	Vector2D ballPosition = ball->getTransfrom().getPosition();
	Vector2D objectPosition = transform.getPosition();

	float objectToBalldistance = (objectPosition - ballPosition).vectorLength();

	if (objectToBalldistance < 0.15f + ballRadius)				// Generic size of objects
	{
		destroyed = true;

		Vector2D closestVertice;
		Vector2D closerVertice;
		float closestDistance = wallX;
		float closerDistance = wallX;

		for (int i = 0; i < numVertices; i++)			// Retrieve two closest vertices
		{
			float verticeBallDistance = (ballPosition - vertices[i]).vectorLength();

			if (verticeBallDistance < closestDistance) {
				closerDistance = closestDistance;
				closestDistance = verticeBallDistance;

				closerVertice = closestVertice;
				closestVertice = vertices[i];
			}
			else if (verticeBallDistance < closerDistance)
			{
				closerDistance = verticeBallDistance;

				closerVertice = vertices[i];
			}
		}

		Vector2D vectorNormal = (closestVertice + closerVertice - objectPosition * 2) / 2;
		Vector2D normilizedNormal = vectorNormal.normalized();

		Vector2D newVelocity = ball->getVelocity() - (ball->getVelocity() * normilizedNormal) * 2 * normilizedNormal;
		ball->setVelocity(newVelocity);
	}
}

ExtMatrix2D Shape::getTransfrom()
{
	return transform;
}

Vector2D Shape::getVelocity()
{
	return velocity;
}

void Shape::setVelocity(Vector2D velocity)
{
	this->velocity = velocity;
}

// SQUARE
Square::~Square()
{
}

Square::Square(float s) : Shape(), size(s)
{
	destructuble = true;

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
	Shape::updateShape(vertices, 4);
}

void Square::drawShape()
{
	Shape::drawShape(vertices, 4);
}

void Square::distanceToBall(Shape * ball)
{
	Shape::distanceToBall(ball, vertices, 4);
};

// TRIANGLE
Triangle::~Triangle()
{
}

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
	Shape::updateShape(vertices, 3);
};

void Triangle::drawShape()
{
	Shape::drawShape(vertices, 3);
}

void Triangle::distanceToBall(Shape * ball)
{
	Shape::distanceToBall(ball, vertices, 3);
}

// CIRCLE
Circle::~Circle()
{

}

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
	Shape::updateShape(vertices, roundness);
};

void Circle::drawShape()										// Draw 
{
	Shape::drawShape(vertices, roundness);
}

void Circle::distanceToBall(Shape * ball)
{
	Shape::distanceToBall(ball, vertices, roundness);
}

// PLAYER OBJECTS

// BALL
Ball::~Ball()
{
}

Ball::Ball() : Circle(ballRadius)
{
	destructuble = false;
	velocity = ballSpeed;
}

void Ball::distanceToBall(Shape * ball)
{
	// Overrides distance calculation inhereted from Circle
}

void Ball::updateShape()
{
	Circle::updateShape();

	if ((transform.getPosition().getX() > wallX) || (transform.getPosition().getX() < -wallX))				// Right or left wall inverts x-speed
	{
		Vector2D wall(-1, 1, 1);			
		velocity = velocity * wall;
	} 

	if ((transform.getPosition().getY() > wallY) || (transform.getPosition().getY() < -wallY))				// Top or bottom wall inverts y-speed
	{
		Vector2D wall(1, -1, 1);
		velocity = velocity * wall;
	}

	float speed = velocity.vectorLength();
	if (speed < ballSpeed.vectorLength())
	{
		velocity = velocity * 2;
	}


}