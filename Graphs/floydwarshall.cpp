
/*
 * Author: Ashwin Goel
 */

// Floyd Warshall's Algorithm

#include <bits/stdc++.h>
using namespace std;
#define mp make_pair
#define INF 0x3f3f3f3f

class Graph {
  int V;
  int dpSP[1000][1000];
  int next[1000][1000];
  map<int, list<pair<int, int>>> l;

public:
  Graph(int v){
      V = v;
  }; // Constructor

  void addEdge(int src, int dest, int wt) {
    l[src].push_back(mp(wt, dest));
  }

  void constructMatrix(){
	  
	  memset(dpSP, INF, sizeof(dpSP));
	  memset(next, -1, sizeof(next));

	  for(auto node:l){
		  dpSP[node.first][node.first] = 0;
		  
		for(auto nbr: node.second){
			dpSP[nbr.second][nbr.second] = 0;
			dpSP[node.first][nbr.second] = nbr.first;
			next[node.first][nbr.second] = nbr.second;
	  }
  }
}

  void floyd() {
		constructMatrix();

		for(int k=0; k<V; k++){
			for(int i=0; i<V; i++){
				for(int j=0; j<V; j++){
					//If there's a better path available moving from K
					if(dpSP[i][k] + dpSP[k][j] < dpSP[i][j]){
						dpSP[i][j] = dpSP[i][k] + dpSP[k][j];
						next[i][j] = next[i][k];
					}

				}
			}
		}
		//TODO: Add check for negative cycle
		
		cout<<"From  To  Cost\n";

		for(int i=0; i<V; i++){
			for(int j = 0; j<V; j++){
				if(dpSP[i][j] == INF){
					cout<<i<<"     "<<j<<"    INF"<<endl;
				}
				else{
					cout<<i<<"     "<<j<<"    "<<dpSP[i][j]<<endl;
				}
				
			}
		}
  }
};

int main() {
  Graph g(6);
  g.addEdge(0, 1, 10);
  g.addEdge(1, 2, 2);
  g.addEdge(2, 3, 5);
  g.addEdge(3, 5, 1);
  g.addEdge(1, 4, 20);
  g.addEdge(0, 5, 8);
  g.addEdge(2, 5, 7);
  g.floyd();
  return 0;
}

