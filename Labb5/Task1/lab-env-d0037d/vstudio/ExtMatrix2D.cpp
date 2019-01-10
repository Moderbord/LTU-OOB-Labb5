#include "Matrix2D.h"

ExtMatrix2D::ExtMatrix2D()
{
	point[0][0] = 1;
	point[1][1] = 1;
	point[2][2] = 1;
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
				v1.arr[k] = this->point[outer][k];
				v2.arr[k] = matrix.point[k][i];
			}
			mat.point[outer][i] = v1.dotProduct(v2);
		}
	}
	return mat;
}