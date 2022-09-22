#ifndef LINE_H
#define LINE_H

#include "../Core/vector.h"

template <std::size_t dimension>
class Line {
    Vector<dimension> start_point;
    Vector<dimension> direction;

public:
    Line() = default;
    Line(const Vector<dimension>& _start_point, const Vector<dimension>& _end_point){
        start_point = _start_point;
        direction = _end_point - _start_point;
        //direction.normalize();
    };    

    Vector<dimension> get_start_point() const { return start_point;}

    Vector<dimension> get_direction() const { return direction;}

    void set_direction(Vector<dimension> _direction) {direction = _direction;}
    void set_start_point(Vector<dimension> _start_point) {start_point = _start_point;}
};

typedef Line<DIM2> Line2d;
typedef Line<DIM3> Line3d;

#endif