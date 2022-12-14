#include <iostream>

#include "Primitives/vector.h"
#include "Primitives/line.h"
#include "Primitives/Plane.h"
#include "Geo/intersection.h"
#include "Geo/angle.h"
#include "Primitives/polygon.h"
#include "Geo/geo_utils.h"
#include "Algorithms/triangulation.h"

int main(){
    // Vector<3> v1(1,2,3);
    // Vector<3> v2(3,-2,1);
    // Vector<2> v3(1.9,2.3);
    // Vector<2> v4(1.3,3.9);
    // std::cout << "v1 " << v1 << std::endl;
    // std::cout << "v2 " << v2 << std::endl;
    // std::cout << "v3 " << v3 << std::endl;
    // std::cout << "v4 " << v4 << std::endl;

    // bool v1v2 = v1 == v2;
    // std::cout << "v1 == v2 " << v1v2 << std::endl;
    // std::cout << "v1 - v2 " << v1-v2 << std::endl;
    // std::cout << "v1 + v2 " << v1 + v2 << std::endl;
    // std::cout << "v2 . v2 " << v1*v2 << std::endl;
    // std::cout << "v2 * v2 " << v1.cross_prod(v2) << std::endl;
    // v2.normalize();
    // std::cout << "v2 normalize " << v2 << std::endl;

    // std::array<float, 4> arrv5 {1.9,2.3,5.6,7.4};
    // std::array<float, 4> arrv6 {1.3,3.9,4,3};
    // Vector<4> v5(arrv5);
    // Vector<4> v6(arrv6);

    // std::cout << "v5 * v6 " << v5*v6 << std::endl;

    // Vector2f v21(0,0);
    // Vector2f v22(1,2);
    // Vector2f v23(-1,2);
    // Vector2f v24(-1,-1);

    // Line2d line1(v22,v21);
    // Line2d line2(v23,v24);

    // Point2d point_intersect(0.0f,0.0f);
    // std::cout << "intersect ?" << intersect(line1,line2,point_intersect) << std::endl;
    // std::cout << "point_intersect " << point_intersect << std::endl;

    // Vector3f v7(2,1,-1);
    // Vector3f v8(0,-2,0);
    // Vector3f v9(1,-1,2);

    // Plane plane(v7,v8,v9);
    // Plane planebis(v7,5);
    // std::cout << "plane " << plane << std::endl;
    // std::cout << "plane " << v7 -v8 << std::endl;

	// Vector2f l1A(2, 4);
	// Vector2f l2A(-2, 6);
	// Point2d l1P(0, 3);
	// Point2d l2P(0,5);

	// Line2d l1(l1P, l1A);
	// Line2d l2(l2P, l2A);


	// auto result = angleLine2d(l1, l2);

	// std::cout << result << std::endl;

    // Vector3f l3A(0, 0,0);
	// Vector3f l4A(0, 0,0);
	// Point3d l3P(0.5, -10,-7);
	// Point3d l4P(-6,-8,-2);
    // Line3d l3(l3A,l3P);
    // Line3d l4(l4A,l4P);

	// auto result3 = angleLine3d(l3, l4);

	// std::cout << result3 << std::endl;


    // Point3d l1P1(-3, -4, -5);
	// Point3d l1P2(4, 3, 5);
	
	// Vector3f pNormal(-14.26,9.32,18.89);

	// Line3d l1(l1P1, l1P2);
    // Point3d p0(0,0,0);
	// Plane p(pNormal,p0);

    // Vector3f v31(1,2,3);
    // Vector3f v32(2,4,5);
	// std::cout << v31.colinear(v32) << std::endl;

    // Vector3f n(2,3,4);
    // Plane p(n, 8.0f);
    
    // Point3d A(2,2,3);
    // Point3d B(4,3,6);

    // Line AB(A,B);

    // Point3d intersect_point;
    // std::cout << intersectLinePlane(AB,p,intersect_point) << std::endl;
    // std::cout << intersect_point << std::endl;

    // Test sur diagonale

    // Vector2f v1(0,0);
    // Vector2f v2(0,4);
    // Vector2f v3(1,4);
    // Vector2f v4(3,2);
    // Vector2f v5(1,1);
    // Vector2f v6(1,0);

    // std::list<Vector2f> l{v1,v2,v3,v4,v5,v6};
    // Polygon2d p(l);
    // bool a = is_diagonal(p.get_vertex_list()[0],p.get_vertex_list()[2],&p);
    // bool b = is_diagonal(p.get_vertex_list()[0],p.get_vertex_list()[3],&p);
    // bool c = is_diagonal(p.get_vertex_list()[0],p.get_vertex_list()[4],&p);
    // bool d = is_diagonal(p.get_vertex_list()[1],p.get_vertex_list()[4],&p);
    // std::cout << "true : =?" << a << std::endl;
    // std::cout << "false : =?" << b << std::endl;
    // std::cout << "true : =?" << c << std::endl;
    // std::cout << "false : =?" << b << std::endl;
    // std::cout << "false : =?" << b << std::endl;
    
    // Test sur ear triangulation

    Vector2f v0(0,0);
    Vector2f v1(0,4);
    Vector2f v2(1,4);
    Vector2f v3(3,2);
    Vector2f v4(3,0);
    Vector2f v5(1,2);
    Vector2f v6(1,0);

    std::list<Vector2f> l{v0,v1,v2,v3,v4,v5,v6};

    Polygon2d pbis(l);
    std::vector<Edge2d> edges_list;

    triangulate_earclipping(&pbis,edges_list);

    return 0;
}

