#ifndef ANGLE_H
#define ANGLE_H

#include "../Core/line.h"
#include "../Core/Plane.h"
#include "../Helper/helper.h"
#include <cmath>

float angleLine2d(const Line2d& l1, const Line2d& l2);

float angleLine3d(const Line3d& l1, const Line3d& l2);

float angleLinePlane(const Line3d& l1, const Plane& plane);

float anglePlanes(const Plane& p1, const Plane& p2);

template<size_t dim>
float get_angle(Vector<dim> v1, Vector<dim> v2){
    auto dot = v1.dotProd(v2);
    auto angle = acos(std::abs(dot)/(v1.norm2()*v2.norm2()));
    return radianceToDegrees(angle);
}

#endif