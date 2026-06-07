#include <iostream>
using namespace std;

int table[5][6];

int main()
{
    table[1][1]=0; table[1][2]=8;
    table[2][1]=2; table[2][2]=2;
    table[3][1]=4; table[3][2]=5;
    table[4][1]=6; table[4][2]=3;

    int time=0;
    int done=0;

    int rt[5];
    for(int i=1;i<=4;i++)
        rt[i]=table[i][2];

    int completed[5]={0};

    while(done!=4)
    {
        int shortest=-1;

        for(int i=1;i<=4;i++)
        {
            if(!completed[i] &&
               table[i][1]<=time &&
               (shortest==-1 || rt[i]<rt[shortest]))
            {
                shortest=i;
            }
        }

        if(shortest==-1)
        {
            time++;
            continue;
        }

        cout<<"P"<<shortest<<" ";

        rt[shortest]--;   // execute for 1 unit
        time++;

        if(rt[shortest]==0)
        {
            completed[shortest]=1;
            done++;
        }
    }

    return 0;
}