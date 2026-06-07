#include <iostream>
using namespace std;

int n, len;
int str[100];
int pf;

bool present(int f[], int page)
{
    for(int i=0;i<n;i++)
        if(f[i]==page)
            return true;
    return false;
}

void fifo()
{
    int f[20];
    for(int i=0;i<n;i++) f[i]=-1;

    pf=0;
    int ptr=0;

    for(int i=0;i<len;i++)
    {
        if(!present(f,str[i]))
        {
            f[ptr]=str[i];
            ptr=(ptr+1)%n;
            pf++;
        }
    }

    cout<<"FIFO Page Faults = "<<pf<<endl;
}

void lru()
{
    int f[20], recent[20];

    for(int i=0;i<n;i++)
    {
        f[i]=-1;
        recent[i]=-1;
    }

    pf=0;

    for(int i=0;i<len;i++)
    {
        int page=str[i];
        bool hit=false;

        for(int j=0;j<n;j++)
        {
            if(f[j]==page)
            {
                recent[j]=i;
                hit=true;
                break;
            }
        }

        if(!hit)
        {
            int pos=0;

            for(int j=1;j<n;j++)
                if(recent[j]<recent[pos])
                    pos=j;

            f[pos]=page;
            recent[pos]=i;
            pf++;
        }
    }

    cout<<"LRU Page Faults = "<<pf<<endl;
}

void lfu()
{
    int f[20], freq[20];

    for(int i=0;i<n;i++)
    {
        f[i]=-1;
        freq[i]=0;
    }

    pf=0;

    for(int i=0;i<len;i++)
    {
        int page=str[i];
        bool hit=false;

        for(int j=0;j<n;j++)
        {
            if(f[j]==page)
            {
                freq[j]++;
                hit=true;
                break;
            }
        }

        if(!hit)
        {
            int pos=0;

            for(int j=1;j<n;j++)
                if(freq[j]<freq[pos])
                    pos=j;

            f[pos]=page;
            freq[pos]=1;
            pf++;
        }
    }

    cout<<"LFU Page Faults = "<<pf<<endl;
}

void optimal()
{
    int f[20];

    for(int i=0;i<n;i++)
        f[i]=-1;

    pf=0;

    for(int i=0;i<len;i++)
    {
        int page=str[i];

        if(present(f,page))
            continue;

        int pos=-1;

        for(int j=0;j<n;j++)
        {
            if(f[j]==-1)
            {
                pos=j;
                break;
            }
        }

        if(pos==-1)
        {
            int farthest=-1;

            for(int j=0;j<n;j++)
            {
                int next=len+1;

                for(int k=i+1;k<len;k++)
                {
                    if(f[j]==str[k])
                    {
                        next=k;
                        break;
                    }
                }

                if(next>farthest)
                {
                    farthest=next;
                    pos=j;
                }
            }
        }

        f[pos]=page;
        pf++;
    }

    cout<<"Optimal Page Faults = "<<pf<<endl;
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