#ifndef TRIANGULATE_H
#define TRIANGULATE_H

#include "geo_utils.h"
#include <bits/stdc++.h>

void update_ear_status(Polygon2d& poly);

void triangulate_earclipping2d(Polygon2d& poly,std::vector<Edge2d>& edges_list);

#endif