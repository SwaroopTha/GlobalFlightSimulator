#include <catch2/catch_test_macros.hpp>

#include "Graph.h"
#include "readdat.h"

using namespace std;

/**
* @brief Determines if two distance are close enough to be considered equal (within 1%)
* This accounts for the ellipticity of the Earth 
*/
bool closeEnough(double distance1, double distance2) {
    return max(distance1, distance2) / min(distance1, distance2) < 1.01;
}

TEST_CASE("graph constructor") {
    Graph g;
    REQUIRE(g.connections() == 0);
    REQUIRE(g.size() == 0);
    REQUIRE(g.getIDs() == vector<int>());
}

TEST_CASE("adding and accessing nodes") {
    Graph g;
    g.addNode(12, "idk", 30, -30);
    REQUIRE(g.connections() == 0);
    REQUIRE(g.size() == 1);
    REQUIRE(g.getIDs() == vector<int>(1,12));
    REQUIRE(g.getName(12) == "idk");
    REQUIRE(g.getLatitude(12) == 30);
    REQUIRE(g.getLongitude(12) == -30);

    g.addNode(24, "smth", 25, -35);
    REQUIRE(g.connections() == 0);
    REQUIRE(g.size() == 2);
    vector<int> expected = {12, 24};
    REQUIRE(g.getIDs() == expected);
    REQUIRE(g.getName(24) == "smth");
    REQUIRE(g.getLatitude(24) == 25);
    REQUIRE(g.getLongitude(24) == -35);
}

TEST_CASE("connecting nodes") {
    Graph g;
    g.addNode(12, "idk", 30, -30);
    g.addNode(24, "smth", 25, -35);

    REQUIRE(g.connections() == 0);
    REQUIRE(g.getConnections(12).size() == 0);
    REQUIRE(g.getConnections(24).size() == 0);
    REQUIRE(g.connectedTo(12, 24) == false);
    REQUIRE(g.connectedTo(24, 12) == false);
    
    REQUIRE(g.connect(12, 24) == true);

    REQUIRE(g.connections() == 1);
    REQUIRE(g.getConnections(12) == vector<int>(1,24));
    REQUIRE(g.getConnections(24).size() == 0);
    REQUIRE(g.getDistance(12, 24) == g.distance(12, 24));
    REQUIRE(g.getDistance(24, 12) == numeric_limits<double>::infinity());
    REQUIRE(g.connectedTo(12, 24) == true);
    REQUIRE(g.connectedTo(24, 12) == false);

    REQUIRE(g.connect(24, 12) == true);

    REQUIRE(g.connections() == 2);
    REQUIRE(g.getConnections(12) == vector<int>(1,24));
    REQUIRE(g.getConnections(24) == vector<int>(1,12));
    REQUIRE(g.getDistance(12, 24) == g.distance(12, 24));
    REQUIRE(g.getDistance(24, 12) == g.distance(24, 12));
    REQUIRE(g.connectedTo(12, 24) == true);
    REQUIRE(g.connectedTo(24, 12) == true);

    REQUIRE(g.connect(12, 25) == false);
}

TEST_CASE("distance function") {
    Graph g = readData();
    // real-life distances are calculated beforehand
    REQUIRE(closeEnough(g.distance(1, 2), 106.80));
    REQUIRE(closeEnough(g.distance(26, 41), 560.91));
    REQUIRE(closeEnough(g.distance(6332, 9751), 17742.30));
    REQUIRE(g.distance(1, 1) == 0);
}
