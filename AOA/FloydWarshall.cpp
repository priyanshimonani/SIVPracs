#include <iostream>
using namespace std;

int main() {

    int INF = 9999;

    int d[4][4] = {
        {0,5,INF,10},
        {INF,0,3,INF},
        {INF,INF,0,1},
        {INF,INF,INF,0}
    };

    for(int k=0;k<4;k++)
        for(int i=0;i<4;i++)
            for(int j=0;j<4;j++)
                d[i][j]=min(
                    d[i][j],
                    d[i][k]+d[k][j]
                );

    for(int i=0;i<4;i++) {
        for(int j=0;j<4;j++)
            cout<<d[i][j]<<" ";
        cout<<"\n";
    }
}