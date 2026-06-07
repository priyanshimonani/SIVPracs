#include <iostream>
using namespace std;

int alloc[][3]={{0,1,0},{2,0,0},{3,0,2},{2,1,1},{0,0,2}};
int maxx[][3]={{7,5,3},{3,2,2},{9,0,2},{4,2,2},{5,3,3}};
int done=0;
int avail[]={3,3,2};
int need[5][3];
int completed[5];
int i,j;
int main(){
    for(i=0;i<5;i++){
        for(j=0;j<3;j++){
            need[i][j]=maxx[i][j]-alloc[i][j];
        }
    }
    int ptr=0;
    int c=0;
    while(done!=5){
        
        if(!completed[ptr] && need[ptr][0]<=avail[0] && need[ptr][1]<=avail[1] && need[ptr][2]<=avail[2]){
            cout<<"P"<<ptr+1<<"\t";
            completed[ptr]=1;
            avail[0]+=alloc[ptr][0];
            avail[1]+=alloc[ptr][1];
            avail[2]+=alloc[ptr][2];
            done++;
            c=0;
        }
        else{
            c++;
        }
        if(c==5){
            cout<<"Unsafe state"; break;
        }
        ptr=(ptr+1)%5;
    }
    return 0;
}