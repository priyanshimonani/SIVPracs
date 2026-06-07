#include <iostream>
using namespace std;

int n, len;
int str[100];
int pf, hit;


bool present(int f[], int x)
{
    for (int i=0;i<n;i++)
        if (x==f[i])
            return true;
    return false;
}

void fifo()
{
    int f[100];
    pf=0;
    for (int i=0;i<n;i++)
        f[i]=-1;
    int ptr=0;
    for (int i=0;i<len;i++){
        int page=str[i];
        if(!present(f, page)){
            pf++;
            f[ptr]=page;
            ptr=(ptr+1)%n;
        }
    }
    cout<<"\nFIFO Page Faults: "<<pf;
}

int minn(int f[], int lp[])
{
    int mindex = 0;

    for(int i=1;i<n;i++)
    {
        if(lp[f[i]] < lp[f[mindex]])
            mindex = i;
    }

    return mindex;
}

void lru()
{
    int f[100];

    for(int i=0;i<n;i++)
        f[i] = -1;

    pf = 0;

    int lp[100];

    for(int i=0;i<100;i++)
        lp[i] = -1;

    for(int i=0;i<len;i++)
    {
        int page = str[i];
        lp[page] = i;

        if(!present(f,page))
        {
            int pos = -1;

            // Find empty frame first
            for(int j=0;j<n;j++)
            {
                if(f[j] == -1)
                {
                    pos = j;
                    break;
                }
            }

            // If no empty frame, find LRU page
            if(pos == -1)
                pos = minn(f, lp);

            f[pos] = page;
            pf++;
        }
    }

    cout<<"\nLRU Page Faults: "<<pf;
}


void lfu()
{
    int f[100];
    for(int i=0;i<n;i++)
        f[i] = -1;
    pf = 0;
    int freq[100];
    for(int i=0;i<100;i++)
        freq[i] = 0;
    for(int i=0;i<len;i++){
        int page=str[i];
        if(!present(f,page)){
            pf++;
            freq[page]=1;
            int mindex=minn(f,freq);
            f[mindex]=page;
        }
        else
            freq[page]++;

    }
    cout<<"\nLFU Page Faults: "<<pf;
}

void optimal()
{

}

int main()
{
    cout<<"Enter number of requests: ";
    cin>>len;

    cout<<"Enter requests: ";
    for(int i=0;i<len;i++)
        cin>>str[i];

    cout<<"Enter frame size: ";
    cin>>n;

    fifo();
    lru();
    lfu();
    optimal();

    return 0;
}