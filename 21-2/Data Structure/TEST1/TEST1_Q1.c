#include <stdio.h>

int main(){
    int n, b;
    int i = 0;
    scanf("%d", &n); 
    int result = 0;
    while(i<n){
        scanf("%d", &b);
        result += b;
        i++;
    }
    printf("%d", result);
}