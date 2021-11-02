#include <stdio.h>
#define MAX 1000000 //MAX를 100000으로 설정

 
int queue[MAX]; //입력값 큐 생성
int output[MAX]; //결과값 어레이 생성
int front =-1; //front 는 -1
int rear =-1; //rear 은 -1
 
void push(int n) { //push 함수 생성
    queue[++rear] = n; //큐의 rear 앞으로 n 요소 삽입
}
 
int pop() { //pop 함수 생성
    if (front == rear) { //큐에 아무것도 없으면 -1을 반환
        return -1;
    }
    else { //큐에 데이터가 있다면 
        return queue[++front]; //큐의 front 앞 요소 반환
    }
}

//main 함수 생성
int main() {
    int n, m; //n,m 변수 선언
    int i, cnt=0; //i, cnt 는 0
 
    scanf("%d %d", &n, &m); //n,m 입력값 받기
    for (i = 1; i <= n; i++) {
        push(i); //1부터 n까지 큐에 데이터 삽입
    }
 
    while (front != rear) { //큐에 데이터가 있으면
        for (i = 0; i < m - 1; i++) { //*규칙상 m-1번을 건너 뛴 이후에 m 번째 요소가 선택이 됨.
            push(pop()); //m-1을 rear 뒤로 보냄
        }
        output[cnt] = pop(); //output어레이의 cnt 위치에 pop()을 삽입 ->output 어레이에 순서대로 삭제된 순서대로 요소가 들어가게 됨.
        cnt++; //cnt는 1씩 커진다.
    }
 
 // 결과값 출력
    printf("<"); // < 를 프린트
    for (i = 0; i < n - 1; i++) { //n번째까지
        printf("%d, ", output[i]); //output 어레이의 i번째 요소 출력
    }
    printf("%d>\n", output[i]); //마지막 i번째 요소 출력후 > 출력
}