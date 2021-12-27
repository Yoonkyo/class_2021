//FX,FY 리스트를 이용해 나이트가 이동할 수 있는 모든 방향을 저장해 준 후, 각 값을 모두 Queue에 저장하는 BFS 방식을 사용한 프로그램입니다.
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
int px,py,l,cnt,nx,ny,front,rear;
int fx[8]={-2,-2,-1,-1,1,1,2,2};
int fy[8]={1,-1,2,-2,2,-2,1,-1};//이동 방향을 리스트형으로 저장
typedef struct{
    int x,y;
}queue;//좌표를 저장해주는 구조체

void BFS(bool graph[][301],queue *que)
{
    if(graph[px][py]==1)
        return;//목표지점에 도달하면 루프를 종료
    cnt++;//한 ‘층’을 탐색 할 때 마다 CNT를 증가시켜 몇 번의 이동이 있었는지 세준다.
    int temp=rear-front;
    int tx,ty;
    while(temp--)//반복문을 사용해야 하는 횟수
    {
        nx=que[front].x,ny=que[front].y;//이전 이동지점 호출 (각 이동 지점에서 여러 방향으로 이동)
        front++;
        for(int i=0;i<8;i++)
        {
            tx=nx+fx[i];
            ty=ny+fy[i];
            if((tx>=0&&ty>=0&&tx<l&&ty<l)&&graph[tx][ty]==0)
            {
                graph[tx][ty]=1;
                que[rear].x=tx,que[rear].y=ty;
                rear++;//이동한 점을 Queue리스트에 저장해준 후 리어를 밀어줌
            }
        }
    }
    BFS(graph,que);
}

int main(void){
    int T;
    scanf("%d",&T);
    while(T--)//T개의 케이스에 대해 반복
    {
        front=rear=cnt=0;//front rear cnt를 각 케이스에 대해 초기화
        queue que[90001]={{0,0},};//Que를 각 케이스에 대해 초기화
        bool graph[301][301]={0,};//그래프(이전 방문 여부를 체크해주는 이차원 어레이 초기화)
        scanf("%d",&l);//길이 입력
        scanf("%d %d %d %d",&nx,&ny,&px,&py);//현재 x y 좌표, 목표 x y 좌표 입력
        graph[nx][ny]=1;//현재 지점을 “방문함”으로 설정
        que[rear].x=nx,que[rear].y=ny;//BFS의 시작지점 설정
        rear++;
        BFS(graph,que);//BFS방식 탐색
        printf("%d\n",cnt);//이동횟수 출력
    }
}