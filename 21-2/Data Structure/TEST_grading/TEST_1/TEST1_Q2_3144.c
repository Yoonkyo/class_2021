//Q2-code
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void)
{
    int input,MAX,i=0;
    int Arr[11];
    char S[1000000];
    scanf("%[^\n]s",S);
    char *ptr=strtok(S," ");
    while(ptr!=NULL)
    { 
        Arr[i]=atoi(ptr);
        ptr=strtok(NULL," ");
        i++;
    }
    for(int j=0;j<i;j++)
    {
        if(j==0)
            MAX=Arr[j];
        if(MAX<Arr[j])
            MAX=Arr[j];
        
    }
    printf("%d",MAX);
    return 0;
}