#include <stdio.h>

// Function to merge two sorted subarrays
void merge(int a[], int left, int mid, int right)
{
    int i = left;      // starting index of left subarray
    int j = mid + 1;   // starting index of right subarray
    int k = left;      // index for temporary array
    int temp[100];     // temporary array
    // Compare elements from both subarrays and store smaller one
    while(i <= mid && j <= right)
    {
        if(a[i] <= a[j])
        {
            temp[k] = a[i];
            i++;
        }
        else
        {
            temp[k] = a[j];
            j++;
        }
        k++;
    }
    // Copy remaining elements from left subarray (if any)
    while(i <= mid)
    {
        temp[k] = a[i];
        i++;
        k++;
    }
    // Copy remaining elements from right subarray (if any)
    while(j <= right)
    {
        temp[k] = a[j];
        j++;
        k++;
    }
    // Copy sorted elements back to original array
    for(i = left; i <= right; i++)
    {
        a[i] = temp[i];
    }
}

// Merge Sort function
void mergeSort(int a[], int left, int right)
{
    if(left < right)
    {
        int mid = (left + right) / 2;
        // Divide left part
        mergeSort(a, left, mid);
        // Divide right part
        mergeSort(a, mid + 1, right);
        // Merge both parts
        merge(a, left, mid, right);
    }
}

int main()
{
    int a[6] = {70,30,50,10};
    int n = 4;
    int i;

    // Call merge sort
    mergeSort(a, 0, n - 1);

    // Print sorted array
    printf("Sorted array:\n");
    for(i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }

    return 0;
}