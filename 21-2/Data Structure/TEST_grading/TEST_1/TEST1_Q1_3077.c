#include <stdio.h>
int main(){
    int N, A, sum=0;
    scanf("%d",&N);
    for (int i=0; i<N; i++){
        scanf("%d", &A);
        sum = sum+A;

    }
    printf("%d", sum);
}
