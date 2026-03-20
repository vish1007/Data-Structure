#include <stdio.h>

int main()
{
    // Initial unsorted array
    int a[5] = {23, 1, 10, 5, 2};
    int i, j, key;
    int n = 5;

    // Loop through all elements starting from index 1
    // (Assume first element is already sorted)
    for(i = 1; i < n; i++)
    {
        // Take the current element as key
        key = a[i];

        // Compare with previous elements
        j = i - 1;

        // Shift elements to the right until correct position is found
        while(j >= 0 && a[j] > key)
        {
            a[j + 1] = a[j];   // move element one position ahead
            j = j - 1;         // move to previous element
        }

        // Place the key in its correct position
        a[j + 1] = key;
    }

    // Print the sorted array
    printf("Sorted array:\n");

    for(i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }

    return 0;
}