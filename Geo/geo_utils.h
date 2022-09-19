#ifndef GEO_UTILS_H
#define GEO_UTILS_H

#include "../Core/vector.h"
#include "../Core/point.h"
#include "../Helper/helper.h"

float areaTriangle2d(Point2d p1,Point2d p2,Point2d p3){
    Vector2f v1 = p1 - p2;
    Vector2f v2 = p2 - p3;
    return std::abs(crossProduct2d(v1,v2)) / 2;
}

#endif


