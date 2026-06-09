#include<stdio.h>
#include<math.h>
int q[20], n;
int isSafe(int row, int col) {
    int i;
    for(i=1;i<row;i++)
        if(q[i]==col || abs(q[i]-col)==abs(i-row)) return 0;
    return 1;
}
void solve(int row) {
    int col, i;
    if(row>n) {
        for(i=1;i<=n;i++) printf("%d ",q[i]);
        printf("\n"); return;
    }
    for(col=1;col<=n;col++)
        if(isSafe(row,col)) { 
            q[row]=col; 
            solve(row+1); 
        }
}
void main() {
    printf("Enter N: "); scanf("%d",&n);
    solve(1);
}
