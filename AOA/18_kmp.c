#include<stdio.h>
#include<string.h>

void main() {
    char txt[]="AABABCABCABC";
    char pat[]="ABCABC";

    int n=strlen(txt);
    int m=strlen(pat);

    int lps[20];

    // Compute LPS
    lps[0]=0;
    int len=0, i=1;

    while(i<m){
        if(pat[i]==pat[len]){
            len++;
            lps[i]=len;
            i++;
        }
        else{
            if(len)
                len=lps[len-1];
            else{
                lps[i]=0;
                i++;
            }
        }
    }

    // KMP Search
    i=0;
    int j=0;

    while(i<n){

        if(txt[i]==pat[j]){
            i++;
            j++;
        }

        if(j==m){
            printf("Pattern found at index %d\n", i-j);
            j=lps[j-1];
        }
        else if(i<n && txt[i]!=pat[j]){
            if(j)
                j=lps[j-1];
            else
                i++;
        }
    }
}