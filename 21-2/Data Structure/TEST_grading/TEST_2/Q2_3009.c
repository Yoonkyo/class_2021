#include <stdio.h>
#define SIZE 101 
typedef struct {
	int data[SIZE];
	int front, rear;
}queue;

void queue_init(queue *q){
    q->front=q->rear=0;
}

int is_empty(queue *q){
    return (q->front == q->rear);
}

int is_full(queue *q){
    return ((q->rear+1)%SIZE ==q->front);
}

void enqueue(queue *q, int e){
    if(is_full(q)) return;
    q->rear = (q->rear+1)%SIZE;
    q->data[q->rear]=e;
}

int dequeue(queue *q){
    if(is_empty(q)) return -1;
    q->front = (q->front+1)%SIZE;
    return q->data[q->front];
}

int main(){
    queue q;
    queue_init(&q);
    int i, n, e=0;
    scanf("%d", &n);
    for(i=0; i<n; i++){
        enqueue(&q, i+1);
    }
    while(!is_empty(&q)){
        e=dequeue(&q);
        if(is_empty(&q)){
            break;
        }
        e=dequeue(&q);
        if(is_empty(&q)){
            break;
        }
        enqueue(&q, e);
    }
    printf("%d\n", e);
    return 0;
}