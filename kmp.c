#include<stdio.h>
#include<string.h>

void lps_pat(char *p, int M, int *lps){   //M is length of pattern
    int length = 0;
    int i = 1;
    lps[0] = 0;
    while(i < M){
        if(p[i] == p[length]){
            length++;
            lps[i]=length;
            i++;
        }
        else{
            if(length!=0){
                length = lps[length-1];
            }
            else{
                lps[i]=0;
                i++;
            }
        }
    }
}

void KMP(char *t, char *p){
    int M=strlen(p);
    int N=strlen(t);
    int lps[M];
    lps_pat(p, M, lps);
    int k=0;
    int i=0;
    int j=0;
    while(i<N){
        if(p[j] == t[i]){
            i++;
            j++;
        }
        if(j==M){
            k++;
            printf("Pattern found at index %d\n", i-j);
            j = lps[j-1];
        }
        else if(i<N && p[j] != t[i]){
            if(j!=0){
                j=lps[j-1];
            }
            else{
                i=i+1;
            }
        }
    }
    if(k==0){
        printf("No match found\n");
    }
}

int main() {
    char t[100];
    char p[10];
    printf("Enter the text: ");
    scanf("%s", t);
    printf("Enter the pattern to be found: ");
    scanf("%s", p);

    KMP(t, p);
    return 0;
}