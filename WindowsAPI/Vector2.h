#pragma once

struct Vector2
{
	float x = 0.0f;
	float y = 0.0f;
	
	Vector2 operator+(const POINT pt);
	Vector2 operator+(const Vector2 other);
	void operator+=(const Vector2 other);

	Vector2 operator-(const POINT pt);
	Vector2 operator-(const Vector2 other);
	void operator-=(const Vector2 other);

	Vector2 operator*(const float other);
	void operator*=(const float other);

	Vector2 operator/(const float other);
	void operator/=(const float other);

	float Length();
	Vector2 Normalize();

	Vector2(float x, float y);
	Vector2();

	float Dot(Vector2 other);
	float Dot(Vector2 origin, Vector2 other);

	Vector2 Reflect(Vector2 normal);
	Vector2 Reflect(Vector2 origin, Vector2 normal);

	static Vector2 Zero() { return Vector2(0, 0); }
	static Vector2 Up() { return Vector2(0, 1); }
	static Vector2 Down() { return Vector2(0, -1); }
	static Vector2 Left() { return Vector2(-1, 0); }
	static Vector2 Right() { return Vector2(1, 0); }
};
