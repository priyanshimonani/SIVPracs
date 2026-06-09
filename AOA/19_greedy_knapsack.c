#include<stdio.h>

void main() {
    float w[]={2,3,5,7,1,4,1}, p[]={10,5,15,7,6,18,3};
    int n=7, cap=15;
    float tp=0, tw=0;
    float a[7];
    int id[7];
    for (int i=0;i<7;i++){
        a[i]=p[i]/w[i];
        id[i]=i;
    }
    int i;
    for (i=0;i<6;i++){
        int mindex=i;
        for(int j=i+1;j<7;j++)
            if(a[j]>a[mindex])
                mindex=j;
        float temp=a[i];
        a[i]=a[mindex];
        a[mindex]=temp;
        int temp1;
        temp1=id[i];
        id[i]=id[mindex];
        id[mindex]=temp1;
    }
    for(i=0;i<7;i++){
        if(tw+w[id[i]]>cap)
            break;
        else{
            tp+=p[id[i]];
            tw+=w[id[i]];
        }
    }
    tp+=p[id[i]]*(cap-tw)/w[id[i]];
    printf("%f units", tp);
}

