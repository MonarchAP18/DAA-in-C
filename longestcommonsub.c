#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int values[50][50];  //or c table
int arrow[50][50];  //or b table

int lcs(char x[], char y[], int xlen, int ylen){
    for(int i=0; i<=xlen; i++){
        values[i][0]=0;
    }
    for(int i=0; i<=ylen; i++){
        values[0][i]=0;
    }

    //c, u and l denotes cross, upward and downward directions
    for(int i=0; i<=xlen; i++){
        for(int j=0; j<=ylen; j++){

            if(x[i-1] == y[j-1]){    //if character match is found
                values[i][j] = values[i-1][j-1] +1;
                arrow[i][j] = 'c';
            }

            else if(values[i-1][j] >= values[i][j-1]){
                values[i][j] = values[i-1][j];  //take max value of upper and left box, here upper his larger
                arrow[i][j] = 'u';
            }

            else{
                values[i][j] = values[i][j-1];  //take max value of upper and left box, here left his larger
                arrow[i][j] = 'l';
            }
        }
    }
    return values[xlen][ylen]-1;
}

void printlcs(char x[], int i, int j){   //i and j are indexes of values/arrows table equal to string length
    if(i==0 || j==0){
        return;
    }
    if(arrow[i][j] == 'c'){
        printlcs(x, i-1,j-1);
        printf("%c", x[i-1]);
    }
    else if(arrow[i][j] == 'u'){
        printlcs(x, i-1, j);
    }
    else printlcs(x,i,j-1);
}

int main(){
    char x[25], y[25];
    printf("Enter 1st sequence: ");
    scanf("%s", x);
    printf("Enter 2nd sequence: ");
    scanf("%s", y);
    

    int xlen,ylen;
    xlen = strlen(x);
    ylen = strlen(y);

    int finalans = lcs(x, y, xlen, ylen);
    printf("\nThe length of longest common subsequence is: %d", finalans);

    printf("\nThe Longest Common Subsequence is: ");
    printlcs(x, xlen, ylen);
}