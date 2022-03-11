#include <stdio.h>

int main(void){
    int N,front=0,rear;
    int que[100001];
    scanf("%d",&N);
    rear=N-1;
    for(int i=0;i<N;i++){
        que[i]=i+1;
    }
    
    while(1){
        front=(front+2)%N; 
        rear=(rear+1)%N;
        que[rear]=que[front];
        front=(front+1)%N; 
        if(rear==front)
            break;
    }
    printf("%d",que[front]);
    return 0;
}