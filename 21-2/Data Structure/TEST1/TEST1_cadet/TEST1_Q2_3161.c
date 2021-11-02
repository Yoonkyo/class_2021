#include <stdio.h>

int main(){
    int A[10]={};
    for(int i=0; i<sizeof(A)/sizeof(int); i++){
        scanf("%d", &A[i]);
    }
    int max;
    for(int i=0; i<sizeof(A)/sizeof(int); i++){
        if (A[i]>=max){
            max=A[i];
        }
    }
    printf("%d", max);
}