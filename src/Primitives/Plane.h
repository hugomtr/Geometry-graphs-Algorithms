#ifndef PLANE_H
#define PLANE_H

#include "vector.h"
#include "point.h"


class Plane {
    Vector3f normal;
    float d = 0.0f;
public:
    Plane() = default;
    
    Plane(Vector3f& _normal, float _d){
        normal = _normal;
        d = _d;
    }
    
    Plane(Vector3f& _normal, Point3d& _point)
    {
        _normal.normalize();
        normal = _normal;
        d = normal.dotProd(_point);
    }

    Plane(Point3d& v1,Point3d& v2,Point3d& v3){
        Vector3f v21 = v2 - v1;
        Vector3f v31 = v3 - v1;
        normal = v21.cross_prod(v31);
        // find the "constante" => dot product between v1 (origin of our plane) and the normal vector
        normal.normalize();
        d = v1.dotProd(normal);
    }
    
    friend std::ostream& operator<<(std::ostream& out,Plane& plane){out << "Plane : [ normal_vector :  " << plane.normal << ", constante : " << plane.d ;
        return out;} 

    Vector3f get_normal() const {return normal;}

    float get_d() const	{return d;}
};

#endif