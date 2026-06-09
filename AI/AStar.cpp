#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

vector<pair<int,int>> g[7]={
    {{1,3},{4,2}},     // S
    {{2,5},{3,10}},    // A
    {{3,2},{5,1}},     // B
    {{6,4}},           // C
    {{2,1},{5,4}},     // D
    {{6,3}},           // E
    {}
};

char node[]={'S','A','B','C','D','E','G'};
int h[]={7,9,4,2,5,3,0};

struct State{
    int f,g,u;

    bool operator<(const State &x) const{
        return f > x.f;
    }
};

int main(){

    priority_queue<State> pq;

    int closed[7]={0};
    int parent[7];

    for(int i=0;i<7;i++)
        parent[i]=-1;

    pq.push({h[0],0,0});

    int goal=-1;
    int finalCost=0;

    cout<<"A* Traversal\n\n";

    while(!pq.empty()){

        State cur=pq.top();
        pq.pop();

        int u=cur.u;

        if(closed[u])
            continue;

        closed[u]=1;

        cout<<"Closed List : ";

        for(int i=0;i<7;i++)
            if(closed[i])
                cout<<node[i]<<" ";

        cout<<"\n\n";

        if(u==6){
            goal=u;
            finalCost=cur.g;
            break;
        }

        for(auto x:g[u]){

            int v=x.first;
            int cost=x.second;

            if(!closed[v]){

                int ng=cur.g+cost;
                int nf=ng+h[v];

                parent[v]=u;

                pq.push({nf,ng,v});
            }
        }
    }

    vector<int> path;

    while(goal!=-1){
        path.push_back(goal);
        goal=parent[goal];
    }

    reverse(path.begin(),path.end());

    cout<<"\nFinal Path : ";

    for(int i=0;i<path.size();i++){

        cout<<node[path[i]];

        if(i!=path.size()-1)
            cout<<" -> ";
    }

    cout<<"\nFinal Cost = "<<finalCost;
}