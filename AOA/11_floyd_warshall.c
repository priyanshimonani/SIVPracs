#include <stdio.h>
void main(){
    int a[][4]={{0,3,999,7},{8,0,2,999},{5,999,0,1},{2,999,999,0}};
    for(int k=0;k<4;k++){
        for(int i=0;i<4;i++){
            for(int j=0;j<4;j++){
                a[i][j]=(a[i][j]<a[i][k]+a[k][j])?a[i][j]:a[i][k]+a[k][j];
            }
        }
    }
    for(int i=0;i<4;i++){
            for(int j=0;j<4;j++){
                printf("%d\t", a[i][j]);
            }
            printf("\n");
        }
}