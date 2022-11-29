#include <catch2/catch_test_macros.hpp>

#include "readdat.h"

#include <iostream>

#include "Algorithms/bet_cent.h"

using namespace std;

TEST_CASE("Betweenness Centrality Simple") {

    Graph g;

    g.addNode(1, "air1", 0, 1);
    g.addNode(2, "air2", 0, 2);
    g.addNode(3, "air3", 0, 3);

    g.connect(1, 3);
    g.connect(3, 2);

    g.connect(2, 3);
    g.connect(3, 1);

    BetweenessCentrality betcent;

    map<int, int> test = betcent.getAllScores(g);

    // map<int, int> expected;
    // expected[1] = 0;
    // expected[2] = 0;
    // expected[3] = 2;

    REQUIRE(test[1] == 0);
    REQUIRE(test[2] == 0);
    REQUIRE(test[3] == 2);

    // REQUIRE(test == expected);

}

//---------------------------------------- WITH DIJKSTRA--------------------------------------------

TEST_CASE("Betweenness Centrality Dijkstra Simple") {

    Graph g;

    g.addNode(1, "air1", 0, 1);
    g.addNode(2, "air2", 0, 2);
    g.addNode(3, "air3", 0, 3);

    g.connect(1, 3);
    g.connect(3, 2);

    g.connect(2, 3);
    g.connect(3, 1);

    BetweenessCentrality betcent;

    map<int, int> test = betcent.getAllScoresDijkstras(g);

    // map<int, int> expected;
    // expected[1] = 0;
    // expected[2] = 0;
    // expected[3] = 2;

    REQUIRE(test[1] == 0);
    REQUIRE(test[2] == 0);
    REQUIRE(test[3] == 2);

    // REQUIRE(test == expected);

}