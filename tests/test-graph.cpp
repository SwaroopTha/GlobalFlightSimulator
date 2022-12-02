#include <catch2/catch_test_macros.hpp>

#include "Graph.h"
#include "readdat.h"

using namespace std;

double inf = numeric_limits<double>::infinity();

/**
* @brief Determines if two distance are close enough to be considered equal (within 2%)
* This accounts for the ellipticity of the Earth 
*
* @param distance1 The first distance
* @param distance2 The second distance
* @return double Whether the distances are close enough
*/
bool closeEnough(double distance1, double distance2) {
    return max(distance1, distance2) / min(distance1, distance2) < 1.02;
}

TEST_CASE("graph constructor") {
    Graph g;
    REQUIRE(g.connections() == 0);
    REQUIRE(g.size() == 0);
    REQUIRE(g.getIDs() == vector<int>());
}

TEST_CASE("adding and accessing nodes") {
    Graph g;
    REQUIRE(!g.inGraph(12));
    REQUIRE(!g.inGraph(24));

    g.addNode(12, "idk", 30, -30);
    REQUIRE(g.connections() == 0);
    REQUIRE(g.size() == 1);
    REQUIRE(g.getIDs() == vector<int>(1,12));
    REQUIRE(g.getName(12) == "idk");
    REQUIRE(g.getLatitude(12) == 30);
    REQUIRE(g.getLongitude(12) == -30);
    REQUIRE(g.inGraph(12));
    REQUIRE(!g.inGraph(24));

    g.addNode(24, "smth", 25, -35);
    REQUIRE(g.connections() == 0);
    REQUIRE(g.size() == 2);
    vector<int> expected = {12, 24};
    REQUIRE(g.getIDs() == expected);
    REQUIRE(g.getName(24) == "smth");
    REQUIRE(g.getLatitude(24) == 25);
    REQUIRE(g.getLongitude(24) == -35);
    REQUIRE(g.inGraph(12));
    REQUIRE(g.inGraph(24));
}

TEST_CASE("connecting nodes") {
    Graph g;
    g.addNode(12, "idk", 30, -30);
    g.addNode(24, "smth", 26, -33);

    REQUIRE(g.connections() == 0);
    REQUIRE(g.getConnections(12).size() == 0);
    REQUIRE(g.getConnections(24).size() == 0);
    REQUIRE(g.getDistance(12, 24) == inf);
    REQUIRE(g.getDistance(24, 12) == inf);
    REQUIRE(g.connectedTo(12, 24) == false);
    REQUIRE(g.connectedTo(24, 12) == false);
    
    REQUIRE(g.connect(12, 24) == true);

    REQUIRE(g.connections() == 1);
    REQUIRE(g.getConnections(12) == vector<int>(1,24));
    REQUIRE(g.getConnections(24).size() == 0);
    REQUIRE(g.getDistance(12, 24) < inf);
    REQUIRE(g.getDistance(24, 12) == inf);
    REQUIRE(g.connectedTo(12, 24) == true);
    REQUIRE(g.connectedTo(24, 12) == false);

    REQUIRE(g.connect(24, 12) == true);

    REQUIRE(g.connections() == 2);
    REQUIRE(g.getConnections(12) == vector<int>(1,24));
    REQUIRE(g.getConnections(24) == vector<int>(1,12));
    REQUIRE(g.getDistance(12, 24) < inf);
    REQUIRE(g.getDistance(24, 12) < inf);
    REQUIRE(g.connectedTo(12, 24) == true);
    REQUIRE(g.connectedTo(24, 12) == true);

    REQUIRE(g.connect(12, 25) == false);
}

TEST_CASE("distance function") {
    Graph g = readData("../Data/airports.dat",  "../Data/routes.dat");
    // real-life distances are calculated beforehand
    // some airports aren't automatically connected
    REQUIRE(closeEnough(g.getDistance(1, 2), 106.80));
    REQUIRE(g.getDistance(26, 41) == inf);
    g.connect(26, 41);
    REQUIRE(closeEnough(g.getDistance(26, 41), 560.91));
    REQUIRE(g.getDistance(6332, 9751) == inf);
    g.connect(6332, 9751);
    REQUIRE(closeEnough(g.getDistance(6332, 9751), 17742.30));
    g.connect(1, 1); // this is nonsensical but just used to test a distance of 0
    REQUIRE(g.getDistance(1, 1) == 0);
}
