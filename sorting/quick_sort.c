#include <stdio.h>

// Swap function
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
// Partition function (first element as pivot)
int partition(int a[], int start, int end)
{
    int pivot = a[start];   // first element as pivot
    int i = start + 1;
    int j = end;
    while(i <= j)
    {
        // move i forward until element > pivot
        while(i <= end && a[i] <= pivot)
            i++;
        // move j backward until element <= pivot
        while(a[j] > pivot)
            j--;
        // swap only if i < j
        if(i < j)
            swap(&a[i], &a[j]);
    }
    // place pivot at correct position
    swap(&a[start], &a[j]);
    return j;
}

// Quick Sort function
void quickSort(int a[], int start, int end)
{
    if(start < end)
    {
        int p = partition(a, start, end);

        quickSort(a, start, p - 1);  // left part
        quickSort(a, p + 1, end);    // right part
    }
}
int main()
{
    int a[6] = {5,4,3,2,1};
    int n = 6;
    int i;
    quickSort(a, 0, n - 1);
    printf("Sorted array:\n");
    for(i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
    return 0;
}