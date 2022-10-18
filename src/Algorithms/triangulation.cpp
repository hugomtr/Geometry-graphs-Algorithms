#include "triangulation.h"

void initialize_ears_status(Polygon2d* polygon)
{
	Vertex2d* v0, *v1, *v2;

	auto vertices = polygon->get_vertex_list_ptr();
	v1 = vertices[0];
	do {
		v0 = v1->pred;
		v2 = v1->next;
		v1->is_ear = is_diagonal(v0,v2,polygon);
		v1 = v1->next;
	} while (v1->point != vertices[0]->point);
}

void triangulate_earclipping(Polygon2d* poly, std::vector<Edge2d>& edge_list){
	
	initialize_ears_status(poly);

	auto vertex_list = poly->get_vertex_list_ptr();

	int no_vertex_to_process = vertex_list.size();
	
	Vertex2d* v0, * v1, * v2, * v3, * v4;
	int index = 0;
	while (no_vertex_to_process > 3){	
		for (size_t i = 0; i < vertex_list.size(); i++)
		{
			v2 = vertex_list[i];
			if (v2->is_ear && !v2->is_process) {
				v3 = v2->next;
				v4 = v3->next;
				v1 = v2->pred;
				v0 = v1->pred;

				edge_list.push_back(Edge2d(*v1, *v3));
				std::cout << "v1" << v1->point << "v3" << v3->point << std::endl;

				v2->is_process = true;
				v1->next = v3;
				v3->pred = v1;

				v1->is_ear = is_diagonal(v0, v3, nullptr);
				v3->is_ear = is_diagonal(v1, v4, nullptr);

				no_vertex_to_process--;
				index++;
				break;
			}
		}
	}
}