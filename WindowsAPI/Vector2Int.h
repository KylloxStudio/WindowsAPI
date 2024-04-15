#pragma once

struct Vector2Int
{
	int x = 0;
	int y = 0;

	Vector2Int();
	Vector2Int(int x, int y);
	Vector2Int(Vector2 vector);
	Vector2Int(POINT point);

	Vector2Int operator+(const Vector2Int& other);
	void operator+=(const Vector2Int& other);

	Vector2Int operator-(const Vector2Int& other);
	void operator-=(const Vector2Int& other);

	Vector2Int operator*(const int32 value);
	void operator*=(const int32 value);

	Vector2Int operator/(const int32 value);
	void operator/=(const int32 value);

	float Length();
	int32 LengthSquared();

	int32 Dot(Vector2Int other);
};
