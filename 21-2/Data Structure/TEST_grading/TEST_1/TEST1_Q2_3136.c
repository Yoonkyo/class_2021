#include <stdio.h>

int main()
{
    int a[10]={0,0,0,0,0,0,0,0,0,0};
    printf("");
    scanf("%d %d %d %d %d %d %d %d %d %d", &a[0],&a[1],&a[2],&a[3],&a[4],&a[5],&a[6],&a[7],&a[8],&a[9]);
    int c=0;
    for (int i = 0; i < 10; i++)
    {
        if(c>=a[i])
            c=c;
        else
            c=a[i];
    }
    printf("%d", c);
}