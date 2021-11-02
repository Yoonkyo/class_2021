#define _CRT_SECURE_NO_WARNINGS //scanf 사용시 안전성의 이유로 넣어주는 코드
#include <stdio.h>

#define SIZE 500001 //전역변수로 배열 선언(원형큐 알고리즘에서 is_full 함수의 rear와 front 사이에 한 칸의 빈칸이 있어야 하므로 500001)

typedef struct {
	int queue[SIZE]; //큐 선언
	int front, rear;
}QueueType;

QueueType Queue;

void Queue_init(QueueType* q) //큐를 초기화함
{
	q->front = q->rear = 0;
}

int is_empty(QueueType* q) //큐가 공백일 때를 검출함
{
	return (q->front == q->rear); //0 1 2 3...n의 형태로 나타나므로 큐가 공백일 때에만 이 식이 성립함
}

int is_full(QueueType* q) //큐가 꽉 찼을 때를 검출함
{
	return ((q->rear + 1) % SIZE == q->front); //n==500000일 때에 (500001)%500001==0
}

void enqueue(QueueType* q, int e) //삽입과정 enqueue 정의
{
	if (is_full(q))
		return;
	q->rear = (q->rear + 1) % SIZE;
	q->queue[q->rear] = e;
}

int dequeue(QueueType* q) //삭제과정 dequeue 정의
{
	if (is_empty(q))
		return -1;
	q->front = (q->front + 1) % SIZE;
	return q->queue[q->front];
}

int main()
{
	Queue_init(&Queue); //큐 초기화
	int i, n, e = 0; //변수 지정

	scanf("%d", &n); //n 입력받기

	for (i = 0; i < n; i++) //i는 0부터 n-1까지 실행
	{
		enqueue(&Queue, i + 1); //1부터 n까지 순차적으로 삽입
	}

	while (!is_empty(&Queue)) //큐가 비어있지 않는 동안 계속 실행
	{
		e = dequeue(&Queue); //맨 위에 있는 값 빼내기
		if (is_empty(&Queue)) //큐가 비어있으면 바로 중지해서 출력으로 넘어감
			break;
		e = dequeue(&Queue); //맨 위에 있는 값 빼내서
		enqueue(&Queue, e); //맨 아래로 다시 넣기

	}
	printf("%d\n", e); //마지막 남은 값 출력

	return 0;
}