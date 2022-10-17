#ifndef GEO_UTILS_H
#define GEO_UTILS_H

#include "../Primitives/vector.h"
#include "../Primitives/point.h"
#include "../Helper/helper.h"
#include "../Primitives/polygon.h"

float areaTriangle2d(const Point2d p1,const Point2d p2,const Point2d p3);

int orientation2d(const Point2d& a, const Point2d& b, const Point2d& c);

//float areaTriangle3d(Point3d& p1,Point3d& p2,Point3d& p3);

float areaTriangle3d(Point2d p1,Point2d p2,Point2d p3);

bool coplaner(const Point3d& a, const Point3d& b, const Point3d& c);

bool is_diagonal(const Vertex2d& v1,const Vertex2d& v2,const Polygon2d& p);
#endif