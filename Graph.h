#pragma once
#include <vector>
#include <map>
#include <string>
#include <utility>

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
        int id;
        std::string name;
        double latitude, longitude;
        /**
         * @brief A vector of the pairs representing connections
         * 
         * The first element in the pair is the destination GraphNode
         * The second element is the distance between this GraphNode and the destination
         */
        std::vector<std::pair<GraphNode*, double> > connections;
        /**
         * @brief Constructs a new GraphNode object with the given specifications
         * 
         * @param id_ The airport's ID
         * @param name_ The name of the airport
         * @param lat_ The latitude of the airport
         * @param long_ The longitude of the airport
         */
        GraphNode(int id_, std::string name_, double lat_, double long_) : id(id_),
            name(name_), latitude(lat_), longitude(long_) {}
        // std::vector<std::pair<GraphNode*, double> > getNeighbors() const;
    };
public:
    /**
     * @brief Constructs a new Graph object with no airports or connections
     */
    Graph() : numConnections(0) {}
    /**
     * @brief Adds an airport to the graph without any connections
     * 
     * @param id the unique idenifying number of the airport
     * @param name the airport name
     * @param latitude the airport's latitude
     * @param longitude the airport's longitude
     */
    void addNode(int id, std::string name, double latitude, double longitude);
    /**
     * @brief Makes a connection from one airport to another (does not go both ways)
     * 
     * @param id1 The ID of the starting airport
     * @param id2 The ID of the ending airport
     * @return bool Whether a successful connection was made (i.e. both airports exist)
     */
    bool connect(int id1, int id2);
    /**
     * @brief Gets the number of airports in the graph
     * 
     * @return int The number of airports in the graph
     */
    int size() const { return nodes.size(); }
    /**
     * @brief Gets the number of connections in the graph
     * 
     * @return int The number of connections in the graph
     */
    int connections() const { return numConnections; }
    /**
     * @brief Calculates the great circle distance between two GraphNodes using the haversine formula
     * This technically assumes the Earth is a sphere but is easier to calculate
     * 
     * @param a the first airport's GraphNode
     * @param b the second airport's GraphNode
     * @return double The distance between the airports, accounting for the Earth's curvature
     */
    double distance(GraphNode * a, GraphNode * b) const;
    /**
     * @brief Gets the airport GraphNode for the given ID
     * 
     * @param id the ID
     * @return GraphNode* the airport's GraphNode
     */
    GraphNode* getNode(int id) const {return nodes.at(id);}
    /**
     * @brief Gets the IDs of all airports that were added
     * 
     * @return vector<int> A vector contains all airport IDs
     */
    std::vector<int> getIDs() const; 
private:
    /**
     * @brief Stores the number of connections made in the graph
     */
    int numConnections;
    /**
     * @brief Maps each airport's ID to its GraphNode
     */
    std::map<int, GraphNode*> nodes;
};
