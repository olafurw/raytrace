#ifndef VECTOR3D_H
#define VECTOR3D_H

#include <cmath>
#include <iostream>

#define PI 3.14159265

using namespace std;

// Forward declaration
class Point3D;

class Vector3D
{
public:
	float x;
	float y;
	float z;
	Vector3D();
	Vector3D(float, float, float);
	Vector3D(const Vector3D&);
	Vector3D(const Point3D&);

	Vector3D& operator =(const Vector3D&);
	Vector3D operator +(const Vector3D& vec) const;
	Vector3D operator -(const Vector3D& vec) const;
	Vector3D operator *(const float num) const;

	void add(const Vector3D* vec);
	void add(const Vector3D& vec);

	void sub(const Vector3D* vec);
	void sub(const Vector3D& vec);

	void pointTo(const Point3D* from, const Point3D* to);
	void pointTo(const Point3D& from, const Point3D& to);

	static Vector3D mult(const Vector3D*, const Vector3D*);
	static Vector3D mult(const Vector3D& a, const Vector3D& b);

	static Vector3D sub(const Vector3D* a, const Vector3D* b);
	static Vector3D sub(const Vector3D& a, const Vector3D& b);

	static Vector3D cross(const Vector3D* a, const Vector3D* b);
	static Vector3D cross(const Vector3D& a, const Vector3D& b);

	static void crossToVector(const Vector3D*, const Vector3D*, Vector3D* dest);
	static void crossToVector(const Vector3D& a, const Vector3D& b, Vector3D& dest);
	
	static float dot(const Vector3D*, const Vector3D*);
	static float dot(const Vector3D&, const Vector3D&);

	static float dot(const Point3D&, const Vector3D&);
	static float dot(const Vector3D&, const Point3D&);

	float getX() const;
	float getY() const;
	float getZ() const;

	void setX(float);
	void setY(float);
	void setZ(float);

	void addX(float);
	void addY(float);
	void addZ(float);

	float getAngle();

	void set(float, float, float);
	float length();
	void normalize();
	void scale(float);

	friend ostream& operator<<(ostream& out, const Vector3D& vec);
	Point3D asPoint();
};

#endif
