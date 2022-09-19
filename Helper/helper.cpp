#include <cmath>
#include "helper.h"

bool isEqualZ(float x){
    if (std::abs(x) < 0.0000001){
        return true;
    }
    return false; 
}