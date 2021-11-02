#include <stdio.h>

int main()
{
    int a,c=0;
    printf("");
    scanf("%d", &a);
    int b[a];
    for (int i = 0; i < sizeof(b)/sizeof(int); i++)
    {
        printf("");
        scanf("%d", &b[i]);
    }
    for (int i = 0; i < sizeof(b)/sizeof(int); i++)
    {
       c=c+b[i];
    }
    printf("%d", c);
}