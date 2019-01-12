#include "Matrix2D.h"
#include "Vector2D.h"
#include <vector>
#include <cmath>
#include <stdlib.h>

class Shape
{
protected:
	ExtMatrix2D transform;
	Vector2D velocity;
	Assignment::AssignmentApp::Colour colour;

public:
	virtual ~Shape();
	virtual void updateShape() = 0;
	virtual void drawShape() = 0;
	virtual void distanceToBall(Shape* ball) = 0;
	void updateShape(Vector2D vertices[], int numVertices);
	void drawShape(Vector2D vertices[], int numVertices);
	void distanceToBall(Shape* ball, Vector2D vertices[], int numVertices);
	ExtMatrix2D getTransfrom();
	Vector2D getVelocity();
	void setVelocity(Vector2D velocity);
	bool destructuble;
	bool destroyed;
};

// Square
class Square : public Shape
{
private:
	float size;
	Vector2D vertices[4];

public:
	~Square();
	Square(float size);
	void updateShape();
	void drawShape();
	void distanceToBall(Shape* ball);
};

// Triangle
class Triangle : public Shape
{
private:
	float base;
	float height;
	Vector2D vertices[3];

public:
	~Triangle();
	Triangle(float base, float height);
	void updateShape();
	void drawShape();
	void distanceToBall(Shape* ball);
};

// Cirlce
class Circle : public Shape
{
private:
	float radius;
	float roundness;
	Vector2D vertices[10];

public:
	~Circle();
	Circle(float radius);
	void updateShape();
	void drawShape();
	void distanceToBall(Shape* ball);
};

// Ball
class Ball : public Circle
{
public:
	~Ball();
	Ball();
	void distanceToBall(Shape* ball);
	void updateShape();
};