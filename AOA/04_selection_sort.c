#include<stdio.h>
void selectionSort(int a[], int n) {
    int i,j,min,temp;
    for(i=0;i<n-1;i++) {
        min=i;
        for(j=i+1;j<n;j++)
            if(a[j]<a[min]) min=j;
        temp=a[i]; a[i]=a[min]; a[min]=temp;
    }
}
void main() {
    int a[]={5,2,8,1,9}, n=5, i;
    selectionSort(a,n);
    for(i=0;i<n;i++) printf("%d ",a[i]);
}
