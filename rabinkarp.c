#include <stdio.h>
#include <string.h>

#define D 10
#define Q 11

int main() {
    char T[] = "DAAINCLANGUAGE";
    char P[] = "LA";
    int n = strlen(T);
    int m = strlen(P);
    int i, j;
    int p = 0, t = 0;
    int h = 1;
    int count = 0;
    for (i = 0; i < m-1; i++) {
        h = (h * D) % Q;
    }
    for (i = 0; i < m; i++) {
        p = (D*p + P[i]) % Q;
        t = (D*t + T[i]) % Q;
    }
    for (i = 0; i <= n-m; i++) {
        if (p == t) {
            for (j = 0; j < m; j++) {
                if (T[i+j] != P[j]) {
                    break;
                }
            }
            if (j == m) {
                printf("Pattern found at index %d\n", i);
            } else {
                count++;
            }
        }
        if (i < n-m) {
            t = (D*(t - T[i]*h) + T[i+m]) % Q;
            if (t < 0) {
                t = (t + Q);
            }
        }
    }
    printf("Number of spurious hits: %d\n", count);

    return 0;
}