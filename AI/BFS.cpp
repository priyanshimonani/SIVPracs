#include<iostream>
#include<vector>
#include<queue>
using namespace std;

vector<int> g[7]={
    {1,2},    // A
    {3,4},    // B
    {5,6},    // C
    {},       // D
    {},       // E
    {},       // F
    {}        // G
};

char node[]={'A','B','C','D','E','F','G'};

int main(){

    queue<int> q;
    int vis[7]={0};

    q.push(0);
    vis[0]=1;

    while(!q.empty()){

        int u=q.front();
        q.pop();

        cout<<node[u]<<" ";

        for(int v:g[u])
            if(!vis[v]){
                vis[v]=1;
                q.push(v);
            }
    }
}