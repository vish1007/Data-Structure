#include <stdio.h>
int main()
{
    int a[7] = {7,4,5,9,8};
    int i, j, min, temp;
    int n = 7;
    for(i = 0; i < n-1; i++)   // passes
    {
        min = i;
        for(j = i+1; j < n; j++)   // find smallest
        {
            if(a[j] < a[min])
            {
                min = j;
            }
        }
        temp = a[i];
        a[i] = a[min];
        a[min] = temp;
    }
    for(i = 0; i < n; i++)
        printf("%d ", a[i]);
    return 0;
}