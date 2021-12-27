#include<stdio.h>

int N, K, num[100005] = {0, }, queue[100005] = {0, };  //num배열에는 N으로부터 해당수까지 이동하는데 걸린 최소이동수 저장
                                                        //N을 기준으로 +1, -1, *2를 하여 나오는 수를 queue배열에 저장
int BFS(int pos) {                                      //BFS방식으로 탐색하면서 num배열 수를 채운다.
    int front = 0, rear = 1, pop;
    queue[front] = pos;
    while(front < rear) {
        pop = queue[front++]; //큐를 꺼내고, 수빈이가 동생의 위치에 도달했는지 확인한다.
        if(pop+1<=100000 && !num[pop+1] && pos!=pop+1) {   
            num[pop+1] = num[pop]+1;
            queue[rear++] = pop+1;
            if(pop+1 == K) break;
        }                                   //수빈이 현재 위치의 +1이 100,000보다 작거나 같고, 방문한 적이 없을 경우, 현재 값에서 레벨을 1증가시켜 큐에 넣어준다.
        if(pop-1>=0 && !num[pop-1] && pos!=pop-1) {
            num[pop-1] = num[pop]+1;
            queue[rear++] = pop-1;
            if(pop-1 == K) break;           //수빈의 현재 위치 -1이 0보다 크거나 같고, 방문한 적이 없을 경우, 현재 값에서 레벨을 1증가시켜 큐에 넣어준다.
        }
        if(pop*2<=100000 && !num[pop*2] && pos!=pop*2) {
            num[pop*2] = num[pop]+1;
            queue[rear++] = pop*2;
            if(pop*2 == K) break;           //수빈이 현재 위치의 2배의 크기가 100,000보다 작거나 같고, 방문한 적이 없을 경우, 현재 값에서 레벨을 1증가시켜 큐에 넣어준다.
        }
    }                   //BFS방식으로 계속 돌리면서 탐색하다가 POP에 K가 나오면 프로그램이 종료된다.
    return num[K];
}

int main() {
    scanf("%d %d", &N, &K);
    printf("%d", BFS(N));
}