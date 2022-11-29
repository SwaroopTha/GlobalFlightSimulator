#pragma once
#include "../Graph.h"
#include <vector>
#include <map>
#include <string>
#include <queue>

using namespace std;
class BFS {
public:
//will return vectors of node IDs visiteds
vector<int> traversalOfBFS(const Graph& g, int startID);
vector<int> getPath();
void setAllFalse(const Graph& g);
private:
queue<int> queued;
map<int, bool> visited;
vector<int> pathOfBFS;
};
