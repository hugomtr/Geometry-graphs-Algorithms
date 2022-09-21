#ifndef HELPER_H
#define HELPER_H

#define TOLERANCE 0.0000001 
#define PI 3.1415928

enum POSITION_TYPE
{
    LEFT,RIGHT,INTER,ON_LINE,ON_SEGMENT
};

bool isEqualZ(float x);

float radianceToDegrees(float angle);

#endif