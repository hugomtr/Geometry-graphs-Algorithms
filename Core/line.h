#ifndef LINE_H
#define LINE_H

#include "../Core/vector.h"

template <std::size_t dimension>
class Line {
public:

    Vector<dimension> start_point;
    Vector<dimension> direction;

public:
    Line() = default;
    Line(const Vector<dimension>& _start_point, const Vector<dimension>& _end_point){
        start_point = _start_point;
        direction = _end_point - _start_point;
    };    
};

typedef Line<2> Line2d;
typedef Line<3> Line3d;

#endif