#pragma once
#include <vector>
#include <map>
#include <string>
#include <utility>
#include <iostream>
#include <limits>

/**
 * Graph class
 * Stores all airports and their connections
 */
class Graph {
public:
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
         * The first element in the pair is the destination ID
         * The second element is the distance between this GraphNode and the destination
         */
        std::map<int, double> connections;
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
        /**
        * @brief Determines if this GraphNode is connected to another.
        *
        * @param id The ID to see if it's connected to
        * @return bool Whether there is a connection
        */
        bool connectedTo(int id) {return connections.find(id) != connections.end();}
        /**
        * @brief Gets the connection weight between this and an ID
        * If not connected returns 0
        *
        * @param id The ID it's connected to
        */
        double connectionDistance(int id) {
            if (connectedTo(id)) {
                return connections[id];
            }
            return std::numeric_limits<double>::infinity();
        }
    };
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
     * @brief Gets the number of connections in the graph (one-directional)
     * 
     * @return int The number of connections in the graph
     */
    int connections() const { return numConnections; }
    /**
     * @brief Calculates the great circle distance between two airports using the haversine formula
     * This technically assumes the Earth is a sphere but is easier to calculate
     *
     * @param a the first airport's ID
     * @param b the second airport's ID
     * @return double The distance between the airports, accounting for the Earth's curvature
    */
    double distance(int id1, int id2) const;
    /**
     * @brief Gets the IDs of all airports that were added
     * 
     * @return vector<int> A vector contains all airport IDs
     */
    std::vector<int> getIDs() const; 
    /**
    * @brief Determines if the the first airport is connected to the second
    *
    * @param id1 The first airport's ID
    * @param id2 The second airport's ID
    * @return bool Whether there is a connection
    */
    bool connectedTo(int id1, int id2) const {
        return nodes.at(id1)->connectedTo(id2);
    }
    /**
    * @brief Gets the weight of the connection between two airports
    *
    * @param id1 The first airport's ID
    * @param id2 The second airport's ID
    * @return double The weight
    */
    double getDistance(int id1, int id2) const {
        return nodes.at(id1)->connectionDistance(id2);
    }

    /**
    * @brief Gets all connections of an airport (one-way, starting from the given airport)
    *
    * @param id The airport's ID
    *
    */
    std::vector<int> getConnections(int id) const;

    /**
    * @brief: Gets the name of an airport from its ID
    *
    * @param id The airport's ID
    * @return string The airport's name
    */
    std::string getName(int id) const {return nodes.at(id)->name;}
    /**
    * @brief: Gets the latitude of an airport from its ID
    *
    * @param id The airport's ID
    * @return string The airport's latitude
    */
    double getLatitude(int id) const {return nodes.at(id)->latitude;}
    /**
    * @brief: Gets the longitude of an airport from its ID
    *
    * @param id The airport's ID
    * @return string The airport's longitude
    */
    double getLongitude(int id) const {return nodes.at(id)->longitude;}
    // TO BE REMOVED
    GraphNode * getNode(int id) const {return nodes.at(id);}
private:
    /**
     * @brief Stores the number of connections made in the graph
     */
    int numConnections;
    /**
     * @brief Maps each airport's ID to its GraphNode
     */
    std::map<int, GraphNode*> nodes;
    /**
     * @brief Calculates the great circle distance between two GraphNodes using the haversine formula
     * This technically assumes the Earth is a sphere but is easier to calculate
     * 
     * @param a the first airport's GraphNode
     * @param b the second airport's GraphNode
     * @return double The distance between the airports, accounting for the Earth's curvature
     */
    double distance(GraphNode * a, GraphNode * b) const;
};
