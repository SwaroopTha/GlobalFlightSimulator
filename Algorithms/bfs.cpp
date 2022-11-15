#include "bfs.h"
std::vector<int> BFS::traversalOfBFS(const Graph& g, int startID, int endID) {
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
        for (Graph it : g.getNode(present)) {
            if (!visited[it]) {
                visited[it] = true;
                queued.push(it);
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
std::vector<int> BFS::getPath() {
    return pathOfBFS;
}
