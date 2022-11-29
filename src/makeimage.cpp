#include "makeimage.h"
#include <cmath>

using namespace std;
using cs225::PNG;
using cs225::HSLAPixel;

PNG plotDijkstra(Graph g, int source, int target, double pointSize, int lineThickness) {
    PNG worldMap;
    Dijkstras dij;
    worldMap.readFromFile("../Images/map.png");
    vector<int> path = dij.getPath(g, source, target);
    // iterates over every airport in the path
    for (size_t i = 0; i < path.size() - 1; i++) {
        int id1 = path[i];
        // draw a line between this airport and the next (excludes the last iteration)
        // the routes dataset doesn't specify whether the flight is eastward or westward so
        // it is assumed that the line doesn't wrap around the map
        int id2 = path[i+1];
        plotLine(worldMap, g.getLatitude(id1), g.getLongitude(id1), g.getLatitude(id2), g.getLongitude(id2), lineThickness);
    }
    for (int id : path) {
        plotPoint(worldMap, g.getLatitude(id), g.getLongitude(id), pointSize);
    }
    return worldMap;
}

PNG plotBetweenness(Graph g, double maxRadius) {
    PNG worldMap;
    BetweenessCentrality bc;
    worldMap.readFromFile("../Images/map.png");
    // currently the scores take too long to compute so here's an example
    map<int, int> scores = {{1,3},{200,2},{300,1}, {400, 4}};
    int max = 0;
    for (auto it = scores.begin(); it != scores.end(); it++) {
        if (it->second > max) {
            max = it->second;
        }
    }
    for (auto it = scores.begin(); it != scores.end(); it++) {
        double ratio = (double) it->second / max;
        plotPoint(worldMap, g.getLatitude(it->first), g.getLongitude(it->first), maxRadius * ratio);
    }
    return worldMap;
}

void plotPoint(PNG & worldMap, double lat, double lon, double radius) {
    int halfWidth = worldMap.width() / 2;
    int halfHeight = worldMap.height() / 2;
    int centerX = (halfWidth * lon / 180) + halfWidth;
    int centerY = (halfHeight * -lat / 90) + halfHeight;
    // considers the square that circumscribes the point's circle
    for (int x = centerX - radius; x <= centerX + radius; x++) {
        for (int y = centerY - radius; y <= centerY + radius; y++) {
            // out of bounds check
            if (x < 0 || y < 0 || x >= (int) worldMap.width() || y >= (int) worldMap.height()) {
                continue;
            }
            int r2 = pow(x - centerX, 2) + pow(y - centerY, 2);
            // draw if inside the radius
            if (r2 < pow(radius, 2)) {
                worldMap.getPixel(x, y) = HSLAPixel(0, 1, 0.5, 1);
            }
        }
    }
}

void plotLine(PNG & worldMap, double lat1, double lon1, double lat2, double lon2, int thickness) {
    // the documentation for this function is left as an exercise to the reader
    int halfThickness = thickness / 2;
    for (int adj = -halfThickness; adj < -halfThickness + thickness; adj++) {
        int halfWidth = worldMap.width() / 2;
        int halfHeight = worldMap.height() / 2;
        int x1 = (halfWidth * lon1 / 180) + halfWidth;
        int y1 = (halfHeight * -lat1 / 90) + halfHeight;
        int x2 = (halfWidth * lon2 / 180) + halfWidth;
        int y2 = (halfHeight * -lat2 / 90) + halfHeight;
        int dy = y2 - y1;
        int dx = x2 - x1;
        if (abs(dy) < abs(dx)) {
            y1 += adj;
            y2 += adj;
            if (x1 > x2) {
                swap(x1, x2);
                swap(y1, y2);
                dy *= -1;
                dx *= -1;
            }
            int yi = 1;
            if (dy < 0) {
                yi = -1;
                dy *= -1;
            }
            int d = 2 * dy - dx;
            int y = y1;
            for (int x = x1; x != x2; x1 < x2 ? x++ : x--) {
                if (!(x < 0 || y < 0 || x >= (int) worldMap.width() || y >= (int) worldMap.height())) {
                    worldMap.getPixel(x, y) = HSLAPixel(20, 1, 0.5, 1);
                }
                if (d > 0) {
                    y += yi;
                    d += 2 * (dy - dx);
                } else {
                    d += 2 * dy;
                }
            }
        } else {
            x1 += adj;
            x2 += adj;
            if (y1 > y2) {
                swap(x1, x2);
                swap(y1, y2);
                dx *= -1;
                dy *= -1;
            }
            int xi = 1;
            if (dx < 0) {
                xi = -1;
                dx *= -1;
            }
            int d = 2 * dx - dy;
            int x = x1;
            for (int y = y1; y != y2; y1 < y2 ? y++ : y--) {
                if (!(x < 0 || y < 0 || x >= (int) worldMap.width() || y >= (int) worldMap.height())) {
                    worldMap.getPixel(x, y) = HSLAPixel(20, 1, 0.5, 1);
                }
                if (d > 0) {
                    x += xi;
                    d += 2 * (dx - dy);
                } else {
                    d += 2 * dx;
                }
            }
        }
    }
}