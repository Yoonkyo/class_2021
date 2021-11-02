#include<stdio.h>
int main(){
    int i,n,a,max;
    scanf("%d",&n);
    int A[n];
    for(i=0;i<n; i++){
        scanf("%d",&a);
        A[i]=a;
    }
    for(i=0;i<n;i++){
        if(A[i]> A[i+1]){
            max=A[i];
        }
        else{
            max=A[i+1];

        }
        
    }
    printf("%d",max);
    return 0;   
}

