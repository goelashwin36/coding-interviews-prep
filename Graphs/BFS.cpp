/*
 * Author: Ashwin Goel
 */

// BFS for Undirected Graphs

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

  void bfs(T src) {
    cout << "BFS: ";
    unordered_set<T> visited;
    queue<T> q;
    q.push(src);
    visited.insert(src);

    while (!q.empty()) {
      T node = q.front();
      q.pop();
      cout << node << " ";
      for (T nbr : l[node]) {
        if (visited.find(nbr) == visited.end()) {
          visited.insert(nbr);
          q.push(nbr);
        }
      }
    }
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
  g.bfs(0);

  return 0;
}