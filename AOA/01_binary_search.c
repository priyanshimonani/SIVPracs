#include<stdio.h>
int binarySearch(int a[], int n, int key) {
    int low=0, high=n-1, mid;
    while(low<=high) {
        mid=(low+high)/2;
        if(a[mid]==key) return mid;
        else if(a[mid]<key) low=mid+1;
        else high=mid-1;
    }
    return -1;
}
void main() {
    int a[]={1,3,5,7,9,11}, n=6, key, pos;
    printf("Enter key: "); scanf("%d",&key);
    pos=binarySearch(a,n,key);
    if(pos!=-1) printf("Found at index %d",pos);
    else printf("Not found");
}
