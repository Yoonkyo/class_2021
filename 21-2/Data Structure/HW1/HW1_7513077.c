#include <stdio.h>
 
int main(void)
{
    int sidelen;  //보드 한 변의 길이
    int applenum;  //사과의 개수
    int changenum;  //방향 변환 횟수
    int len = 1;  //뱀의 길이
    int board[100][100];  //보드
    int i, j, y, x, sec, dir, cur_time;
    char ch;
        
    scanf("%d", &sidelen);//보드 크기 입력
    scanf("%d", &applenum);//사과 갯수 입력
 
    //보드 내 모든 값 0으로 초기화(sidelen 이내의 범위)
    for (i = 0; i < sidelen; i++)
    {
        for (j = 0; j < sidelen; j++)
        {
            board[i][j] = 0;
        }
    }
    //사과 위치에 -1 저장 
    for (i = 0; i < applenum; i++)
    {
        scanf("%d %d", &y, &x);
        board[y - 1][x - 1] = -1;
    }
 
    scanf("%d", &changenum);
    cur_time = 0;  //시간정보 초기화
    x = y = 0;  //뱀의 시작위치 초기화
    dir = 1; //뱀의 움직임 방향 초기화(우측)
 
    scanf("%d %c", &sec, &ch);// sec초에 ch방향으로 방향변환
    changenum--;  //입력 받은 횟수 차감
    //뱀의 움직임
    while (1)
    {
        //방향 전환할 시간
        if (cur_time == sec)
        {
            if (ch == 'D')  //우측으로 전환
                dir++;
            else if (ch == 'L')  //좌측으로 전환
                dir--;
            //방향변환 특수케이스 보정
            if (dir == 0)
                dir = 4;
            else if (dir == 5)
                dir = 1;
                
 
            if (changenum > 0)
            {
                scanf("%d %c", &sec, &ch);
                changenum--;  //입력 받은 횟수 차감
            }
        }
        if (dir == 1)  //우
            x++;
        else if (dir == 2) //하
            y++;
        else if (dir == 3) //좌
            x--;
        else if (dir == 4) //상
            y--;
 
        cur_time++;
        //printf("cur_time: %d, y: %d x: %d , dir: %d, len: %d\n", cur_time, y, x, dir, len);
 
        if (board[y][x] == -1)  //사과가 있을시 길이 증가
            len++;
            
        //몸에 부딪히면 종료
        if (board[y][x] > 0 && board[y][x] >= cur_time - len)
        {
            printf("%d\n", cur_time);
            return 0;
        }
        //보드를 벗어나면 종료
        //헤드가 해당 칸을 지나간 시간이 curtime>=지나간 시간>curtime-len꼴인 칸이 현재의 몸 위치임을 이용해 충돌여부 확인
        if (x < 0 || y < 0 || x >= sidelen || y >= sidelen)
        {
            printf("%d\n", cur_time);
            return 0;
        }
        //헤드가 해당 칸을 지나간 시간을 기록 
        board[y][x] = cur_time;
    }
 
    return 0;
}
