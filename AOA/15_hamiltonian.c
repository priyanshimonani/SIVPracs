#include<stdio.h>
int g[10][10], path[10], n;
int isSafe(int v, int pos) {
    if(!g[path[pos-1]][v]) return 0;
    int i;
    for(i=0;i<pos;i++) if(path[i]==v) return 0;
    return 1;
}
int solve(int pos) {
    int v, i;
    if(pos==n) return g[path[pos-1]][path[0]];
    for(v=1;v<n;v++) {
        if(isSafe(v,pos)) {
            path[pos]=v;
            if(solve(pos+1)) return 1;
            path[pos]=-1;
        }
    }
    return 0;
}
void main() {
    int i,j;
    n=5;
    int adj[5][5]={{0,1,0,1,0},{1,0,1,1,1},{0,1,0,0,1},{1,1,0,0,1},{0,1,1,1,0}};
    for(i=0;i<n;i++) for(j=0;j<n;j++) g[i][j]=adj[i][j];
    for(i=0;i<n;i++) path[i]=-1;
    path[0]=0;
    if(solve(1)) { printf("Hamiltonian Cycle: "); for(i=0;i<n;i++) printf("%d ",path[i]); printf("0"); }
    else printf("No Hamiltonian Cycle");
}
