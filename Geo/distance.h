#ifndef DISTANCE_H
#define DISTANCE_H

#include "../Core/line.h"
#include "../Core/Plane.h"
#include "../Core/point.h"

float distancePointToLine(const Point3d& p1, const Line3d& l1);

float distancePointToPlane(const Point3d& p1,const Plane& l1);


#endif