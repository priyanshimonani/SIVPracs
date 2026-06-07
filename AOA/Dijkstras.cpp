#include <iostream>
using namespace std;

int main() {

    int V = 5;

    int g[5][5] = {
        {0, 2, 4, 0, 0},
        {2, 0, 1, 7, 0},
        {4, 1, 0, 3, 5},
        {0, 7, 3, 0, 1},
        {0, 0, 5, 1, 0}
    };

    int dist[5];
    bool vis[5];

    for(int i=0;i<V;i++) {
        dist[i] = 1e9;
        vis[i] = false;
    }

    dist[0] = 0;  // source vertex

    for(int count=0; count<V-1; count++) {

        // find unvisited vertex with minimum distance
        int u = -1;
        int mn = 1e9;

        for(int i=0;i<V;i++) {
            if(!vis[i] && dist[i] < mn) {
                mn = dist[i];
                u = i;
            }
        }

        vis[u] = true;

        // relax adjacent vertices
        for(int v=0; v<V; v++) {

            if(g[u][v] != 0 &&
               !vis[v] &&
               dist[u] + g[u][v] < dist[v])
            {
                dist[v] = dist[u] + g[u][v];
            }
        }
    }

    cout << "Shortest distances from 0:\n";

    for(int i=0;i<V;i++)
        cout << i << " : " << dist[i] << endl;
}