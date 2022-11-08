#pragma once
#include <vector>
#include <map>
#include <string>

/**
 * Graph class
 * Stores all airports and their connections
 */
class Graph {
private:
    /**
    * GraphNode struct
    * Stores the data of an airport and its connections
    */
    struct GraphNode {
        std::string name;
        double latitude, longitude;
        /**
         * @brief neighbors
         * A vector of the GraphNodes for airports that are connected to this
         */
        std::vector<GraphNode*> neighbors;
        /**
         * @brief Construct a new GraphNode object with the given specifications
         * @param name_ The name of the airport
         * @param lat_ The latitude of the airport
         * @param long_ The longitude of the airport
         */
        GraphNode(std::string name_, double lat_, double long_) :
            name(name_), latitude(lat_), longitude(long_) {}
    };
public:
    /**
     * @brief Construct a new Graph object with no airports or connections
     */
    Graph() : numConnections(0) {}
    /**
     * @brief addNode
     * Adds an airport to the graph without any connections
     * @param id the unique idenifying number of the airport
     * @param name the airport name
     * @param latitude the airport's latitude
     * @param longitude the airport's longitude
     */
    void addNode(int id, std::string name, double latitude, double longitude);
    /**
     * @brief connect
     * Makes a connection from one airport to another (does go both ways)
     * @param id1 The ID of the starting airport
     * @param id2 The ID of the ending airport
     * @return bool Whether a successful connection was made (i.e. both airports exist)
     */
    bool connect(int id1, int id2);
    /**
     * @brief size
     * Gets the number of airports in the graph
     * @return int The number of airports in the graph
     */
    int size() const { return nodes.size(); }
    /**
     * @brief connections
     * Gets the number of connections in the graph
     * @return int The number of connections in the graph
     */
    int connections() const { return numConnections; }
    /**
     * @brief distance
     * Calculates the great circle distance between two GraphNodes using the haversine formula
     * This technically assumes the Earth is a sphere but is easier to calculate
     * @param a the first airport's GraphNode
     * @param b the second airport's GraphNode
     * @return double The distance between the airports, accounting for the Earth's curvature
     */
    double distance(GraphNode * a, GraphNode * b) const;
    std::map<int, GraphNode*> getNodes() {return nodes;}
private:
    /**
     * @brief numConnections
     * Stores the number of connections made in the graph
     */
    int numConnections;
    /**
     * @brief nodes
     * Maps each airport's ID to its GraphNode
     */
    std::map<int, GraphNode*> nodes;
};
