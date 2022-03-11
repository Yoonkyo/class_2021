//Q1-code
#include <stdio.h>

int main(void)
{
    int n,input,sum=0;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&input);
        sum+=input;
    }
    printf("%d",sum);
    return 0;
}