#include <stdio.h>
int main(){
    char A[10];
    int min;
    scanf("%s",A);
    for(int i = 0;i < sizeof(A) / sizeof(int); i++)
    if(A[i] <= A[i+1]) 
            {
			min = A[i];
			A[i+1] = min;
            }

		else
			{min = A[i+1];}
        
    printf("%d",min);
