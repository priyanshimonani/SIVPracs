#include<stdio.h>
void main() {
    int a[]={5,2,8,1,9}, n=5, i;
    
    for(int i=0;i<n-1;i++){
        int key=a[i+1];
        int j=i;
        while(j>=0 && key<=a[j]){
            a[j+1]=a[j];
            j--;
        }
        a[j+1]=key;
    }
    for(i=0;i<n;i++) printf("%d ",a[i]);
}
