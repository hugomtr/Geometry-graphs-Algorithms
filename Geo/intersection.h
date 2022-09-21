#include "../Core/point.h"
#include "../Core/line.h"
#include "../Core/Plane.h"
#include "../Helper/helper.h"

// Return true if 2 lines are intersecting and store the intersection_point
bool intersect(const Line3d& line1,const Line3d& line2,Point3d& intersection_point);

bool intersect(const Line2d& line1,const Line2d& line2,Point2d& intersection_point);

// Return true if a line intersect the plane and store the intersection_point
/* if the intersection is the all plane it display a specific message and return true */
bool intersectLinePlane(const Line3d& line,const Plane& plane,Point3d& intersection_point);

bool intersectPlane(const Plane& p1,const Plane& p2,Line3d& intersection_line);



