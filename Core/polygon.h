#pragma once
#include <iostream>
#include <vector>
#include <list>
#include "vector.h"
#include "../Geo/intersection.h"

enum VERTEX_TYPE {
    Convex,Reflex
};

template<size_t dimension>
struct Vertex{
    Vector<dimension> point;
    Vertex<dimension>* next;
    Vertex<dimension>* pred;

    Vertex(const Vector<dimension>& _point)
    : point(_point), next(nullptr), pred(nullptr){}

    Vertex(const Vector<dimension>& _point,const Vector<dimension>* _next,const Vector<dimension>* _pred)
    : point(_point), next(_next), pred(_pred){}

    VERTEX_TYPE get_vertex_type2d() const {
        Point2d A = point;
        Point2d B = next->point;
        Point2d C = pred->point;

        Vector2f AB = B - A;
        Vector2f AC = C - A;

        float det = AB[X]*AC[Y] - AB[Y]*AC[X];
        if (det < 0){
            return Reflex;
        } else {
            return Convex;
        }
    }
};

template<size_t dimension>
class Polygon {
    std::vector<Vertex<dimension>> vertex_list;
public:
    Polygon() = default;
    Polygon(std::vector<Vertex<dimension>>& _vertex_list){
        std::size_t n = _vertex_list.size();
        
        if (n < 3){
            std::cout << "Not enough vertex must be >= 3" << std::endl;
            return;
        }
        vertex_list = _vertex_list;

    }

    /* points have to be initialized in counter-clockwise-order */
    Polygon(const std::list<Vector<dimension>>& _vector_list){
        const unsigned int n = _vector_list.size();
        if (n < 3){
            std::cout << "Not enough vertex must be >= 3" << std::endl;
            return;
        }

        for (auto const& v : _vector_list){
            vertex_list.push_back(Vertex<dimension>(v));
        }

        for(std::size_t i{0}; i < n;i++){
            vertex_list[i].next = &(vertex_list[i+1]);
            vertex_list[i].pred = &(vertex_list[i-1]);
        }

        vertex_list[0].pred = &(vertex_list[n-1]);
        vertex_list[n-1].next = &(vertex_list[0]);
    }

    std::vector<Vertex<dimension>> get_vertex_list() const {return vertex_list;};
};


typedef Polygon<3> Polygon3d;
typedef Polygon<2> Polygon2d;
typedef Vertex<3> Vertex3d;
typedef Vertex<2> Vertex2d;
