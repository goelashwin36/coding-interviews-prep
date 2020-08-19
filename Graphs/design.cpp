/*
 * Author: Ashwin Goel
 */

// Graphs Design for Undirected Graphs

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

//   void display() {}
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
  return 0;
}