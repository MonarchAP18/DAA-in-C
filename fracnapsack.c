#include<stdio.h>
#include<stdlib.h>


void frac_napsack(int n, int *cost, int *wt, int W){
    int curr_wt;
    float final_cost;
    int maxi;
    int *used;   //array to store which object is used. if value is 1 then the object is already used else 0 if not used
    used=(int*)malloc(sizeof(int)*n);
    float *cw_ratio;   //array that stores ratio of cost to weight
    cw_ratio=(float*)malloc(sizeof(float)*n);

    for(int i=0;i<n;i++){
        cw_ratio[i]=(float)cost[i]/wt[i];
        used[i]=0;
    }

    curr_wt=W;
    while(curr_wt>0){
        maxi=-1;
        for(int i=0; i<n; i++){
            if((used[i]==0) && ((maxi==-1) || (cw_ratio[i] > cw_ratio[maxi]))){
                maxi=i;
            }
        }

        used[maxi]=1;
        curr_wt = curr_wt - wt[maxi];
        final_cost = final_cost + (float)cost[maxi];

        if(curr_wt >=0){
            printf("Added object %d (%d$, %dKg) completely in the bag. Space left: %d.\n", maxi + 1, cost[maxi], wt[maxi], curr_wt);
        }
        else{
            float fractional_add=(1 + (float)curr_wt/wt[maxi]);
            printf("Added %.2f%% (%d$, %dKg) of object %d in the bag.\n",fractional_add*100, cost[maxi], wt[maxi], maxi + 1);
            final_cost=final_cost-(float)cost[maxi];
            final_cost=final_cost+ fractional_add*(float)cost[maxi];
            
        }
    }

    printf("Total max cost: %.2f\n", final_cost);
}

int main(){
    printf("Enter no. of objects and max weight in a sack: ");
    int n,W;  //no. of objects and total weight that can be carried at a time
    scanf("%d %d", &n,&W);
    int *cost,*wt;  //Cost of each object (array) & Weight of each object (array)
    cost=(int*)malloc(sizeof(int)*n);
    wt=(int*)malloc(sizeof(int)*n);
    for(int i=0;i<n;i++){
        printf("Enter object %d cost and weight: ", i+1);
        scanf("%d %d", &cost[i], &wt[i]);
    }

    frac_napsack(n,cost,wt,W);
}