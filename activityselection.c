// ind array has activity number, arr has start time, arr2 has finish time.

/*
ind  0 1 2 3 4 5    (Activity number)
arr  5 8 0 1 5 3    (Start time of activity)
arr2 9 9 6 2 7 4    (Finish time of activity)
*/

#include <stdio.h>

void swap(int *xp, int *yp){
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}



void bubbleSort(int arr[], int arr2[], int ind[], int n){
    int i, j;
    for (i = 0; i < n - 1; i++){
        for (j = 0; j < n - i - 1; j++){
            if (arr2[j] > arr2[j + 1]){   
                swap(&arr2[j], &arr2[j + 1]);
                swap(&arr[j], &arr[j + 1]);
                swap(&ind[j], &ind[j + 1]);
            }
        }

        if (arr2[j] == arr2[j + 1]){    //if finish time is same, check the start time of activity
            if (arr[j] > arr[j + 1]){
                swap(&arr[j], &arr[j + 1]);
                swap(&ind[j], &ind[j + 1]);
            }
        }
    }
}


// Prints a maximum set of activities that can be done by a
// single person, one at a time.
void printMaxActivities(int arr[], int arr2[], int ind[], int n){
    int i, j;
    printf("Following Activities are selected\n");

    // The first activity always gets selected
    i = 0;
    printf("%d ", ind[i]);
    for (j = 1; j < n; j++){
        // If this activity has start time greater than or
        // equal to the finish time of previously selected
        // activity, then select it
        if (arr[j] >= arr2[i]){
            printf("%d ", ind[j]);
            i = j;
        }
    }
}

int main(){
    int s[] = {1,0,1,4,2,5,4,3};
    int f[] = {3,4,2,6,9,8,5,5};
    int ind[] = {1,2,3,4,5,6,7,8};
    int n = sizeof(s) / sizeof(s[0]);
    bubbleSort(s, f, ind, n);
    for(int i=0;i<n;i++){
        printf("%d ", ind[i]);
        
    }
    printf("\n");
    for(int i=0;i<n;i++){
        printf("%d ", s[i]);
    }
    printf("\n");
    for(int i=0;i<n;i++){
        printf("%d ", f[i]);
    }
    printf("\n");
    printMaxActivities(s, f, ind, n);
    return 0;
}