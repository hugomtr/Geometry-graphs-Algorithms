#include <iostream>

struct Vertex{
    int a;
    float b;
    float* c;
    Vertex(int _a, float _b): a(_a), b(_b) {};
};

int main(){
    Vertex vertex(1,2);

    std::cout << vertex.a << std::endl;
    // vertex.c = &(vertex.b);
    std::cout << vertex.c << std::endl;
    return 0;
}
