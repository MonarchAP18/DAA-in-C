#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to partition the array
int partition(int arr[], int low, int high)
{
    int pivot = arr[low];
    int i = low - 1, j = high + 1;

    while (1)
    {
        do
        {
            i++;
        } while (arr[i] < pivot);

        do
        {
            j--;
        } while (arr[j] > pivot);

        if (i >= j){
            return j;
        }   
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
}

// Function to partition the array randomly
int partition_random(int arr[], int low, int high)
{
    srand(time(0));
    int random = low + rand() % (high - low);

    int temp = arr[random];
    arr[random] = arr[low];
    arr[low] = temp;

    return partition(arr, low, high);
}

// Function to sort the array using quicksort algorithm
void quicksort(int arr[], int low, int high)
{
    if (low < high)
    {
        int pi = partition_random(arr, low, high);
        quicksort(arr, low, pi);
        quicksort(arr, pi + 1, high);
    }
}

// Function to print the sorted array
void print_array(int arr[], int n)
{
    printf("Sorted array: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main()
{
    int arr[] = {-27, 74, -95, 61, -33, 12, -5, 49};
    int n = sizeof(arr) / sizeof(arr[0]);
    quicksort(arr, 0, n - 1);
    print_array(arr, n);

    return 0;
}