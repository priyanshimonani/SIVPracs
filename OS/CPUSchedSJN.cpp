#include <iostream>
#include <conio.h>
using namespace std;
int table[5][6];

int main(){
    table[1][1]=0;
    table[1][2]=6;
    table[2][1]=2;
    table[2][2]=8;
    table[3][1]=4;
    table[3][2]=7;
    table[4][1]=6;
    table[4][2]=3;
    int shortest=-1;
    int done=0;
    int completed[5]={0};
    int time=0;
    while(done!=4){
        //finding shortest that has arrived in given time and isnt complete, NOT SORT
        shortest=1;
        int st=100000;
        for (int i=1;i<=4;i++){
            if(!completed[i] && table[i][1]<=time && table[i][2]<=st){
                shortest=i;
                st=table[shortest][2];
            }
        }
        done++;
        completed[shortest]=1;
        cout<<time<<" | P"<<shortest<<" | ";
        time+=table[shortest][2];
    }
    cout<<time;
}