#include <iostream>
#include "Core/vector.h"
#include "Core/line.h"
#include "Core/Plane.h"
#include "Geo/intersection.h"


int main(){
    Vector<3> v1(1,2,3);
    Vector<3> v2(3,-2,1);
    Vector<2> v3(1.9,2.3);
    Vector<2> v4(1.3,3.9);
    std::cout << "v1 " << v1 << std::endl;
    std::cout << "v2 " << v2 << std::endl;
    std::cout << "v3 " << v3 << std::endl;
    std::cout << "v4 " << v4 << std::endl;

    bool v1v2 = v1 == v2;
    std::cout << "v1 == v2 " << v1v2 << std::endl;
    std::cout << "v1 - v2 " << v1-v2 << std::endl;
    std::cout << "v1 + v2 " << v1 + v2 << std::endl;
    std::cout << "v2 . v2 " << v1*v2 << std::endl;
    std::cout << "v2 * v2 " << v1.cross_prod(v2) << std::endl;
    v2.normalize();
    std::cout << "v2 normalize " << v2 << std::endl;

    std::array<float, 4> arrv5 {1.9,2.3,5.6,7.4};
    std::array<float, 4> arrv6 {1.3,3.9,4,3};
    Vector<4> v5(arrv5);
    Vector<4> v6(arrv6);

    std::cout << "v5 * v6 " << v5*v6 << std::endl;

    Vector2f v21(0,0);
    Vector2f v22(1,2);
    Vector2f v23(-1,2);
    Vector2f v24(-1,-1);

    Line2d line1(v22,v21);
    Line2d line2(v23,v24);

    Point2d point_intersect(0.0f,0.0f);
    std::cout << "intersect ?" << intersect(line1,line2,point_intersect) << std::endl;
    std::cout << "point_intersect " << point_intersect << std::endl;

    Vector3f v7(2,1,-1);
    Vector3f v8(0,-2,0);
    Vector3f v9(1,-1,2);

    Plane<3> plane(v7,v8,v9);
    Plane<3> planebis(v7,5);
    std::cout << "plane " << plane << std::endl;
    std::cout << "plane " << v7 -v8 << std::endl;

    return 0;
}
