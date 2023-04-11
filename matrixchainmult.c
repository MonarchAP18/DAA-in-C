#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

int K[20][20];    //the k matrix to tell where to put paranthesis '( )'

int costOfMatrixMultiplication(int d[], int n){
    int cost[n][n]; //cost matrix

    //initialize cost matrix and k matrix to 0
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cost[i][j]=0;
            K[i][j]=0;
        }
    }

    //here Mlen is chain length of matrix taken. if Mlen=x it means product of x matrices taken first.
    //it goes from 2 to n
    for(int Mlen=2; Mlen<n; Mlen++){
        for(int i=1; i<n-Mlen+1; i++){   //i should go from 1 to n-Mlen+1, 
            int j=i+Mlen-1;              //j-i=Mlen. if n=5 Mlen=2 then c[i][j] should be c[1][3] c[2][4] c[3][5]
            cost[i][j]=INT_MAX; //assign max value first

            for(int k=i; k<=j-1; k++){   //  i <= k < j
                int temp = cost[i][k] + cost[k+1][j] + d[i-1]*d[k]*d[j];
                if(temp < cost[i][j]){   //to find minimum of all
                    cost[i][j] = temp;
                    K[i][j] = k;
                }
            }
        }
    }
    return cost[1][n-1];
}

void printMatrixWithParanthesis(int a, int b){
    if(a==b){
        printf(" A%d ", a);
    }
    else{
        printf("(");
        printMatrixWithParanthesis(a, K[a][b]);
        printMatrixWithParanthesis(K[a][b]+1, b);
        printf(")");
    }
}

int main(){
    printf("Enter the number of matrices: ");
    int n;
    scanf("%d", &n);

    n+=1;  //increment as no. of dimensions = no. of matrix + 1
    int d[n];  //dimension array
    printf("Enter dimensions of matrix:\n");
    for(int i=0; i<n; i++){
        printf("Enter dim%d: ", i);
        scanf("%d", &d[i]);
    }

    int totalMinCost=costOfMatrixMultiplication(d,n);
    printf("Total minimum cost of multiplying matrices: %d\n", totalMinCost);
    printMatrixWithParanthesis(1,n-1);  //as only first row is required to tell where to put paranthesis
}