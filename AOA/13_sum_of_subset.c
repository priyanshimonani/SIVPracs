#include<stdio.h>
int a[]={3,5,6,7}, n=4, target=15;
void subset(int idx, int sum, int sel[]) {
    int i;
    if(sum==target) {
        printf("{ ");
        for(i=0;i<n;i++) if(sel[i]) printf("%d ",a[i]);
        printf("}\n"); return;
    }
    if(idx==n || sum>target) return;
    sel[idx]=1; subset(idx+1, sum+a[idx], sel);
    sel[idx]=0; subset(idx+1, sum, sel);
}
void main() {
    int sel[10]={0};
    printf("Subsets with sum %d:\n",target);
    subset(0,0,sel);
}
