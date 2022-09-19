#ifndef VECTOR_H
#define VECTOR_H

#include <iostream>
#include <array>

#define DIM2 2
#define DIM3 3

#define X 0
#define Y 1
#define Z 2


template <typename coordinates_type, size_t dimension>
class Vector{
    //static_assert(std::is_arithmetic<coordinates_type> ,"types of coordinates must be arithmetic");
    static_assert(dimension >= DIM2,"dimension must be at least 2");

public:
    Vector() = default;
    Vector(std::array<coordinates_type, dimension> _coords): coords(_coords){};
    Vector(coordinates_type x, coordinates_type y,coordinates_type z): coords(std::array<coordinates_type, DIM3>{x,y,z}){};
    Vector(coordinates_type x, coordinates_type y): coords(std::array<coordinates_type, DIM2>{x,y}){};
    ~Vector() = default;

    // defining useful operators
    bool operator==(const Vector<coordinates_type,dimension>& other);
    bool operator!=(const Vector<coordinates_type,dimension>& other);
    Vector<coordinates_type,dimension> operator+(const Vector<coordinates_type,dimension>& other);
    Vector<coordinates_type,dimension> operator-(const Vector<coordinates_type,dimension>& other);
    bool operator<=(const Vector<coordinates_type,dimension>& other);
    bool operator>=(const Vector<coordinates_type,dimension>& other);
    Vector<coordinates_type,dimension> operator*(const Vector<coordinates_type,dimension>& other);
    Vector<coordinates_type,dimension> cross_prod(const Vector<coordinates_type,dimension>& other);
    coordinates_type norm2();
    std::array<coordinates_type, dimension> get_coords() const {return coords;};  

private:
    std::array<coordinates_type, dimension> coords;

};

template <typename coordinates_type,size_t dimension>
std::ostream& operator<<(std::ostream& out, const Vector<coordinates_type,dimension>& vector)
{
    std::array<coordinates_type,dimension> _coords = vector.get_coords();
    if (dimension == 2)
    {   out << "Vector : [ size :  " << dimension
        << ", X : " << _coords[X] << ", Y : " << _coords[Y];} 
    else if (dimension == 3){
        out << "Vector : [ size :  " << dimension
        << ", X : " << _coords[X] << ", Y : " << _coords[Y] << ", Z : " << _coords[Z];} 
    return out;
}

template <typename coordinates_type,size_t dimension>
bool Vector<coordinates_type,dimension>::operator==(const Vector<coordinates_type,dimension>& other){
    for (size_t i{0}; i < dimension; i++){
        if (other.coords[i] != coords[i]){
            return false;
        }
    }
    return true;
};

template <typename coordinates_type,size_t dimension>
bool Vector<coordinates_type,dimension>::operator!=(const Vector<coordinates_type,dimension>& other){
    return (!(*this == other));
};

template <typename coordinates_type,size_t dimension>
bool Vector<coordinates_type,dimension>::operator<=(const Vector<coordinates_type,dimension>& other){
    for (size_t i{0}; i < dimension; i++){
        if (other.coords[i] >= coords[i]){
            return false;
        }
    }
    return true;
};

template <typename coordinates_type,size_t dimension>
bool Vector<coordinates_type,dimension>::operator>=(const Vector<coordinates_type,dimension>& other){
    return (!(*this <= other));
};

template <typename coordinates_type,size_t dimension>
Vector<coordinates_type,dimension> Vector<coordinates_type,dimension>::operator+(const Vector<coordinates_type,dimension>& other){
    std::array<coordinates_type,dimension> arr;
    Vector<coordinates_type,dimension> sum_vec(arr);
    for (size_t i{0}; i < dimension; i++){
        sum_vec.coords[i] = coords[i] + other.coords[i];
    }
    return sum_vec;
};

template <typename coordinates_type,size_t dimension>
Vector<coordinates_type,dimension> Vector<coordinates_type,dimension>::operator-(const Vector<coordinates_type,dimension>& other){
    std::array<coordinates_type,dimension> arr;
    Vector<coordinates_type,dimension> sum_vec(arr);
    for (size_t i{0}; i < dimension; i++){
        sum_vec.coords[i] = coords[i] - other.coords[i]; 
    }
    return sum_vec;
};

template <typename coordinates_type,size_t dimension>
Vector<coordinates_type,dimension> Vector<coordinates_type,dimension>::operator*(const Vector<coordinates_type,dimension>& other){
    std::array<coordinates_type,dimension> arr;
    Vector<coordinates_type,dimension> sum_vec(arr);
    for (size_t i{0}; i < dimension; i++){
        sum_vec.coords[i] = coords[i] * other.coords[i]; 
    }
    return sum_vec;
};

template <typename coordinates_type,size_t dimension>
Vector<coordinates_type,dimension> Vector<coordinates_type,dimension>::cross_prod(const Vector<coordinates_type,dimension>& other){
    std::array<coordinates_type,dimension> arr;
    //std::array<coordinates_type,dimension> _coords = other.get_coords();
    Vector<coordinates_type,dimension> cross_vec(arr);
    if (dimension == 2)
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

template <typename coordinates_type,size_t dimension>
coordinates_type Vector<coordinates_type,dimension>::norm2(){
    if (dimension == 2)
    {
        return coords[X]*coords[X] + coords[Y]*coords[Y];
    } 
    else if (dimension == 3){
        return coords[X]*coords[X] + coords[Y]*coords[Y]+ coords[Z]*coords[Z];
    } 
}
#endif

