#include<stdio.h>
int g[10][10], color[10], n, m;
int isSafe(int v, int c) {
    int i;
    for(i=0;i<n;i++) if(g[v][i]&&color[i]==c) return 0;
    return 1;
}
int solve(int v) {
    int c;
    if(v==n) return 1;
    for(c=1;c<=m;c++) {
        if(isSafe(v,c)) {
            color[v]=c;
            if(solve(v+1)) return 1;
            color[v]=0;
        }
    }
    return 0;
}
void main() {
    int i, adj[4][4]={{0,1,1,1},{1,0,1,0},{1,1,0,1},{1,0,1,0}};
    n=4; m=3;
    for(i=0;i<n;i++) { int j; for(j=0;j<n;j++) g[i][j]=adj[i][j]; color[i]=0; }
    if(solve(0)) { printf("Colors: "); for(i=0;i<n;i++) printf("V%d=%d ",i,color[i]); }
    else printf("Not possible with %d colors",m);
}
