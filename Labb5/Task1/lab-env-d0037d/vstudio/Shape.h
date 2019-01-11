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
	bool destructuble;
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
};