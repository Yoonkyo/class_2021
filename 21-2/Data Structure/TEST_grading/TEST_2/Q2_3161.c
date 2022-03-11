#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>

#define SIZE 101

typedef struct {
	int queue[SIZE]; 
	int front, rear;
}QueueType;

QueueType Queue;

void Queue_init(QueueType* q) 
{
	q->front = q->rear = 0;
}

int is_empty(QueueType* q) 
{
	return (q->front == q->rear); 
}

int is_full(QueueType* q) 
{
	return ((q->rear + 1) % SIZE == q->front); 
}

void enqueue(QueueType* q, int e) 
{
	if (is_full(q))
		return;
	q->rear = (q->rear + 1) % SIZE;
	q->queue[q->rear] = e;
}

int dequeue(QueueType* q) 
{
	if (is_empty(q))
		return -1;
	q->front = (q->front + 1) % SIZE;
	return q->queue[q->front];
}

int main()
{
	Queue_init(&Queue); 
	int i, N, e = 0; 

	while(1){
        scanf("%d", &N);
        if (N%2==1){
            break;
        }
        else{
            printf("2n+1의 값을 입력하세요");
        }
    } 

	for (i = 0; i < N; i++) 
	{
		enqueue(&Queue, i + 1); 
	}

	while (!is_empty(&Queue)) 
	{
		e = dequeue(&Queue); 
		if (is_empty(&Queue)){
            break;
        }
        e = dequeue(&Queue);
		e = dequeue(&Queue);
        if (is_empty(&Queue)){
            break;
        } 
		enqueue(&Queue, e); 
	}
	printf("%d\n", e); 

	return 0;
}
