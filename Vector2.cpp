#include "Vector2.h"

///Default constructor
Vector2::Vector2() {
	x = y = 0;
}

///Constructor where both x and y have the same values
Vector2::Vector2(float a) {
	x = y = a;
}

///Constructor to set x and y
Vector2::Vector2(float x, float y) {
	this->x = x;
	this->y = y;
}

void Vector2::Normalise()
{
	float magnitude = GetMagnitude();
	if (magnitude != 0) {
		x = x / magnitude;
		y = y / magnitude;
	}
}

float Vector2::GetMagnitude()
{
	return sqrt((x * x) + (y * y));
}

Vector2 Vector2::operator*(float n) {
	return Vector2(x * n, y * n);
}

Vector2 Vector2::operator+(Vector2 v)
{
	return Vector2(x + v.x, y + v.y);
}

Vector2 Vector2::operator-(Vector2 v)
{
	return Vector2(x - v.x, y - v.y);
}

void Vector2::operator+=(Vector2 v) {
	x += v.x;
	y += v.y;
}

std::ostream& operator<< (std::ostream& out, const Vector2& v)
{
	out << "(" << v.x << ", " << v.y << ")";
	return out;
}
