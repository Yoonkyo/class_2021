#include <stdio.h>

int main(){
    int n, input, sum=0;

    scanf("%d", &n);

    for(int i=0; i<n; i++){
        scanf("%d", &input);
        sum = sum + input;
    }
    printf("%d", sum);

    return 0;
}