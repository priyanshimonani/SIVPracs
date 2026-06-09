#include<stdio.h>
#define INF 9999
void dijkstra(int g[][10], int n, int src) {
    int dist[10], visited[10]={0}, i, j, u, min;
    for(i=0;i<n;i++) dist[i]=INF;
    dist[src]=0;
    for(i=0;i<n-1;i++) {
        min=INF; u=-1;
        for(j=0;j<n;j++) if(!visited[j]&&dist[j]<min) { min=dist[j]; u=j; }
        visited[u]=1;
        for(j=0;j<n;j++)
            if(!visited[j]&&g[u][j]&&dist[u]+g[u][j]<dist[j])
                dist[j]=dist[u]+g[u][j];
    }
    printf("Vertex  Distance\n");
    for(i=0;i<n;i++) printf("  %d  ->  %d\n",i,dist[i]);
}
void main() {
    int g[4][10]={{0,9,INF,5},{9,0,1,2},{INF,1,0,4},{5,2,4,0}};
    dijkstra(g,4,0);
}
