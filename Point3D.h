#ifndef POINT3D_H
#define POINT3D_H

#include "Vector3D.h"

class Point3D
{
	public:
		Point3D();
		Point3D(const Vector3D&);
		Point3D(const Point3D*);
		Point3D(float, float, float);

		Point3D& operator =(const Point3D&);
		Point3D operator +(const Vector3D& vec) const;
		Point3D operator -(const Vector3D& vec) const;

		Vector3D operator +(const Point3D& poi) const;
		
		void add(const Vector3D* vec);
		void add(const Vector3D& vec);

		static Vector3D sub(const Point3D* a, const Point3D* b);
		static void subFromFirst(Point3D* a, Point3D* b);

		static void subToVector(const Point3D* a, const Point3D* b, Vector3D& v);
		static void subToVector(const Point3D& a, const Point3D& b, Vector3D& v);

		float getX() const;
		float getY() const;
		float getZ() const;

		void setX(float);
		void setY(float);
		void setZ(float);

		void addX(float);
		void addY(float);
		void addZ(float);

		void set(float, float, float);
		float length();

		friend ostream& operator<<(ostream& out, const Point3D& vec);

        float x;
        float y;
        float z;
};

#endif
