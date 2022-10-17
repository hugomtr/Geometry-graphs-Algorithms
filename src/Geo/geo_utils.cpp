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

bool is_diagonal(const Vertex2d& start_vertex,const Vertex2d& end_vertex,const Polygon2d& p){
	std::vector<Vertex2d> vertex_list;
	size_t n = (p.get_vertex_list()).size();

	if(n == 0)
		vertex_list = p.get_vertex_list();
	else {
		auto vertex_ptr = start_vertex.next;
		vertex_list.push_back(start_vertex);
		while (vertex_ptr != &start_vertex) {
			vertex_list.push_back(*vertex_ptr);
			vertex_ptr = vertex_ptr->next;
		}
	}

	/* Test 1 line should not intersect with any other edges */
	n = (p.get_vertex_list()).size();
	std::list<Line2d> edges_list;
	const Point2d A(start_vertex.point);
	const Point2d B(end_vertex.point);
	const Line2d diagonal(A,B);

	for (size_t i = 0; i < n;i++){
		Vertex2d vertex_candidate = vertex_list[i];
		// just making sure that we don't consider edges starting or ending on the 2 vertex
		if (&start_vertex != &vertex_candidate && &start_vertex != vertex_candidate.next 
			&& &end_vertex != &vertex_candidate && &end_vertex != vertex_candidate.next)
		{
			Line2d edge(vertex_list[i].point,(vertex_list[i].next)->point);
			edges_list.push_back(edge);
		}
	}

	for (const Line2d& edge : edges_list){
		Point2d M;
		// M store the intersection point
		if (intersect(edge,diagonal,M)){
			int type_intersection = orientation2d(edge.get_start_point(),edge.get_start_point() + edge.get_direction(),M);
			int type_intersection_bis = orientation2d(A,B,M);
			if (type_intersection == ON_SEGMENT && type_intersection_bis == ON_SEGMENT){
				// M is the intersection point between an edge segment and the diagonal candidate segment
				int type_intersection_bis = orientation2d(A,B,M);
				return false;
			}
		}
	}

	/* 
	Test 2 If the start vertex is a convex vertex then, 
	the neighbors should lie on different sides of the line
	*/

	VERTEX_TYPE type = start_vertex.get_vertex_type2d();
	if (type == Convex ){
		int type_orientation_pred = orientation2d(A,B,(start_vertex.pred)->point);
		int type_orientation_next = orientation2d(A,B,(start_vertex.next)->point);
		bool condition = (type_orientation_pred == LEFT && type_orientation_next == RIGHT) || (type_orientation_pred == RIGHT && type_orientation_next == LEFT);
		if (!condition){
			return false;
		}
	}

	/* 
	Test 3 If the start vertex is a reflex vertex then, 
	it should not be an exterior line
	*/

	if (type == Reflex ){
		Point2d M;
		Line2d neighbors_segment((start_vertex.pred)->point,(start_vertex.next)->point);

		// M store the intersection point of segment [start_vertex.next,start_vertex.pred]
		// and diagonal line
		
		intersect(neighbors_segment,diagonal,M);
		int type_intersection = orientation2d(A,B,(start_vertex.next)->point);
		if (type_intersection == ON_SEGMENT){
			return false;
		}
	}
	return true;
}