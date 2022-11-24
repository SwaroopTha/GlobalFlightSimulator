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
private:
    /**
    * GraphNode struct
    * Stores the data of an airport and its connections
    */
    struct GraphNode {
        int id_;
        std::string name_;
        double latitude_, longitude_;
        /**
         * @brief A vector of the pairs representing connections
         * 
         * The first element in the pair is the destination ID
         * The second element is the distance between this GraphNode and the destination
         */
        std::map<int, double> connections_;
        GraphNode() : id_(0), name_(""), latitude_(0), longitude_(0) {}
        /**
         * @brief Constructs a new GraphNode object with the given specifications
         * 
         * @param id The airport's ID
         * @param name The name of the airport
         * @param lat The latitude of the airport
         * @param long The longitude of the airport
         */
        GraphNode(int id, std::string name, double lat, double lon) : id_(id),
            name_(name), latitude_(lat), longitude_(lon) {}
        /**
        * @brief Determines if this GraphNode is connected to another.
        *
        * @param id The ID to see if it's connected to
        * @return bool Whether there is a connection
        */
        bool connectedTo(int id) const {return connections_.find(id) != connections_.end();}
        /**
        * @brief Gets the connection weight between this and an ID
        * If not connected returns 0
        *
        * @param id The ID it's connected to
        */
        double connectionDistance(int id) const {
            if (connectedTo(id)) {
                return connections_.at(id);
            }
            return std::numeric_limits<double>::infinity();
        }
    };
public:
    /**
     * @brief Constructs a new Graph object with no airports or connections
     */
    Graph() : numConnections_(0) {}
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
    int size() const { return nodes_.size(); }
    /**
     * @brief Gets the number of connections in the graph (one-directional)
     * 
     * @return int The number of connections in the graph
     */
    int connections() const { return numConnections_; }
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
        if (nodes_.find(id1) != nodes_.end() && nodes_.find(id2) != nodes_.end()) {
            return nodes_.at(id1).connectedTo(id2);
        }
        return false;
    }
    /**
    * @brief Gets the weight of the connection between two airports
    *
    * @param id1 The first airport's ID
    * @param id2 The second airport's ID
    * @return double The weight
    */
    double getDistance(int id1, int id2) const {
        return nodes_.at(id1).connectionDistance(id2);
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
    std::string getName(int id) const {return nodes_.at(id).name_;}
    /**
    * @brief: Gets the latitude of an airport from its ID
    *
    * @param id The airport's ID
    * @return string The airport's latitude
    */
    double getLatitude(int id) const {return nodes_.at(id).latitude_;}
    /**
    * @brief: Gets the longitude of an airport from its ID
    *
    * @param id The airport's ID
    * @return string The airport's longitude
    */
    double getLongitude(int id) const {return nodes_.at(id).longitude_;}
private:
    /**
     * @brief Stores the number of connections made in the graph
     */
    int numConnections_;
    /**
     * @brief Maps each airport's ID to its GraphNode
     */
    std::map<int, GraphNode> nodes_;
};
