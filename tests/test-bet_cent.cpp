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

    vector<int> all = betcent.getAirportsWithMinFrequencyDijkstras(0);
    map<int, int> all_map;
    int count = 1;
    for (int i : all) {
        if (all_map.find(i) != all_map.end()) all_map[i]++;
        else all_map[i] = 1;

        count++;
    }
    cout << "count: " << count << endl;
    REQUIRE(all.size() == 3);
    REQUIRE(all_map[0] == 2);
    REQUIRE(all_map[2] == 1);

    vector<int> only_2 = betcent.getAirportsWithMinFrequencyDijkstras(2);
    map<int, int> map_2;
    for (int i : only_2) {
        if (map_2.find(i) != map_2.end()) map_2[i]++;
        else map_2[i] = 1;
    }
    REQUIRE(all.size() == 1);
    REQUIRE(all_map[2] == 1);

    // REQUIRE(all == {0, 0, 2});
    // REQUIRE(only_2 == {2});

}