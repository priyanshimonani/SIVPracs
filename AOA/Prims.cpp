#include <iostream>
using namespace std;

int main() {

    int V = 5;

    int g[5][5] = {
        {0,2,4,0,0},
        {2,0,1,7,0},
        {4,1,0,3,5},
        {0,7,3,0,1},
        {0,0,5,1,0}
    };

    int key[5];
    bool vis[5];

    for(int i=0;i<V;i++) {
        key[i]=1e9;
        vis[i]=false;
    }

    key[0]=0;

    int cost=0;

    for(int cnt=0;cnt<V;cnt++) {

        int u=-1;
        int mn=1e9;

        for(int i=0;i<V;i++) { //selecting minimum unvisited code
            if(!vis[i] && key[i]<mn) {
                mn=key[i];
                u=i;
            }
        }

        vis[u]=true;
        cost += key[u];

        for(int v=0;v<V;v++) {

            if(g[u][v] &&
               !vis[v] &&
               g[u][v] < key[v])
            {
                key[v]=g[u][v];
            }
        }
    }

    cout<<"MST Cost = "<<cost;
}