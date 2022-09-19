#ifndef PLANE_H
#define PLANE_H

#include "../Core/vector.h"
#include "../Core/point.h"


template <std::size_t dimension>
class Plane {
    Vector3f normal;
    float d = 0.0f;
public:
    Plane() = default;
    Plane(Vector3f& _normal, float _d): normal(_normal), d(_d){};
    Plane(Point3d& v1,Point3d& v2,Point3d& v3){
        Vector3f v21 = v2 - v1;
        Vector3f v31 = v3 - v1;
        normal = v21.cross_prod(v31);
        // find the "constante" => dot product between v1 (origin of our plane) and the normal vector
        d = v1.dotProd(normal);
    };
    
    friend std::ostream& operator<<(std::ostream& out,Plane<dimension>& plane){out << "Plane : [ normal_vector :  " << plane.normal << ", constante : " << plane.d ;
        return out;} 
};

#endif