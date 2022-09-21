#ifndef VECTOR_H
#define VECTOR_H

#include <iostream>
#include <array>
#include <cmath>
#include "../Helper/helper.h"

#define DIM2 2
#define DIM3 3

#define X 0
#define Y 1
#define Z 2


template <size_t dimension>
class Vector{
    //static_assert(std::is_arithmetic<float> ,"types of coordinates must be arithmetic");
    static_assert(dimension >= DIM2,"dimension must be at least 2");

public:
    Vector() = default;
    Vector(std::array<float, dimension> _coords): coords(_coords){};
    Vector(float x, float y,float z): coords(std::array<float, DIM3>{x,y,z}){};
    Vector(float x, float y): coords(std::array<float, DIM2>{x,y}){};
    ~Vector() = default;

    // defining useful operators
    bool operator==(const Vector<dimension>& other) const; 
    bool operator!=(const Vector<dimension>& other) const;
    Vector<dimension> operator+(const Vector<dimension>& other) const;
    Vector<dimension> operator-(const Vector<dimension>& other) const;
    bool operator<=(const Vector<dimension>& other) const;
    bool operator>=(const Vector<dimension>& other) const;
    float operator[](const unsigned int) const;
    Vector<dimension> operator*(const Vector<dimension>& other) const;
    Vector<dimension> operator*(float lambda) const;
    float dotProd(const Vector<dimension>& other) const;
    Vector<dimension> cross_prod(const Vector<dimension>& other) const;
    float norm2() const;
    void normalize();
    bool colinear(const Vector<dimension>& _other) const;

    // getter & setter 
    std::array<float, dimension> get_coords() const {return coords;};  
    void assign(float value,int position){
        coords[position] = value;
        std::cout << value <<std::endl;
    };

private:
    std::array<float, dimension> coords;
};

typedef Vector<DIM2> Vector2f;
typedef Vector<DIM3> Vector3f;

template <size_t dimension>
std::ostream& operator<<(std::ostream& out, const Vector<dimension>& vector)
{
    std::array<float,dimension> _coords = vector.get_coords();
    out << "Vector : size :  " << dimension << ": [";
    for(auto coord: _coords){
        out << coord << ", ";
    } 
    out << "]";
    return out;
}

template <size_t dimension>
bool Vector<dimension>::operator==(const Vector<dimension>& other) const{
    for (size_t i{0}; i < dimension; i++){
        if (other.coords[i] != coords[i]){
            return false;
        }
    }
    return true;
};

template <size_t dimension>
bool Vector<dimension>::operator!=(const Vector<dimension>& other) const{
    return (!(*this == other));
};

template <size_t dimension>
bool Vector<dimension>::operator<=(const Vector<dimension>& other) const{
    for (size_t i{0}; i < dimension; i++){
        if (other.coords[i] >= coords[i]){
            return false;
        }
    }
    return true;
};

template <size_t dimension>
bool Vector<dimension>::operator>=(const Vector<dimension>& other) const{
    return (!(*this <= other));
};

template <size_t dimension>
Vector<dimension> Vector<dimension>::operator+(const Vector<dimension>& other) const{
    std::array<float,dimension> arr;
    Vector<dimension> sum_vec(arr);
    for (size_t i{0}; i < dimension; i++){
        sum_vec.coords[i] = coords[i] + other.coords[i];
    }
    return sum_vec;
};

template <size_t dimension>
Vector<dimension> Vector<dimension>::operator-(const Vector<dimension>& other) const{
    std::array<float,dimension> arr;
    Vector<dimension> sum_vec(arr);
    for (size_t i{0}; i < dimension; i++){
        sum_vec.coords[i] = coords[i] - other.coords[i]; 
    }
    return sum_vec;
};

template <size_t dimension>
Vector<dimension> Vector<dimension>::operator*(const Vector<dimension>& other) const{
    std::array<float,dimension> arr;
    Vector<dimension> prod_vec(arr);
    for (size_t i{0}; i < dimension; i++){
        prod_vec.coords[i] = coords[i] * other.coords[i]; 
    }
    return prod_vec;
};

template <size_t dimension>
Vector<dimension> Vector<dimension>::operator*(float lambda) const{
    std::array<float,dimension> arr;
    Vector<dimension> prod_vec(arr);
    for (size_t i{0}; i < dimension; i++){
        prod_vec.coords[i] = coords[i] * lambda; 
    }
    return prod_vec;
};

template<size_t dimensions>
float Vector<dimensions>::operator[](const unsigned int _index) const
{
    if (_index >= coords.size()) {
        std::cout << "Index out of bounds";
        return -1;
    }
    return coords[_index];
}

template <size_t dimension>
float Vector<dimension>::dotProd(const Vector<dimension>& other) const {
    Vector<dimension> vec = (*this) * other;
    float sum{0.0f};
    for (size_t i{0}; i < dimension; i++){
        sum += vec[i]; 
    }
    return sum;
};

template <size_t dimension>
Vector<dimension> Vector<dimension>::cross_prod(const Vector<dimension>& other) const{
    std::array<float,dimension> arr;
    Vector<dimension> cross_vec(arr);
    if (dimension == 2 || dimension > 3)
    {
        std::cout << "Error computing cross product: only for vectors of size 3" << std::endl;
    } 
    else if (dimension == 3){
        cross_vec.coords[X] = coords[Y]*other.coords[Z] - coords[Z]*other.coords[Y];
        cross_vec.coords[Y] = -coords[X]*other.coords[Z] + coords[Z]*other.coords[X]; 
        cross_vec.coords[Z] = coords[X]*other.coords[Y] - coords[Y]*other.coords[X]; 
    } 
    return cross_vec;
};

template <size_t dimension>
float Vector<dimension>::norm2() const {
    float value{0.0f};
    for (size_t i{0}; i < dimension; ++i){
        value += coords[i]*coords[i];
    }
    return sqrt(value);
}

template <size_t dimension>
void Vector<dimension>::normalize(){
    float norm2 = this->norm2();
    for (size_t i{0}; i < dimension; ++i){
        assign(coords[i]/norm2,i);
    }
}

template <size_t dimension>
bool Vector<dimension>::colinear(const Vector<dimension>& _other) const {
    std::array<float,dimension> _other_coords = _other.get_coords();
    float sum = coords[X]*_other_coords[Y] - coords[Y]*_other_coords[X] + 
    coords[Y]*_other_coords[Z] - coords[Z]*_other_coords[Y] + 
    coords[X]*_other_coords[Z] - coords[Z]*_other_coords[X];

    if (isEqualZ(sum)){
        return true;
    }
    return false;
}

float crossProduct2d(Vector2f& a, Vector2f& b);

/* u.(v*w) */
float scalerTripleProduct(Vector3f& a, Vector3f& b, Vector3f& c);

Vector2f perpendicluar(Vector2f&);

bool orthogonal(Vector3f a, Vector3f b);

#endif


