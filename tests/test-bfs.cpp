#include <catch2/catch_test_macros.hpp>
 
#include "readdat.h"
 
#include <iostream>
 
#include "Algorithms/bfs.h"

TEST_CASE("Simple traversal") {
 
   Graph g;
 
   g.addNode(1, "one", 0, 1);
   g.addNode(2, "two", 0, 2);
   g.addNode(3, "three", 0, 3);
   g.addNode(4, "four", 1, 3);
   g.connect(1, 2);
   g.connect(2, 4);
   g.connect(1, 3);
   g.connect(1, 4);
   g.connect(3, 4);
 
   BFS bfs;
   std::vector<int> actual = bfs.traversalOfBFS(g, 1);
   std::vector<int> expected = {1, 2, 3, 4};
 
   REQUIRE(actual == expected);
}

TEST_CASE("get path") {
 
   Graph g;
 
   g.addNode(1, "one", 0, 1);
   g.addNode(2, "two", 0, 2);
   g.addNode(3, "three", 0, 3);
   g.addNode(4, "four", 1, 3);
   g.connect(1, 2);
   g.connect(2, 4);
   g.connect(1, 3);
   g.connect(1, 4);
   g.connect(3, 4);
 
   BFS bfs;
   bfs.traversalOfBFS(g, 4);
   std::vector<int> actual = bfs.getPath();
   std::vector<int> expected = {4, 3, 2, 1};
 
   REQUIRE(actual == expected);
}

TEST_CASE("visited") {
 
   Graph g;
 
   g.addNode(1, "one", 0, 1);
   g.addNode(2, "two", 0, 2);
   g.addNode(3, "three", 0, 3);
   g.addNode(4, "four", 1, 3);
   g.addNode(6, "a", 0, 0);
   g.addNode(7, "b", 0, 10);
   g.addNode(8, "c", 0, 8);
   g.addNode(9, "d", 1, 1);
   g.connect(1, 2);
   g.connect(2, 4);
   g.connect(1, 3);
   g.connect(1, 4);
   g.connect(3, 4);
   g.connect(1, 7);
   g.connect(7, 9);
   g.connect(9, 1);
   g.connect(2, 8);
   g.connect(8, 6);
 
   BFS bfs;
   bfs.traversalOfBFS(g, 4);
    std::map visit = bfs.getVisited();
    for(std::map<int,bool>::iterator iter = visit.begin(); iter != visit.end(); ++iter) {
        int key =  iter->first;
        REQUIRE(visit[key] == true);
    }
}

