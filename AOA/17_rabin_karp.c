#include<stdio.h>
#include<string.h>

void main() {
    char txt[] = "ABCCDABCD";
    char pat[] = "ABCD";

    int n = strlen(txt);
    int m = strlen(pat);

    int ph = 0, th = 0;

    // Hash of pattern and first window
    for(int i=0; i<m; i++) {
        ph += pat[i];
        th += txt[i];
    }

    for(int i=0; i<=n-m; i++) {

        if(ph == th) {
            int j;
            for(j=0; j<m; j++) {
                if(txt[i+j] != pat[j])
                    break;
            }

            if(j == m)
                printf("Pattern found at index %d\n", i);
        }

        // Rolling hash
        if(i < n-m)
            th = th - txt[i] + txt[i+m];
    }
}