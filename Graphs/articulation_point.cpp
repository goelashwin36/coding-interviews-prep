/*
 * Author: Ashwin Goel
 */

// Finding Articulation Points in Graphs

#include <bits/stdc++.h>
using namespace std;

template <typename T> class Graph {
  map<T, list<T>> l;

public:
  void addEdge(T src, T dest) {
    // For undirected
    l[src].push_back(dest);
    l[dest].push_back(src);
  }

  void dfsHelper(T src, unordered_set<T> &visited,
                 vector<T> &articulationPoints, unordered_map<T, int> low,
                 unordered_map<T, int> &nodeTime, int time) {


    // cout << src << " ";
    visited.insert(src);
    nodeTime[src] = time;

    for (T nbr : l[src]) {
      if (visited.find(nbr) == visited.end()) {
        visited.insert(nbr);
        dfsHelper(nbr, visited, articulationPoints, low, nodeTime, time + 1);
      }
    }
  }

  void dfs(T src) {
    cout << "Articulation Points: ";
    unordered_set<T> visited;
    vector<T> articulationPoints;
    unordered_map<T, int> low;
    unordered_map<T, int> nodeTime;
    int time = 0;

    visited.insert(src);
    dfsHelper(src, visited, articulationPoints, low, nodeTime, time);
    cout << endl;
  }
};

int main() {
  Graph<int> g;
  g.addEdge(0, 1);
  g.addEdge(1, 2);
  g.addEdge(2, 3);
  g.addEdge(3, 5);
  g.addEdge(1, 4);
  g.addEdge(3, 5);
  g.addEdge(2, 3);
  g.dfs(0);

  return 0;
}