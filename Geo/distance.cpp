#include "distance.h"

float distancePointToLine(const Point3d& p1, const Line3d& l1){
    Vector3f v = l1.get_direction();
    Point3d A = l1.get_start_point();
    Vector3f AB = p1 - A;
    float t = v.dotProd(AB);

    Vector3f vt = v*Vector3f(t,t,t);
    
    float distance = ((vt + A) - p1).norm2();

    return distance;
}

float distancePointToPlane(const Point3d& p1,const Plane& plane){
    Vector3f normal = plane.get_normal();
    return normal.dotProd(p1) - plane.get_d(); 
}

