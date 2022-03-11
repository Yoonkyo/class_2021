#include <stdio.h>

int main(){
    int n, sum;
    scanf("%d", &n);
    for(int i=0; i<n; i++){
        int a;
        scanf("%d",&a);
        sum=sum+a;
    }
    printf("%d",sum);
}