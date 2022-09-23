#include "polygon.h"

bool is_convex(Vertex2d& v1,Vertex2d& v2,Vertex2d& v3){
    Point2d p1,p2,p3;
    p1 = v1.point;
    p2 = v2.point;
    p3 = v3.point;

    float det = (p2[X]-p1[X])*(p3[Y]-p1[Y]) - (p3[X]-p1[X])*(p2[Y]-p1[Y]);
    if (det < 0.0){
        return false;
    }
    return true;
}