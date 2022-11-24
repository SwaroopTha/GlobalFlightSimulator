#include <catch2/catch_test_macros.hpp>

#include "readdat.h"

#include <iostream>

#include "Algorithms/dijkstra.h"

using namespace std;

TEST_CASE("Simple Dijkstra") {

    cout << "------------------------------------------------" << endl;

    cout << "starting [Simple Dijkstra]" << endl;

    Graph g;

    g.addNode(1, "one", 0, 1);
    g.addNode(2, "two", 0, 2);
    g.addNode(3, "three", 0, 3);
    g.addNode(4, "four", 1, 2);


    g.connect(1, 2);
    g.connect(2, 3);

    Dijkstras dij;
    vector<int> actual = dij.getPath(g, 1, 3);
    vector<int> expected = {1, 2, 3};

    REQUIRE(actual == expected);
}

TEST_CASE("Complex Dijkstra") {

    cout << "------------------------------------------------" << endl;

    cout << "starting [Complex Dijkstra]" << endl;
    Graph g;

    g.addNode(1, "one", 0, 0);
    g.addNode(2, "two", 1, 1);
    g.addNode(3, "three", 2, 1);
    g.addNode(4, "four", 1, -1);
    g.addNode(5, "five", 2, -1);
    g.addNode(6, "six", 2, -2);

    g.connect(1, 2);
    g.connect(1, 4);
    g.connect(2, 4);
    g.connect(2, 3);
    g.connect(4, 5);
    g.connect(3, 5);
    g.connect(5, 6);

    Dijkstras dij;
    vector<int> actual = dij.getPath(g, 1, 6);
    vector<int> expected = {1, 4, 5, 6};

    REQUIRE(actual == expected);
}

TEST_CASE("No Path") {


    cout << "------------------------------------------------" << endl;

    cout << "starting [No Path]" << endl;
    Graph g;

    g.addNode(1, "one", 0, 1);
    g.addNode(2, "two", 0, 2);
    g.addNode(3, "three", 0, 3);
    g.addNode(4, "four", 1, 2);
    g.addNode(5, "five", 4, 4);

    g.connect(1, 2);
    g.connect(2, 3);
    g.connect(4, 5);

    Dijkstras dij;
    vector<int> actual = dij.getPath(g, 1, 5);
    // vector<int> expected = {1, 2, 3};

    REQUIRE(actual == vector<int>());
    REQUIRE(dij.shortestDistance() == std::numeric_limits<double>::infinity());
}

TEST_CASE("Dijkstra Airport Nearby") {

    Dijkstras canvas;

    cout << "------------------------------------------------" << endl;

    cout << "starting [Dijkstra Airport Nearby]" << endl;

    Graph g = readData();

    cout << g.size() << " airports added" << endl;

    Dijkstras dij;
    // auto vec = dij.getPath(g, 1, 2);

    cout << "starting journey from Champaign to O'Hare: " << endl;

    int champ = 4049;
    int ohare = 3830;


    vector<int> vec1 = dij.getPath(g, champ, ohare);

    double minDist = dij.shortestDistance();
    double expec1 = g.distance(4049, 3830);

    for (auto i : vec1) {
        if (i == -1) continue;
        cout << g.getName(i) << " ---> ";
    }
    std::cout << "arrived to " << g.getName(ohare) << std::endl;
    // std::cout << ports[target] << std::endl;

    vector<int> expected = {4049, 3830};

    cout << dij.shortestDistance() << endl;

    REQUIRE(vec1 == expected);

    REQUIRE(minDist == expec1);

}


TEST_CASE("Dijkstra Airport Complex") {

    cout << "------------------------------------------------" << endl;

    cout << "starting [Dijkstra Airport Complex]" << endl;


    Dijkstras canvas;
    Graph g = readData();
    Dijkstras dij;
    cout << "starting journey from Champaign to Hong Kong: " << endl;

    int champ = 4049;
    int hgk = 3077;

    vector<int> journey = dij.getPath(g, champ, hgk);

    double real = g.distance(4049, 3830);
    real += g.distance(3830, 3077);



    double actual = g.distance(4049, 3670);
    actual += g.distance(3670, 3690);
    actual += g.distance(3690, 193);
    actual += g.distance(193, 1382);
    actual += g.distance(1382, 3077);

    // cout << real << endl;
    // cout << actual;

    for (auto i : journey) {
        if (i == -1) continue;
        cout << g.getName(i) << " ---> ";
    }
    std::cout << "arrived to " << g.getName(hgk) << std::endl;

    REQUIRE(actual > real);
    // vector<int> expected = {-1, 4049, 3670, 3690, 193, 1382, 3077};

    vector<int> expected = {4049, 3830, 3077};

    // vector<int> expected = {-1};

    cout << dij.shortestDistance() << endl;


    REQUIRE(journey == expected);
}

