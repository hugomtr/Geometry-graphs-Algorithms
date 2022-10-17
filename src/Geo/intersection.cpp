#include "intersection.h"

// bool intersect(const Line3d& line1,const Line3d& line2, Point3d& intersection_point){
// }

bool intersect(const Line2d& line1,const Line2d& line2,Point2d& intersection_point){
    
    Vector2f v1 = line1.get_direction();
    Vector2f v2 = line2.get_direction();
    Point2d a1 = line1.get_start_point();
    Point2d a2 = line2.get_start_point();

    if (isEqualZ(crossProduct2d(v1,v2))){
        return false;
    }
    
    float x_inter,y_inter;
    
    if (v1[X] == 0){
        /* cas où il y'a une droite verticale 
        {X_1 + t*Ux_2 = X_inter
        {Y_1 + t*Uy_2 = Y_inter
        <=> 
        {(X_inter - X_1)/Ux_2 = t
        {Y_inter = Y_1 + Uy_2 * (X_inter - X_1)/Ux_2
        */
        x_inter = a1[X];
        y_inter = a2[Y] + v2[Y]*((x_inter - a2[X])/v2[X]);

    } else if (v2[X] == 0) {
        x_inter = a2[X];
        y_inter = a1[Y] + v1[Y]*((x_inter - a1[X])/v1[X]);
    } 
    else {
        /* autre cas où l'équation de droite est bien defini (pas de droite verticale) */
        // coeff directeur droite line1     
        float m1 = v1[Y]/v1[X];
        // coeff directeur droite line2     
        float m2 = v2[Y]/v2[X];
        // ord à l'origine line1     
        float b1 = a1[Y] - a1[X] * m1;
        // ord à l'origine line2      
        float b2 = a2[Y] - a2[X] * m2;

        x_inter = (b2 - b1) / (m1 - m2);
        y_inter = x_inter * m1 + b1;
    }
    
    intersection_point = Point2d(x_inter,y_inter);

    return true;
}

bool intersectLinePlane(const Line3d& line,const Plane& plane,Point3d& intersection_point){
    auto normal = plane.get_normal();
    auto d = plane.get_d();
    auto vec_dir = line.get_direction();
    auto start_point = line.get_start_point();

    if (normal.dotProd(vec_dir) == 0){
        if (normal.dotProd(start_point) == d){
            std::cout << "La droite est confondus avec le plan" << std::endl;
            return true;
        }
        return false;
    }
    float t_value = (-1*(normal.dotProd(start_point)) + d)/(normal.dotProd(vec_dir));

    std::cout << "normal" << normal << std::endl;
    std::cout << "start_point" << start_point << std::endl;
    std::cout << "t" << normal.dotProd(start_point) << std::endl;

    intersection_point = start_point + vec_dir*t_value;   
    return true;
}

bool intersectPlane(const Plane& p1,const Plane& p2,Line3d& intersection_line){
    Vector3f n1 = p1.get_normal();
    Vector3f n2 = p2.get_normal();
    float d1 = p1.get_d();
    float d2 = p2.get_d();
    Vector3f direction = n1.cross_prod(n2);


	// Check if the planes are parallel.
	if (isEqualZ(direction.norm2()))
		return false;

	auto n1n2 = n1.dotProd(n2);
	auto n1n2_2 = n1n2 * n1n2;

	auto a = (d2 * n1n2 - d1) / (n1n2_2 - 1);
	auto b = (d1 * n1n2 - d2) / (n1n2_2 - 1);

	auto point = n1*a + n2*b;

    intersection_line.set_direction(direction);
    intersection_line.set_start_point(point);

    return true;
}