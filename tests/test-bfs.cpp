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

/*
TEST_CASE("visited") {
 
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
    std::map visit = bfs.getVisited();
    for(std::map<int,bool>::iterator iter = visit.begin(); iter != visit.end(); ++iter) {
        int key =  iter->first;
        REQUIRE(visit[key] == true);
    }
}
*/
