#include<iostream>
#include<vector>
using namespace std;

vector<int> g[7]={
    {1,2},
    {3,4},
    {5,6},
    {},{},{},{}
};

char node[]={'A','B','C','D','E','F','G'};

void dls(int u,int depth){

    cout<<node[u]<<" ";

    if(depth==0)
        return;

    for(int v:g[u])
        dls(v,depth-1);
}

int main(){

    for(int level=0;level<=2;level++){

        cout<<"\nLevel "<<level<<" : ";

        dls(0,level);
    }
}