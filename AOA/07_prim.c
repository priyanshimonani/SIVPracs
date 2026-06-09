#include<stdio.h>
#define INF 9999
void prim(int cost[][10], int n) {
    int selected[10]={0}, ne=0, min, a,b,i,j;
    selected[0]=1;
    printf("Edges in MST:\n");
    while(ne<n-1) {
        min=INF;
        for(i=0;i<n;i++)
            if(selected[i])
                for(j=0;j<n;j++)
                    if(!selected[j]&&cost[i][j]<min)
                        { min=cost[i][j]; a=i; b=j; }
        printf("%d - %d : %d\n",a,b,min);
        selected[b]=1; ne++;
    }
}
void main() {
    int cost[4][10]={{INF,2,6,INF},{2,INF,3,8},{6,3,INF,7},{INF,8,7,INF}};
    prim(cost,4);
}
