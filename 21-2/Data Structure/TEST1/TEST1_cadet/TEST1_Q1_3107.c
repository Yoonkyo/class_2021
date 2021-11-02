#include <stdio.h>
int main(){
    int n;
    scanf("%d", &n);
    
    char integers[100];
    
    scanf("%[^\n]s", integers);
    
    int sum=0;
    int a;
    for(int i=0;i<n;i++)
    {
        a = integers[i];
        sum+=a;
    }
    printf("%d",sum);
    return 0;
}