#include "vector.h"
#include "../Helper/helper.h"

float crossProduct2d(Vector2f& a, Vector2f& b) {
    return a[X]*b[Y] - a[Y]*b[X];
}

Vector2f perpendicluar(Vector2f& vec){
	return Vector2f( vec[Y], -vec[X]);
}

bool orthogonal(Vector3f a, Vector3f b){
    float dotProd = a.dotProd(b);
    return isEqualZ(dotProd);
}

float scalerTripleProduct(Vector3f& a, Vector3f& b, Vector3f& c){
    Vector3f cross_prod = b.cross_prod(c);
    return a.dotProd(cross_prod);
}