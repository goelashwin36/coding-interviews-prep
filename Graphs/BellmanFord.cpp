
/*
 * Author: Ashwin Goel
 */

// Bellman Ford's Algorithm

#include <bits/stdc++.h>
using namespace std;
#define mp make_pair
#define INF 99999999

template <typename T>
class Graph {
  int V;
  map<T, list<pair<int, T>>> l;

public:
  Graph(int v){
      V = v;
  };

  void addEdge(T src, T dest, int wt) {
    l[src].push_back(mp(wt, dest));
  }

  void bellman(T src) {
    // Initializing distance vector
    vector<int> dist(V, INF);

    // Distance of src to src is 0
    dist[src] = 0;

for(int i=0; i<V; i++){
	for(auto node: l){
      T u = node.first;

      for (auto nbr : node.second) {
        T v = nbr.second;
        int weight = nbr.first;

        if (dist[v] > dist[u] + weight) {
          dist[v] = dist[u] + weight;
        }
      }
  }
    }

    cout << "Shortest distance from: " << src << endl;
    cout << "Node: Dist" << endl;
    for (int i = 0; i < V; i++) {
      if (i != src) {
        cout << i << "   " << dist[i]<<endl;
      }
    }
  }
};

int main() {
  Graph<int> g(6);
  g.addEdge(0, 1, 10);
  g.addEdge(1, 2, 2);
  g.addEdge(2, 3, 5);
  g.addEdge(3, 5, 15);
  g.addEdge(1, 4, 20);
  g.addEdge(0, 5, 8);
  g.addEdge(2, 5, 7);
  g.bellman(0);
  return 0;
}
