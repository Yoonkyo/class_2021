#include <stdio.h>
#define size 101


typedef struct{
    int Queue[size];
    int front, rear;
}Queue;

Queue que;

void Queue_init(Queue* q)
{
    q->front=q->rear=0;
}

int is_full(Queue* q)
{
    return (q->rear+1)%size==q->front;
}

int is_empty(Queue* q)
{
    return (q->front==q->rear);
}

void enqueue(Queue* q, int n)
{
    if(is_full(q))
        return;
    else
        q->rear=(q->rear+1)%size;
        q->Queue[q->rear]=n;
}

int dequeue(Queue* q)
{
    if(is_empty(q))
        return;
    else
        q->front=(q->front+1)%size;
        return q->Queue[q->front];

}

int main()
{
    int num, ans;
    scanf("%d", &num);
    Queue_init(&que);
    for(int i=1; i<=num; i++)
    {
        enqueue(&que, i);
    }
    while(!is_empty(&que))
    {
        ans=dequeue(&que);
        if(is_empty(&que))
            break;
        ans=dequeue(&que);
        ans=dequeue(&que);
        enqueue(&que, ans);
    }
    printf("%d", ans);
}