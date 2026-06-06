#include <iostream>
#include <conio.h>
using namespace std;
int table[5][6];
int q=4;
int done=0;
int time=0;
int rem[5]={0};
int comp[5]={0};

int main(){
    table[1][1]=0;
    table[1][2]=10;
    table[2][1]=1;
    table[2][2]=4;
    table[3][1]=2;
    table[3][2]=5;
    table[4][1]=3;
    table[4][2]=8;
    for(int i=1;i<=4;i++)
        rem[i]=table[i][2];
    cout<<"Gantt Chart:\n";
    cout<<"0";
    while(done!=4){
        for(int i=1;i<=4;i++){
            if(!comp[i] && table[i][1]<=time)
            {
                if(rem[i]<=q){
                    time+=rem[i];
                    comp[i]=1;
                    done++;
                }
                else{
                    time+=q;
                    rem[i]-=q;
                }
                cout<<" | P"<<i<<" | "<<time;
            }
        }
    }
    return 0;
}