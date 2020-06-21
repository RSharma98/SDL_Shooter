#ifndef VECTOR2_H
#define VECTOR2_H

#include <math.h>
#include <ostream>

class Vector2 {
public:
	float x, y;
	Vector2();
	Vector2(float a);
	Vector2(float x, float y);

	void Normalise();
	float GetMagnitude();

	Vector2 operator*(float n);
	Vector2 operator+(Vector2 v);
	Vector2 operator-(Vector2 v);
	void operator+=(Vector2 v);
	friend std::ostream& operator<< (std::ostream& out, const Vector2& v);
};

#endif // !VECTOR2_H