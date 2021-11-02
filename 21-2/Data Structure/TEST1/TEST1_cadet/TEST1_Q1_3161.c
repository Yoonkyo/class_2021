#include <stdio.h>

int main(){
    int n, summ;
    scanf("%d", &n);
    for(int i=0; i<n; i++){
        int a;
        scanf("%d", &a);
        summ=summ+a;
    }
    printf("%d", summ);
}