#include <stdio.h>
# define n 10
int main()
{
    int max = 0;
    int arr[n];
    for (int i = 0; i < 10; i++)
    {
        scanf_s("%d", &arr[i]);
        if (max < arr[i])
        {
            max = arr[i];
        }
        printf("maximum:%d \n", max);
    }
    return 0;
}