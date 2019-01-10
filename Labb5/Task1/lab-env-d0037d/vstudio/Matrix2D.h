#pragma once
#define _USE_MATH_DEFINES
#include <math.h>
#include <iostream>
#include "Vector2D.h"

namespace {
	using std::cout;
	using std::endl;
}

class Matrix2D
{
private:
	float arr[4];

public:
	// Constructors
	Matrix2D();
	Matrix2D(float a, float b, float c, float d);
	Matrix2D(const Matrix2D &matrix);

	// Operators
	const Matrix2D operator*(const Matrix2D &matrix);
	void operator=(const Matrix2D &matrix);
	const Vector2D operator*(Vector2D &vector);

	// Setters and getters
	const float getA();
	const float getB();
	const float getC();
	const float getD();
	float *getPointer();
	void setA(float a);
	void setB(float b);
	void setC(float c);
	void setD(float d);
	void setAll(float x);

	// Computations
	const Matrix2D transpose();


	// Additional functionality
	const static Matrix2D rotationMatrix(float x);
	const static Matrix2D identityMatrix();
	const void print();
	const void printA();
	const void printB();
	const void printC();
	const void printD();

};

class ExtMatrix2D
{
private:
	float point[3][3] = { 0 };

public:
	// Constructor
	ExtMatrix2D();

	// Operators
	const ExtMatrix2D operator*(const ExtMatrix2D &matrix);
	const Vector2D operator*(Vector2D &vector);

	// Additional
	const static ExtMatrix2D rotationMatrix(float x);
	const static ExtMatrix2D translationMatrix(const Vector2D v);

};
