#include "triangulate.h"

// void update_ear_status(Polygon2d& poly){
//     size_t n = poly.get_vertex_list().size(); 
//     Vertex2d v = poly.get_vertex_list()[0];
//     Vertex2d* pred = v.pred;
//     Vertex2d* next = v.next;

//     for (size_t i = 0; i < n ; i++){
//         if (is_convex(*pred,v,*next)){
//             v.is_ear = is_diagonal(*pred,*next,poly);
//         }
//     }
// }

// void triangulate_earclipping2d(Polygon2d& poly,std::vector<Edge2d>& edges_list){
//     /* initialize an empty list for stocking all diagonal */
//     std::vector<Edge2d> edges_list;
//     std::vector<Vertex2d> vertex_list = poly.get_vertex_list();
//     size_t n = vertex_list.size(); 
//     Vertex2d v = poly.get_vertex_list()[0];

//     if (n <= 3){
//         std::cout << "must be a polynom with > 3 vertex " << std::endl;
//         return;
//     }

//     while( n > 3){
//         std::vector<Vertex2d>::iterator left_vertex_it;        
        
//         /* 2 neigbors of the chosen vertex */
//         Vertex2d* pred = (v.pred)->pred;
//         Vertex2d* next = (v.next)->next;
        
//         if (v.is_ear){
//             /* report the diagonal */
//             Edge2d new_diagonal(*pred,*next);
//             edges_list.push_back(new_diagonal);
//             left_vertex_it = std::remove(vertex_list.begin(),vertex_list.end(),v);
//             size_t n = vertex_list.size(); 
            
//             /* updating the vertex list in our polygon */
//             poly.set_vertex_list(vertex_list);

//             update_ear_status(poly);    
//         }
//         v = *next;
//     }
// }

