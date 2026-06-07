#include <iostream>
using namespace std;

struct Edge {
    int u,v,w;
};

int main() {

    Edge e[] = {
        {0,1,2},
        {0,2,4},
        {1,2,1},
        {1,3,7},
        {2,3,3}
    };

    int E=5;
    int V=4;

    int dist[4];

    for(int i=0;i<V;i++) //all dist as infinity
        dist[i]=9999;

    dist[0]=0;

    for(int i=1;i<V;i++) { //v-1 relax

        for(int j=0;j<E;j++) {

            int u=e[j].u;
            int v=e[j].v;
            int w=e[j].w;

            if(dist[u]!=9999 &&
               dist[u]+w < dist[v])
            {
                dist[v]=dist[u]+w;
            }
        }
    }

    for(int i=0;i<V;i++)
        cout<<dist[i]<<" ";
}