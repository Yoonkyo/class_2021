#include <stdio.h>

int main()
{
    int num, sum = 0;
    
    scanf("%d", &num);
    int arr[num]={};
    
   
    for(int i = 0; i < num; i++)
    {
        scanf("%d", &arr[i] );
    }

    for (int j = 0; j <= sizeof(arr)/sizeof(int); j++)
    {
        sum += arr[j];
    }
    printf("%d\n", sum);
    return 0;
}