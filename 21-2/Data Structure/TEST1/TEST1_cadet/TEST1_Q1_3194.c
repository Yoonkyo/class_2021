#include <stdio.h>
int main(){
    int num1;
    printf("\nnum1 enter:");
    scanf("%d",&num1);
    int A[num1];

    int i;
    for (int n=0;n<num1;n++){
        scanf("%d",&i);
        A[n]=i;
        
    }
    int j=0,sum;
    while(j<sizeof(A)/sizeof(int)){
        sum=A[j]+sum;
        j++;

    }
    printf("%d",sum);
    return 0;
}

