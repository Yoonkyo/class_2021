#include <stdio.h>

int main(){

    int n=0;
    int arr[10];
    int max=0;
    for(int i=0; i<10; i++){
        scanf("%d", arr[i]);
        if(arr[i]=='\n') break;
        n=i;
        }
    for(int j=0; j<n; j++){
        if(arr[j]>=max){
            max=arr[j];
        }
    }
    printf("%d", max);
    return 0;
    }
