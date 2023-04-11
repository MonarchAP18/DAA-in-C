#include<stdio.h>
#include<string.h>

void search(char *p, char *t){
    int len_p = strlen(p);
    int len_t = strlen(t);
    int k;   //number of matches

    for(int i = 0; i <= len_t - len_p; i++){
        int j;
        for(j = 0; j < len_p; j++){
            if(t[i+j] != p[j]){
               break;
            }
        }
        if(j == len_p){           //pattern found
            k++;
            printf("Pattern found at index %d\n", i);
        }
    }

    if(k==0){
        printf("No match found\n");
    }
}

int main(){
    char t[100];
    char p[10];

    printf("\nEnter the text: ");
    scanf("%s", t);

    printf("Enter the pattern to be found: ");
    scanf("%s", p);

    search(p,t);
    return 0;
}