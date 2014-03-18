#include <iostream>
#include <opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <vector>

#include "Point3D.h"

float zToColor(float z, float far_plane)
{
    return 255.0f - ((z / far_plane) * 255.0f);
}

class color
{
public:
    unsigned char red;
    unsigned char green;
    unsigned char blue;

    color(unsigned char r, unsigned char g, unsigned char b)
    {
        red = r;
        green = g;
        blue = b;
    }

    color(unsigned char c)
    {
        red = c;
        green = c;
        blue = c;
    }
};

class triangle
{
public:
    Point3D p1;
    Point3D p2;
    Point3D p3;

    triangle(Point3D a, Point3D b, Point3D c)
    {
        p1 = a;
        p2 = b;
        p3 = c;
    }
};

bool sameSide(const Point3D& p1, const Point3D& p2,
              const Point3D& a, const Point3D& b)
{
    Vector3D cp1 = Vector3D::cross(b - a, p1 - a);
    Vector3D cp2 = Vector3D::cross(b - a, p2 - a);

    if(Vector3D::dot(cp1, cp2) >= 0)
    {
        return true;
    }

    return false;
}

bool pointInTriangle(const Point3D& p,
                     const triangle& t)
{
    if(sameSide(p, t.p1, t.p2, t.p3) &&
       sameSide(p, t.p2, t.p1, t.p3) &&
       sameSide(p, t.p3, t.p1, t.p2))
    {
        return true;
    }

    return false;
}

// rp = ray point
// rv = ray vector
// p1, p2, p3 = 3 points in the plane
void rayPlaneIntersection(const Point3D& rp,
        const Vector3D& rv,
        const triangle& t,
        Point3D& result)
{
    // Get a normal to the plane
    Vector3D v1;
    Point3D::subToVector(t.p2, t.p1, v1);

    Vector3D v2;
    Point3D::subToVector(t.p3, t.p1, v2);

    Vector3D n;
    Vector3D::crossToVector(v1, v2, n);
    n.normalize();

    // Eye to plane DOT n
    Vector3D subTemp;
    Point3D::subToVector(t.p1, rp, subTemp);
    float top = Vector3D::dot(subTemp, n);

    // Vector from eye DOT n
    float bot = Vector3D::dot(rv, n);

    if(bot == 0)
    {
        return;
    }

    float tHit = top / bot;

    if(tHit < 0)
    {
        return;
    }

    result = (rp + rv * tHit);
}

void draw_pixel(cv::Mat& image, const int x, const int y, const color c)
{
    cv::line( image, cv::Point(x, y), cv::Point(x, y), cv::Scalar(c.red, c.green, c.blue), 1 );
}

int main()
{
    const unsigned int height = 400;
    const unsigned int width = 400;
    const float far_plane = 400.0f;

    float x = 20.0f;
    
    while(true)
    {
        cv::Mat image(height, width, CV_8UC3, cv::Scalar::all(0));
        std::vector<triangle> triangles;

        triangles.push_back(triangle(Point3D(20.0f + x, 20.0f, 400.0f),
                                     Point3D(20.0f + x, 300.0f, 50.0f),
                                     Point3D(300.0f + x, 20.0f, 400.0f)));

        triangles.push_back(triangle(Point3D(30.0f, 30.0f, 300.0f),
                                     Point3D(30.0f, 350.0f, 300.0f),
                                     Point3D(350.0f, 30.0f, 300.0f)));


        for(unsigned int i = 0; i < height; ++i)
        {
            for(unsigned int j = 0; j < width; ++j)
            {
                Point3D ray_point(i, j, 0.0f);
                Vector3D ray_vector(0.0f, 0.0f, 1.0f);
                
                float z = 900.0f;

                for(auto& triangle : triangles)
                {
                    Point3D result(0.0f, 0.0f, 0.0f);
                    rayPlaneIntersection(ray_point, ray_vector, triangle, result);

                    if(pointInTriangle(result, triangle))
                    {
                        if(z > result.z)
                        {
                            z = result.z;
                        }
                    }
                }
                
                draw_pixel(image, i, j, zToColor(z, far_plane));
            }
        }

        cv::imshow("raytrace", image);

        cv::waitKey(1);

        x += 1.0f;
    }

    return 0;
}
