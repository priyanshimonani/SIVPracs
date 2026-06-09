#include<stdio.h>
void main() {
    char x[]="LONGEST"; int lenx=7;
    char y[]="STONE"; int leny=5;
    int dp[8][6];
    for(int i=0;i<8;i++)
        for(int j=0;j<6;j++)
            dp[i][j]=0;
    for(int i=0;i<lenx;i++){
        for(int j=0;j<leny;j++){
            if(x[i]==y[j]){
                dp[i+1][j+1]=1+dp[i][j];
            }
            else{
                dp[i+1][j+1]=(dp[i][j+1]>dp[i+1][j])?dp[i][j+1]:dp[i+1][j];
            }
            }
        }
        printf("%d", dp[7][5]);
    }
