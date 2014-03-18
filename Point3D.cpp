#include "Point3D.h"

// Init ctor
Point3D::Point3D()
{
	set(0.0f, 0.0f, 0.0f);
}

Point3D::Point3D(const Vector3D& v)
{
	this->x = v.getX();
	this->y = v.getY();
	this->z = v.getZ();
}

Point3D::Point3D(const Point3D* v)
{
	this->x = v->getX();
	this->y = v->getY();
	this->z = v->getZ();
}

// Set ctor
Point3D::Point3D(float x, float y, float z)
{
	set(x, y, z);
}

// = operator
Point3D& Point3D::operator =(const Point3D& point)
{
	// Prevent self assignment
	if(this != &point)
	{
		this->x = point.x;
		this->y = point.y;
		this->z = point.z;
	}

	return *this;
}

// Add vector
Point3D Point3D::operator +(const Vector3D& vec) const
{
	Point3D result;

	result.x = this->x + vec.getX();
	result.y = this->y + vec.getY();
	result.z = this->z + vec.getZ();
	
	return result;
}

// Subtract vector
Point3D Point3D::operator -(const Vector3D& vec) const
{
	Point3D result;

	result.x = this->x - vec.getX();
	result.y = this->y - vec.getY();
	result.z = this->z - vec.getZ();
	
	return result;
}

// Add Point
Vector3D Point3D::operator +(const Point3D& poi) const
{
	Vector3D result;
	result.set(this->x + poi.getX(),this->y + poi.getY(), this->z + poi.getZ());	

	return result;
}

void Point3D::add(const Vector3D* vec)
{
	this->x += vec->getX();
	this->y += vec->getY();
	this->z += vec->getZ();
}

void Point3D::add(const Vector3D& vec)
{
    this->x += vec.getX();
    this->y += vec.getY();
    this->z += vec.getZ();
}

Vector3D Point3D::sub(const Point3D* a, const Point3D* b)
{
	return Vector3D(a->getX() - b->getX(),
				    a->getY() - b->getY(),
					a->getZ() - b->getZ());
}

void Point3D::subFromFirst(Point3D* a, Point3D* b)
{
	a->setX(b->getX());
	a->setY(b->getY());
	a->setZ(b->getZ());	
}

void Point3D::subToVector(const Point3D* a, const Point3D* b, Vector3D& v)
{
	v.set(a->getX() - b->getX(),
	      a->getY() - b->getY(),
	      a->getZ() - b->getZ());
}

void Point3D::subToVector(const Point3D& a, const Point3D& b, Vector3D& v)
{
    v.set(a.x - b.x,
          a.y - b.y,
          a.z - b.z);
}

float Point3D::getX() const
{
	return this->x;
}

float Point3D::getY() const
{
	return this->y;
}

float Point3D::getZ() const
{
	return this->z;
}

void Point3D::setX(float x)
{
	this->x = x;
}

void Point3D::setY(float y)
{
	this->y = y;
}

void Point3D::setZ(float z)
{
	this->z = z;
}

void Point3D::addX(float x)
{
	this->x += x;
}

void Point3D::addY(float y)
{
	this->y += y;
}

void Point3D::addZ(float z)
{
	this->z += z;
}

void Point3D::set(float x, float y, float z) 
{
	this->x = x;
	this->y = y;
	this->z = z;
}

// Distance from (0,0,0)
float Point3D::length()
{
	return sqrt(x * x + y * y + z * z);
}

ostream& operator<<(ostream& out, const Point3D& p)
{
    out << "X:" << p.x << " Y:" << p.y << " Z:" << p.z;

    return out;
}
