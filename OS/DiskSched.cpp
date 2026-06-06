#include <iostream>
#include <conio.h>
#include <algorithm>
#include <stdlib.h>
using namespace std;
int f,l,s,hm=0, n;
int req[100];

void fcfs(){
    hm=abs(s-req[0]);
    cout<<"\nOrder: "<<s<<"\t";
    for(int i=0;i<n-1;i++){
        cout<<req[i]<<"\t";
        hm+=abs(req[i]-req[i+1]);
    }
    cout<<req[n-1];
    cout<<"\nTotal head moment: "<<hm;
} 

void sstf(){
    int visited[n];
    sort(req, req+n+1);
    int si=0;
    while(req[si]!=s)
        si++;
    int ci=si;
    int done=0;
    while(done!=n){
        int ld=100, rd=1000;
        if(!visited[ci] && ci==0){ //first req
            cout<<ci<<"\t";
            visited[ci]=1;
            while(!visited[ci]) //go to next unvisited
                ci++;
            done++;
        }
        else if(!visited[ci] && ci==n){
            cout<<ci<<"\t";
            visited[ci]=1;
            while(!visited[ci]) //go to next unvisited
                ci--;
            done++;
        }
        else{
            cout<<ci;
            visited[ci]=1;
            done++;
            int i=ci, j=ci;
            //calc rd
            while(i<=n){
                if(!visited[i])
                    break;
                i++;
            }
            rd=abs(req[ci]-req[i]);
            while(j<=0){
                if(!visited[j])
                    break;
                j--;
            }
            ld=abs(req[ci]-req[j]);
            ci=(ld<rd)?j:i;
        }
    }
}

void scan(){ //input direction, rn assuming higher
    sort(req, req+n+1);
    int si=0;
    while(req[si]!=s)
        si++;
    cout<<"\nOrder: ";
    for(int i=si;i<n+1;i++)
        cout<<req[i]<<"\t";
    cout<<l<<"\t";
    for(int i=si-1;i>=0;i--)
        cout<<req[i]<<"\t";
    hm=(l-s)+(l-req[0]);
    cout<<"\nTotal head moment: "<<hm;
}

void cscan(){
    sort(req, req+n+1);
    int si=0;
    while(req[si]!=s)
        si++;
    cout<<"\nOrder: ";
    for(int i=si;i<n+1;i++)
        cout<<req[i]<<"\t";
    cout<<l<<"\t"<<f<<"\t";
    for(int i=f;i<si;i++)
        cout<<req[i]<<"\t";
    hm=(l-s)+(l-f)+(req[si-1]-f);
    cout<<"\nTotal head moment: "<<hm;
}

void look(){

}

void  clook(){

}

int main(){
    cout<<"Enter first rim number: ";
    cin>>f;
    cout<<"Enter last rim number: ";
    cin>>l;
    cout<<"Enter starting head position: ";
    cin>>s;
    cout<<"Enter number of requests: ";
    cin>>n;
    cout<<"Enter Requests: ";
    for(int i=0;i<n;i++)
        cin>>req[i];
    req[n]=s;
    int ch;
    cout<<"1.FCFS\n2.SSTF\n3.SCAN\n4.CSCAN\n5.LOOK\n6.CLOOK\nEnter Choice: ";
    cin>>ch;
    switch(ch){
        case 1: fcfs(); break;
        case 2: sstf(); break;
        case 3: scan(); break;
        case 4: cscan(); break;
        case 5: look(); break;
        case 6: clook(); break;
        default: cout<<"Invalid Input";
    }
    return 0;
}