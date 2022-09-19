#include <iostream>
#include "Core/vector.h"

int main(){
    Vector<3> v1(1,2,3);
    Vector<3> v2(3,-2,1);
    Vector<2> v3(1.9,2.3);
    Vector<2> v4(1.3,3.9);
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
    v2.normalize();
    std::cout << "v2 normalize " << v2 << std::endl;

    std::array<float, 4> arrv5 {1.9,2.3,5.6,7.4};
    std::array<float, 4> arrv6 {1.3,3.9,4,3};
    Vector<4> v5(arrv5);
    Vector<4> v6(arrv6);

    std::cout << "v5 * v6 " << v5*v6 << std::endl;
    return 0;
}
