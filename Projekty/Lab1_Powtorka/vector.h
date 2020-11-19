#pragma once

class Vector
{
private:
		float x, y, z;
public:
	float getx() const { return x; }
	void setx(float x) { this->x = x; }
	float gety() const { return y; }
	void sety(float y) { this->y = y; }
	float getz() const { return z; }
	void setz(float z) { this->z = z; }

	inline Vector() { x = y = z = 0.0; };
	Vector(float x, float y, float z);
	Vector(const Vector& other);

	void print();
	float module();

	Vector operator+(float b)
	{
		return Vector(x + b, y + b, z + b);
	}

};

Vector add(Vector& v1, Vector& v2);
float dot(Vector& v1, Vector& v2);
Vector cross(Vector& v1, Vector& v2);
//Vector operator+(const Vector& v, float b);
