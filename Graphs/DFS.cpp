/*
 * Author: Ashwin Goel
 */

// DFS for Undirected Graphs

#include <bits/stdc++.h>
using namespace std;

template <typename T>
class Graph {
  map<T, list<T>> l;

public:
  void addEdge(T src, T dest) {
    // For undirected
    l[src].push_back(dest);
    l[dest].push_back(src);
  }

  void dfsHelper(T src, unordered_set<T> &visited) {
    cout << src << " ";
    for (T nbr : l[src]) {
      if (visited.find(nbr) == visited.end()) {
        visited.insert(nbr);
        dfsHelper(nbr, visited);
      }
    }
  }

  void dfs(T src) {
    cout << "DFS: ";
    unordered_set<T> visited;
    visited.insert(src);
    dfsHelper(src, visited);
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