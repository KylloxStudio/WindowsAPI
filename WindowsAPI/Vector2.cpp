#include "pch.h"
#include "Vector2.h"

Vector2 Vector2::operator-(const POINT pt)
{
	return Vector2{ static_cast<float>(x - pt.x), static_cast<float>(y - pt.y) };
}

Vector2 Vector2::operator-(const Vector2 other)
{
	return Vector2{ x - other.x, y - other.y };
}

void Vector2::operator-=(const Vector2 other)
{
	this->x -= other.x;
	this->y -= other.y;
}

Vector2 Vector2::operator+(const POINT pt)
{
	return Vector2{ static_cast<float>(x + pt.x), static_cast<float>(y + pt.y) };
}

Vector2 Vector2::operator+(const Vector2 other)
{
	return Vector2{ x + other.x, y + other.y };
}

void Vector2::operator+=(const Vector2 other)
{
	this->x += other.x;
	this->y += other.y;
}

Vector2 Vector2::operator*(const float other)
{
	return Vector2{ x * other, y * other };
}

void Vector2::operator*=(const float other)
{
	this->x *= other;
	this->y *= other;
}

Vector2 Vector2::operator/(const float other)
{
	return Vector2{ x / other, y / other };
}

void Vector2::operator/=(const float other)
{
	this->x /= other;
	this->y /= other;
}

float Vector2::Length()
{
	return static_cast<float>(::sqrt(x * x + y * y));
}

Vector2 Vector2::Normalize()
{
	float length = this->Length();
	if (length <= 0.00000000000001f)
	{
		return *this;
	}

	return { x / length, y / length };
}

Vector2::Vector2(float x, float y)
{
	this->x = x;
	this->y = y;
}

Vector2::Vector2()
{
	this->x = 0.0f;
	this->y = 0.0f;
}

float Vector2::Dot(Vector2 other)
{
	return x * other.x + y * other.y;
}

float Vector2::Dot(Vector2 origin, Vector2 other)
{
	return origin.x * other.x + origin.y * other.y;
}

Vector2 Vector2::Reflect(Vector2 normal)
{
	Vector2 normalizedNormal = normal.Normalize();
	Vector2 normalizedOrigin = this->Normalize();
	float tempLength = this->Dot(normalizedNormal * -1) * 2;

	return normalizedOrigin + normalizedNormal * tempLength;
}

Vector2 Vector2::Reflect(Vector2 origin, Vector2 normal)
{
	Vector2 normalizedNormal = normal.Normalize();
	Vector2 normalizedOrigin = origin.Normalize();
	float tempLength = Dot(origin, normalizedNormal * -1) * 2;

	return normalizedOrigin + normalizedNormal * tempLength;
}
