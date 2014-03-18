#include "Vector3D.h"
#include "Point3D.h"

// Init ctor
Vector3D::Vector3D()
{
	this->x = 0.0f;
	this->y = 0.0f;
	this->z = 0.0f;
}

// Set ctor
Vector3D::Vector3D(float x, float y, float z)
{
	this->x = x;
	this->y = y;
	this->z = z;
}

// Copy ctor
Vector3D::Vector3D(const Vector3D& vec)
{
	// Prevent self assignment
	if(this != &vec)
	{
		this->x = vec.x;
		this->y = vec.y;
		this->z = vec.z;
	}
}

Vector3D::Vector3D(const Point3D& poi)
{
	this->x = poi.getX();
	this->y = poi.getY();
	this->z = poi.getZ();
}

// = operator
Vector3D& Vector3D::operator =(const Vector3D& vec)
{
	// Prevent self assignment
	if(this != &vec)
	{
		this->x = vec.x;
		this->y = vec.y;
		this->z = vec.z;
	}

	return *this;
}

// Addition
Vector3D Vector3D::operator +(const Vector3D& vec) const
{
	Vector3D result;

	result.x = this->x + vec.x;
	result.y = this->y + vec.y;
	result.z = this->z + vec.z;
	
	return result;
}

// Subtraction
Vector3D Vector3D::operator -(const Vector3D& vec) const
{
	Vector3D result;

	result.x = this->x - vec.x;
	result.y = this->y - vec.y;
	result.z = this->z - vec.z;
	
	return result;
}

Vector3D Vector3D::operator *(const float num) const
{
	return Vector3D(this->x * num, this->y * num, this->z * num);
}

void Vector3D::add(const Vector3D* vec)
{
	this->x += vec->getX();
	this->y += vec->getY();
	this->z += vec->getZ();
}

void Vector3D::add(const Vector3D& vec)
{
    this->x += vec.getX();
    this->y += vec.getY();
    this->z += vec.getZ();
}

void Vector3D::sub(const Vector3D* vec)
{
	this->x -= vec->getX();
	this->y -= vec->getY();
	this->z -= vec->getZ();
}

void Vector3D::sub(const Vector3D& vec)
{
    this->x -= vec.getX();
    this->y -= vec.getY();
    this->z -= vec.getZ();
}

void Vector3D::pointTo(const Point3D* from, const Point3D* to)
{
	this->x = to->getX() - from->getX();
	this->y = to->getY() - from->getY();
	this->z = to->getZ() - from->getZ();
}

void Vector3D::pointTo(const Point3D& from, const Point3D& to)
{
    this->x = to.getX() - from.getX();
    this->y = to.getY() - from.getY();
    this->z = to.getZ() - from.getZ();
}

Vector3D Vector3D::mult(const Vector3D* a, const Vector3D* b)
{
	return Vector3D(a->x * b->x, a->y * b->y, a->z * b->z);
}

Vector3D Vector3D::mult(const Vector3D& a, const Vector3D& b)
{
    return Vector3D(a.x * b.x, a.y * b.y, a.z * b.z);
}

Vector3D Vector3D::sub(const Vector3D* a, const Vector3D* b)
{
    return Vector3D(a->x - b->x,
                    a->y - b->y,
                    a->z - b->z);
}

Vector3D Vector3D::sub(const Vector3D& a, const Vector3D& b)
{
    return Vector3D(a.x - b.x,
                    a.y - b.y,
                    a.z - b.z);
}

// Cross product
Vector3D Vector3D::cross(const Vector3D* a, const Vector3D* b)
{
    return Vector3D(a->y * b->z - a->z * b->y,
                    a->z * b->x - a->x * b->z,
                    a->x * b->y - a->y * b->x);
}

// Cross product
Vector3D Vector3D::cross(const Vector3D& a, const Vector3D& b)
{
    return Vector3D(a.y * b.z - a.z * b.y,
                    a.z * b.x - a.x * b.z,
                    a.x * b.y - a.y * b.x);
}

void Vector3D::crossToVector(const Vector3D* a, const Vector3D* b, Vector3D* dest)
{
	dest->set(a->getY() * b->getZ() - a->getZ() * b->getY(),
	          a->getZ() * b->getX() - a->getX() * b->getZ(),
	          a->getX() * b->getY() - a->getY() * b->getX());
}

void Vector3D::crossToVector(const Vector3D& a, const Vector3D& b, Vector3D& dest)
{
    dest.set(a.y * b.z - a.z * b.y,
             a.z * b.x - a.x * b.z,
             a.x * b.y - a.y * b.x);
}

// Dot product
float Vector3D::dot(const Vector3D* a, const Vector3D* b)
{
	return a->x * b->x + a->y * b->y + a->z * b->z;
}

// Dot product
float Vector3D::dot(const Vector3D& a, const Vector3D& b)
{
    return a.x * b.x + a.y * b.y + a.z * b.z;
}

// Dot product
float Vector3D::dot(const Point3D& a, const Vector3D& b)
{
    return a.x * b.x + a.y * b.y + a.z * b.z;
}

// Dot product
float Vector3D::dot(const Vector3D& a, const Point3D& b)
{
    return a.x * b.x + a.y * b.y + a.z * b.z;
}

float Vector3D::getX() const
{
	return x;
}

float Vector3D::getY() const
{
	return y;
}

float Vector3D::getZ() const
{
	return z;
}

void Vector3D::setX(float x)
{
	this->x = x;
}

void Vector3D::setY(float y)
{
	this->y = y;
}

void Vector3D::setZ(float z)
{
	this->z = z;
}

void Vector3D::addX(float x)
{
	this->x += x;
}

void Vector3D::addY(float y)
{
	this->y += y;
}

void Vector3D::addZ(float z)
{
	this->z += z;
}

// Basic set
void Vector3D::set(float x, float y, float z) 
{
	this->x = x;
	this->y = y;
	this->z = z;
}

float Vector3D::getAngle()
{
	return atan2f(z, x);
}

// Vector length
float Vector3D::length()
{
	return sqrt(x*x + y*y + z*z);
}

// Normalizes the vector
void Vector3D::normalize()
{
	float len = length();

	if(len == 0) return; // Null vector is a special case

	x /= len;
	y /= len;
	z /= len;
}

// Scales the vector by a factor
void Vector3D::scale(float factor)
{
	x *= factor;
	y *= factor;
	z *= factor;
}

// cout overloading
ostream& operator<<(ostream& out, const Vector3D& vec)
{
	out << "X:" << vec.getX() << " Y:" << vec.getY() << " Z:" << vec.getZ();
	
	return out;
}

// Return a point with the same values as the vector
Point3D Vector3D::asPoint()
{
	return Point3D(this->x,this->y,this->z);
}
