#include<iostream>
#include<vector>
#include<stack>
using namespace std;

vector<int> g[7]={
    {1,2},
    {3,4},
    {5,6},
    {},{},{},{}
};

char node[]={'A','B','C','D','E','F','G'};

int main(){

    stack<int> s;
    int vis[7]={0};

    s.push(0);

    while(!s.empty()){

        int u=s.top();
        s.pop();

        if(vis[u]) continue;

        vis[u]=1;
        cout<<node[u]<<" ";

        for(int i=g[u].size()-1;i>=0;i--)
            s.push(g[u][i]);
    }
}