#include <iostream>
#include <algorithm>
#include <conio.h>
using namespace std;
int nb,np;
int b[100];
int p[100];
int palloc=0;
int filled[100];
int intf=0,extf=0; //internal-free inside a block, ext-blocks unused
void ff(){
    for(int i=0;i<np;i++){
        int alloc=0;
        for (int j=0;j<nb;j++){
            if(!filled[j] && p[i]<=b[j]){
                cout<<"\nProccess "<<i+1<<"("<<p[i]<<"KB): "<<b[j]<<"KB";
                filled[j]=1;
                palloc++;
                intf+=(b[j]-p[i]);
                alloc=1;
                break;
            }
        }
        if(alloc==0)
            cout<<"\nProccess "<<i+1<<"("<<p[i]<<"): Unallocated";
    }
    for(int i=0;i<nb;i++)
        if(!filled[i])
            extf+=b[i];
    cout<<"\nInternal Fragmentation: "<<intf<<"KB";
    cout<<"\nExternal Fragmentation: "<<extf<<"KB";
}

void bf(){
    sort(b, b + nb);
    for(int i=0;i<np;i++){
        int alloc=0;
        for (int j=0;j<nb;j++){
            if(!filled[j] && p[i]<=b[j]){
                cout<<"\nProccess "<<i+1<<"("<<p[i]<<"KB): "<<b[j]<<"KB";
                filled[j]=1;
                palloc++;
                intf+=(b[j]-p[i]);
                alloc=1;
                break;
            }
        }
        if(alloc==0)
            cout<<"\nProccess "<<i+1<<"("<<p[i]<<"): Unallocated";
    }
    for(int i=0;i<nb;i++)
        if(!filled[i])
            extf+=b[i];
    cout<<"\nInternal Fragmentation: "<<intf<<"KB";
    cout<<"\nExternal Fragmentation: "<<extf<<"KB";
}

void wf(){
    sort(b, b + nb);
    for(int i=0;i<np;i++){
        int alloc=0;
        for (int j=nb-1;j>=0;j--){
            if(!filled[j] && p[i]<=b[j]){
                cout<<"\nProccess "<<i+1<<"("<<p[i]<<"KB): "<<b[j]<<"KB";
                filled[j]=1;
                palloc++;
                intf+=(b[j]-p[i]);
                alloc=1;
                break;
            }
        }
        if(alloc==0)
            cout<<"\nProccess "<<i+1<<"("<<p[i]<<"): Unallocated";
    }
    for(int i=0;i<nb;i++)
        if(!filled[i])
            extf+=b[i];
    cout<<"\nInternal Fragmentation: "<<intf<<"KB";
    cout<<"\nExternal Fragmentation: "<<extf<<"KB";
}

void nf(){
    int j=0;
    for(int i=0;i<np;i++){
        int alloc=0;
        int c=0;
        while(c<=nb){
            if(!filled[j] && p[i]<=b[j]){
                cout<<"\nProccess "<<i+1<<"("<<p[i]<<"KB): "<<b[j]<<"KB";
                filled[j]=1;
                palloc++;
                intf+=(b[j]-p[i]);
                alloc=1;
                break;
            }
            c++; //IMP!!!!
            j=(j+1)%nb;
        }
        if(alloc==0)
            cout<<"\nProccess "<<i+1<<"("<<p[i]<<"): Unallocated";
    }
    for(int i=0;i<nb;i++)
        if(!filled[i])
            extf+=b[i];
    cout<<"\nInternal Fragmentation: "<<intf<<"KB";
    cout<<"\nExternal Fragmentation: "<<extf<<"KB";
}

int main(){
    cout<<"Enter number of memory blocks: \n";
    cin>>nb;
    cout<<"Enter size of memory blocks: \n";
    for(int i=0;i<nb;i++)
        cin>>b[i];
    cout<<"Enter number of processes: \n";
    cin>>np;
    cout<<"Enter size of proccesses: \n";
    for(int i=0;i<np;i++)
        cin>>p[i];
    int ch;
    cout<<"1.First Fit\n2.Best Fit\n3.Worst Fit\n4.Next Fit\nEnter Choice: ";
    cin>>ch;
    switch(ch){
        case 1: ff(); break;
        case 2: bf(); break;
        case 3: wf(); break;
        case 4: nf(); break;
        default: cout<<"Invalid Input";
    }
    return 0;
}