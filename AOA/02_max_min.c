#include<stdio.h>

int a[]={5,7,3,1,9};

int min,max;

void mm(int l,int h)
{
    int min1,max1,min2,max2,m;

    if(l==h){
        min=max=a[l];
        return;
    }

    if(l==h-1){
        if(a[l]<a[h]){
            min=a[l];
            max=a[h];
        }
        else{
            min=a[h];
            max=a[l];
        }
        return;
    }

    m=(l+h)/2;

    mm(l,m);
    min1=min;
    max1=max;

    mm(m+1,h);
    min2=min;
    max2=max;

    min=(min1<min2)?min1:min2;
    max=(max1>max2)?max1:max2;
}

void main()
{
    mm(0,4);

    printf("Min=%d\nMax=%d",min,max);
}