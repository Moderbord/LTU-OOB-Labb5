#include "Matrix2D.h"

ExtMatrix2D::ExtMatrix2D()
{
	point[0][0] = 1;
	point[1][1] = 1;
	point[2][2] = 1;
}

void ExtMatrix2D::operator=(const ExtMatrix2D & matrix)
{
	this->point[0][0] = matrix.point[0][0];
	this->point[0][1] = matrix.point[0][1];
	this->point[0][2] = matrix.point[0][2];
	this->point[1][0] = matrix.point[1][0];
	this->point[1][1] = matrix.point[1][1];
	this->point[1][2] = matrix.point[1][2];
	this->point[2][0] = matrix.point[2][0];
	this->point[2][1] = matrix.point[2][1];
	this->point[2][2] = matrix.point[2][2];
}

const ExtMatrix2D ExtMatrix2D::operator*(const ExtMatrix2D & matrix)
{
	ExtMatrix2D mat;
	Vector2D v1;
	Vector2D v2;

	for (int outer = 0; outer < 3; outer++)
	{
		for (int i = 0; i < 3; i++)
		{
			for (int k = 0; k < 3; k++)
			{
				v1.arr[k] = this->point[outer][k];		// Vector from row in first matrix
				v2.arr[k] = matrix.point[k][i];			// Vector from column in second matrix
			}
			mat.point[outer][i] = v1.dotProduct(v2);	// Point in new matrix from vector multiplication
		}
	}
	return mat;
}

const Vector2D ExtMatrix2D::operator*(Vector2D & vector)
{
	Vector2D matV;
	Vector2D newV;

	for (int outer = 0; outer < 3; outer++)
	{
		for (int i = 0; i < 3; i++)
		{
			matV.arr[i] = this->point[outer][i];		// Vector from row in matrix
		}
		newV.arr[outer] = matV.dotProduct(vector);		// Point in new vector from vector multiplication
	}
	return newV;
}

void ExtMatrix2D::setPosition(Vector2D & vector)
{
	this->point[0][2] = vector.getX();
	this->point[1][2] = vector.getY();
}

const Vector2D ExtMatrix2D::getPosition()
{
	Vector2D pos;
	pos.setX(this->point[0][2]);
	pos.setY(this->point[1][2]);
	return pos;
}

const ExtMatrix2D ExtMatrix2D::rotationMatrix(float x)
{
	ExtMatrix2D rotMat;
	rotMat.point[0][0] = cosf(x * M_PI / 180.0);
	rotMat.point[0][1] = -sinf(x * M_PI / 180.0);
	rotMat.point[1][0] = sinf(x * M_PI / 180.0);
	rotMat.point[1][1] = cosf(x * M_PI / 180.0);
	return rotMat;
}

const ExtMatrix2D ExtMatrix2D::translationMatrix(Vector2D & v)
{
	ExtMatrix2D transMat = *this;
	transMat.point[0][2] = v.getX();
	transMat.point[1][2] = v.getY();
	return transMat;
}
