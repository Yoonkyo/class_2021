#include <stdio.h>
#include <string.h>

typedef struct queue{
    int data[2000000];
    int front, rear;
}queue; //queue라는 데이터 타입을 만들기

void clear(queue *q){
    q->front=q->rear=-1;
}   //queue 초기화

int empty(queue *q){
    return(q->front==q->rear);
} //queue가 비어있을 경우 1, 아닐경우 0. 비어있으면 front와 rear의 값이 같기 때문

int size(queue *q){
    if(empty(q)) return 0;
    return (q->rear - q->front);
} //queue의 사이즈 측정. queue가 비어있을 경우 0, 아닌 경우 rear에서 front 값을 뺌

void push(queue *q, int data){
    q->data[++(q->rear)]=data;
} //queue에 데이터 집어넣기. 

int pop(queue *q){
    if(empty(q)) return -1;
    return q->data[++(q->front)];
} //가장 먼저 들어온 데이터 빼기. queue가 비어있을 경우 -1 반환

int front(queue *q){
    if(empty(q)) return -1;
    return q->data[q->front +1];
} //가장 앞에 있는 데이터 확인. queue가 비어있을 경우 -1 반환

int back(queue *q){
    if(empty(q)) return -1;
    return q->data[q->rear];
} //가장 뒤에 있는 데이터 확인. queue가 비어있을 경우 -1 반환

int main(void){
    queue q; //queue 생성
    clear(&q); //queue 초기화
    int n;
    scanf("%d", &n);
    while (n--){
        char str[6];
        scanf("%s", str);
        if(!strcmp(str, "push")){ //strcmp = string compare. scanf로 입력한 단어가 같을 경우~
            int data =0;
            scanf("%d", &data);
            push(&q, data);
        }
        else if(!strcmp(str, "front")){
            printf("%d\n", front(&q));
        }
        else if(!strcmp(str, "back")){
            printf("%d\n", back(&q));
        }
        else if(!strcmp(str, "pop")){
            printf("%d\n", pop(&q));
        }
        else if(!strcmp(str, "size")){
            printf("%d\n", size(&q));
        }
        else if(!strcmp(str, "empty")){
            printf("%d\n", empty(&q));
        }//scanf로 입력한 단어들과 함수들을 연결        
    }
    return 0;
}