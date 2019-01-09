#include "Matrix2D.h"
#include "Vector2D.h"
#include <vector>
#include <cmath>

class Shape
{
protected:
	Vector2D anchorPoint;
	Matrix2D rotation;
	Assignment::AssignmentApp::Colour colour;

public:
	virtual ~Shape();
	virtual void updateShapePosition(float x, float y) = 0;
	virtual void updateShapeRotation(float x) = 0;
	virtual void drawShape() = 0;
};

// Square
class Square : public Shape
{
private:
	float size;
	Vector2D vertices[4];

public:
	Square(float dim);
	void updateShapePosition(float x, float y);
	void updateShapeRotation(float x);
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
	Triangle(float base, float height);
	void updateShapePosition(float x, float y);
	void updateShapeRotation(float x);
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
	Circle(float radius);
	void updateShapePosition(float x, float y);
	void updateShapeRotation(float x);
	void drawShape();
};