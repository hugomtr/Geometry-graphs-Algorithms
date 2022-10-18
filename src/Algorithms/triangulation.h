#ifndef TRIANGULATION_H
#define TRIANGULATION_H

#include "../Geo/geo_utils.h"
#include <algorithm>

void initialize_ears_status(Polygon2d* poly);

void triangulate_earclipping(Polygon2d* poly,std::vector<Edge2d>& edges_list);

#endif