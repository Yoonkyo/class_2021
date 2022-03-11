#define A 10
#include <stdio.h>
int main(){

    int A[];

    int i;
    for (int n=0;n<10;n++){
        scanf("%d",&i);
        A[n]=i;
    }
    
    int Max=0;
    for (int n=0;n<10;n++){
        if Max<A[n];
            Max=A[n];

    }
    printf("%d",Max);
    return 0;

}
