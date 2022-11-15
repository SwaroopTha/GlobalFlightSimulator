#pragma once
#include "../Graph.h"
#include <vector>
#include <map>
#include <string>
#include <queue>
class BFS {
  public:
  //will return vectors of node IDs visiteds
  std::vector<int> traversalOfBFS(const Graph& g, int startID, int endID);
  std::vector<int> getPath();
 
  void setAllFalse(const Graph& g);
  private:
  std::queue<int> queued;
  std::map<int, bool> visited;
  std::vector<int> pathOfBFS;
};
