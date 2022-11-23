#include "bfs.h"
using namespace std;
vector<int> BFS::traversalOfBFS(const Graph& g, int startID, int endID) {
  setAllFalse(g);
  queued.push(startID);
  visited[startID] = true;
  while(!queued.empty()) {
      int present = queued.front();
      queued.pop();
      pathOfBFS.push_back(present);
      if (present == endID) {
          return pathOfBFS;
      }
      for (auto pair : g.getNode(present)->connections) {
          int id = pair.first;
          if (!visited[id]) {
              visited[id] = true;
              queued.push(id);
          }
      }
  }
  return pathOfBFS;
}
void BFS::setAllFalse(const Graph& g) {
  for (int i : g.getIDs()) {
      visited[i] = false;
  }
}
vector<int> BFS::getPath() {
  return pathOfBFS;
}
