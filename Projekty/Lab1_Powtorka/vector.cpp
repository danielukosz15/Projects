#include <iostream>
#include "vector.h"

using namespace std;

Vector::Vector(float x, float y, float z)
	: x(x), y(y), z(z) {}

Vector::Vector(const Vector& other)
	: x(other.x), y(other.y), z(other.z) {}

void Vector::print()
{
	cout << "(" << x << ", " << y << ", " << z << ")" << endl;
}

float Vector::module()
{
	return sqrt((x*x) + (y*y) + (z*z));
}

Vector add(Vector& v1, Vector& v2)
{
	return Vector(v1.getx() + v2.getx(), v1.gety() + v2.gety(), v1.getz() + v2.getz());
}

float dot(Vector& v1, Vector& v2)
{
	return (v1.getx() * v2.getx()) + (v1.gety() * v2.gety()) + (v1.getz() * v2.getz());
}

Vector cross(Vector& v1, Vector& v2)
{
	return Vector((v1.gety()* v2.getz()- v1.getz()* v2.gety()),((v1.getx()* v2.getz()- v1.getz()* v2.getx()*(-1))), (v1.getx()* v2.gety()- v1.gety()* v2.getx()));
}