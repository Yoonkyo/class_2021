//FX,FY ����Ʈ�� �̿��� ����Ʈ�� �̵��� �� �ִ� ��� ������ ������ �� ��, �� ���� ��� Queue�� �����ϴ� BFS ����� ����� ���α׷��Դϴ�.
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
int px,py,l,cnt,nx,ny,front,rear;
int fx[8]={-2,-2,-1,-1,1,1,2,2};
int fy[8]={1,-1,2,-2,2,-2,1,-1};//�̵� ������ ����Ʈ������ ����
typedef struct{
    int x,y;
}queue;//��ǥ�� �������ִ� ����ü

void BFS(bool graph[][301],queue *que)
{
    if(graph[px][py]==1)
        return;//��ǥ������ �����ϸ� ������ ����
    cnt++;//�� �������� Ž�� �� �� ���� CNT�� �������� �� ���� �̵��� �־����� ���ش�.
    int temp=rear-front;
    int tx,ty;
    while(temp--)//�ݺ����� ����ؾ� �ϴ� Ƚ��
    {
        nx=que[front].x,ny=que[front].y;//���� �̵����� ȣ�� (�� �̵� �������� ���� �������� �̵�)
        front++;
        for(int i=0;i<8;i++)
        {
            tx=nx+fx[i];
            ty=ny+fy[i];
            if((tx>=0&&ty>=0&&tx<l&&ty<l)&&graph[tx][ty]==0)
            {
                graph[tx][ty]=1;
                que[rear].x=tx,que[rear].y=ty;
                rear++;//�̵��� ���� Queue����Ʈ�� �������� �� ��� �о���
            }
        }
    }
    BFS(graph,que);
}

int main(void){
    int T;
    scanf("%d",&T);
    while(T--)//T���� ���̽��� ���� �ݺ�
    {
        front=rear=cnt=0;//front rear cnt�� �� ���̽��� ���� �ʱ�ȭ
        queue que[90001]={{0,0},};//Que�� �� ���̽��� ���� �ʱ�ȭ
        bool graph[301][301]={0,};//�׷���(���� �湮 ���θ� üũ���ִ� ������ ��� �ʱ�ȭ)
        scanf("%d",&l);//���� �Է�
        scanf("%d %d %d %d",&nx,&ny,&px,&py);//���� x y ��ǥ, ��ǥ x y ��ǥ �Է�
        graph[nx][ny]=1;//���� ������ ���湮�ԡ����� ����
        que[rear].x=nx,que[rear].y=ny;//BFS�� �������� ����
        rear++;
        BFS(graph,que);//BFS��� Ž��
        printf("%d\n",cnt);//�̵�Ƚ�� ���
    }
}