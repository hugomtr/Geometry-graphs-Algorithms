#include "angle.h"

float angleLine2d(const Line2d& l1, const Line2d& l2){
    return get_angle(l1.get_direction(), l2.get_direction());
}

float angleLine3d(const Line3d& l1, const Line3d& l2){
    return get_angle(l1.get_direction(), l2.get_direction());
}

float angleLinePlane(const Line3d& l1, const Plane& plane){
    float angle = get_angle(l1.get_direction(), plane.get_normal());
    return 90 - angle;
}

float anglePlanes(const Plane& p1, const Plane& p2){
    return get_angle(p1.get_normal(), p2.get_normal());
}
