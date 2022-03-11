#include<stdio.h>
int main(){
    int n,i,a,sum;
    scanf("%d",&n);
    int A[n];
    sum=0;
    for(i=0;i<n;i++){
        scanf("%d",&a);
        A[i]=a;
        sum=sum+A[i];
    }
    printf(" the sum of array element %d",sum);
    return 0;
}