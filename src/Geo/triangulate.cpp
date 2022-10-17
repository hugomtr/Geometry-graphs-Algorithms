#include "triangulate.h"

void update_ear_status(Polygon2d& poly){    
    size_t n = poly.get_vertex_list().size(); 
    Vertex2d v = poly.get_vertex_list()[0];
    Vertex2d* pred = v.pred;
    Vertex2d* next = v.next;

    for (size_t i = 0; i < n ; i++){
        if (is_convex(*pred,v,*next)){
            /* diagonal test */
            v.is_ear = is_diagonal(*pred,*next,poly);
        }
    }
}

void triangulate_earclipping2d(Polygon2d& poly,std::vector<Edge2d>& edges_list){
    update_ear_status(poly);
    
    /* initialize an empty list for stocking all diagonal */
    std::vector<Vertex2d> vertex_list = poly.get_vertex_list();
    size_t n = vertex_list.size(); 
    Vertex2d* v0, *v1, *v2, *v3, *v4;

    if (n <= 3){
        std::cout << "must be a polynom with > 3 vertex " << std::endl;
        return;
    }

    while( n > 3){
        for (size_t i{0}; i < vertex_list.size(); i++){
            if (v2->is_ear && !v2->is_process){
                v3 = v2->next;
                v4 = v3->next;
                v1 = v2->pred;
                v0 = v1->pred;

                /* report the diagonal */
                Edge2d new_diagonal(*v1,*v3);
                edges_list.push_back(new_diagonal);
                v2->is_process = true;
                
                v1->next = v3;
                v3->pred = v1;
                Polygon2d default_polygon;
				v1->is_ear = is_diagonal(*v0, *v3, default_polygon);
				v3->is_ear = is_diagonal(*v0, *v3, default_polygon);

				n--;
				break;
            }
        }
    }
}

