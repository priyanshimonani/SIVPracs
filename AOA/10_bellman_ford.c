#include<stdio.h>
#define INF 9999
void bellmanFord(int n, int e, int edges[][3], int src) {
    int dist[10], i, j;
    for(i=0;i<n;i++) dist[i]=INF;
    dist[src]=0;
    for(i=0;i<n-1;i++)
        for(j=0;j<e;j++)
            if(dist[edges[j][0]]!=INF&&dist[edges[j][0]]+edges[j][2]<dist[edges[j][1]])
                dist[edges[j][1]]=dist[edges[j][0]]+edges[j][2];
    printf("Vertex  Distance\n");
    for(i=0;i<n;i++) printf("  %d  ->  %d\n",i,dist[i]);
}
void main() {
    int edges[5][3]={{0,1,6},{0,2,7},{1,2,8},{1,3,5},{2,3,9}};
    bellmanFord(4,5,edges,0);
}
