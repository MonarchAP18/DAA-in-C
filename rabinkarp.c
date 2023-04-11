#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//d is number of characters in input alphabet
#define d 256

void search(char pat[], char txt[], int q){
    int M=strlen(pat);
    int N=strlen(txt);
    int i,j;
    int p=0; //hash value of pattern
    int t=0; //hash value of text
    int h=1;
    int k=0;

    //value of h is "pow(d, M-1)%q"
    for(i=0; i<M; i++){
        h=(h*d)%q;
    }

    //calculate hash value of pattern and text of first window of text
    for(i = 0; i<M; i++){
        p=(d*p + pat[i]) % q;   //will be taken in ASCII
        t=(d*t + txt[i]) % q;
    }

    for(i=0; i<=N-M; i++){
        //check hash value, if match, compare
        if(p==t){
            for(j=0; j<M; j++){
                if(txt[i+j] != pat[j]){
                    break;
                }
            }

            if(j==M){
                k++;
                printf("Pattern found at index %d\n", i);
            }
        }

        if(i<N-M){
            //if t=123 and next letter is 4, then change t to 234. remove 1 from start and add 4 at last.
            t=(d*(t-txt[i]*h) + txt[i+M])%q;  //removing leading digit and adding trailing digit.
            

            if(t<0){  //if hash is negative
                t=t+q;
            }
        }
    }

    if(k==0){
        printf("No match found\n");
    }
}

int main(){
    char txt[100];
    char pat[10];
    int q=17;

    printf("\nEnter the text: ");
    scanf("%s", txt);
    printf("Enter the pattern to be found: ");
    scanf("%s", pat);

    search(pat, txt, q);
    return 0;
}