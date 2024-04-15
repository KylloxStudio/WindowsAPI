#include "pch.h"
#include "Vector2Int.h"

Vector2Int Vector2Int::operator+(const Vector2Int& other)
{
	return Vector2Int{ x + other.x, y + other.y };
}

void Vector2Int::operator+=(const Vector2Int& other)
{
	this->x += other.x;
	this->y += other.y;
}

Vector2Int Vector2Int::operator-(const Vector2Int& other)
{
	return Vector2Int{ x - other.x, y - other.y };
}

void Vector2Int::operator-=(const Vector2Int& other)
{
	this->x -= other.x;
	this->y -= other.y;
}

Vector2Int Vector2Int::operator*(const int32 value)
{
	return Vector2Int{ x * value, y * value };
}

void Vector2Int::operator*=(const int32 value)
{
	this->x *= value;
	this->y *= value;
}

Vector2Int Vector2Int::operator/(const int32 value)
{
	return Vector2Int{ x / value, y / value };
}

void Vector2Int::operator/=(const int32 value)
{
	this->x /= value;
	this->y /= value;
}

float Vector2Int::Length()
{
	return ::sqrtf(x * x + y * y);
}

int32 Vector2Int::LengthSquared()
{
	return x * x + y * y;
}

Vector2Int::Vector2Int()
{
	this->x = 0.0f;
	this->y = 0.0f;
}

Vector2Int::Vector2Int(int x, int y)
{
	this->x = x;
	this->y = y;
}

Vector2Int::Vector2Int(Vector2 vector)
{
	this->x = static_cast<int>(vector.x);
	this->y = static_cast<int>(vector.y);
}

Vector2Int::Vector2Int(POINT pt)
{
	this->x = static_cast<int>(pt.x);
	this->y = static_cast<int>(pt.y);
}

int32 Vector2Int::Dot(Vector2Int other)
{
	return x * other.x + y * other.y;
}
