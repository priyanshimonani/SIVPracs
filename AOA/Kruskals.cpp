#include <iostream>
#include <algorithm>
using namespace std;

struct Edge {
    int u,v,w;
};

int parent[100];

int find(int x) {

    if(parent[x]==x)
        return x;

    return find(parent[x]);
}

int main() {

    Edge e[] = {
        {0,1,2},
        {1,2,1},
        {2,3,3},
        {0,2,4},
        {1,3,7}
    };

    int E=5;

    for(int i=0;i<100;i++)
        parent[i]=i;

    sort(e,e+E,[](Edge a,Edge b){
        return a.w<b.w;
    });

    int cost=0;

    for(int i=0;i<E;i++) {

        int u=e[i].u;
        int v=e[i].v;

        if(find(u)!=find(v)) {

            parent[find(u)] = find(v);

            cost += e[i].w;
        }
    }

    cout<<"MST Cost = "<<cost;
}