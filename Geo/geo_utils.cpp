#include "geo_utils.h"

int orientation2d(){
    
};

float areaTriangle2d(Point2d p1,Point2d p2,Point2d p3){
    // formule du determinant
    return std::abs((p2[X]-p1[X])*(p3[Y]-p1[Y]) - (p3[X]-p1[X])*(p2[Y]-p1[Y])) /2 ;
}

float areaTriangle3d(Point2d p1,Point2d p2,Point2d p3){
    // formule du determinant    
}


int orientation3d(){};
