#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

int max(int x, int y){
    if(x>y){
        return x;
    }
    return y;
}

//-----Using Divide and conquer-------------- O(nlogn)
int max_sum(int arr[], int st, int end){
    //if array contains 0 or 1 element
    if(end<=st){
        return arr[st];
    }

    //find middle element of array
    int mid=(st+end)/2;

    //find max subarray sum for left subarray including middle element
    int left_max=INT_MIN;
    int sum=0;
    for(int i=mid; i>=st; i--){
        sum+=arr[i];
        if(sum>left_max){
            left_max=sum;
        }
    }

    //find max subarray sum for right subarray excluding middle element
    int right_max=INT_MIN;
    sum=0;
    for(int i=mid+1; i<=end; i++){
        sum+=arr[i];
        if(sum>right_max){
            right_max=sum;
        }
    }

    //recursively find max subarray sum for left and right subarray and take max
    int max_left_right= max(max_sum(arr, st, mid), max_sum(arr,mid+1,end));  //max of LSS and RSS
    

    return max(max_left_right, left_max+right_max);     //left_max+right_max = CSS
}

int main(){
    int arr[]={-2,-5,6,-2,-3,1,5,-6};
    int n= sizeof(arr)/sizeof(arr[0]);
    printf("Max sum of contiguous subarray: %d\n",max_sum(arr,0,n-1));
    return 0;
}


//------------Kadane-------  O(n)
// void kadane(int arr[], int n){
//     int max_sum=0;
//     int curr_sum=0;

//     int max_st=0;
//     int max_end=0;
//     int curr_st=0;
//     int curr_end=0;

//     for(int i=0; i<n; i++){
//         curr_sum += arr[i];
//         curr_end=i;

//         if(curr_sum < 0){
//             curr_sum=0; //no use of including this subarray as it's value is neagtive so it decreases the max possible sum
//             //Start new sequence from nxt element
//             curr_st=curr_end+1;
//         }

//         if(max_sum < curr_sum){
//             max_sum=curr_sum;
//             max_st=curr_st;
//             max_end=curr_end;
//         }
//     }

//     printf("Total max sum of a subarray: %d\n", max_sum);
//     printf("SUbarray with max sum: ");
//     for(int i= max_st; i<max_end+1; i++){
//         printf("%d, ", arr[i]);
//     }
// }

