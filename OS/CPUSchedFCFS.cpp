#include <iostream>
#include <conio.h>
using namespace std;
int table[5][6];
int tp=0;
int tat=0;
int wt=0;
int main(){
    table[1][1]=0;
    table[1][2]=5;
    table[2][1]=1;
    table[2][2]=3;
    table[3][1]=2;
    table[3][2]=8;
    table[4][1]=3;
    table[4][2]=6;
    cout<<"Gantt Chart:\n";
    for(int i=1;i<=4;i++){
        cout<<tp<<" | P"<<i<<" | ";
        tp+=table[i][2];
        table[i][3]=tp;
        table[i][4]=tp-table[i][1];
        tat+=table[i][4];
        table[i][5]=table[i][4]-table[i][2];
        wt+=table[i][5];
    }
    cout<<tp;
    cout<<"\n\nProcess\tAT\tBT\tCT\tTAT\tWT\n";
    for(int i=1;i<=4;i++){
        cout<<i<<"\t";
        for(int j=1;j<=5;j++)
            cout<<table[i][j]<<"\t";
        cout<<"\n";
    }
    cout<<"Avg. TAT:"<<(float)tat/4.0<<"ms";
    cout<<"\nAvg. WT:"<<(float)wt/4.0<<"ms";
    return 0;
}
