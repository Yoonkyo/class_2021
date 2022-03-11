#include <stdio.h>
#define SIZE 10

int main()
{
    int arr[SIZE]={};
    
    for(int k = 0; k <SIZE; k++)
    {
        scanf("%d", &arr[k] );
    }
    int max = arr[0];
    
    for (int i = 0; i < SIZE; i++) {
        if (arr[i] > max) max = arr[i];
    }
    printf("%d", max);
    return 0;
}