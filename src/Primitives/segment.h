#ifndef SEGMENT_H
#define SEGMENT_H

#include "vector.h"

template <std::size_t dimension>
class Line {
public:
    Vector<dimension> start_point;
    Vector<dimension> end_point;

    Line() = default;
    Line(const Vector<dimension>& _start_point, const Vector<dimension>& _end_point):start_point(_start_point), end_point(_end_point){};    

    Vector<dimension> getDirection(){return end_point - start_point;};

};

typedef Line<2> Line2d;
typedef Line<3> Line3d;

#endif