#include "intersection.h"

bool intersect(Line3d& line1, Line3d& line2, Point3d& intersection_point){
}

bool intersect(Line2d& line1, Line2d& line2, Point2d& intersection_point){
    if (isEqualZ(crossProduct2d(line1.direction, line2.direction))){
        return false;
    }
    
    float x_inter,y_inter;
    
    if (line1.direction[X] == 0){
        /* cas où il y'a une droite verticale 
        {X_1 + t*Ux_2 = X_inter
        {Y_1 + t*Uy_2 = Y_inter
        <=> 
        {(X_inter - X_1)/Ux_2 = t
        {Y_inter = Y_1 + Uy_2 * (X_inter - X_1)/Ux_2
        */
        x_inter = line1.start_point[X];
        y_inter = line2.start_point[Y] + line2.direction[Y]*((x_inter - line2.start_point[X])/line2.direction[X]);

    } else if (line2.direction[X] == 0) {
        x_inter = line2.start_point[X];
        y_inter = line1.start_point[Y] + line1.direction[Y]*((x_inter - line1.start_point[X])/line1.direction[X]);
    } 
    else {
        /* autre cas où l'équation de droite est bien defini (pas de droite verticale) */
        // coeff directeur droite line1     
        float m1 = line1.direction[Y]/line1.direction[X];
        // coeff directeur droite line2     
        float m2 = line2.direction[Y]/line2.direction[X];
        // ord à l'origine line1     
        float b1 = line1.start_point[Y] - line1.start_point[X] * m1;
        // ord à l'origine line2      
        float b2 = line2.start_point[Y] - line2.start_point[X] * m2;

        x_inter = (b2 - b1) / (m1 - m2);
        y_inter = x_inter * m1 + b1;
    }
    
    intersection_point = Point2d(x_inter,y_inter);

    return true;
}

