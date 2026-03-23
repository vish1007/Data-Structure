#include <stdio.h>-
int main()
{
    int a[5] = {5, 3, 8, 4, 2};
    int i, j, temp;
    int n = 5;
    for(i = 0; i < n-1; i++)          // number of passes
    {
        for(j = 0; j < n-1; j++)      // comparisons
        {
            if(a[j] > a[j+1])
            {
                temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
            }
        }
    }
    printf("Sorted array:\n");
    for(i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
    return 0;
}