#include "geo_utils.h"

float areaTriangle2d(const Point2d p1,const Point2d p2,const Point2d p3){
    // formule du determinant
    return std::abs((p2[X]-p1[X])*(p3[Y]-p1[Y]) - (p3[X]-p1[X])*(p2[Y]-p1[Y])) /2 ;
}

int orientation2d(const Point2d& a, const Point2d& b, const Point2d& c)
{
	float area = areaTriangle2d(a, b, c);

	if (area > 0 && area < TOLERANCE)
		area = 0;

	if (area < 0 && area > TOLERANCE)
		area = 0;

	Vector2f ab = b - a;
	Vector2f ac = c - a;

	if (area > 0.0)
		return LEFT;
	if (area < 0.0)
		return RIGHT;
	if ((ab[X] * ac[X] < 0.0) || (ab[Y] * ac[Y] < 0.0))
		return ON_LINE;
	if (ab.norm2() < ac.norm2())
		return ON_LINE;
	if (a == c)
		return ON_LINE;
	if (b == c)
		return ON_LINE;
	return ON_SEGMENT;
}

float areaTriangle3d(Point2d p1,Point2d p2,Point2d p3){
    // formule du determinant    
}

int orientation3d(){}
