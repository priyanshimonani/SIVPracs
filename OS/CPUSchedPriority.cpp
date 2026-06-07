#include <iostream>
using namespace std;

int table[5][6];

int main()
{
    table[1][1]=0; table[1][2]=6; table[1][3]=2;
    table[2][1]=2; table[2][2]=8; table[2][3]=1;
    table[3][1]=4; table[3][2]=7; table[3][3]=4;
    table[4][1]=6; table[4][2]=3; table[4][3]=3;

    int completed[5]={0};
    int done=0;
    int time=0;

    while(done!=4)
    {
        int best=-1;

        for(int i=1;i<=4;i++)
        {
            if(!completed[i] &&
               table[i][1]<=time &&
               (best==-1 || table[i][3]<table[best][3]))
            {
                best=i;
            }
        }

        if(best==-1)
        {
            time++;
            continue;
        }

        cout<<time<<" | P"<<best<<" | ";

        time += table[best][2];
        completed[best]=1;
        done++;
    }

    cout<<time;

    return 0;
}