#pragma once
#include "Algorithms/dijkstra.h"
#include "../lib/cs225/png.h"

/**
* @brief Plots the Dijkstra path onto a plate carrée map projection
*
* @param g The graph on which to apply Dijkstra
* @param source The source airport ID
* @param target The target airport ID
* @param pointSize The radius of the points, in pixels
* @param lineThickness The thickness of the lines, in pixels
* @return PNG The map png
*/
cs225::PNG plotDijkstra(Graph g, int source, int target, double pointSize = 8, int lineThickness = 4);

/**
* @brief Plots a red point on a map at a given latitude and longitude
*
* @param worldMap The map to plot the point on
* @param lat The point's latitude
* @param long The point's longitude
* @param radius The radius of the point
*/
void plotPoint(cs225::PNG & worldMap, double lat, double lon, double radius);

/**
* @brief Plots an orange line on a map between two points
* Uses Bresenham's line algorithm
* Makes the line thicker along axis where it is most noticable
*
* @param worldMap The map to plot the line on
* @param lat1 The latitude of the first point
* @param lon1 The longitude of the first point
* @param lat2 The latitude of the second point
* @param lon2 The longitude of the second point
* @param thickness The thickness of the line in pixels
*/
void plotLine(cs225::PNG & worldMap, double lat1, double lon1, double lat2, double lon2, int thickness);
