#pragma once

// RANDOM NUMBERS
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

