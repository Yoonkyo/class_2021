#include <stdio.h>

int N=0, M=0, map[101][101]={0, };

int move_x[4]={1,-1,0,0}; //좌우 움직임
int move_y[4]={0,0,1,-1}; //상하 움직임

typedef struct queue_m{
    int x,y;
}queue_m;

queue_m que[10001];//구조체 que로 x,y 저장

int maze()
{
	int front=0, rear=1;
	que[front].x=1;
    que[front].y=1;

	while(front<rear) //큐가 공백이 될때까지
	{
		int x = que[front].x; //x 좌표와 y좌표를 각각 queue의 front값을 부여
		int y = que[front].y;
		front++;    // front는 1개씩 증가

		for (int i = 0; i < 4; i++)
		{
			int maze_x=x+move_x[i];  //x, y값을 1씩 변동시켜 상하좌우 변동
			int maze_y=y+move_y[i];

			if(maze_x<1 || maze_y<1 || maze_y>N || maze_x >M) //조건이 만족되지 않으면
				continue; //실행하지 않음
			if(map[maze_y][maze_x]!=1)  // 길이 아니거나 이미 지나온 길일 경우
				continue; //실행하지 않음
			
			map[maze_y][maze_x]=map[y][x]+1; // 처음 시작 값이 1, 그 다음부터 지나온 길은 시작값에 1개씩 더해 이동한 횟수로 maze를 바꿈

			que[rear].x=maze_x;  //queue에 그 다음 x, y값을 넣음
			que[rear].y=maze_y;
			rear++;
		}
		
	}
	return map[N][M];
}

int main(void)
{
	scanf("%d %d", &N, &M);
	for (int i = 1; i <= N; i++)
	{
		for(int j=1; j<=M; j++)
			scanf("%1d", &map[i][j]);
	}
	int ans=maze();
	printf("%d", ans);
}