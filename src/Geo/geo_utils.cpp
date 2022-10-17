#include "geo_utils.h"

float areaTriangle2d(const Point2d p1,const Point2d p2,const Point2d p3){
    // formule du determinant
    return std::abs((p2[X]-p1[X])*(p3[Y]-p1[Y]) - (p3[X]-p1[X])*(p2[Y]-p1[Y])) /2 ;
}

int orientation2d(const Point2d& a, const Point2d& b, const Point2d& c)
{
	float area = (b[X]-a[X])*(c[Y]-a[Y]) - (c[X]-a[X])*(b[Y]-a[Y]);

	if (area > 0 && area < TOLERANCE)
		area = 0;

	if (area < 0 && area > TOLERANCE)
		area = 0;

	Vector2f ab = b - a;
	Vector2f ac = c - a;

	if (area > 0.0)
		return LEFT;
	if (area < 0.0)
		return RIGHT;
	if ((ab[X] * ac[X] < 0.0) || (ab[Y] * ac[Y] < 0.0))
		return ON_LINE;
	if (ab.norm2() < ac.norm2())
		return ON_LINE;
	if (a == c)
		return ON_LINE;
	if (b == c)
		return ON_LINE;
	return ON_SEGMENT;
}

// int orientation3d(){}

bool coplaner(Point3d& a,Point3d& b,Point3d& c){
	float value = scalerTripleProduct(a,b,c);
	if (isEqualZ(value)){
		return true;
	}
	return false;
}

bool is_diagonal(const Vertex2d* v1,const Vertex2d* v2,const Polygon2d* polygon_ptr){

	std::vector<Vertex2d *> vertex_list;

	if(polygon_ptr){
		//Polygon2d p = *polygon_ptr;
		vertex_list = polygon_ptr->get_vertex_list_ptr();
	} else {
		auto vertex_ptr = v1->next;
		vertex_list.push_back((Vertex2d*)v1);
		while (vertex_ptr->point != v1->point) {
			vertex_list.push_back((Vertex2d*)vertex_ptr);
			vertex_ptr = vertex_ptr->next;
		}
	}

	Line2d v1v2(v1->point, v2->point);

	/* Test 1 line should not intersect with any other edges */

	Vertex2d *current, *next;
	for (size_t i = 1; i <vertex_list.size(); i++){
		current = vertex_list[i];
		next = vertex_list[i]->next;

		Point2d intersect_point;
		Line2d currentNext(current->point, next->point);
		bool on_segment = false;
		
		intersect(v1v2, currentNext,intersect_point);
		int type_intersection_curr_next = orientation2d(current->point, next->point,intersect_point);
		int type_intersection_v1v2 = orientation2d(v1->point, v2->point, intersect_point);
		

		if (type_intersection_curr_next == ON_SEGMENT && type_intersection_v1v2 == ON_SEGMENT){
			on_segment = true;
		}
		
		if (current != v1 && next != v1 && current != v2 && next != v2
			&& on_segment){ 
			return false;
		}
	} 

	/* 
	Test 2 If the start vertex is a convex vertex then, 
	the neighbors should lie on different sides of the line
	*/ 

	VERTEX_TYPE type = v1->get_vertex_type2d();
	if (type == Convex ){
		int type_orientation_pred = orientation2d(v1->point,v2->point,v1->pred->point);
		int type_orientation_next = orientation2d(v1->point,v2->point,v1->next->point);
		bool condition = (type_orientation_pred == LEFT && type_orientation_next == RIGHT) || (type_orientation_pred == RIGHT && type_orientation_next == LEFT);
		if (!condition){
			return false;
		}
	}

	// /* 
	// Test 3 If the start vertex is a reflex vertex then, 
	// (start_vertex,end_vertex) should not be an exterior line
	// */

	if (type == Reflex ){
		Point2d M;
		Line2d neighbors_segment((v1->pred)->point,(v1->next)->point);

		// M store the intersection point of segment [v1.next,v1.pred]
		// and diagonal line
		intersect(v1v2,neighbors_segment,M);
		int type_intersection = orientation2d(v1->point,v2->point,v1->next->point);
		if (type_intersection == ON_SEGMENT){
			std::cout << "in 3" << std::endl;
			return false;
		}
	}
	return true;
}