#include<iostream>
using namespace std;

int signum(double x){ //note double
    return (x>=0)?1:-1;
}

int main(){

    double x[4][4]={
        {0.2,0.3,0.4,0.1},
        {0.1,0.8,0.5,0.2},
        {0.7,0.6,0.3,0.4},
        {0.9,0.7,0.8,0.5}
    };

    int target[4]={-1,-1,1,1};
    double net=0;

    double w[4]={0.1,0.2,0.3,0.4};
    int epoch=3;
    double lr=0.1;

    for(int e=0;e<epoch;e++){
        cout<<"\n\n****************** Epoch "<<1+e<<" ******************\n";
        //net=w*x
        for(int i=0;i<4;i++){
            cout<<"\n\n"<<i+1<<".";
            net=0; //remember
            for(int j=0;j<4;j++){
                net+=w[j]*x[i][j];
            }
            double y=signum(net);
            cout<<"\nNet: "<<net;
            cout<<"\nDesired Output: "<<target[i];
            cout<<"\nOutput: "<<y;
            if(target[i]==y){
                cout<<"\nNo changes!";
                continue;
            }
            
            for(int j=0;j<4;j++){
                w[j]=w[j]+((lr)*(target[i]-y)*x[i][j]); //careful with i j
            }
            cout<<"\nUpdated Weight: ";
            for(int j=0;j<4;j++){
                cout<<w[j]<<"\t";
            }
        }
    }
    cout<<"\nFinal Weight: ";
            for(int j=0;j<4;j++){
                cout<<w[j]<<"\t";
            }

    return 0;
}