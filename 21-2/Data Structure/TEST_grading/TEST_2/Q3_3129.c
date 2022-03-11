#include<stdio.h>
int paper[2000][2000]; // 흰색 및 파란색 작은 사각형의 array
int white=0,blue=0;
void solve(int y, int x, int size)
{
    int check;
    check = paper[y][x]; // array 첫 번째 값
    for (int i = y; i < y + size; i++)
    {
        for (int j = x; j < x + size; j++)
        {   
            if (check == 0 && paper[i][j] == 1) // 첫 번째 숫자를 다음 숫자와 비교하고 첫 번째 숫자가 횐색이라는 조건을 지정합니다.
            {
                check = 2; //틀리면 check is 2
            }
            else if (check == 1 && paper[i][j] == 0) // 첫 번째 숫자를 다음 숫자와 비교하고 첫 번째 숫자가 파란색이라는 조건을 지정합니다.
            {
                check = 2;
            }
            if (check == 2) //2라면, 그것은 같은 색깔의 정사각형 칸을 찾기 위해 계속해서 더 작은 정사각형 부분으로 쪼개질 것입니다.
            {     
                // 왼쪽 위 사분면 같은 색깔의 정사각형들을 찾기
                solve(y, x, size / 2);
                // 오른쪽 위 사분면 같은 색깔의 정사각형들을 찾기
                solve(y, x + size / 2, size / 2);
                // 왼쪽 아래 사분면 같은 색깔의 정사각형들을 찾기
                solve(y + size / 2, x, size / 2);
                // 오른쪽 아래 사분면 같은 색깔의 정사각형들을 찾기
                solve(y + size / 2, x + size / 2, size / 2);
                return;
            }
        }
    }

    if (check == 0) // 같은 흰색 사각형으로 찾으면 1을 더해서
        white++;
    else // 같은 파란색색 사각형으로 찾으면 1을 더해서
        blue++;
    
}
int main(){
    int i,size,j;
    scanf("%d",&size);
    for(i=0;i<size;i++){
        for(j=0;j<size;j++){
            scanf("%d",&paper[i][j]); //흰색 및 파란색 작은 사각형이 들어 있는 판 만들기
        }
        printf("\n");
    }
    solve(0,0,size); // solve에 변수 입력
    printf("%d\n",white);// 흰색 사각형 수
    printf("%d",blue); // 파란색 사각형 수
    return 0;
}