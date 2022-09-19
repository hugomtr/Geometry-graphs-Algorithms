#include <iostream>
#include "vector.h"

int main(){
    Vector<int,3> v1(1,2,3);
    Vector<int,3> v2(3,-2,1);
    Vector<double,2> v3(1,2);
    Vector<double,2> v4(1,3);
    std::cout << "v1 " << v1 << std::endl;
    std::cout << "v2 " << v2 << std::endl;
    std::cout << "v3 " << v3 << std::endl;
    std::cout << "v4 " << v4 << std::endl;

    bool v1v2 = v1 == v2;
    std::cout << "v1 == v2 " << v1v2 << std::endl;
    std::cout << "v1 - v2 " << v1-v2 << std::endl;
    std::cout << "v1 + v2 " << v1 + v2 << std::endl;
    std::cout << "v2 . v2 " << v1*v2 << std::endl;
    std::cout << "v2 * v2 " << v1.cross_prod(v2) << std::endl;

    return 0;
}
